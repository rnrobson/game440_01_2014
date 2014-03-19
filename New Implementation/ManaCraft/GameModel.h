#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "Teams.h"
#include "Minion.h"
#include "Tower.h"
#include "Projectile.h"
#include "GridSquare.h"
#include "PlayerBase.h"

struct GameModel{

public:

	const int MAX_MINIONS = 500;
	const int MAX_TOWERS = 100;
	const int MAX_PROJECTILES = 600;
	const int MAX_GRIDSQUARES = 128;
	const float MAX_BASE_HP = 300.0f;

	unsigned int id;

	bool paused;

	Teams* teams;
	float team1mps;
	float team2mps;

	vector<Minion*> minions;
	vector<Tower*> towers;
	vector<Projectile*> projectiles;
	vector<GridSquare*> gridSquares;

	PlayerBase* darkBase;
	PlayerBase* lightBase;

	GameModel()
	{
		id = 1;
		Init();
	}
	GameModel(unsigned int _id)
	{
		id = _id;
		Init();
	}
	~GameModel(){}
	void Init()
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

	static bool GameModel::CompareGamesByID(GameModel *gameOne, GameModel *gameTwo)
	{
		return gameOne->id > gameTwo->id;
	}
};


#endif

