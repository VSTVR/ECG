#ifndef __LED_H
#define __LED_H	 
#include "sys.h"


#define LED0 PAout(8)	// PA8������LED0
#define LED1 PDout(2)	// PD2������LED1

void LED_Init(void);  //��������

		 				    
#endif
