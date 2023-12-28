#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"


#define GPIOAEN  1U
/*#define GPIOAEN  (1U<<0)*/
#define PIN5 		(1U<<5)
#define LED_PIN 	PIN5


int main(void) {

	/*Enable clock to GPIOA */
	RCC->AHB1ENR 	 |= GPIOAEN;
	/*Set PA5 as an output pin*/
	GPIOA->MODER	 |= (1U<<10);
	GPIOA->MODER	 &=~ (1U<<11);

	/*Initialisation of uart Tx and Tim2*/
	uart2_tx_init();
	pc13_exti_init();

	while(1){

	}
}

static  void exti_callback(void)
{
	printf("Btn pressed...! \n\r");
	GPIOA->ODR ^=LED_PIN;
}

void EXTI15_10_IRQHandler(void) {
	if ( (EXTI->PR & LINE13)!=0) {
		/*Clear PR flag*/
		EXTI->PR |= LINE13;
		//Do traitement
		exti_callback();
	}
}







