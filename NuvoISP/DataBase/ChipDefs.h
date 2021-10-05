#ifndef INC__CHIP_DEFS_H__
#define INC__CHIP_DEFS_H__

/* Chip type rule:

	First number - Core type or Flash type
				0: M0
				1: M0
				2: M23 without SE
				3: M23 SE
				4: M4
				5: NUC505 (SPI Flash)
				7: ARM7
				8: 8051
				9: ARM9
				Other: Reserved
	Second number - Bit[6:4] Page Size
				M0/M23(0: 512B, 1: 1KB, 2: 2KB)
				M4(0: 2KB, 1:4KB)

				 - Bit[7] for Flash Address definition
				0: Old, e.g. LDROM 0x0010_0000
				1: New, e.g. LDROM 0x0F10_0000

	Third number - Bit[2:0]
				0-3: NuMicro Series
				6: Special Case (M0A21)
				7: Special Case (M030G)
				4: NuVoice / ISD
				5: Motor

				 - Bit[3] for M0
				0: AHB = 0x5000_0000
				1: AHB = 0x4000_0000
 */

typedef enum {
    NUC_CHIP_TYPE_GENERAL_V6M	= 0,
    NUC_CHIP_TYPE_NUC1XX		= 1,
    NUC_CHIP_TYPE_M05X			= 3,
    NUC_CHIP_TYPE_N572			= 4,
    NUC_CHIP_TYPE_NANO100		= 0x101,
    NUC_CHIP_TYPE_MINI51		= 0x102,
    NUC_CHIP_TYPE_MT5XX			= 0x103,
    NUC_CHIP_TYPE_N570			= 0x104,
    NUC_CHIP_TYPE_NM1120		= 0x105,
    NUC_CHIP_TYPE_I96000		= 0x10C,
    NUC_CHIP_TYPE_AU91XX		= 0x114,
    NUC_CHIP_TYPE_M0564			= 0x121,
    NUC_CHIP_TYPE_M031			= 0x10A,
    NUC_CHIP_TYPE_M0A21			= 0x10E,
    NUC_CHIP_TYPE_M030G			= 0x10F,
    NUC_CHIP_TYPE_M031G			= 0x12A,
    NUC_CHIP_TYPE_M251			= 0x201,
    NUC_CHIP_TYPE_M2351			= 0x321,
    NUC_CHIP_TYPE_M2354			= 0x322,
    NUC_CHIP_TYPE_M2379			= 0x323,
    NUC_CHIP_TYPE_GENERAL_V7M	= 0x400,
    NUC_CHIP_TYPE_NUC4XX		= 0x401,
    NUC_CHIP_TYPE_M451			= 0x402,
    NUC_CHIP_TYPE_M471			= 0x40A,
    NUC_CHIP_TYPE_M480			= 0x411,
    NUC_CHIP_TYPE_I94000		= 0x414,
    NUC_CHIP_TYPE_M460			= 0x49A,
    NUC_CHIP_TYPE_NUC505		= 0x500,
    NUC_CHIP_TYPE_KM1M7			= 0x600,	// NTCJ M7
    NUC_CHIP_TYPE_GENERAL_ARM7	= 0x700,
    NUC_CHIP_TYPE_GENERAL_1T	= 0x800,	// For 8051 1T N76/ML51/MS51 Series
    NUC_CHIP_TYPE_GENERAL_855	= 0x801,	// 85J, 37J
    NUC_CHIP_TYPE_GENERAL_82J	= 0x802,
    NUC_CHIP_TYPE_GENERAL_83J	= 0x803,
    NUC_CHIP_TYPE_GENERAL_35J	= 0x804,
    NUC_CHIP_TYPE_GENERAL_87J	= 0x805,	// 87J, 23J
    NUC_CHIP_TYPE_GENERAL_21J	= 0x806,
    NUC_CHIP_TYPE_GENERAL_658	= 0x807,
    NUC_CHIP_TYPE_GENERAL_659	= 0x808,
    NUC_CHIP_TYPE_GENERAL_ARM9	= 0x900
} NUC_CHIP_TYPE_E;

/* Chip definition for NUC1xx */
#define NUC1XX_FLASH_PAGE_SIZE			512

