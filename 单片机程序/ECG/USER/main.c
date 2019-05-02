#include"head.h"

int main(void)
{
   u16 adc_x;
	 delay_init();
   uart2_init(9600);
   LED_Init();
   Adc_Init();
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置优先级
   LED0=0;LED1=0;
  delay_ms(500); 
  
  while(1)
  {
   adc_x=Get_Adc_Average(ADC_Channel_1,10);
   float p;
   p=(float)adc_x*(3.3/4096);
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
}

