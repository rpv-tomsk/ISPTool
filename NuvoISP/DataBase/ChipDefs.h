#ifndef INC__CHIP_DEFS_H__
#define INC__CHIP_DEFS_H__

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
#define NUC1XX_FLASH_CONFIG_LOCK		0x00000002UL
#define NUC1XX_FLASH_CONFIG_DFEN		0x00000001UL
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
#define AU91XX_FLASH_CONFIG_LOCK		0x00000002UL
#define AU91XX_FLASH_CONFIG_DFEN		0x00000001UL
#define AU91XX_FLASH_CONFIG_DFBA		0x0003FC00UL

/* Chip definition for M05x */
#define M05X_FLASH_PAGE_SIZE			512

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
#define M05X_FLASH_CONFIG_LOCK			0x00000002UL
#define M05X_FLASH_CONFIG_DFEN			0x00000001UL
#define M05X_FLASH_CONFIG_DFBA			0x000FFFFFUL

/* Chip definition for M0564 */
#define M0564_FLASH_PAGE_SIZE			2048

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
#define M0564_FLASH_CONFIG_LOCK			0x00000002UL
#define M0564_FLASH_CONFIG_DFEN			0x00000001UL
#define M0564_FLASH_CONFIG_DFBA			0x0003F800UL

/* Chip definition for Nano100 */
#define NANO100_FLASH_PAGE_SIZE			512

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
#define NANO100_FLASH_CONFIG_LOCK		0x00000002UL
#define NANO100_FLASH_CONFIG_DFEN		0x00000001UL
#define NANO100_FLASH_CONFIG_DFBA		0x0000FE00UL	//NANO100 AN
#define NANO100_FLASH_CONFIG_DFBA_BN	0x0001EA00UL	//NANO100 BN
#define NANO112_FLASH_CONFIG_DFBA		0x00007E00UL	//NANO112

/* Chip definition for Mini51 */
#define MINI51_FLASH_PAGE_SIZE			512

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
#define MINI51_FLASH_CONFIG_LOCK		0x00000002UL
#define MINI51_FLASH_CONFIG_DFEN		0x00000001UL
//#define MINI51_FLASH_CONFIG_DFBA		0x00003E00UL
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
#define NM1120_FLASH_CONFIG_LOCK		0x00000002UL
#define NM1120_FLASH_CONFIG_DFEN		0x00000001UL
#define NM1120_FLASH_CONFIG_DFBA		0x00007E00UL
#define NM1120_FLASH_PAGE_SIZE			512

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
#define N570_FLASH_CONFIG_LOCK			0x00000002UL
#define N570_FLASH_CONFIG_DFEN			0x00000001UL

/* Chip definition for NUC4xx */
#define NUC4XX_FLASH_PAGE_SIZE			2048

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
#define NUC4XX_FLASH_CONFIG_LOCK		0x00000002UL
#define NUC4XX_FLASH_CONFIG_DFEN		0x00000001UL
#define NUC4XX_FLASH_CONFIG_DFBA		0x0007F800UL

/* Chip definition for M451 */
#define M451_FLASH_PAGE_SIZE			2048

#define M451_FLASH_CONFIG_CWDTEN		0x80000000UL
#define M451_FLASH_CONFIG_CWDTEN_BIT1		0x00000010UL
#define M451_FLASH_CONFIG_CWDTEN_BIT0		0x00000008UL
#define M451_FLASH_CONFIG_CWDTPDEN		0x40000000UL
#define M451_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define M451_FLASH_CONFIG_CFOSC			0x04000000UL
#	define M451_FLASH_CONFIG_E12M		0x00000000UL
#	define M451_FLASH_CONFIG_I22M		0x04000000UL
#define M451_FLASH_CONFIG_CBODEN		0x00800000UL
#define M451_FLASH_CONFIG_CBOV			0x00600000UL
#	define M451_FLASH_CONFIG_CBOV_45	0x00600000UL
#	define M451_FLASH_CONFIG_CBOV_38	0x00400000UL
#	define M451_FLASH_CONFIG_CBOV_26	0x00200000UL
#	define M451_FLASH_CONFIG_CBOV_22	0x00000000UL
#define M451_FLASH_CONFIG_CBORST		0x00100000UL
#define M451_FLASH_CONFIG_CIOINI		0x00000400UL
#define M451_FLASH_CONFIG_CBS			0x00000080UL
#define M451_FLASH_CONFIG_CBS2			0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define M451_FLASH_CONFIG_CBS_AP		0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define M451_FLASH_CONFIG_CBS_LD		0x00000040UL
/* Boot from APROM, LDROM visible */
#	define M451_FLASH_CONFIG_CBS_AP_LD	0x00000080UL
/* Boot from LDROM, APROM visible */
#	define M451_FLASH_CONFIG_CBS_LD_AP	0x00000000UL
#	define M451_FLASH_CONFIG_CBS_MK		0x00000020UL
#define M451_FLASH_CONFIG_DFVSEN		0x00000004UL
#define M451_FLASH_CONFIG_LOCK			0x00000002UL
#define M451_FLASH_CONFIG_DFEN			0x00000001UL
#define M451_FLASH_CONFIG_DFBA			0x0003F800UL