#define NUC1XX_FLASH_CONFIG_CWDTEN		0x80000000UL
#define NUC1XX_FLASH_CONFIG_CWDTEN_BIT1		0x00000010UL
#define NUC1XX_FLASH_CONFIG_CWDTEN_BIT0		0x00000008UL
#define NUC1XX_FLASH_CONFIG_CWDTPDEN		0x40000000UL
#define NUC1XX_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define NUC1XX_FLASH_CONFIG_CKF			0x10000000UL
#define NUC1XX_FLASH_CONFIG_CFOSC		0x07000000UL
#	define NUC1XX_FLASH_CONFIG_E12M		0x00000000UL
#	define NUC1XX_FLASH_CONFIG_E32K		0x01000000UL
#	define NUC1XX_FLASH_CONFIG_PLL		0x02000000UL
#	define NUC1XX_FLASH_CONFIG_I10K		0x03000000UL
#	define NUC1XX_FLASH_CONFIG_I22M		0x04000000UL
#define NUC1XX_FLASH_CONFIG_CBODEN		0x00800000UL
#define NUC1XX_FLASH_CONFIG_CBOV		0x00600000UL
#	define NUC1XX_FLASH_CONFIG_CBOV_45	0x00600000UL
#	define NUC1XX_FLASH_CONFIG_CBOV_38	0x00400000UL
#	define NUC1XX_FLASH_CONFIG_CBOV_26	0x00200000UL //2.6/2.7V
#	define NUC1XX_FLASH_CONFIG_CBOV_22	0x00000000UL
#define NUC1XX_FLASH_CONFIG_CBORST		0x00100000UL
#define NUC1XX_FLASH_CONFIG_CIOINI		0x00000400UL
#	define NUC1XX_FLASH_CONFIG_CIOINI_INPUT	0x00000000UL
#	define NUC1XX_FLASH_CONFIG_CIOINI_BI	0x00000400UL
#define NUC1XX_FLASH_CONFIG_CBS			0x00000080UL
#define NUC1XX_FLASH_CONFIG_CBS2		0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define NUC1XX_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define NUC1XX_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define NUC1XX_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define NUC1XX_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define NUC1XX_FLASH_CONFIG_DFVSEN		0x00000004UL
#define NUC1XX_FLASH_CONFIG_DFBA		0x0001FE00UL

#define MT5XX_FLASH_CONFIG_CHZ_BPWM		0x00001000UL
#define MT5XX_FLASH_CONFIG_CHZ_Odd1		0x00000800UL
#define MT5XX_FLASH_CONFIG_CHZ_Event1	0x00000400UL
#define MT5XX_FLASH_CONFIG_CHZ_Odd0		0x00000200UL
#define MT5XX_FLASH_CONFIG_CHZ_Event0	0x00000100UL

/* Chip definition for AU91xx */
#define AU91XX_FLASH_PAGE_SIZE			1024

#define AU91XX_FLASH_CONFIG_CBODEN		0x00800000UL
#define AU91XX_FLASH_CONFIG_CBS			0x00000080UL
#define AU91XX_FLASH_CONFIG_LDROM_EN	0x00000004UL
#define AU91XX_FLASH_CONFIG_DFBA		0x0003FC00UL

/* Chip definition for M05x */

#define M05X_FLASH_CONFIG_CWDTEN		0x80000000UL
#define M05X_FLASH_CONFIG_CWDTPDEN		0x40000000UL
#define M05X_FLASH_CONFIG_CKF			0x10000000UL
#define M05X_FLASH_CONFIG_CGP7MFP		0x08000000UL
#define M05X_FLASH_CONFIG_CFOSC			0x07000000UL
#	define M05X_FLASH_CONFIG_E12M		0x00000000UL
#	define M05X_FLASH_CONFIG_E32K		0x01000000UL
#	define M05X_FLASH_CONFIG_PLL		0x02000000UL
#	define M05X_FLASH_CONFIG_I10K		0x03000000UL
#	define M05X_FLASH_CONFIG_I22M		0x04000000UL
#define M05X_FLASH_CONFIG_CBODEN		0x00800000UL
#define M05X_FLASH_CONFIG_CBOV			0x00600000UL
#	define M05X_FLASH_CONFIG_CBOV_45	0x00600000UL
#	define M05X_FLASH_CONFIG_CBOV_38	0x00400000UL
#	define M05X_FLASH_CONFIG_CBOV_26	0x00200000UL
#	define M05X_FLASH_CONFIG_CBOV_22	0x00000000UL
#define M05X_FLASH_CONFIG_CBORST		0x00100000UL
#define M05X_FLASH_CONFIG_CIOINI		0x00000400UL
#	define M05X_FLASH_CONFIG_CIOINI_INPUT	0x00000000UL
#	define M05X_FLASH_CONFIG_CIOINI_BI		0x00000400UL
#define M05X_FLASH_CONFIG_CBS2			0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define M05X_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define M05X_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define M05X_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define M05X_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define M05X_FLASH_CONFIG_CBS			0x00000080UL

/* Chip definition for M0564 */

#define M0564_FLASH_CONFIG_CWDTEN		0x80000000UL
#define M0564_FLASH_CONFIG_CWDTEN_BIT1	0x00000010UL
#define M0564_FLASH_CONFIG_CWDTEN_BIT0	0x00000008UL
#define M0564_FLASH_CONFIG_CWDTPDEN		0x40000000UL
#define M0564_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define M0564_FLASH_CONFIG_CFOSC		0x04000000UL
#	define M0564_FLASH_CONFIG_E12M		0x00000000UL
#	define M0564_FLASH_CONFIG_I22M		0x04000000UL
#define M0564_FLASH_CONFIG_CBODEN		0x00800000UL
#define M0564_FLASH_CONFIG_CBOV			0x00600000UL
#	define M0564_FLASH_CONFIG_CBOV_45	0x00600000UL
#	define M0564_FLASH_CONFIG_CBOV_38	0x00400000UL
#	define M0564_FLASH_CONFIG_CBOV_26	0x00200000UL
#	define M0564_FLASH_CONFIG_CBOV_22	0x00000000UL
#define M0564_FLASH_CONFIG_CBORST		0x00100000UL
#define M0564_FLASH_CONFIG_ICELOCK		0x00001000UL
#define M0564_FLASH_CONFIG_CIOINI		0x00000400UL
#define M0564_FLASH_CONFIG_CBS			0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define M0564_FLASH_CONFIG_CBS_AP	0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define M0564_FLASH_CONFIG_CBS_LD	0x00000040UL
/* Boot from APROM, LDROM visible */
#	define M0564_FLASH_CONFIG_CBS_AP_LD	0x00000080UL
/* Boot from LDROM, APROM visible */
#	define M0564_FLASH_CONFIG_CBS_LD_AP	0x00000000UL
#define M0564_FLASH_CONFIG_MERASE		0x00000020UL
#define M0564_FLASH_CONFIG_DFBA			0x0003F800UL

