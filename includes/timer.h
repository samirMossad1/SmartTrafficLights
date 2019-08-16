
#ifndef TIMER_H_
#define TIMER_H_


#include "micro_config.h"
#include "std_types.h"
#include "macros.h"



typedef enum
{
	_NORMAL_MODE, /*Overflow Mode*/
	_CTC_MODE,
	_PWM_MODE,
	_ICU_MODE

}TIMER_MODE;

typedef enum
{
	_OVERFLOW,
	_COMPARE,
	_INPUT_CAPTURE


}TIMER_FLAG;

typedef enum
{
	_FCPU	=1, /*start from 001*/
	_FCPU_8,
	_FCPU_64,
	_FCPU_256,
	_FCPU_1024

}TIMER_PRESCALAR;

typedef enum
{
	_NORMAL_PIN, /*Choose this option in the normal mode*/
	_OUTPUT_COMPARE_PIN

}TIMER_PINS;

typedef enum
{
	_OUTPUT_COMPARE_DISCONNECTED,
	_OUTPUT_COMPARE_TOGGLE, /*Only in CTC mode*/
	_OUTPUT_COMPARE_CLEAR,
	_OUTPUT_COMPARE_SET,
	_IGNORE_TYPE


}TIMER_OUTPUT_TYPES;


typedef enum
{

	_IGNORE_EDGE,
	_NON_INVERTING=2,
	_INVERTING=3


}TIMER_PWM_SIGNAL;

typedef enum
{
	TIMER_FALLING_EDGE,
	TIMER_RISING_EGDE

}TIMER_ICU_EDGE;





typedef struct timer_configStruct
{

	TIMER_NUMBER 		TIMER_N;
	TIMER_CHANNEL 		TIMER_CH;	 /*use the ignore option in case of timer0/2*/
	TIMER_MODE  		TIMER_MODE;
	TIMER_OUTPUT_TYPES	TIMER_OUT; 	 /*use the ignore option in case of normal mode*/
	TIMER_PINS			TIMER_PIN;
	TIMER_PWM_SIGNAL	TIMER_PWM;   /*use the ignore option in case of NON pwm mode*/

}TIMER_ConfigStruct;


bool TIMER_init(const TIMER_ConfigStruct *);

bool TIMER_enable(const TIMER_NUMBER,const TIMER_PRESCALAR); /*Use this function to enable any timer for OVERFLOW/ICU mode*/

bool TIMER_disable(const TIMER_NUMBER);

uint16_t TIMER_readCount(const TIMER_NUMBER);

uint8_t	 TIMER_readStatus(const TIMER_NUMBER,const TIMER_CHANNEL,const TIMER_FLAG);

void TIMER_COMPARE_setValue(const TIMER_NUMBER ,const TIMER_CHANNEL,const TIMER_MODE,const uint16_t);

void TIMER1_ICU_setEdge(const TIMER_ICU_EDGE);

uint16_t TIMER1_ICU_readCaptureReg();

bool TIMER_interruptEnable(const TIMER_NUMBER,const TIMER_CHANNEL,const TIMER_FLAG,void(*)(void));

bool TIMER_interruptDisable(const TIMER_NUMBER,const TIMER_CHANNEL,const TIMER_FLAG);




#endif
