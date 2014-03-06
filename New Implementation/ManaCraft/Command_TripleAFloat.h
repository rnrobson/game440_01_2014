#ifndef COMMAND_TRIPLE_FLOAT_H
#define COMMAND_TRIPLE_FLOAT_H

//#include <iostream>
#include "ServerIncludes.h"
#include "ServerCommandIncludes.h"
struct Params_TripleAFloat
{
	float x;
	float result;
	Params_TripleAFloat(float _x)
	{
		x = _x;
		result = 0;
	}
	~Params_TripleAFloat(){}
};

class Command_TripleAFloat : public ServerCommand
{
public:
	
	Params_TripleAFloat* params;

	Command_TripleAFloat(void* _data)
	{
		data = _data;
		params = (Params_TripleAFloat*)data;

		//printf("\nTripleAFloatCommand: Initialized --data = %f", params.x);
	}
	~Command_TripleAFloat(){}

	void Execute()
	{
		params->result = params->x*3.0f;
		//printf("\nTripleAFloatCommand: Executed --result = %f", params.result);
	}

};

#endif