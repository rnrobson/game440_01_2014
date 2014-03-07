#include "GameManager.h"


/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
std::vector<GameModel*> GameManager::games;
const int GameManager::MAX_GAMES = 10;

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
