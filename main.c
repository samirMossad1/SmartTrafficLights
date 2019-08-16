


#include "includes/gpio.h"
#include "includes/segment7.h"
#include "includes/timer.h"
#include "includes/configStructs.h"


extern uint8_t ledState_g;
extern uint8_t timeSecondsUnits_g;
extern uint8_t timeSecondsTens_g;


int main(void)
{

	/*RESET BUTTON INITIALIZATION*/
	GPIO_pinInit(&resetPin_t);
	GPIO_pinPullUpInit(&resetPin_t);
	GPIO_interruptInit(&resetPinInt_t);
	GPIO_interruptEnable(INTERRUPT_0);

	/*LEDS INITIALIZATION*/
	GPIO_pinInit(&ledGreen_t);
	GPIO_pinInit(&ledRed_t);

	/*7SEGMENTS INITIALIZATION*/
	SEGMENT7_init(&segment1_t);
	SEGMENT7_init(&segment2_t);


	/*TIMER INITIALIZATIONS*/


	TIMER_init(&timer0_t);
	TIMER_interruptEnable(timer0_t.TIMER_N,timer0_t.TIMER_CH,timer0_t.TIMER_MODE,callBackfunction);

	_enableGlobal_interrupts();
	TIMER_enable(timer0_t.TIMER_N,_FCPU_1024);



	while(1)
	{
		SEGMENT7_write(&segment1_t,timeSecondsUnits_g);
		SEGMENT7_write(&segment2_t,timeSecondsTens_g);

		if(ledState_g==GREEN_LIGHT)
		{
			ledRedOff();
			ledGreenOn();
		}
		else if(ledState_g==RED_LIGHT)
		{
			ledGreenOff();
			ledRedOn();
		}


	}


	return 0;
}