/* Chip definition for Nano100 */

#define NANO100_FLASH_CONFIG_CWDTEN		0x80000000UL
#define NANO100_FLASH_CONFIG_CKF		0x10000000UL
#define NANO100_FLASH_CONFIG_CFOSC		0x04000000UL
#	define NANO100_FLASH_CONFIG_E12M	0x00000000UL
#	define NANO100_FLASH_CONFIG_I12M	0x04000000UL
#define NANO100_FLASH_CONFIG_CBORST		0x00180000UL
#	define NANO100_FLASH_CONFIG_CBORST_RESERVED	0x00180000UL
#	define NANO100_FLASH_CONFIG_CBORST_25		0x00100000UL
#	define NANO100_FLASH_CONFIG_CBORST_20		0x00080000UL
#	define NANO100_FLASH_CONFIG_CBORST_17		0x00000000UL
#define NANO103_FLASH_CONFIG_CBORST				0x00780000UL	//NANO103
#	define NANO103_FLASH_CONFIG_CBORST_RESERVED	0x00000000UL
#	define NANO103_FLASH_CONFIG_CBORST_18		0x00080000UL
#	define NANO103_FLASH_CONFIG_CBORST_19		0x00100000UL
#	define NANO103_FLASH_CONFIG_CBORST_20		0x00180000UL
#	define NANO103_FLASH_CONFIG_CBORST_21		0x00200000UL
#	define NANO103_FLASH_CONFIG_CBORST_22		0x00280000UL
#	define NANO103_FLASH_CONFIG_CBORST_23		0x00300000UL
#	define NANO103_FLASH_CONFIG_CBORST_24		0x00380000UL
#	define NANO103_FLASH_CONFIG_CBORST_25		0x00400000UL
#	define NANO103_FLASH_CONFIG_CBORST_26		0x00480000UL
#	define NANO103_FLASH_CONFIG_CBORST_27		0x00500000UL
#	define NANO103_FLASH_CONFIG_CBORST_28		0x00580000UL
#	define NANO103_FLASH_CONFIG_CBORST_29		0x00600000UL
#	define NANO103_FLASH_CONFIG_CBORST_30		0x00680000UL
#	define NANO103_FLASH_CONFIG_CBORST_31		0x00780000UL
#define NANO103_FLASH_CONFIG_CBODEN				0x00800000UL
#define NANO100_FLASH_CONFIG_CBS				0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define NANO100_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define NANO100_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define NANO100_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define NANO100_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define NANO100_FLASH_CONFIG_HXT_GAIN			0x0000E000UL	//NANO112
#	define NANO100_FLASH_CONFIG_HXT_RESERVED	0x00000000UL
#	define NANO100_FLASH_CONFIG_HXT_H16			0x00002000UL
//#	define NANO100_FLASH_CONFIG_HXT_12_16		0x00004000UL
#	define NANO100_FLASH_CONFIG_HXT_12_16		0x0000E000UL
#	define NANO100_FLASH_CONFIG_HXT_8_12		0x00006000UL
#	define NANO100_FLASH_CONFIG_HXT_L8			0x00008000UL
#define NANO103_FLASH_CONFIG_HXT_GAIN			0x0000E000UL	//NANO103
#	define NANO103_FLASH_CONFIG_HXT_RESERVED	0x00000000UL
#	define NANO103_FLASH_CONFIG_HXT_4			0x00002000UL
#	define NANO103_FLASH_CONFIG_HXT_H8			0x00004000UL
#	define NANO103_FLASH_CONFIG_HXT_H12			0x00006000UL
#	define NANO103_FLASH_CONFIG_HXT_H16			0x00008000UL
#	define NANO103_FLASH_CONFIG_HXT_H24			0x0000A000UL
#	define NANO103_FLASH_CONFIG_HXT_H32			0x0000E000UL
#define NANO100_FLASH_CONFIG_CCKSTOP			0x00001000UL
#define NANO100_FLASH_CONFIG_MERASE				0x00000020UL
#define NANO100_FLASH_CONFIG_DFBA		0x0000FE00UL	//NANO100 AN
#define NANO100_FLASH_CONFIG_DFBA_BN	0x0001EA00UL	//NANO100 BN
#define NANO112_FLASH_CONFIG_DFBA		0x00007E00UL	//NANO112

/* Chip definition for Mini51 */

