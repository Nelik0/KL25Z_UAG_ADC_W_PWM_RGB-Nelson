/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "adc.h"
#include "lcd.h"

void ADCread(void)
{ 
	if((ADC0_SC1A & ADC_SC1_COCO_MASK) == ADC0_SC1A)
	{
		InputADC = ADC0_RA;
	}
}
void cfgPortsADC(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	
	PORTE_PCR20=(0|PORT_PCR_MUX(0)); //ADC0_DP0
	PORTB_PCR2=(0|PORT_PCR_MUX(0)); //ADC0_SE12
	PORTE_PCR22=(0|PORT_PCR_MUX(0)); //ADC0_DP3
	
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	ADC0_CFG1 = 0;  	//0000 0000
	ADC0_CFG2 = 0x10;  	//0000 0000
	ADC0_SC2 = 0;   	//0000 0000
	ADC0_SC3 = 0x0F; 
	//0000 1101
	ADC0_SC1A = 0x00;	//READING  	ADC0_DP0 = 0x00 (ROJO)
								//	ADC0_SE12 = 0x0C (VERDE)
								//	ADC0_DP3 = 0x03	(AZUL)
	
}
