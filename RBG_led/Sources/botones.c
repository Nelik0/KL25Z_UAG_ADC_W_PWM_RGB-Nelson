/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "botones.h"


void cfgPortBot(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	
	PORTB_PCR9=(PORT_PCR_MUX(1)); 	//0x01
    PORTB_PCR11=(PORT_PCR_MUX(1));	//0x02
	PORTC_PCR16=(PORT_PCR_MUX(1));  //0x04
    PORTC_PCR17=(PORT_PCR_MUX(1));	//0x08
	
	GPIOC_PDDR = 0x00;
	GPIOB_PDDR |= 0x6FF;
}
void debounce(long stage)
{
	while(stage>0) 
    { 
		stage--; 
    } 
}

void botread(void)
{
	read = ((GPIOC_PDIR & 0x30000)) + ((GPIOB_PDIR & 0xA00));
	switch (read)
	{
	case 0x20000:
	debounce(280000);
	botones = 0x08;
	break;
	case 0x10000:
	debounce(280000);
	botones = 0x04;
	break;
	case 0x800:
	debounce(280000);
	botones = 0x02;
	break;
	case 0x200:
	debounce(280000);
	botones = 0x01;
	break;
	default:
	botones = 0x00;
	break;
	}
}
