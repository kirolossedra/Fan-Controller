 /*
 * adc.c
 *
 *  Created on: 11 Oct 2021
 *      Author: kirol
 */


#include "avr/io.h" /* To use the ADC Registers */
#include <avr/interrupt.h> /* For ADC ISR */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/




/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */


		ADMUX = (Config_Ptr->setting)<<7;



	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 1 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN)|(Config_Ptr->prescale);


}

void ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
}
uint16 ADC_readOutput(void){
	while(BIT_IS_SET(ADCSRA,ADSC)){}
	return ADC;
}
