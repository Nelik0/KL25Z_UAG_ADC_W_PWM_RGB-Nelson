//adc.h

#ifndef adc_H_

#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))

int InputADC;
void ADCread(void); 
void cfgPortsADC(void); 

#endif /* adc_H_ */