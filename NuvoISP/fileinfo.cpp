#include "StdAfx.h"
#include "fileinfo.h"
#include <sys/stat.h>

BOOL IsFolder2(const CString &path)
{
    WIN32_FIND_DATA fd;
    BOOL ret = FALSE;
    HANDLE hFind = FindFirstFile(path, &fd);

    if ((hFind != INVALID_HANDLE_VALUE) && (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        ret = TRUE;
    }

    FindClose(hFind);
    return ret;
}

/**
 * Get the size of a file.
 * @param filename The name of the file to check size for
 * @return The filesize, or 0 if the file does not exist.
 */
size_t getFilesize(const std::tstring &filename)
{
    struct _stat st;

    if (_tstat(filename.c_str(), &st) != 0) {
        return 0;
    }

    return st.st_size;
}


#include <fstream>
#include <vector>
#if 0
bool UpdateFileInfo(CString strFN, struct fileinfo *sfinfo)
{
    std::ifstream       file(strFN);

    if (file) {
        /*
         * Get the size of the file
         */
        file.seekg(0, std::ios::end);
        std::streampos          length = file.tellg();
        file.seekg(0, std::ios::beg);
        /*
         * Use a vector as the buffer.
         * It is exception safe and will be tidied up correctly.
         * This constructor creates a buffer of the correct length.
         * Because char is a POD data type it is not initialized.
         *
         * Then read the whole file into the buffer.
         */
        //std::vector<char>       buffer(length);
        //file.read(&buffer[0],length);
        sfinfo->filename = strFN.GetBuffer(0);
        sfinfo->st_size = length;
        sfinfo->vbuf.resize(length);
        file.read(&(sfinfo->vbuf[0]), length);

        if (file) {
            printf("all characters read successfully.\n");
        } else {
            printf("error: only %i could be read\n", file.gcount());
        }

        unsigned short cks = 0;

        for (size_t i = 0; i < length; i++) {
            cks += sfinfo->vbuf[i];
        }

        sfinfo->usCheckSum = cks;
        return true;
    }

    return false;
}
#else
#include <string>
#include <cstdio>
#include <cstdint>
#include <cerrno>

#define C_FirstCharacter    1
#define C_HeadSize          8
#define C_ChecksumSize      2
#define C_StringEnd         2
#define C_LineSize          (C_FirstCharacter + C_HeadSize + 255 + C_ChecksumSize + C_StringEnd ) * 2

typedef enum 
{
    E_SegmentAddress = 0,
    E_LinearAddress
} Enum_MemoryType;

typedef enum
{
    E_OK = 1,
    E_InProcess = 0,
    E_FileNotFound = -1,
    E_CheckSum = -2,
    E_IncompatibleFile = -3,
    E_MemoryAllocation = -4,
    E_EndianesIncompatibleBits = -5
}Enum_Errors;

uint8_t F_ConvertAsciiToNumeric(int8_t VF_Ascii)
{
    if (VF_Ascii >= '0' && VF_Ascii <= '9')
    {
        return (VF_Ascii - 0x30);
    }
    else if (VF_Ascii >= 'a' && VF_Ascii <= 'f')
    {
        return (VF_Ascii - 87);
    }
    else if (VF_Ascii >= 'A' && VF_Ascii <= 'F')
    {
        return (VF_Ascii - 55);
    }
    return 0xFF;
}

int8_t F_ConvertArrayFromAsciiToNumeric(int8_t A_Data[], int VF_DataSize, int8_t A_ConvertedData[])
{
    int VF_ArrayPos = 0;
    int VF_Result = 0;
    for (VF_ArrayPos = 0; VF_ArrayPos < VF_DataSize; VF_ArrayPos = VF_ArrayPos + 2)
    {
        VF_Result = F_ConvertAsciiToNumeric(A_Data[VF_ArrayPos + 1]) + ((F_ConvertAsciiToNumeric(A_Data[VF_ArrayPos])) << 4);
        if (VF_Result > 0xFF)
        {
            return 0;
        }
        A_ConvertedData[VF_ArrayPos / 2] = VF_Result;
    }
    return 1;
}



bool UpdateFileInfo(CString strFN, struct fileinfo *sfinfo)
{
    if (IsFolder2(strFN)) {
        printf("THis is a folder\n");
        return false;
    }

    _TCHAR *ext = PathFindExtension(strFN.GetBuffer(0));

    if (wcscmp(ext, _T(".hex")) == 0 ) { //HEX file format
        //Parser code taken and adapted from https://sourceforge.net/projects/intelhex2bin/ by franiodoro

        std::uint8_t * A_BinaryData = 0;
        int8_t* AF_FileAsciiRow = 0;
        int8_t* AF_FileRowInHex = 0;

        uint8_t VP_Num_Bytes = 0;
        uint16_t VP_16bitsAddress = 0;
        uint8_t VF_Type = 0;
        uint8_t VF_Checksum = 0;
        uint32_t VF_PhysicalAddress = 0;
        uint32_t VF_MaxPhysicalAddress = 0;
        uint16_t VF_High_Address = 0;
        uint16_t VF_AF_FileRowInHexPos = 0;
        uint16_t VF_SegmentedMemoryAddress = 0;
        uint32_t VF_A_BinaryDataPos = 0;

        Enum_MemoryType E_MemoryType = E_SegmentAddress;
        Enum_Errors E_OperationResult = E_InProcess;

        //
        const size_t VF_FileSize = 256*1024;
        //

        std::FILE *F_HexadecimalFile = _tfopen(strFN.GetBuffer(0), _T("rt")); /* open the file for reading in text mode */
        if ( F_HexadecimalFile == NULL) 
        {
            return false;
        }

        AF_FileAsciiRow = (int8_t *) malloc (C_LineSize * sizeof (int8_t));
        A_BinaryData = (uint8_t*) malloc ( VF_FileSize * sizeof (int8_t));
        if ( A_BinaryData == NULL || AF_FileAsciiRow == NULL)
        {
            //E_OperationResult = E_MemoryAllocation;
            return false;
        }

        //Rellenamos el array con FF por las memorías Flash
        for (VF_A_BinaryDataPos = 0; VF_A_BinaryDataPos < VF_FileSize; VF_A_BinaryDataPos++)
        {
            A_BinaryData[VF_A_BinaryDataPos] = 0xFF;
            //A_BinaryData[VF_A_BinaryDataPos] = 0x00;
        }

        while(fgets((char*)AF_FileAsciiRow, C_LineSize, F_HexadecimalFile) != NULL && E_OperationResult == E_InProcess)
        {
            int16_t VP_TamanoArrayHex = 0;
            if (AF_FileAsciiRow[0] != ':')
            {
                E_OperationResult = E_IncompatibleFile;
                break;
            }
            for ( VP_TamanoArrayHex = 1; VP_TamanoArrayHex < C_LineSize && AF_FileAsciiRow[VP_TamanoArrayHex] != 0 ; VP_TamanoArrayHex++)
            {
                if ( AF_FileAsciiRow[VP_TamanoArrayHex] == '\r' || AF_FileAsciiRow[VP_TamanoArrayHex] == '\n')
                {
                    VP_TamanoArrayHex--;
                    break;
                }
                if (((AF_FileAsciiRow[VP_TamanoArrayHex] >= '0' && AF_FileAsciiRow[VP_TamanoArrayHex] <= '9') ||
                    (AF_FileAsciiRow[VP_TamanoArrayHex] >= 'a' && AF_FileAsciiRow[VP_TamanoArrayHex] <= 'f') ||
                    (AF_FileAsciiRow[VP_TamanoArrayHex] >= 'A' && AF_FileAsciiRow[VP_TamanoArrayHex] <= 'F') ) == 0)
                {
                    VP_TamanoArrayHex = C_LineSize;
                }
            }
            if ( VP_TamanoArrayHex == C_LineSize )
            {
                E_OperationResult = E_IncompatibleFile;
                break;
            }
            AF_FileRowInHex = (int8_t*) malloc ( ((VP_TamanoArrayHex)/2)* sizeof(int8_t));
            if ( AF_FileRowInHex == NULL)
            {
                E_OperationResult =  E_MemoryAllocation;
                break;
            }

            if ( F_ConvertArrayFromAsciiToNumeric(&AF_FileAsciiRow[1], VP_TamanoArrayHex, AF_FileRowInHex) == 0 )
            {
                E_OperationResult = E_IncompatibleFile;
                break;
            }
            VF_Checksum = AF_FileRowInHex[(VP_TamanoArrayHex - C_ChecksumSize)/2];
            VP_Num_Bytes = AF_FileRowInHex[0];
            VP_16bitsAddress = ((((uint16_t) AF_FileRowInHex[1]) << 8) & 0xFF00) + (((uint16_t) AF_FileRowInHex[2]) & 0xFF);
            VF_Type = AF_FileRowInHex[3];
            VF_AF_FileRowInHexPos = 4;

            VF_Checksum = VF_Checksum +  AF_FileRowInHex[0] +  AF_FileRowInHex[1] +  AF_FileRowInHex[2] + AF_FileRowInHex[3] ;

            switch (VF_Type)
            {
                //Registro de Datos
            case 0:
                if (E_MemoryType == E_SegmentAddress)
                {
                    VF_PhysicalAddress = ((((uint32_t) VF_SegmentedMemoryAddress) << 4) & 0xFFFF0) + (((uint32_t) VP_16bitsAddress) & 0xFFFF);
                }
                else
                {
                    VF_PhysicalAddress = ((((uint32_t) VF_High_Address) << 16) & 0xFFFF0000) + (((uint32_t) VP_16bitsAddress) & 0xFFFF);
                }

                if (VF_PhysicalAddress >= VF_FileSize) {
                    //Out of supported range
                    E_OperationResult = E_IncompatibleFile;
                    break;
                }

                for (VF_A_BinaryDataPos = 0; VF_A_BinaryDataPos < VP_Num_Bytes; VF_A_BinaryDataPos++)
                {
                    A_BinaryData[VF_PhysicalAddress++] = AF_FileRowInHex[VF_AF_FileRowInHexPos];
                    VF_Checksum = (VF_Checksum + AF_FileRowInHex[VF_AF_FileRowInHexPos++]);
                }

                if (VF_PhysicalAddress > VF_MaxPhysicalAddress)
                    VF_MaxPhysicalAddress = VF_PhysicalAddress;

                if (VF_Checksum != 0)
                {
                    E_OperationResult = E_CheckSum;
                    break;
                }
                break;

                //Fin de fichero
            case 1:
                if ( VF_Checksum != 0)
                {
                    E_OperationResult = E_CheckSum;
                    break;
                }
                while(fgets((char*)AF_FileAsciiRow, C_LineSize, F_HexadecimalFile) != NULL)
                {
                }
                E_OperationResult = E_OK;
                break;

                //Zona de memoria de segmento extendido, permite hasta 1Mb de memoria
            case 2:
                E_MemoryType = E_SegmentAddress;
                VF_SegmentedMemoryAddress = ((((uint16_t) AF_FileRowInHex[VF_AF_FileRowInHexPos]) << 8) & 0xFF00) + (((uint16_t) AF_FileRowInHex[VF_AF_FileRowInHexPos + 1]) & 0xFF);
                VF_Checksum = (AF_FileRowInHex[VF_AF_FileRowInHexPos + 1] + AF_FileRowInHex[VF_AF_FileRowInHexPos] + VF_Checksum);
                if (VF_Checksum != 0)
                {
                    E_OperationResult = E_CheckSum;
                    break;
                }
                break;
            case 3: 
                break;
                //Zona de memoria lineal extendida, permite hasta 4GiB
            case 4:
                E_MemoryType = E_LinearAddress;
                VF_High_Address = ((((uint16_t) AF_FileRowInHex[VF_AF_FileRowInHexPos]) << 8) & 0xFF00) + (((uint16_t) AF_FileRowInHex[VF_AF_FileRowInHexPos + 1]) & 0xFF);

                VF_Checksum = (AF_FileRowInHex[VF_AF_FileRowInHexPos + 1] + AF_FileRowInHex[VF_AF_FileRowInHexPos] + VF_Checksum);

                if (VF_Checksum != 0)
                {
                    E_OperationResult = E_CheckSum;
                    break;
                }
                break;
            case 5:
                break;
            default:
                break;
            }
            free(AF_FileRowInHex);
        }

        std::fclose(F_HexadecimalFile);
        free(AF_FileAsciiRow);
        if ( E_OperationResult != E_OK)
        {
            free(A_BinaryData);
            return false;
        }

        {
            sfinfo->st_size = VF_MaxPhysicalAddress;
            sfinfo->vbuf.resize(VF_MaxPhysicalAddress);

            unsigned short cks = 0;
            for (size_t i = 0; i < VF_MaxPhysicalAddress; i++) {
                sfinfo->vbuf[i] = A_BinaryData[i];
                cks += sfinfo->vbuf[i];
            }
            sfinfo->usCheckSum = cks;
        }

        free(A_BinaryData);
        return true;
    }

    //Binary file (not HEX)
    std::FILE *fp = _tfopen(strFN.GetBuffer(0), _T("rb"));

    if (fp) {
        std::fseek(fp, 0, SEEK_END);
        size_t length = std::ftell(fp);
        std::rewind(fp);
        sfinfo->filename = strFN;
        sfinfo->st_size = length;
        sfinfo->vbuf.resize(length);
        size_t result = 0;
        unsigned short cks = 0;

        if (length) {
            result = std::fread(&(sfinfo->vbuf[0]), 1, length, fp);
        }

        for (size_t i = 0; i < length; i++) {
            cks += sfinfo->vbuf[i];
        }

        sfinfo->usCheckSum = cks;
        //if(result == length)
        //	printf("all characters read successfully. (%d, %X)\n", length, cks);
        //else
        //	printf("error: only %i could be read\n", result);
        std::fclose(fp);
        return (result == length);
    }

    return false;
}
#endif

size_t mfwrite(const void *ptr, size_t len, _TCHAR *_FileName)
{
    size_t ret = 0;
    std::FILE *fp = _tfopen(_FileName, _T("wb"));
    ret = std::fwrite(ptr, 1, len, fp);
    std::fclose(fp);
    return ret;
}

size_t mfread(void *ptr, size_t len, _TCHAR *_FileName)
{
    size_t ret = 0;
    std::FILE *fp = _tfopen(_FileName, _T("rb"));
    ret = std::fread(ptr, 1, len, fp);
    std::fclose(fp);
    return ret;
}