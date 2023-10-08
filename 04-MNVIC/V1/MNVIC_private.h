/*
 * NVIC_private.h
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDET.h"

#define GGGG 0x05FA0300 // 16 NESTED
#define GGGS 0x05FA0400
#define GGSS 0x05FA0500 // SEMI-NESTED
#define GSSS 0x05FA0600
#define SSSS 0x05FA0700 //  NON-NESTED

#define PRIGROUP GGSS

typedef struct
{
	u32 ISER[32];
	u32 ICER[32];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[32];
	u32 Res[32] ;
	u8 IP[128];

}NVIC_REG;

/*
typedef struct
{
	u32 ISER[3];
	u32 RES0[29];
	u32 ICER[3];
	u32 RES1[29];
	u32 ISPR[3];
	u32 RES2[29];
	u32 ICPR[3];
	u32 RES3[29];
	u32 IABR[3];
	u32 RES4[61];
	u8 IP[84];

}NVIC_REG;

*/
typedef struct
{
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCRS;
	u32 HFSR;
	u32 MMAR;
	u32 BFAR;


}SCB_REG;

#define NVIC               ((volatile NVIC_REG*)0xE000E100)
#define NVIC_STIR          (*((volatile u32*)0xE000EE00))
#define SCB            	    ((volatile SCB_REG*)0xE000E008)

// SCB -> AIRCR = 0x0FA05000 | PRIGROUP;



#define WWDG              0
#define PVD               1
#define TAMPER            2
#define RTC               3
#define FLASH             4
#define RCC               5
#define EXTI0             6
#define EXTI1             7
#define EXTI2             8
#define EXTI3             9
#define EXTI4            10
#define DMA1_Channel1    11
#define DMA1_Channel2    12
#define DMA1_Channel3    13
#define DMA1_Channel4    14
#define DMA1_Channel5    15
#define DMA1_Channel6    16
#define DMA1_Channel7    17
#define ADC1_2           18
#define USB_HP_CAN_TX    19
#define USB_LP_CAN_TX    20
#define CAN_RX1          21
#define CAN_SCE          22
#define EXTI9_5          23
#define TIM_BRK          24
#define TIM1_UP          25
#define TIM1_TRG_COM     26
#define TIM1_CC          27
#define TIM2             28
#define TIM3             29
#define TIM4             30
#define I2C1_EV          31
#define I2C1_ER          32
#define I2C2_EV          33
#define I2C2_ER          34
#define SPI1             35
#define SPI2             36
#define USART1           37
#define USART2           38
#define USART3           39
#define EXTI15_10        40
#define TRCAlarm         41
#define USBWakeUp        42
#define TIM8_BRK         43
#define TIM8_UP          44
#define TIM8_TRG_COM     45
#define TIM8_CC          46
#define ADC3             47
#define FSMC             48
#define SDIO             49
#define TIM5             50
#define SPI3             51
#define UART4          	 52
#define UART5          	 53
#define TIM6           	 54
#define TIM7           	 55
#define DMA2_Channel  	 56
#define DMA2_Channe2   	 57
#define DMA2_Channe3  	 58
#define DMA2_Channe4_5   59

#endif /* MNVIC_PRIVATE_H_ */