#define MINI51_FLASH_CONFIG_PWM_EVEN	0x40000000UL
#define MINI51_FLASH_CONFIG_PWM_ODD		0x20000000UL
#define MINI51_FLASH_CONFIG_CKF			0x10000000UL
#define MINI51_FLASH_CONFIG_CBOD2VEN	0x00800000UL
#define MINI51_FLASH_CONFIG_CBOV		0x00600000UL
#	define MINI51_FLASH_CONFIG_CBOV_DISABLE	0x00600000UL
#	define MINI51_FLASH_CONFIG_CBOV_44		0x00600000UL
#	define MINI51_FLASH_CONFIG_CBOV_38		0x00400000UL //3.8/3.7V
#	define MINI51_FLASH_CONFIG_CBOV_27		0x00200000UL
#	define MINI51_FLASH_CONFIG_CBOV_27_		0x00000000UL
#	define MINI51_FLASH_CONFIG_CBOV_22		0x00000000UL
#define MINI51_FLASH_CONFIG_CBOV2		0x00080000UL
#	define MINI51_FLASH_CONFIG_CBOVE_30	(~MINI51_FLASH_CONFIG_CBOD2VEN & (MINI51_FLASH_CONFIG_CBOV2 | (0x3 << 21)))
#	define MINI51_FLASH_CONFIG_CBOVE_24	(~MINI51_FLASH_CONFIG_CBOD2VEN & (MINI51_FLASH_CONFIG_CBOV2 | (0x2 << 21)))
#	define MINI51_FLASH_CONFIG_CBOVE_20	(~MINI51_FLASH_CONFIG_CBOD2VEN & (MINI51_FLASH_CONFIG_CBOV2 | (0x1 << 21)))
#	define MINI51_FLASH_CONFIG_CBOVE_17	(~MINI51_FLASH_CONFIG_CBOD2VEN & (MINI51_FLASH_CONFIG_CBOV2 | (0x0 << 21)))
#	define MINI51_FLASH_CONFIG_CBOVE_43	(~MINI51_FLASH_CONFIG_CBOD2VEN & ~MINI51_FLASH_CONFIG_CBOV2 & (0x3 << 21))
#	define MINI51_FLASH_CONFIG_CBOVE_37	(~MINI51_FLASH_CONFIG_CBOD2VEN & ~MINI51_FLASH_CONFIG_CBOV2 & (0x2 << 21))
#	define MINI51_FLASH_CONFIG_CBOVE_27	(~MINI51_FLASH_CONFIG_CBOD2VEN & ~MINI51_FLASH_CONFIG_CBOV2 & (0x1 << 21))
#	define MINI51_FLASH_CONFIG_CBOVE_22	(~MINI51_FLASH_CONFIG_CBOD2VEN & ~MINI51_FLASH_CONFIG_CBOV2 & (0x0 << 21))
#define MINI51_FLASH_CONFIG_CBORST		0x00100000UL
#define MINI51_FLASH_CONFIG_RCCLK_D2	0x00008000UL
#define MINI51_FLASH_CONFIG_CIOINI		0x00000400UL
#define MINI51_FLASH_CONFIG_RCTRIM_S	0x08000000UL
#define MINI51_FLASH_CONFIG_CBS2		0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define MINI51_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define MINI51_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define MINI51_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define MINI51_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define MINI51_FLASH_CONFIG_CBS			0x00000080UL
#define MINI51_FLASH_CONFIG_DFBA		0x00007E00UL //17.5/32K

/* Chip definition for NM1120 */
#define NM1120_FLASH_CONFIG_CBOV		0x0000E000UL
#	define NM1120_FLASH_CONFIG_CBOV_43		0x0000E000UL
#	define NM1120_FLASH_CONFIG_CBOV_40		0x0000C000UL
#	define NM1120_FLASH_CONFIG_CBOV_37		0x0000A000UL
#	define NM1120_FLASH_CONFIG_CBOV_30		0x00008000UL
#	define NM1120_FLASH_CONFIG_CBOV_27		0x00006000UL
#	define NM1120_FLASH_CONFIG_CBOV_24		0x00004000UL
#	define NM1120_FLASH_CONFIG_CBOV_22		0x00002000UL
#	define NM1120_FLASH_CONFIG_CBOV_20		0x00000000UL
#define NM1120_FLASH_CONFIG_GPA0NIRI		0x00030000UL
#define NM1120_FLASH_CONFIG_GPA1NIRI		0x000C0000UL
#define NM1120_FLASH_CONFIG_GPA2NIRI		0x00300000UL
#define NM1120_FLASH_CONFIG_GPA3NIRI		0x00C00000UL
#define NM1120_FLASH_CONFIG_GPA4NIRI		0x03000000UL
#define NM1120_FLASH_CONFIG_GPA5NIRI		0x0C000000UL
#define NM1120_FLASH_CONFIG_CKFHIRC		0x20000000UL
#define NM1120_FLASH_CONFIG_CBORST		0x00001000UL
#define NM1120_FLASH_CONFIG_CBOVEN		0x00000800UL
#define NM1120_FLASH_CONFIG_CIOINI		0x00000400UL
#define NM1120_FLASH_CONFIG_CBS			0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define NM1120_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define NM1120_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define NM1120_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define NM1120_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define NM1120_FLASH_CONFIG_PWM_DBGEN	0x00000004UL
#define NM1120_FLASH_CONFIG_DFBA		0x00007E00UL

