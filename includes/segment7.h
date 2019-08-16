
#ifndef SEGMENT7_H_
#define SEGMENT7_H_


#include "micro_config.h"
#include "std_types.h"
#include "macros.h"


typedef enum mostleast_pins
{
	_LEAST,
	_MOST=4

}SEGMENT7_PORTPINS;

typedef struct segment7_configstruct
{

	GPIO_PORT PORT;
	SEGMENT7_PORTPINS PINS;

}Segment7_ConfigStruct;


bool SEGMENT7_init(const Segment7_ConfigStruct*);

void SEGMENT7_write(const Segment7_ConfigStruct*,const uint8_t);




#endif
