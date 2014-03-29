//timer.h

#ifndef timer_H_

#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))

void cfgtimer(void);
int centesimas;
int segundostimer;

#endif /* timer_H_ */
