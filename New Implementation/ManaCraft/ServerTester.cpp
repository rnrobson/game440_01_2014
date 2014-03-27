#include "ServerTester.h"
#include "Server.h"
#include "PacketFactory.h"

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
	Test_Command_CreateNewGame();
	Test_Command_UpdateMinions();
}

void ServerTester::Test_Command_TripleAFloat()
{
	Reset();
	Params_TripleAFloat* params;
	Command_TripleAFloat* testCommand;
	for (int i = numberOfTests / (-2); i < numberOfTests / 2; i++)
	{
		params = new Params_TripleAFloat(i / 10.0f);
		testCommand = new Command_TripleAFloat(params);
		testCommand->Execute();
		if (testCommand->params->result == (i / 10.0f*3.0f))
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
	for (int i = numberOfTests / (-2); i < numberOfTests / 2; i++)
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

	vector<GameModel*> games = GameManager::games;
	GameManager::games.clear();
	
	//games should be created for values from 1 - max_games
	for (uint i = 1; i <= GameManager::MAX_GAMES; i++)
	{
		numGames = GameManager::games.size();
		command = new Command_CreateNewGame(i);
		command->Execute();
		if (GameManager::games.size() > numGames)
			numTestsPassed++;
		else
			numTestsFailed++;
	}
	//no new games for if already at max_games
	for (int i = GameManager::MAX_GAMES + 1; i <= numberOfTests ; i++)
	{
		numGames = GameManager::games.size();
		command = new Command_CreateNewGame(i);
		command->Execute();
		if (GameManager::games.size() == numGames)
			numTestsPassed++;
		else
			numTestsFailed++;
	}

	printf("\n\nTest_Command_CreateNewGame Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
	
	GameManager::games.clear();
	GameManager::games = games;
	games.clear();
	delete command;
	command = NULL;

}
void ServerTester::Test_Command_UpdateMinions()
{
	Reset();

	uint id = 1;
	CommandPacket* command = new Command_CreateNewGame(id);
	command->Execute();
	GameModel* game = GameManager::FindGame(id);
	//saving the variables to test results against
	vector<Minion*> minions = game->minions;
	size_t numMinions = minions.size();
	int* xPosArr = new int[numMinions];
	int* yPosArr = new int[numMinions];
	uint* speedArr = new uint[numMinions];

	if (game)
	{



		for (size_t i = 0; i < numMinions; i++)
		{
			xPosArr[i] = (int)round(minions[i]->xPos);
			yPosArr[i] = (int)round(minions[i]->yPos);
			speedArr[i] = minions[i]->speed;
		}

		command = new Command_UpdateMinions(id);

		for (int i = 0; i <= numberOfTests / 2; i++)
		{
			bool testPassed = false;
			command->Execute();
			for (size_t i = 0; i < numMinions; i++)
			{
				//testing if minion movement works as expected
				xPosArr[i] += speedArr[i];
				yPosArr[i] += speedArr[i];
				if (minions[i]->xPos == xPosArr[i]
					&& minions[i]->yPos == yPosArr[i])
				{
					testPassed = true;
				}
				else
				{
					testPassed = false;
				}
			}
			if (testPassed)
				numTestsPassed++;
			else
				numTestsFailed++;
		}

		//testing if minions doing damage to the base works as expected
		//for (size_t i = 0; i < numMinions; i++)
		int count = 1;
		numMinions = game->minions.size();
		int baseHP = game->darkBase->health;
		int baseXPos = game->darkBase->xPos;
		int baseYPos = game->darkBase->yPos;

		while (game->minions.size()>0 && count < numberOfTests / 2)
		{
			bool testPassed = false;

			uint minionDamage = game->minions[0]->damage;
			game->minions[0]->xPos = baseXPos*1.0f;
			game->minions[0]->yPos = baseYPos*1.0f;
			game->minions[0]->speed = 0;
			command->Execute();

			if (game->minions.size() < numMinions && game->darkBase->health < baseHP)
			{
				testPassed = true;
				numMinions = game->minions.size();
				baseHP = game->darkBase->health;
			}
			else
			{
				testPassed = false;
			}
			if (testPassed)
				numTestsPassed++;
			else
				numTestsFailed++;

			count++;
		}

		printf("\n\nTest_Command_UpdateMinions Complete: %i Passes, %i Failures", numTestsPassed, numTestsFailed);
	}

	delete command;
	command = NULL;
	delete game;
	game = NULL;
	minions.clear();
	delete[] xPosArr;
	delete[] yPosArr;
	delete[] speedArr;

}

void ServerTester::Test_ServerLobby(ThreadPool *workCrew)
{
	printf("\nTesting ServerLobby:");

	ServerPlayer *hostPlayer = new ServerPlayer();
	ServerLobby *serverLobby = new ServerLobby(workCrew, hostPlayer, 3);

	//Initial info:
	printf("\n TeamSize: %i", serverLobby->teams.MaxPlayers / 2);
	printf("\n MaxPlayers: %i", serverLobby->teams.MaxPlayers);
	printLobbyState(serverLobby, 1);

	//Tests:
	serverLobby->EnterNewPlayer(new ServerPlayer());
	printLobbyState(serverLobby, 2);
	serverLobby->ReadyPlayer(serverLobby->teams.Bench[0]);
	printLobbyState(serverLobby, 3);

	//Testing Complete:
	printf("\nServerLobby testing completed.\nPress Enter key to continue...\n");
	getchar();
}

void ServerTester::printLobbyState(ServerLobby *lobby, int testNumber)
{
	//State info:
	printf("\n ---Lobby State %i---", testNumber);
	printf("\n PlayerCount: %i", lobby->teams.PlayerCount);
	printf("\n Team1: %i", lobby->teams.Team1.size());
	printf("\n Team2: %i", lobby->teams.Team2.size());
	printf("\n Bench: %i", lobby->teams.Bench.size());
	printf("\n ReadyPlayers: %i", lobby->readyPlayers.size());
	printf("\n -------------------");
}