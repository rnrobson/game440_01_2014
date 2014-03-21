#include "GameModel.h"

GameModel::GameModel()
{
	id = 1;
	Init();
}
GameModel::GameModel(unsigned int _id)
{
	id = _id;
	Init();
}
GameModel::~GameModel(){}


void GameModel::UpdateMinions()
{
	//loop trough all minions in the minion list in the game ID
		//check for HP
			//if dead
				//remove MpS bonus from player who had spawned it
				//remove from minion list
		//check if at enemy base
			//if yes:
				//do damage to enemy base
				//kill minion
		//update minion position (pathing)
}
void GameModel::UpdateTowers()
{
		//loop through all towers in the tower list in the gameID
			//find minions within range
			//add them to a queue
					//fire at first minion in queue
			//if minion dies or leave range, remove from queue
}
void GameModel::UpdateProjectiles()
{
	//	//loop through all projectiles in the list in the gameID
	//			//check for collision with minions
	//				//if collided
	//					//damage calculation (gets info from tower that owns projectile)
	//					//despawn projectile
	//		//if projectile reaches max range/timer
	//			//despawn projectile
}
void GameModel::UpdateEconomy()
{
	//	//loop through all players in the gameID
	//		//add MpS value to total mana
}


bool GameModel::CompareGamesByID(GameModel *gameOne, GameModel *gameTwo)
{
	return gameOne->id > gameTwo->id;
}


void GameModel::Init()
{
	minions.reserve(MAX_MINIONS);
	towers.reserve(MAX_TOWERS);
	projectiles.reserve(MAX_PROJECTILES);
	gridSquares.reserve(MAX_GRIDSQUARES);
	teams = new Teams(3);
	team1mps = 0.0f;
	team2mps = 0.0f;
	paused = false;

	darkBase = new PlayerBase(-100, 0, 1000, 20, 30);
	lightBase = new PlayerBase(80, 0, 1000, 20, 30);

	for (int i = 0; i < MAX_MINIONS; i++)
	{
		Minion* minion = new Minion();
		minion->id = i;
		minion->name = "Generic Minion";
		minion->health = 100;
		minion->xPos = 10.0f;
		minion->yPos = 20.0f;
		minion->colWidth = 10;
		minion->colHeight = 20;
		minion->collisionBox->x = (int)round(minion->xPos);// -minion->colWidth / 2;
		minion->collisionBox->y = (int)round(minion->yPos);// -minion->colHeight / 2;
		minion->collisionBox->w = minion->colWidth;
		minion->collisionBox->h = minion->colHeight;

		minion->manaPerSecond = 10.0f;
		minion->armour = 50;
		minion->speed = 3;
		minion->damage = 5;
		minion->researchCost = 50;
		minion->level = 1;
		minion->summonCost = 50;
		minions.push_back(minion);
	}
	for (int i = 0; i < MAX_TOWERS; i++)
	{
		Tower* tower = new Tower();
		tower->name = "Generic Tower";
		tower->id = i;
		tower->range = 20;
		tower->firingRate = 2.0f;
		tower->damage = 3;
		tower->attackType = 'd';
		tower->sellAmount = 50;
		tower->summonCost = 100;
		tower->zoneOfInfluence = 'v';
		tower->level = 1;
		tower->researchCost = 100;
		tower->upgradeCost = 50;
		towers.push_back(tower);

	}
	for (int i = 0; i < MAX_PROJECTILES; i++)
	{
		Projectile* projectile = new Projectile();
		projectile->xPos = 0.0f;
		projectile->yPos = 0.0f;
		projectiles.push_back(projectile);
	}
	for (int i = 0; i < MAX_GRIDSQUARES; i++)
	{
		GridSquare* gridsquare = new GridSquare();
		gridsquare->id = i;
		gridsquare->xPos = i;
		gridsquare->yPos = i;
		gridSquares.push_back(gridsquare);
	}


}