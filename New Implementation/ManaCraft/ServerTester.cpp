#include "ServerTester.h"
#include "Server.h"
ServerTester::ServerTester(int numTests)
{
	numberOfTests = numTests;
}
ServerTester::~ServerTester(){}

void ServerTester::Reset()
{
	numTestsFailed = 0;
	numTestsPassed = 0;
}
void ServerTester::RunAllTests()
{
	Test_Command_IntFloatProduct();
	Test_Command_TripleAFloat();
}

void ServerTester::Test_Command_TripleAFloat()
{
	Reset();
	Params_TripleAFloat* params;
	Command_TripleAFloat* testCommand;
	for (int i = numberOfTests / (-2); i <= numberOfTests / 2; i++)
	{
		params = new Params_TripleAFloat(i / 10.0f);
		testCommand = new Command_TripleAFloat(params);
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
	printf("\n\nTest_Command_TripleAFloat Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
}

void ServerTester::Test_Command_IntFloatProduct()
{
	Reset();
	for (int i = numberOfTests/(-2); i <= numberOfTests/2; i++)
	{
		for (float j = numberOfTests / (-10.0f); j <= numberOfTests / (10.0f); j += numberOfTests / (5.0f*numberOfTests))
		{
			Params_IntFloatProduct* params = new Params_IntFloatProduct(j, i);
			Command_IntFloatProduct* testCommand = new Command_IntFloatProduct(params);
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
	printf("\n\nTest_Command_IntFloatProduct Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
}
void ServerTester::Test_Command_CreateNewGame()
{
	Reset();
	
	Command_CreateNewGame* command;
	unsigned int numGames;

	//no new games should be created for a -ve or 0 id 
	for (int i = numberOfTests / (-2);i<1;i++)
	{
		numGames = GameManager::games.size();
		command = new Command_CreateNewGame(&i);
		command->Execute();
		if (GameManager::games.size() == numGames)
			numTestsPassed++;
		else
			numTestsFailed++;
	}
	//games should be created for values from 1 - max_games
	for (unsigned int i = 1; i <= GameManager::MAX_GAMES; i++)
	{
		numGames = GameManager::games.size();
		command = new Command_CreateNewGame(&i);
		command->Execute();
		if (GameManager::games.size() > numGames)
			numTestsPassed++;
		else
			numTestsFailed++;
	}
	//no new games for if already at max_games
	for (int i = GameManager::MAX_GAMES + 1; i <= numberOfTests / 2; i++)
	{
		numGames = GameManager::games.size();
		command = new Command_CreateNewGame(&i);
		command->Execute();
		if (GameManager::games.size()== numGames)
			numTestsPassed++;
		else
			numTestsFailed++;
	}

	printf("\n\nTest_Command_CreateNewGame Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
}