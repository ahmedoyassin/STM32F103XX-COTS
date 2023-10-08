#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA_u32_BASE_ADDRESS                                0x40020000U

typedef struct
{
		union
		{
			u32 R;
			struct
			{
				u32 GIF1 :1;
				u32	TCIF1 :1;
				u32 HTIF1 :1;
				u32	TEIF1 :1;
				
				u32 GIF2 :1;
				u32	TCIF2 :1;
				u32 HTIF2 :1;
				u32	TEIF2 :1;

				u32 GIF3 :1;
				u32	TCIF3 :1;
				u32 HTIF3 :1;
				u32	TEIF3 :1;

				u32 GIF4 :1;
				u32	TCIF4 :1;
				u32 HTIF4 :1;
				u32	TEIF4 :1;

				u32 GIF5 :1;
				u32	TCIF5 :1;
				u32 HTIF5 :1;
				u32	TEIF5 :1;
				
				u32 GIF6 :1;
				u32	TCIF6 :1;
				u32 HTIF6 :1;
				u32	TEIF6 :1;
				
				u32 GIF7 :1;
				u32	TCIF7 :1;
				u32 HTIF7 :1;
				u32	TEIF7 :1;

				u32 Reserved : 4;
				
			}
		}ISR;
		
		union
		{
			u32 R;
			struct
			{
				u32 CGIF1 :1;
				u32	CTCIF1 :1;
				u32 CHTIF1 :1;
				u32	CTEIF1 :1;
				
				u32 CGIF2 :1;
				u32	CTCIF2 :1;
				u32 CHTIF2 :1;
				u32	CTEIF2 :1;

				u32 CGIF3 :1;
				u32	CTCIF3 :1;
				u32 CHTIF3 :1;
				u32	CTEIF3 :1;

				u32 CGIF4 :1;
				u32	CTCIF4 :1;
				u32 CHTIF4 :1;
				u32	CTEIF4 :1;

				u32 CGIF5 :1;
				u32	CTCIF5 :1;
				u32 CHTIF5 :1;
				u32	CTEIF5 :1;
				
				u32 CGIF6 :1;
				u32	CTCIF6 :1;
				u32 CHTIF6 :1;
				u32	CTEIF6 :1;
				
				u32 CGIF7 :1;
				u32	CTCIF7 :1;
				u32 CHTIF7 :1;
				u32	CTEIF7 :1;

				u32 Reserved : 4;
				
			}
		}IFCR;
			
		union
		{
			u32 R;
			struct
			{
				u32 EN :1;
				u32	TCIE :1;
				u32	HTIE :1;
				u32	TEIE :1;
				u32	DIR	:1;
				u32	CIRC :1;
				u32	PINC :1;
				u32	MINC :1;
				u32 PSIZE :2;
				u32 MSIZE :2;
				u32 PL :2;
				u32 MEM2MEM :1;

				u32 Reserved : 17;
				
			}
		}CCR1;
			
		union
		{
			u32 R;
		}CNDTR1;
		
		union
		{
			u32 R;
		}CPAR1;
		
		union
		{
			u32 R;
		}CMAR1;
		
		union
		{
			u32 R;
		}reserved1;
		
		union
		{
			u32 R;
		}CCR2;
		
		union
		{
			u32 R;
		}CNDTR2;
		
		union
		{
			u32 R;
		}CPAR2;
		
		union
		{
			u32 R;
		}CMAR2;
		
		union
		{
			u32 R;
		}reserved2;
		
		union
		{
			u32 R;
		}CCR3;
		
		union
		{
			u32 R;
		}CNDTR3;
		
		union
		{
			u32 R;
		}CPAR3;
		
		union
		{
			u32 R;
		}CMAR3;
		
		union
		{
			u32 R;
		}reserved3;
		
		union
		{
			u32 R;
		}CCR4;
		
		union
		{
			u32 R;
		}CNDTR4;
		
		union
		{
			u32 R;
		}CPAR4;
		
		union
		{
			u32 R;
		}CMAR4;
		
		union
		{
			u32 R;
		}reserved4;
		
		union
		{
			u32 R;
		}CCR5;
		
		union
		{
			u32 R;
		}CNDTR5;
		
		union
		{
			u32 R;
		}CPAR5;
		
		union
		{
			u32 R;
		}CMAR5;
		
		union
		{
			u32 R;
		}reserved5;
		
		union
		{
			u32 R;
		}CCR6;
		
		union
		{
			u32 R;
		}CNDTR6;
		
		union
		{
			u32 R;
		}CPAR6;
		
		union
		{
			u32 R;
		}CMAR6;
		
		union
		{
			u32 R;
		}reserved6;
		
		union
		{
			u32 R;
		}CCR7;
		
		union
		{
			u32 R;
		}CNDTR7;
		
		union
		{
			u32 R;
		}CPAR7;
		
		union
		{
			u32 R;
		}CMAR7;
		
		union
		{
			u32 R;
		}reserved7;
}DMA_RegDef_t;

#define DMA  ((volatile DMA_RegDef_t*)DMA_u32_BASE_ADDRESS)

#endif /* DMA_PRIVATE_H_ */

