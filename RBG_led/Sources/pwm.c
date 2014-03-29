/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "pwm.h"

void cfgPortsPWM(void)
{
	//TPM0_STATUS	0x100
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	PORTB_PCR18=(0|PORT_PCR_MUX(3));
	PORTB_PCR19=(0|PORT_PCR_MUX(3));
	PORTD_PCR1=(0|PORT_PCR_MUX(4));
	
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
	SIM_SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK); // Selects the MCGFLLCLK clock 
	
	//Turn on clock for TPM0
	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
	SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;
	//Clear counter register
	TPM0_CNT = 0;
	TPM2_CNT = 0;
	//Set signal period to 1 ms
	TPM0_MOD = 1640;
	TPM2_MOD = 3282;
	//See page 552 for TPMx_SC configuration (freq = 1 MHz)
	TPM0_SC  = 0x0F;
	TPM2_SC = 0x0F;//0 0000 1011
	//See page 556 for TPMx_CnSC configuration
	TPM0_C1SC = 0x28;		//0010 1000
	TPM0_C1V = 0;//set time_working of period, it must be LOWER than signal period
	
	TPM2_C1SC = 0x28;		//0010 1000
	TPM2_C1V = 3282;
	
	TPM2_C0SC = 0x28;		//0010 1000
	TPM2_C0V = 3282;
}