/* Chip definition for N570 */
#define N570_FLASH_CONFIG_CBOV			0x03C00000UL
#	define N570_FLASH_CONFIG_CBOV_46	0x03C00000UL
#	define N570_FLASH_CONFIG_CBOV_42	0x03800000UL
#	define N570_FLASH_CONFIG_CBOV_39	0x03400000UL
#	define N570_FLASH_CONFIG_CBOV_37	0x03000000UL
#	define N570_FLASH_CONFIG_CBOV_36	0x02C00000UL
#	define N570_FLASH_CONFIG_CBOV_34	0x02800000UL
#	define N570_FLASH_CONFIG_CBOV_31	0x02400000UL
#	define N570_FLASH_CONFIG_CBOV_30	0x02000000UL
#	define N570_FLASH_CONFIG_CBOV_28	0x01C00000UL
#	define N570_FLASH_CONFIG_CBOV_26	0x01800000UL
#	define N570_FLASH_CONFIG_CBOV_24	0x01400000UL
#	define N570_FLASH_CONFIG_CBOV_22	0x01000000UL
#	define N570_FLASH_CONFIG_CBOV_21	0x00C00000UL
#	define N570_FLASH_CONFIG_CBOV_20	0x00800000UL
#	define N570_FLASH_CONFIG_CBOV_19	0x00400000UL
#	define N570_FLASH_CONFIG_CBOV_18	0x00000000UL
#define N570_FLASH_CONFIG_CLVR			0x08000000UL
#define N570_FLASH_CONFIG_CBHYS			0x04000000UL
#define N570_FLASH_CONFIG_CBORST		0x00200000UL
#define N570_FLASH_CONFIG_CBOVEN		0x00100000UL
#define N570_FLASH_CONFIG_CBS			0x00000080UL

/* Chip definition for NUC4xx */

#define NUC4XX_FLASH_CONFIG_CWDTEN		0x80000000UL
#define NUC4XX_FLASH_CONFIG_CWDTPDEN	0x40000000UL
#define NUC4XX_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define NUC4XX_FLASH_CONFIG_CKF			0x10000000UL
#define NUC4XX_FLASH_CONFIG_CFOSC		0x07000000UL
#	define NUC4XX_FLASH_CONFIG_E12M		0x00000000UL
#	define NUC4XX_FLASH_CONFIG_E32K		0x01000000UL
#	define NUC4XX_FLASH_CONFIG_PLL		0x02000000UL
#	define NUC4XX_FLASH_CONFIG_I10K		0x03000000UL
#	define NUC4XX_FLASH_CONFIG_I22M		0x04000000UL
#define NUC4XX_FLASH_CONFIG_CBODEN		0x00800000UL
#define NUC4XX_FLASH_CONFIG_CBOV		0x00600000UL
#	define NUC4XX_FLASH_CONFIG_CBOV_45	0x00600000UL
#	define NUC4XX_FLASH_CONFIG_CBOV_38	0x00400000UL
#	define NUC4XX_FLASH_CONFIG_CBOV_26	0x00200000UL
#	define NUC4XX_FLASH_CONFIG_CBOV_22	0x00000000UL
#define NUC4XX_FLASH_CONFIG_CBORST		0x00100000UL
#define NUC4XX_FLASH_CONFIG_RMII		0x00008000UL
#define NUC4XX_FLASH_CONFIG_CFG32K		0x00004000UL
#define NUC4XX_FLASH_CONFIG_LDWPEN		0x00000800UL
#define NUC4XX_FLASH_CONFIG_CIOINI		0x00000400UL
#define NUC4XX_FLASH_CONFIG_CBS			0x00000080UL
#define NUC4XX_FLASH_CONFIG_CBS2		0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define NUC4XX_FLASH_CONFIG_CBS_AP			0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define NUC4XX_FLASH_CONFIG_CBS_LD			0x00000040UL
/* Boot from APROM, LDROM visible */
#	define NUC4XX_FLASH_CONFIG_CBS_AP_LD		0x00000080UL
/* Boot from LDROM, APROM visible */
#	define NUC4XX_FLASH_CONFIG_CBS_LD_AP		0x00000000UL
#define NUC4XX_FLASH_CONFIG_DFVSEN		0x00000004UL
#define NUC4XX_FLASH_CONFIG_DFBA		0x0007F800UL

/* Chip definition for M451 */

#define M451_FLASH_CONFIG_XT1TYP		0x00010000UL //not release in TRM

/* Chip definition for M471 */
#define M471_MAX_APROM_SIZE				0x80000

/* CONFIG 0 */
#define M471_FLASH_CONFIG_ICELOCK		0x00000800UL
#define M471_FLASH_CONFIG_CFGXT1		0x08000000UL

/* Chip definition for M460 */
#define M460_MAX_APROM_SIZE				0x100000
#define M460_FMC_ISPSTS_VECMAP				0x0FFFFE00UL

#	define M460_SPIM_CTL0_QDIODIR			0x00008000UL
#	define M460_SPIM_CTL0_DWIDTH_8BIT		0x00000700UL
#	define M460_SPIM_CTL0_DWIDTH_16BIT		0x00000F00UL
#	define M460_SPIM_CTL0_DWIDTH_24BIT		0x00001700UL
#	define M460_SPIM_CTL0_DWIDTH_32BIT		0x00001F00UL
#	define M460_SPIM_CTL0_CIPHOFF			0x00000001UL
#	define M460_SPIM_CTL1_SS				0x00000010UL
#	define M460_SPIM_CTL1_SPIMEN			0x00000001UL

