#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H


//#include "ServerIncludes.h"
#include <iostream> //BAND_AID
//#include "ServerCommand.h"

class TestCommand //: public ServerCommand
{
public:
	TestCommand(void* _data) //: ServerCommand(_data)
	{
		//data = _data;

		//printf("\nTestCommand: Initialized --data = %i",   data);
		
	}

	~TestCommand()
	{

	}


	void  Execute()
	{
		//std::cout << "\nTestCommand: Execute!";
		//data += 1;
		//data = (void*)2;
		//printf("TestCommand: Initialized --data = ");
		//printf("\nTestCommand: Executed --data = %i", data);
	};
};

#endif