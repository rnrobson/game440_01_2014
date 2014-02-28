#ifndef INT_FLOAT_PRODUCT_COMMAND_H
#define INT_FLOAT_PRODUCT_COMMAND_H

//#include <iostream>
#include "ServerIncludes.h"
#include "ServerCommandIncludes.h"

struct IntFloatProductParams
{
public:
	float x;
	int y;
	float result;
	IntFloatProductParams(float _x, int _y)
	{
		x = _x;
		y = _y;
		result = 0;
	}
	~IntFloatProductParams(){}
};
class IntFloatProductCommand : public ServerCommand
{
public:
	IntFloatProductParams* params;

	IntFloatProductCommand(void* _data)
	{
		data = _data;
		params = (IntFloatProductParams*)data;
		//printf("\nIntFloatProductCommand: Initialized --float = %f", params->x);
		//printf("\nIntFloatProductCommand: Initialized --int = %i", params->y);
	}
	~IntFloatProductCommand(){}

	void Execute()
	{
		params->result = params->x*params->y;
		//printf("\nIntFloatProductCommand: Executed --result = %f", params->result);
	}

};

#endif