#	define M460_KS_CTL_INIT					0x00000100UL
#	define M460_KS_CTL_START				0x00000001UL
#	define M460_KS_CTL_OPMODE_READ			0x00000000UL
#	define M460_KS_CTL_OPMODE_CREATE		0x00000002UL
#	define M460_KS_CTL_OPMODE_LOCK			0x0000000EUL
#	define M460_KS_METADATA_DST_SRAM		0x00000000UL
#	define M460_KS_METADATA_DST_FLASH		0x40000000UL
#	define M460_KS_METADATA_DST_OTP			0x80000000UL
#	define M460_KS_METADATA_NUMBER_Pos		20
#	define M460_KS_METADATA_NUMBER_Msk		0x03F00000UL
#	define M460_KS_METADATA_OWNER_ECC		0x00040000UL
#	define M460_KS_METADATA_OWNER_CPU		0x00050000UL
#	define M460_KS_METADATA_SIZE_256BIT		0x00000600UL
#	define M460_KS_METADATA_BS				0x00000010UL
#	define M460_KS_METADATA_READABLE		0x00000004UL
#	define M460_KS_STS_KRVKF				0x00000200UL
#	define M460_KS_STS_INITDONE				0x00000080UL
#	define M460_KS_STS_BUSY					0x00000004UL
#	define M460_KS_STS_EIF					0x00000002UL
#	define M460_KS_STS_IF					0x00000001UL

#	define M460_SYS_IPRST0_SPIMRST			0x00004000UL
#	define M460_SYS_IPRST0_KSRST			0x00002000UL
#	define M460_CLK_AHBCLK_SPIMCKEN			0x00004000UL
#	define M460_CLK_AHBCLK_KSCKEN			0x00002000UL

/* CONFIG 3 */
#define M460_FLASH_CONFIG_SPIMPSL			0x00000030UL
#	define M460_FLASH_CONFIG_SPIMPSL_SEL0		0x00000000UL
#	define M460_FLASH_CONFIG_SPIMPSL_SEL1		0x00000010UL
#	define M460_FLASH_CONFIG_SPIMPSL_SEL2		0x00000020UL
#	define M460_FLASH_CONFIG_SPIMPSL_SEL3		0x00000030UL
#define M460_FLASH_CONFIG_UART1PSL			0x00000003UL
#	define M460_FLASH_CONFIG_UART1PSL_SEL0		0x00000000UL
#	define M460_FLASH_CONFIG_UART1PSL_SEL1		0x00000001UL
#	define M460_FLASH_CONFIG_UART1PSL_SEL2		0x00000002UL
#	define M460_FLASH_CONFIG_UART1PSL_SEL3		0x00000003UL

#define M460_FLASH_CONFIG_UARTISPEN			0x00000100UL
#define M460_FLASH_CONFIG_USBISPDIS			0x00000200UL
#define M460_FLASH_CONFIG_CANISPEN			0x00000400UL
#define M460_FLASH_CONFIG_I2CISPEN			0x00000800UL
#define M460_FLASH_CONFIG_SPIISPEN			0x00001000UL

/* Chip definition for M480 */

#define M480_FLASH_CONFIG_CWDTEN		0x80000000UL
#define M480_FLASH_CONFIG_CWDTEN_BIT1		0x00000010UL
#define M480_FLASH_CONFIG_CWDTEN_BIT0		0x00000008UL
#define M480_FLASH_CONFIG_CWDTPDEN	0x40000000UL
#define M480_FLASH_CONFIG_CKF			0x10000000UL
#define M480_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define M480_FLASH_CONFIG_CFOSC			0x04000000UL
#	define M480_FLASH_CONFIG_E12M		0x00000000UL
#	define M480_FLASH_CONFIG_I22M		0x04000000UL
#define M480_FLASH_CONFIG_CBODEN		0x00080000UL
#define M480_FLASH_CONFIG_CBOV		0x00E00000UL
#	define M480_FLASH_CONFIG_CBOV_16		0x00000000UL
#	define M480_FLASH_CONFIG_CBOV_18		0x00200000UL
#	define M480_FLASH_CONFIG_CBOV_20		0x00400000UL
#	define M480_FLASH_CONFIG_CBOV_22		0x00600000UL
#	define M480_FLASH_CONFIG_CBOV_24		0x00800000UL
#	define M480_FLASH_CONFIG_CBOV_26		0x00A00000UL
#	define M480_FLASH_CONFIG_CBOV_28		0x00C00000UL
#	define M480_FLASH_CONFIG_CBOV_30		0x00E00000UL
#define M480_FLASH_CONFIG_CBORST		0x00100000UL
#define M480_FLASH_CONFIG_CIOINI		0x00000400UL
#define M480_FLASH_CONFIG_CBS			0x00000080UL
#define M480_FLASH_CONFIG_CBS2		0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define M480_FLASH_CONFIG_CBS_AP		0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define M480_FLASH_CONFIG_CBS_LD		0x00000040UL
/* Boot from APROM, LDROM visible */
#	define M480_FLASH_CONFIG_CBS_AP_LD	0x00000080UL
/* Boot from LDROM, APROM visible */
#	define M480_FLASH_CONFIG_CBS_LD_AP	0x00000000UL
#	define M480_FLASH_CONFIG_BOOTLOADER	0x00000020UL
#define M480_FLASH_CONFIG_MBS			0x00000020UL
#define M480_FLASH_CONFIG_DFVSEN		0x00000004UL
#define M480_FLASH_CONFIG_DFBA		0x0007F000UL
#define M480_FLASH_CONFIG_MERASE		0x00002000UL
#define M480_FLASH_CONFIG_SPLCAEN		0x00001000UL
#define M480_FLASH_CONFIG_ICELOCK		0x00000800UL
// Security boot lock and ALock
#define M480_FLASH_CONFIG_SBLOCK		0x0000FF00UL
#define M480_FLASH_CONFIG_ALOCK		0x000000FFUL
#define M480_FLASH_CONFIG_SPIM		0x00000030UL
#	define M480_FLASH_CONFIG_SPIM_SEL0	0x00000000UL
#	define M480_FLASH_CONFIG_SPIM_SEL1	0x00000010UL
#	define M480_FLASH_CONFIG_SPIM_SEL2	0x00000020UL
#	define M480_FLASH_CONFIG_SPIM_SEL3	0x00000030UL
#define M480_FLASH_CONFIG_UART1		0x00000003UL
#	define M480_FLASH_CONFIG_UART1_SEL0	0x00000000UL
#	define M480_FLASH_CONFIG_UART1_SEL1	0x00000001UL
#	define M480_FLASH_CONFIG_UART1_SEL2	0x00000002UL
#	define M480_FLASH_CONFIG_UART1_SEL3	0x00000003UL
#define M480_SPIM_DMM_MAP_ADDR			0x08000000UL
#define M480_SPIM_SUPPORT_SIZE			0x02000000UL

