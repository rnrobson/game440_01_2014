#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H

#include "PacketFactory.h"
#include <iostream>

class TestCommand : public CommandPacket
{
public:
	struct Params
	{
		int x;
	};
	Params params;
	Packet nullPacket;

	TestCommand(void* _data) : CommandPacket(&nullPacket)
	{
		params = *(Params*)_data;
		printf("\nTestCommand: Initialized --data = %i", params.x);
	}

	~TestCommand(){}

	void  Execute()
	{
		params.x++;
		printf("\nTestCommand: Executed --data = %i", params.x);
	}
};

#endif