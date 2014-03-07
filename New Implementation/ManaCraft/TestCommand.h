#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H


#include <iostream>

#include "ServerCommand.h"

class TestCommand : public ServerCommand
{
public:
	struct Params
	{
		int x;
	};
	Params params;
	TestCommand(void* _data)
	{

		data = _data;

		params = *(Params*)data;

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