/* Chip definition for I94000 */
#define I94000_FLASH_CONFIG_CGPA8		0x00000800UL
#define I94000_FLASH_CONFIG_ICELOCK		0x00000004UL

/* Chip definition for M2351 */
#define M2351_MAX_APROM_SIZE			0x80000
#define M2351_FLASH_PAGE_SIZE			0x800
#define M2351_FLASH_BLOCK_SIZE			(M2351_FLASH_PAGE_SIZE * 4)
#define M2351_OTP_TOTAL_COUNTS			256

#define M2351_FMC_KPKEYCNT_KPKEMAX		0x00001F00UL
#define M2351_FMC_KPKEYCNT_KPKECNT		0x0000001FUL
#define M2351_FMC_KPCNT_KPMAX			0x00000700UL
#define M2351_FMC_KPCNT_KPCNT			0x00000007UL

/* CONFIG 0 */
#define M2351_FLASH_CONFIG_MBS			0x00000020UL
#define M2351_FLASH_CONFIG_ICELOCK		0x00000800UL
#define M2351_FLASH_CONFIG_CFGXT1		0x08000000UL

/* CONFIG 3 */
#define M2351_FLASH_CONFIG_UART1PSL		0x00000007UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL0	0x00000000UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL1	0x00000001UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL2	0x00000002UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL3	0x00000003UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL4	0x00000007UL

#define M2354_FLASH_CONFIG_TMPPD		0xFFFF0000UL
#	define M2354_FLASH_CONFIG_TMPPD_CODE	0x5AA50000UL

/* Chip definition for M2379 */
#define M2379_MAX_APROM_SIZE			0x12000

/* Chip definition for M251 */
#define M251_FLASH_CONFIG_ICELOCK		0x00001000UL

#define M258_FLASH_CONFIG_BOOTCLOCKSEL	0x02000000UL

/* Chip definition for M0A21 */
/* CONFIG 0 */
#define M0A21_FLASH_CONFIG_RSTWSEL		0x00000100UL
#define M0A21_FLASH_CONFIG_RSTEXT		0x00000200UL
#define M0A21_FLASH_CONFIG_ICELOCK		0x00001000UL
#define M0A21_FLASH_CONFIG_CFGRPS		0x02000000UL
#define M0A21_FLASH_CONFIG_CFGXT1		0x08000000UL

/* Chip definition for M031 */

#define M031_FLASH_CONFIG_LVRLVSEL		0x20000000UL
#define M031_FLASH_CONFIG_CFGXT1		0x08000000UL
#define M031_FLASH_CONFIG_CBOV			0x00E00000UL
#	define M031_FLASH_CONFIG_CBOV_0		0x00E00000UL
#	define M031_FLASH_CONFIG_CBOV_1		0x00C00000UL
#define M031_FLASH_CONFIG_CBORST		0x00100000UL
#define M031_FLASH_CONFIG_CBODEN		0x00080000UL
#define M031_FLASH_CONFIG_ICELOCK		0x00001000UL
#define M031_FLASH_CONFIG_CIOINI		0x00000400UL
#define M031_FLASH_CONFIG_RSTEXT		0x00000200UL
#define M031_FLASH_CONFIG_RSTWSEL		0x00000100UL

/* General definition for NuMicro-M */

#define NUMICRO_FLASH_PAGE_SIZE_256		256
#define NUMICRO_FLASH_PAGE_SIZE_512		512
#define NUMICRO_FLASH_PAGE_SIZE_2K		2048
#define NUMICRO_FLASH_PAGE_SIZE_4K		4096