/* Chip definition for NUC505 */
#define NUC505_SPIFLASH_PAGE_SIZE		256
#define NUC505_SPIFLASH_SECTOR_SIZE		4096

/* Chip definition for TC8226 */
#define TC8226_FLASH_KPROM_ADDR         0x00301000UL
#define TC8226_FLASH_KPROM_SIZE         0x2000
#define TC8226_FLASH_PAGE_SIZE          0x1000
#define TC8226_FLASH_CONFIG_CWDTEN		0x80000000UL
#define TC8226_FLASH_CONFIG_CWDTEN_BIT1		0x00000010UL
#define TC8226_FLASH_CONFIG_CWDTEN_BIT0		0x00000008UL
#define TC8226_FLASH_CONFIG_CWDTPDEN	0x40000000UL
#define TC8226_FLASH_CONFIG_CKF			0x10000000UL
#define TC8226_FLASH_CONFIG_CGPFMFP		0x08000000UL
#define TC8226_FLASH_CONFIG_CFOSC			0x04000000UL
#	define TC8226_FLASH_CONFIG_E12M		0x00000000UL
#	define TC8226_FLASH_CONFIG_I22M		0x04000000UL
#define TC8226_FLASH_CONFIG_CBODEN		0x00080000UL
#define TC8226_FLASH_CONFIG_CBOV		0x00E00000UL
#	define TC8226_FLASH_CONFIG_CBOV_16		0x00000000UL
#	define TC8226_FLASH_CONFIG_CBOV_18		0x00200000UL
#	define TC8226_FLASH_CONFIG_CBOV_20		0x00400000UL
#	define TC8226_FLASH_CONFIG_CBOV_22		0x00600000UL
#	define TC8226_FLASH_CONFIG_CBOV_24		0x00800000UL
#	define TC8226_FLASH_CONFIG_CBOV_26		0x00A00000UL
#	define TC8226_FLASH_CONFIG_CBOV_28		0x00C00000UL
#	define TC8226_FLASH_CONFIG_CBOV_30		0x00E00000UL
#define TC8226_FLASH_CONFIG_CBORST		0x00100000UL
#define TC8226_FLASH_CONFIG_CIOINI		0x00000400UL
#define TC8226_FLASH_CONFIG_CBS			0x00000080UL
#define TC8226_FLASH_CONFIG_CBS2		0x000000C0UL
/* Boot from APROM, LDROM invisible */
#	define TC8226_FLASH_CONFIG_CBS_AP		0x000000C0UL
/* Boot from LDROM, APROM invisible */
#	define TC8226_FLASH_CONFIG_CBS_LD		0x00000040UL
/* Boot from APROM, LDROM visible */
#	define TC8226_FLASH_CONFIG_CBS_AP_LD	0x00000080UL
/* Boot from LDROM, APROM visible */
#	define TC8226_FLASH_CONFIG_CBS_LD_AP	0x00000000UL
#	define TC8226_FLASH_CONFIG_BOOTLOADER	0x00000020UL
#define TC8226_FLASH_CONFIG_MBS			0x00000020UL
#define TC8226_FLASH_CONFIG_DFVSEN		0x00000004UL
#define TC8226_FLASH_CONFIG_LOCK		0x00000002UL
#define TC8226_FLASH_CONFIG_DFEN		0x00000001UL
#define TC8226_FLASH_CONFIG_DFBA		0x0007F000UL
#define TC8226_FLASH_CONFIG_MERASE		0x00002000UL
#define TC8226_FLASH_CONFIG_SPLCAEN		0x00001000UL
#define TC8226_FLASH_CONFIG_ICELOCK		0x00000800UL
// Security boot lock and ALock
#define TC8226_FLASH_CONFIG_SBLOCK		0x0000FFFFUL
#define TC8226_FLASH_CONFIG_SPIM		0x00000030UL
#	define TC8226_FLASH_CONFIG_SPIM_SEL0	0x00000000UL
#	define TC8226_FLASH_CONFIG_SPIM_SEL1	0x00000010UL
#	define TC8226_FLASH_CONFIG_SPIM_SEL2	0x00000020UL
#	define TC8226_FLASH_CONFIG_SPIM_SEL3	0x00000030UL
#define TC8226_FLASH_CONFIG_UART1		0x00000003UL
#	define TC8226_FLASH_CONFIG_UART1_SEL0	0x00000000UL
#	define TC8226_FLASH_CONFIG_UART1_SEL1	0x00000001UL
#	define TC8226_FLASH_CONFIG_UART1_SEL2	0x00000002UL
#	define TC8226_FLASH_CONFIG_UART1_SEL3	0x00000003UL
#define TC8226_SPIM_DMM_MAP_ADDR			0x08000000UL
#define TC8226_SPIM_SUPPORT_SIZE			0x02000000UL

