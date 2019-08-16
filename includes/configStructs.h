

#ifndef INCLUDES_CONFIGSTRUCTS_H_
#define INCLUDES_CONFIGSTRUCTS_H_


#include "../includes/gpio.h"
#include "../includes/segment7.h"
#include "../includes/timer.h"
#include "applicationsfunctions.h"

#define RED_LIGHT   0X00
#define GREEN_LIGHT 0X01

/*7segments*/

Segment7_ConfigStruct segment1_t={

		PORT_C,
		_LEAST
};


Segment7_ConfigStruct segment2_t={

		PORT_C,
		_MOST
};

 /*RESET PIN*/

GPIO_pinConfigStruct resetPin_t={

		PORT_D,
		PIN_2,
		_INPUT
};


GPIO_intConfigStruct resetPinInt_t={

		INTERRUPT_0,
		TIMER_FALLING_EDGE,
		resetSwitchisPressed
};



/*LEDS*/
GPIO_pinConfigStruct ledGreen_t={

		PORT_A,
		PIN_0,
		_OUTPUT
};

GPIO_pinConfigStruct ledRed_t={

		PORT_A,
		PIN_1,
		_OUTPUT
};



/*TIMERS*/

TIMER_ConfigStruct timer0_t={

		TIMER_0,
		_IGNORE_CHANNEL,
		_NORMAL_MODE,
		_OUTPUT_COMPARE_DISCONNECTED,
		_NORMAL_PIN,
		_IGNORE_EDGE

};



#endif /* INCLUDES_CONFIGSTRUCTS_H_ */