/* CONFIG 0 */
#define NUMICRO_FLASH_CONFIG_DFEN			0x00000001UL
#define NUMICRO_FLASH_CONFIG_LOCK			0x00000002UL
#define NUMICRO_FLASH_CONFIG_CBS_2_MODE		0x00000080UL
#define NUMICRO_FLASH_CONFIG_CBS_4_MODE		0x000000C0UL
#	define NUMICRO_FLASH_CONFIG_CBS_AP				0x000000C0UL
#	define NUMICRO_FLASH_CONFIG_CBS_LD				0x00000040UL
#	define NUMICRO_FLASH_CONFIG_CBS_AP_IAP			0x00000080UL
#	define NUMICRO_FLASH_CONFIG_CBS_LD_IAP			0x00000000UL
#define NUMICRO_FLASH_CONFIG_CIOINI			0x00000400UL
#define NUMICRO_FLASH_CONFIG_CBODEN			0x00080000UL		// BIT19 (e.g. M031, M471)
#define NUMICRO_FLASH_CONFIG_CBORST			0x00100000UL
#define NUMICRO_FLASH_CONFIG_CBOV_8_LEVEL	0x00E00000UL
#define NUMICRO_FLASH_CONFIG_CBOV_4_LEVEL	0x00600000UL
#define NUMICRO_FLASH_CONFIG_CBOV_2_LEVEL	0x00200000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_0				0x00000000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_1				0x00200000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_2				0x00400000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_3				0x00600000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_4				0x00800000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_5				0x00A00000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_6				0x00C00000UL
#	define NUMICRO_FLASH_CONFIG_CBOV_7				0x00E00000UL
#define NUMICRO_FLASH_CONFIG_CWDTPDEN		0x40000000UL
#define NUMICRO_FLASH_CONFIG_CWDTEN			0x80000018UL
#	define NUMICRO_FLASH_CONFIG_CWDTEN_INACTIVE		0x80000018UL
#	define NUMICRO_FLASH_CONFIG_CWDTEN_BY_LIRCEN	0x00000018UL
#	define NUMICRO_FLASH_CONFIG_CWDTEN_ACTIVE		0x00000000UL

#define NUMICRO_FLASH_CONFIG_CBODEN0		0x00800000UL		// BIT23 (e.g. M051, M451)

/* 8051 1T N76/ML51/MS51 Series */
#define OT8051_FLASH_CONFIG_SIZE		8
#define OT8051_FLASH_PAGE_SIZE			32

/* CONFIG 0 */
#define OT8051_CONFIG_LOCK				0x02
#define OT8051_CONFIG_RPD				0x04
#define OT8051_CONFIG_OCDEN				0x10
#define OT8051_CONFIG_OCDPWM			0x20
#define OT8051_CONFIG_FSYS				0x40
#define OT8051_CONFIG_CBS				0x80

/* CONFIG 1 */
#define OT8051_CONFIG_LDSIZE			0x07
#	define OT8051_CONFIG_LDSIZE_0K		0x07
#	define OT8051_CONFIG_LDSIZE_1K		0x06
#	define OT8051_CONFIG_LDSIZE_2K		0x05
#	define OT8051_CONFIG_LDSIZE_3K		0x04
#	define OT8051_CONFIG_LDSIZE_4K		0x03

#define OT8051_CONFIG_IODEFAULT			0x20

/* CONFIG 2 */
#define OT8051_CONFIG_CBORST			0x04
#define OT8051_CONFIG_BOIAP				0x08
#define OT8051_CONFIG_CBOV_8_LEVEL		0x70
#define OT8051_CONFIG_CBOV_4_LEVEL		0x30
#	define OT8051_CONFIG_CBOV_7			0x70
#	define OT8051_CONFIG_CBOV_6			0x60
#	define OT8051_CONFIG_CBOV_5			0x50
#	define OT8051_CONFIG_CBOV_4			0x40
#	define OT8051_CONFIG_CBOV_3			0x30
#	define OT8051_CONFIG_CBOV_2			0x20
#	define OT8051_CONFIG_CBOV_1			0x10
#	define OT8051_CONFIG_CBOV_0			0x00
#define OT8051_CONFIG_CBODEN			0x80

/* CONFIG 3 */
//XTGS[1:0]
#define OT8051_CONFIG_CLKDIV			0x03
#	define OT8051_CONFIG_CLKDIV_3		0x03
#	define OT8051_CONFIG_CLKDIV_2		0x02
#	define OT8051_CONFIG_CLKDIV_1		0x01
#	define OT8051_CONFIG_CLKDIV_0		0x00

/* CONFIG 4 */
#define OT8051_CONFIG_WDT				0xF0
#	define OT8051_CONFIG_WDT_DIS		0xF0
#	define OT8051_CONFIG_WDT_STOP		0x50
#	define OT8051_CONFIG_WDT_RUN		0x00

/* SID */
#define OT8051_SID_N76E885				0x2100
#define OT8051_SID_N76E616				0x2F00
#define OT8051_SID_N76E003				0x3600
#define OT8051_SID_N76L151				0x3E00

#define OT8051_SID_ML51_16K				0x4700
#define OT8051_SID_ML51_32K				0x4800
#define OT8051_SID_ML51_64K				0x4900

#define OT8051_SID_MS51_16K				0x4B00
#define OT8051_SID_MS51_8K				0x5200
#define OT8051_SID_MS51_32K				0x5300

#define OT8051_SID_ML56_64K				0x5700

#define OT8051_SID_MUG51_16K			0x6300

#endif