/* Chip definition for I94000 */
#define I94000_FLASH_CONFIG_CGPA8		0x00000800UL
#define I94000_FLASH_CONFIG_ICELOCK		0x00000004UL

/* Chip definition for M2351 */
#define M2351_FLASH_PAGE_SIZE			0x800
#define M2351_RAM_BLOCK_SIZE			0x2000
#define M2351_MAX_RAM_SIZE				0x18000
#define M2351_APROM_NS_BASE				0x10000000UL
#define M2351_RAM_NS_BASE				0x30000000UL
#define M2351_FLASH_XOM_ADDR			0x00200000UL
#define M2351_FLASH_SECURE_ADDR			0x00200800UL
#define M2351_FLASH_NSECURE_ADDR		0x00210800UL
#define M2351_FLASH_KPROM_ADDR			0x00311000UL
#define M2351_FLASH_KPROM_SIZE			0x1000
#define M2351_FMC_XOMR0STS				0x4000C0D0UL
#define M2351_FMC_XOMR1STS				0x4000C0D4UL
#define M2351_FMC_XOMR2STS				0x4000C0D8UL
#define M2351_FMC_XOMR3STS				0x4000C0DCUL
#define M2351_FMC_XOMSTS				0x4000C0E0UL

#define M2351_SCU_SRAMNSSET				0x4002F024UL
#define M2351_SCU_FNSADDR				0x4002F028UL

#define M2351_FLASH_CONFIG_ICELOCK		0x00000800UL
#define M2351_FLASH_CONFIG_UART1PSL		0x00000007UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL0	0x00000000UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL1	0x00000001UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL2	0x00000002UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL3	0x00000003UL
#	define M2351_FLASH_CONFIG_UART1PSL_SEL4	0x00000007UL

/* Chip definition for M251 */
#define M251_FLASH_CONFIG_CBOV		0x00E00000UL
#	define M251_FLASH_CONFIG_CBOV_16		0x00000000UL
#	define M251_FLASH_CONFIG_CBOV_18		0x00200000UL
#	define M251_FLASH_CONFIG_CBOV_20		0x00400000UL
#	define M251_FLASH_CONFIG_CBOV_24		0x00600000UL
#	define M251_FLASH_CONFIG_CBOV_27		0x00800000UL
#	define M251_FLASH_CONFIG_CBOV_30		0x00A00000UL
#	define M251_FLASH_CONFIG_CBOV_37		0x00C00000UL
#	define M251_FLASH_CONFIG_CBOV_44		0x00E00000UL
#define M251_FLASH_CONFIG_ICELOCK		0x00001000UL
#define M251_FLASH_CONFIG_LOCK			0x00000002UL
#define M251_FLASH_CONFIG_SIZE          8

/* General definition for NuMicro-M */
#define NUMICRO_M0_FLASH_APROM_ADDR		0x00000000UL
#define NUMICRO_M0_FLASH_LDROM_ADDR		0x00100000UL
#define NUMICRO_M0_FLASH_SPROM_ADDR		0x00200000UL
#define NUMICRO_M0_FLASH_CONFIG_ADDR	0x00300000UL
#define NUMICRO_M0_FLASH_PAGE_SIZE		512

#define NUMICRO_M4_FLASH_APROM_ADDR		0x00000000UL
#define NUMICRO_M4_FLASH_LDROM_ADDR		0x00100000UL
#define NUMICRO_M4_FLASH_SPROM_ADDR		0x00200000UL
#define NUMICRO_M4_FLASH_CONFIG_ADDR	0x00300000UL

#define NUMICRO_FLASH_APROM_ADDR		0x00000000UL
#define NUMICRO_FLASH_LDROM_ADDR		0x00100000UL
#define NUMICRO_FLASH_SPROM_ADDR		0x00200000UL
#define NUMICRO_FLASH_CONFIG_ADDR		0x00300000UL

#define NUMICRO_FLASH_PAGE_SIZE_512		512
#define NUMICRO_FLASH_PAGE_SIZE_2K		2048
#define NUMICRO_FLASH_PAGE_SIZE_4K		4096

#define NUMICRO_FLASH_LDROM_SIZE_2K		0x0800
#define NUMICRO_FLASH_LDROM_SIZE_4K		0x1000
#define NUMICRO_FLASH_LDROM_SIZE_8K		0x2000
#define NUMICRO_FLASH_LDROM_SIZE_16K	0x4000

/* 8051 1T Series */
#define N76E1T_FLASH_APROM_ADDR			0x00000
#define N76E1T_FLASH_CONFIG_ADDR		0x30000
#define N76E1T_FLASH_CONFIG_SIZE		8
#define N76E1T_FLASH_CONFIG_LOCK		0x02
#define N76E1T_FLASH_SECTOR_SIZE		128
#define N76E1T_FLASH_SECTOR_SIZE_616	256
#define N76E1T_FLASH_PAGE_SIZE			32

#endif
