#ifndef COMMAND_TRIPLE_FLOAT_H
#define COMMAND_TRIPLE_FLOAT_H

//#include <iostream>
//#include "ServerIncludes.h"
//#include "ServerCommandIncludes.h"
#include "PacketFactory.h"

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

class Command_TripleAFloat : public CommandPacket
{
public:

	Params_TripleAFloat* params;
	Packet nullPacket;

	Command_TripleAFloat(void* _data) : CommandPacket(&nullPacket)
	{
		params = (Params_TripleAFloat*)_data;

		//printf("\nTripleAFloatCommand: Initialized --data = %f", params.x);
	}
	~Command_TripleAFloat(){}

	void Execute()
	{
		params->result = params->x*3.0f;
		printf("\nTripleAFloatCommand: Executed --result = %f\n", params->result);
	}

};
#endif