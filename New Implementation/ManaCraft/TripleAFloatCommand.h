#ifndef TRIPLE_FLOAT_H
#define TRIPLE_FLOAT_H

//#include <iostream>
#include "ServerIncludes.h"
#include "ServerCommandIncludes.h"

struct TripleAFloatParams
{
	float x;
	float result;
	TripleAFloatParams(float _x)
	{
		x = _x;
		result = 0;
	}
	~TripleAFloatParams(){}
};

class TripleAFloatCommand : public ServerCommand
{
public:
	
	TripleAFloatParams* params;

	TripleAFloatCommand(void* _data)
	{
		data = _data;
		params = (TripleAFloatParams*)data;
		//printf("\nTripleAFloatCommand: Initialized --data = %f", params.x);
	}
	~TripleAFloatCommand(){}

	void Execute()
	{
		params->result = params->x*3.0f;
		//printf("\nTripleAFloatCommand: Executed --result = %f", params.result);
	}

};

#endif