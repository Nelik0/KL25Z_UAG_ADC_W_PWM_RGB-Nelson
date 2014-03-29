//rtc.h

#ifndef rtc_H_

#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))

void rtc_init(void);
void RTC_isr_Seconds (void);
void Clock_Configuration (void);
int interrupt;
int seconds, alarm, minutes;

#endif /* rtc_H_ */
