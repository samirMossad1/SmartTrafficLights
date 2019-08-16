

#include "../includes/applicationsfunctions.h"
#include "../includes/gpio.h"

uint8_t timeSecondsUnits_g=0,timeSecondsTens_g=0,ledState_g=0,n_interrupts=0;;

extern GPIO_pinConfigStruct ledGreen_t;
extern GPIO_pinConfigStruct ledRed_t;



void _enableGlobal_interrupts(void)
{
	SREG|=(1<<7);
}



void callBackfunction(void)
{

	if(n_interrupts==0x02)
	{
		n_interrupts=0x00;


		if(timeSecondsUnits_g==0x09)
		{
			timeSecondsUnits_g=0x00;
			if(timeSecondsTens_g==0x02)
			{
				timeSecondsTens_g=0x00;
				ledState_g^=0x01;
			}
			else
			{
				timeSecondsTens_g++;
			}
		}
		else
		{
			timeSecondsUnits_g++;
		}



	}
	else
	{
		n_interrupts++;
	}


}

void ledGreenOn(void)
{
	GPIO_writePin(&ledGreen_t,_HIGH);
}

void ledGreenOff(void)
{
	GPIO_writePin(&ledGreen_t,_LOW);
}

void ledRedOn(void)
{
	GPIO_writePin(&ledRed_t,_HIGH);
}

void ledRedOff(void)
{
	GPIO_writePin(&ledRed_t,_LOW);
}


void resetSwitchisPressed(void)
{
	timeSecondsUnits_g=0x00;
	timeSecondsTens_g=0x00;
	ledState_g=0x00;
}
