/*
 * File        : GPIO_PROGRAM.C
 * Author      : Abdelrhman Rabie Embedded SW Engineer
 * Date        : 15/7/2023

 */
#ifndef UART_Private_h
#define UART_Private_h


typedef struct
{
	
	
	union
{
	uint32 R;
    struct
	{
	uint32 PE    :1;	
	uint32 FE    :1;
	uint32 NF    :1;
	uint32 ORE   :1;
	uint32 IDLE  :1;
    uint32 RXNE  :1;
    uint32 TC    :1;
	uint32 TXE   :1;
	uint32 LBD   :1;
	uint32 CTS   :1;
	uint32 unsed :22;
	}B;	
}SR;
	
		union
{
	uint32 R;
    	
}DR;
	
	union
{
	uint32 R;
    struct
	{
	uint32 DIV_Fraction :4;	
	uint32 DIV_Mantissa :12;
	uint32 UNUSED       :16;
	}B;	
}BRR;	
	
	union
{
	uint32 R;
    struct
	{
	uint32 SBK   :1;	
	uint32 RWU   :1;
	uint32 RE    :1;
	uint32 TE    :1;
    uint32 IDLEIE:1;
    uint32 RXNEIE:1;
	uint32 TCIE  :1;
	uint32 TXEIE :1;
	uint32 PEIE  :1;
	uint32 PS    :1;
	uint32 PCE   :1;
	uint32 WAKE  :1;
	uint32 M     :1;
	uint32 UE    :1;
	uint32 RES   :1;
	uint32 OVER8 :1;
	uint32 UNSED :16;
	
	}B;	
}CR1;	
	
union
{
	uint32 R;
    struct
	{
	uint32 ADD   :4;	
	uint32 RES   :1;
	uint32 LBDL  :1;
	uint32 LBDIE :1;
    uint32 RES_1 :1;
    uint32 LBCL  :1;
	uint32 CPHA  :1;
	uint32 CPOL  :1;
	uint32 CLKEN :1;
	uint32 STOP  :2;
	uint32 LINE  :1;
	uint32 RES_2 :1;
	uint32 UNSED :16;
	}B;	
}CR2;	
	uint32 CR3;
	uint32 GTPR;
		
}UART_t;
/*
UART 1&6 IN APB2 
UART 2 IN APB1
*/
#define                      BASE_ADRESS_UART1      0x40013800
#define                      BASE_ADRESS_UART2      0x40004400
#define                      BASE_ADRESS_UART6      0x40011400

#define UART1            ((volatile UART_t*)BASE_ADRESS_UART1)
#define UART2            ((volatile UART_t*)BASE_ADRESS_UART2)
#define UART6            ((volatile UART_t*)BASE_ADRESS_UART6)

/*USE IT IN CASE YOU WANT TO REMAP USART1*/
#define AFIO_MAPR_REG    *((volatile u32 *) 0x40010004)                
 
#endif
