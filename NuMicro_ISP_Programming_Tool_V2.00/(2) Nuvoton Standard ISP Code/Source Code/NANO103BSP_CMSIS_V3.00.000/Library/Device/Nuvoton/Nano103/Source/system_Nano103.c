/******************************************************************************
 * @file     system_Nano103.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 15/12/27 11:35a $
 * @brief    Nano103 system clock init code and assert handler
 *
 * @note
 * Copyright (C) 2015 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include <stdint.h>
#include "Nano103.h"


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock  = __HSI;              /*!< System Clock Frequency (Core Clock) */
uint32_t CyclesPerUs      = (__HSI / 1000000);  /*!< Cycles per micro second */

/**
  * @brief  Calculate current PLL clock frequency.
  * @param  None.
  * @return PLL clock frequency. The clock UNIT is in Hz.
  */
uint32_t SysGet_PLLClockFreq(void)
{
    uint32_t u32Freq =0, u32PLLSrc;
    uint32_t u32SRC_N,u32PLL_M,u32PllReg;

    u32PllReg = CLK->PLLCTL;

    if (u32PllReg & CLK_PLLCTL_PD)
        return 0;    /* PLL is in power down mode */

    if((u32PllReg & CLK_PLLCTL_PLLSRC_Msk) == CLK_PLLCTL_PLL_SRC_HXT) {
        u32PLLSrc = __HXT;
    } else if((u32PllReg & CLK_PLLCTL_PLLSRC_Msk) == CLK_PLLCTL_PLL_SRC_HIRC) {
        /* HIRC Source Selection */
        if(CLK->CLKSEL0 & CLK_CLKSEL0_HIRCSEL_Msk) {
            /* Clock source from HIRC1 (36MHz) */
            u32PLLSrc =__HIRC36M;
        } else {
            /* Clock source from HIRC0 (12MHz) */
            if(CLK->PWRCTL & CLK_PWRCTL_HIRC0FSEL_Msk)
                u32PLLSrc =__HIRC16M;
            else
                u32PLLSrc =__HIRC12M;
        }
    } else {
        u32PLLSrc =__MIRC;
    }

    u32SRC_N = (u32PllReg & CLK_PLLCTL_INDIV_Msk) >> CLK_PLLCTL_INDIV_Pos;
    u32PLL_M = (u32PllReg & CLK_PLLCTL_PLLMLP_Msk) >> CLK_PLLCTL_PLLMLP_Pos;

    u32Freq = u32PLLSrc * u32PLL_M / (u32SRC_N+1);

    return u32Freq;
}


/**
  * @brief  Get current HCLK clock frequency.
  * @param  None.
  * @return HCLK clock frequency. The clock UNIT is in Hz.
  */
uint32_t SysGet_HCLKFreq(void)
{

    uint32_t u32Freqout, u32AHBDivider, u32ClkSel;

    u32ClkSel = CLK->CLKSEL0 & CLK_CLKSEL0_HCLKSEL_Msk;

    if (u32ClkSel == CLK_CLKSEL0_HCLKSEL_HXT) {  /* external HXT crystal clock */
        u32Freqout = __HXT;
    } else if(u32ClkSel == CLK_CLKSEL0_HCLKSEL_LXT) {           /* external LXT crystal clock */
        u32Freqout = __LXT;
    } else if(u32ClkSel == CLK_CLKSEL0_HCLKSEL_PLL) {           /* PLL clock */
        u32Freqout = SysGet_PLLClockFreq();
    } else if(u32ClkSel == CLK_CLKSEL0_HCLKSEL_LIRC) {          /* internal LIRC oscillator clock */
        u32Freqout = __LIRC;
    } else if(u32ClkSel == CLK_CLKSEL0_HCLKSEL_HIRC) {          /* internal HIRC oscillator clock */
        /* HIRC Source Selection */
        if(CLK->CLKSEL0 & CLK_CLKSEL0_HIRCSEL_Msk) {
            /* Clock source from HIRC1 (36MHz) */
            u32Freqout =__HIRC36M;
        } else {
            /* Clock source from HIRC0 (12MHz) */
            if((CLK->PWRCTL & CLK_PWRCTL_HIRC0FSEL_Msk) == CLK_PWRCTL_HIRC0FSEL_Msk)
                u32Freqout =__HIRC16M;
            else
                u32Freqout =__HIRC12M;
        }
    } else {        /* internal MIRC oscillator clock */
        u32Freqout = __MIRC;
    }
    u32AHBDivider = (CLK->CLKDIV0 & CLK_CLKDIV0_HCLKDIV_Msk) + 1 ;
    return (u32Freqout/u32AHBDivider);
}


/**
  * @brief  This function is used to update the variable SystemCoreClock
  *   and must be called whenever the core clock is changed.
  * @param  None.
  * @retval None.
  */

void SystemCoreClockUpdate (void)
{

    SystemCoreClock = SysGet_HCLKFreq();
    CyclesPerUs = (SystemCoreClock + 500000) / 1000000;
}

#if USE_ASSERT

/**
 * @brief      Assert Error Message
 *
 * @param[in]  file  the source file name
 * @param[in]  line  line number
 *
 * @return     None
 *
 * @details    The function prints the source file name and line number where
 *             the ASSERT_PARAM() error occurs, and then stops in an infinite loop.
 */
void AssertError(uint8_t * file, uint32_t line)
{

    printf("[%s] line %d : wrong parameters.\r\n", file, line);

    /* Infinite loop */
    while(1) ;
}
#endif

/*** (C) COPYRIGHT 2015 Nuvoton Technology Corp. ***/