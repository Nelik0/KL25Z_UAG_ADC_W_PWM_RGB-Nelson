/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "timer.h"

void cfgtimer(void)
{
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK; 
    // Enable the clock to the PIT module
	PIT_LDVAL0 = 105000;     // Default start value (1 cs)
	PIT_MCR = 0x00;     // Enable clock for timer, don't freeze timer in debug mode
	PIT_TCTRL0 = PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;     // Enable timer and timer interrupt
	
// Initialize the NVIC to enable the PIT interrupt
 
NVIC_ICPR |= 1 << ((INT_PIT - 16) % 32);
NVIC_ISER |= 1 << ((INT_PIT - 16) % 32);
centesimas = 0;
segundostimer = 0;
}

void PIT_IRQHandler()
{
PIT_TCTRL0 = 0;     // Disable timer
PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
if (centesimas >= 100)
	{
	centesimas = 0;
	segundostimer++;
	}
centesimas++;// Clear the timer interrupt flag 
PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;     // Enable timer
}
