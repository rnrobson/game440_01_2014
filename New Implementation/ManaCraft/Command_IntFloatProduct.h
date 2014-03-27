#ifndef INT_FLOAT_PRODUCT_COMMAND_H
#define INT_FLOAT_PRODUCT_COMMAND_H

//#include <iostream>
//#include "ServerIncludes.h"
//#include "ServerCommandIncludes.h"
#include "PacketFactory.h"

struct Params_IntFloatProduct
{
public:
	float x;
	int y;
	float result;
	Params_IntFloatProduct(float _x, int _y)
	{
		x = _x;
		y = _y;
		result = 0;
	}
	~Params_IntFloatProduct(){}
};
class Command_IntFloatProduct : public CommandPacket
{
public:
	Params_IntFloatProduct* params;
	Packet nullPacket;

	Command_IntFloatProduct(void* _data) : CommandPacket(&nullPacket)
	{
		params = (Params_IntFloatProduct*)_data;
		//printf("\nIntFloatProductCommand: Initialized --float = %f", params->x);
		//printf("\nIntFloatProductCommand: Initialized --int = %i", params->y);
	}
	~Command_IntFloatProduct(){}

	void Execute()
	{
		params->result = params->x*params->y;
		//printf("\nIntFloatProductCommand: Executed --result = %f", params->result);
	}

};

#endif