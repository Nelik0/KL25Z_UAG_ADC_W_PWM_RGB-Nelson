//botones.h

#ifndef Botones_H_
#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))  		  
 
void cfgPortBot(void); 
void debounce(long stage);
void botread(void);
int read;
int botones;

#endif /* Botones_H_ */
