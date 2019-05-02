#include "led.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //GPIO_InitStructure
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出（节能）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO 口速度为 50MHz（速度设置）
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE); //使能 PA,PD 端口时钟（挂载在APB2总线上）
	
	//LED0
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //LED0-->PA.8 端口配置  【指向】
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化 GPIOA.8           【初始化】
	GPIO_SetBits(GPIOA,GPIO_Pin_8); //PA.8 输出高              
	//LED1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //LED1-->PD.2 端口配置
	GPIO_Init(GPIOD, &GPIO_InitStructure); //初始化GPIOD
	GPIO_SetBits(GPIOD,GPIO_Pin_2); //PD.2 输出高
}