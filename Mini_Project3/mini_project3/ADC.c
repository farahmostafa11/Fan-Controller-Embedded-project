/*
 * ADC.c
 *
 *  Created on: Oct 4, 2021
 *      Author: farah
 */
#include"ADC.h"
#include "avr/io.h" /* To use the ADC Registers */
#include <avr/interrupt.h> /* For ADC ISR */
#include "common_macros.h" /* To use the macros like SET_BIT */

void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX=((uint8)(Config_Ptr->ref_volt & 0X03)<<6);
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * SET first 3 LSB to the prescaler selected by the user
	 */
	ADCSRA=(1<<ADEN);
	ADCSRA=(ADCSRA&0XF8)|(Config_Ptr->prescaler&0X07);
	//PRESCALER 8 interrupt enable & ADC enable
}
uint16 ADC_readChannel(uint8 channel_num){
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
