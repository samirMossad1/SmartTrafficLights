
#ifndef INCLUDES_APPLICATIONSFUNCTIONS_H_
#define INCLUDES_APPLICATIONSFUNCTIONS_H_



#include "gpio.h"
#include "segment7.h"
#include "timer.h"

void resetSwitchisPressed(void);
void callBackfunction(void);
void _enableGlobal_interrupts(void);
void ledGreenOn(void);
void ledGreenOff(void);
void ledRedOn(void);
void ledRedOff(void);
void callBackfunction1(void);

#endif /* INCLUDES_APPLICATIONSFUNCTIONS_H_ */
