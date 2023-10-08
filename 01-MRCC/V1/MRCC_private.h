/*
 * MRCC_private.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDET.h"


#define RCC_BASE_ADDRESS 0x40021000
typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
    u32 APB2ENR;
	u32 APB1ENR;
	u32 RCC_BDCR;
	u32 RCC_CSR;


}RCC_type;

#define RCC  ((RCC_type *)RCC_BASE_ADDRESS)



#define RCC_BASE_ADDRESS       (0x40021000UL)

// RCC_CR Register
#define RCC_CR_HSION      0x00000000
#define RCC_CR_HSIRDY     0x00000001
#define RCC_CR_HSITRIM    0x00000003
#define RCC_CR_HSICAL     0x00000008
#define RCC_CR_HSEON      0x00000010
#define RCC_CR_HSERDY     0x00000011
#define RCC_CR_HSEBYP     0x00000012
#define RCC_CR_CSSON      0x00000013
#define RCC_CR_PLLON      0x00000018
#define RCC_CR_PLLRDY     0x00000019

// RCC_CFGR Register
#define RCC_CFGR_SW       0x00000000
#define RCC_CFGR_SWS      0x00000002
#define RCC_CFGR_HPRE     0x00000004
#define RCC_CFGR_PPRE1    0x00000008
#define RCC_CFGR_PPRE2    0x0000000B
#define RCC_CFGR_ADCPRE   0x0000000E
#define RCC_CFGR_PLLSRC   0x00000010
#define RCC_CFGR_PLLXTPRE 0x00000011
#define RCC_CFGR_PLLMUL   0x00000012
#define RCC_CFGR_USBPRE   0x00000016
#define RCC_CFGR_MCO      0x00000018

// RCC_CIR Register
#define RCC_CIR_LSIRDYF   0
#define RCC_CIR_LSERDYF   1
#define RCC_CIR_HSIRDYF   2
#define RCC_CIR_HSERDYF   3
#define RCC_CIR_PLLRDYF   4
#define RCC_CIR_CSSF      7
#define RCC_CIR_LSIRDYIE  8
#define RCC_CIR_LSERDYIE  9
#define RCC_CIR_HSIRDYIE  10
#define RCC_CIR_HSERDYIE  11
#define RCC_CIR_PLLRDYIE  12
#define RCC_CIR_LSIRDYC   16
#define RCC_CIR_LSERDYC   17
#define RCC_CIR_HSIRDYC   11
#define RCC_CIR_HSERDYC   12
#define RCC_CIR_PLLRDYC   16
#define RCC_CIR_CSSC      17

// RCC_APB2RSTR Register
#define RCC_APB2RSTR_AFIORST   0
#define RCC_APB2RSTR_IOPARST   2
#define RCC_APB2RSTR_IOPBRST   3
#define RCC_APB2RSTR_IOPCRST   4
#define RCC_APB2RSTR_IOPDRST   5
#define RCC_APB2RSTR_IOPERST   6
#define RCC_APB2RSTR_IOPFRST   7
#define RCC_APB2RSTR_IOPGRST   8
#define RCC_APB2RSTR_ADC1RST   9
#define RCC_APB2RSTR_ADC2RST   10
#define RCC_APB2RSTR_TIM1RST   11
#define RCC_APB2RSTR_SPI1RST   12
#define RCC_APB2RSTR_TIM8RST   13
#define RCC_APB2RSTR_USART1RST 14
#define RCC_APB2RSTR_ADC3RST   15
#define RCC_APB2RSTR_TIM9RST   19
#define RCC_APB2RSTR_TIM10RST  20
#define RCC_APB2RSTR_TIM11RST  21

// RCC_APB1RSTR Register
#define RCC_APB1RSTR_TIM2RST   0
#define RCC_APB1RSTR_TIM3RST   1
#define RCC_APB1RSTR_TIM4RST   2
#define RCC_APB1RSTR_TIM5RST   3
#define RCC_APB1RSTR_TIM6RST   4
#define RCC_APB1RSTR_TIM7RST   5
#define RCC_APB1RSTR_TIM12RST  6
#define RCC_APB1RSTR_TIM13RST  7
#define RCC_APB1RSTR_TIM14RST  8
#define RCC_APB1RSTR_WWDGRST   11
#define RCC_APB1RSTR_SPI2RST   14
#define RCC_APB1RSTR_SPI3RST   15
#define RCC_APB1RSTR_USART2RST 17
#define RCC_APB1RSTR_USART3RST 18
#define RCC_APB1RSTR_UART4RST  19
#define RCC_APB1RSTR_UART5RST  20
#define RCC_APB1RSTR_I2C1RST   21
#define RCC_APB1RSTR_I2C2RST   22
#define RCC_APB1RSTR_USBRST    23
#define RCC_APB1RSTR_CANRST    25
#define RCC_APB1RSTR_BKPRST    27
#define RCC_APB1RSTR_PWRRST    28
#define RCC_APB1RSTR_DACRST    29

// RCC_AHBENR Register
#define RCC_AHBENR_DMA1EN    0
#define RCC_AHBENR_DMA2EN    1
#define RCC_AHBENR_SRAMEN    2
#define RCC_AHBENR_FLITFEN   4
#define RCC_AHBENR_CRCEN     6
#define RCC_AHBENR_FMSCEN    8
#define RCC_AHBENR_SDIOEN   10

// RCC_APB2ENR Register
#define RCC_APB2ENR_AFIOEN    0
#define RCC_APB2ENR_IOPAEN    2
#define RCC_APB2ENR_IOPBEN    3
#define RCC_APB2ENR_IOPCEN    4
#define RCC_APB2ENR_IOPDEN    5
#define RCC_APB2ENR_IOPEEN    6
#define RCC_APB2ENR_IOPFEN    7
#define RCC_APB2ENR_IOPGEN    8
#define RCC_APB2ENR_ADC1EN    9
#define RCC_APB2ENR_ADC2EN    10
#define RCC_APB2ENR_TIM1EN    11
#define RCC_APB2ENR_SPI1EN    12
#define RCC_APB2ENR_TIM8EN    13
#define RCC_APB2ENR_USART1EN  14
#define RCC_APB2ENR_ADC3EN    15
#define RCC_APB2ENR_TIM9EN    19
#define RCC_APB2ENR_TIM10EN   20
#define RCC_APB2ENR_TIM11EN   21

// RCC_APB1ENR Register
#define RCC_APB1ENR_TIM2EN    0
#define RCC_APB1ENR_TIM3EN    1
#define RCC_APB1ENR_TIM4EN    2
#define RCC_APB1ENR_TIM5EN    3
#define RCC_APB1ENR_TIM6EN    4
#define RCC_APB1ENR_TIM7EN    5
#define RCC_APB1ENR_TIM12EN   6
#define RCC_APB1ENR_TIM13EN   7
#define RCC_APB1ENR_TIM14EN   8
#define RCC_APB1ENR_WWDGEN    11
#define RCC_APB1ENR_SPI2EN    14
#define RCC_APB1ENR_SPI3EN    15
#define RCC_APB1ENR_USART2EN  17
#define RCC_APB1ENR_USART3EN  18
#define RCC_APB1ENR_UART4EN   19
#define RCC_APB1ENR_UART5EN   20
#define RCC_APB1ENR_I2C1EN    21
#define RCC_APB1ENR_I2C2EN    22
#define RCC_APB1ENR_USBEN     23
#define RCC_APB1ENR_CANEN     25
#define RCC_APB1ENR_BKPEN     27
#define RCC_APB1ENR_PWREN     28
#define RCC_APB1ENR_DACEN     29

// RCC_BDCR Register
#define RCC_BDCR_LSEON     0
#define RCC_BDCR_LSERDY    1
#define RCC_BDCR_LSEBYP    2
#define RCC_BDCR_RTCSEL    8
#define RCC_BDCR_RTCEN     15
#define RCC_BDCR_BDRST     16

// RCC_CSR Register
#define RCC_CSR_LSION      0
#define RCC_CSR_LSIRDY     1
#define RCC_CSR_RMVF       24
#define RCC_CSR_PINRSTF    26
#define RCC_CSR_PORRSTF    27
#define RCC_CSR_SFTRSTF    28
#define RCC_CSR_IWDGRSTF   29
#define RCC_CSR_WWDGRSTF   30
#define RCC_CSR_LPWRRSTF   31

#endif /* MRCC_PRIVATE_H_ */
