#include "ServerCommandTester.h"

ServerCommandTester::ServerCommandTester(int numTests)
{
	numberOfTests = numTests;
}
ServerCommandTester::~ServerCommandTester(){}

void ServerCommandTester::Reset()
{
	numTestsFailed = 0;
	numTestsPassed = 0;
}
void ServerCommandTester::RunAllTests()
{
	TestTripleAFloatCommand();
	TestIntFloatProductCommand();
}

void ServerCommandTester::TestTripleAFloatCommand()
{
	Reset();
	TripleAFloatParams* params;
	TripleAFloatCommand* testCommand;
	//for (float i = numberOfTests / (-10.0f); i <= numberOfTests / (10.0f); i += numberOfTests / (5.0f*numberOfTests))
	for (int i = numberOfTests / (-2); i <= numberOfTests / 2; i++)
	{
		params = new TripleAFloatParams(i / 10.0f);
		testCommand = new TripleAFloatCommand(params);
		testCommand->Execute();
		if (testCommand->params->result == (i/10.0f*3.0f))
			numTestsPassed++;
		else
			numTestsFailed++;
		delete testCommand;
		testCommand = NULL;
		delete params;
		params = NULL;
	}
	printf("\n\nTestTripleAFloatCommand Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
}

void ServerCommandTester::TestIntFloatProductCommand()
{
	Reset();
	for (int i = numberOfTests/(-2); i <= numberOfTests/2; i++)
	{
		//for (float j = numtests-100.0f; j < 100.0f; j++)
		for (float j = numberOfTests / (-10.0f); j <= numberOfTests / (10.0f); j += numberOfTests / (5.0f*numberOfTests))
		{
			IntFloatProductParams* params = new IntFloatProductParams(j, i);
			IntFloatProductCommand* testCommand = new IntFloatProductCommand(params);
			testCommand->Execute();
			
			if (testCommand->params->result == (j*i))
				numTestsPassed++;
			else
				numTestsFailed++;
			
			delete params;
			delete testCommand;
			params = NULL;
			testCommand = NULL;
		}
	}
	printf("\n\nTestIntFloatProductCommand Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
}