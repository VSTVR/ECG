#include"head.h"

void showvoltage(u16 adc_x)
{
   u16 p;
   p=adc_x;
	 p=(3.3/4096)*p;
   p=p*10000;
   
   int v;
   v=(int)p;
	
   USART_SendData(USART2,0x76);
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,0x3D);
   while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,(48+v/10000));
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,0x2E);
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,(48+v%10000/1000));
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,(48+v%10000%1000/100));
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,(48+v%10000%1000%100/10));
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,(48+v%10000%1000%100%10));		
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	 USART_SendData(USART2,0x0A);
	 while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET); 
}