/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "rtc.h"
#include "lcd.h"

void Clock_Configuration (void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	MCG_C1 |= MCG_C1_IRCLKEN_MASK; //Enable internal reference clock
	MCG_C2 &= ~(MCG_C2_IRCS_MASK);  //Internal Reference Clock -->Slow
	
	//**RTC_CLKIN**//
	PORTC_PCR1 |= (PORT_PCR_MUX(0x1));       //PTC1 as RTC_CLKIN
	SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0b10);  //32 Khz clock source for RTC
	
	//**32KHz Frequency**//
	SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0b100); //Clockout pin --> 32 KHz
	
	PORTC_PCR3 |= (PORT_PCR_MUX(0x5)); //PTC3 as CLKOUT
	
	interrupt = 0;
	seconds = 0; 
	alarm = 0;
	minutes = 0;
}

void rtc_init(void) 
{
    /*enable the clock to SRTC module register space*/
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;

	/*Clear Registers*/
    RTC_CR  = RTC_CR_SWR_MASK;
    RTC_CR  &= ~RTC_CR_SWR_MASK;  
  
    if (RTC_SR & RTC_SR_TIF_MASK){
        RTC_TSR = 0x00000000;   //  this action clears the TIF
    }
    
    /*Set time compensation parameters*/
    RTC_TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);
  
    /*Enable RTC seconds irq*/
   // enable_irq(INT_RTC_Seconds - 16);
    NVIC_ICPR |= 1 <<(21%32);
	NVIC_ISER |= 1 <<(21%32);		
    
    
    /*Enable Seconds Interrupt*/
    RTC_IER |= RTC_IER_TSIE_MASK; //Seconds interrupt enable
    
    /*Timer enable*/
    RTC_SR |= RTC_SR_TCE_MASK;
    
    /*Configure the timer seconds and alarm registers*/
    RTC_TSR = 0xFF;

}
void RTC_Seconds_IRQHandler(void)
{
interrupt = 1;
	
	seconds = RTC_TSR;
    if (seconds >59)
	{
    	minutes++;
    	RTC_SR &= ~RTC_SR_TCE_MASK;
    	
		RTC_TSR = 0x00; //Reset counter
    	
		seconds = RTC_TSR;
    	
		RTC_SR |= RTC_SR_TCE_MASK;	
    }
}
