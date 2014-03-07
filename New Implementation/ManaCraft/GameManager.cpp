#include "GameManager.h"


std::vector<GameModel*> GameManager::games;
const unsigned int GameManager::MAX_GAMES = 10;
unsigned int GameManager::numRunningGames = 0;

GameManager::GameManager()
{
	Init();
}

GameManager::~GameManager(){}

void GameManager::Init()
{
	//setting limit of running games
	games.reserve(MAX_GAMES);

}
