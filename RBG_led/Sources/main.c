/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */
#include "adc.h"
#include "lcd.h"
#include "pwm.h"


#define PortLeds GPIOA_PDOR
int uni, dec, cen, mil, r;
int R,B,G;
int rc, rd, ru;
int bc, bd, bu;
int gc, gd, gu;
int r;

int main(void)
{
	cfgPortsLCD();
	cfgPortsADC();
	cfgPortsPWM();
	
	sendCode (nIns,0xC1);
	sendCode (nData,'R');
	
	sendCode (nIns,0xC6);
	sendCode (nData,'G');
	
	sendCode (nIns,0xCB);
	sendCode (nData,'B');
	
	for(;;)
	{
		ADC0_SC1A = 0x00; //red
		delay(1500);
		TPM2_C0V = (ADC0_RA * 3282)/255;
		R =  255- ADC0_RA;
		rc = R / 100;
		r = R % 100;
		rd = r / 10;
		r = r % 10;
		ru = r;
		sendCode (nIns,0x80);
		sendCode (nData,rc+0x30);
		sendCode (nData,rd+0x30);
		sendCode (nData,ru+0x30);
		
		ADC0_SC1A = 0x0C; //green
		delay(1500);
		TPM2_C1V = (ADC0_RA * 3282)/255;
		G = 255 - ADC0_RA;
		gc = G / 100;
		r = G % 100;
		gd = r / 10;
		r = r % 10;
		gu = r;
		sendCode (nIns,0x85);
		sendCode (nData,gc+0x30);
		sendCode (nData,gd+0x30);
		sendCode (nData,gu+0x30);
	
		ADC0_SC1A = 0x03; //blue
		delay(1500);
		TPM0_C1V = (ADC0_RA * 3282)/255;
		B = 255 - ADC0_RA;
		
		bc = B / 100;
		r = B % 100;
		bd = r / 10;
		r = r % 10;
		bu = r;
		sendCode (nIns,0x8A);
		sendCode (nData,bc+0x30);
		sendCode (nData,bd+0x30);
		sendCode (nData,bu+0x30);
	}
	
}