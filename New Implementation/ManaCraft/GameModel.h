#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "Teams.h"
#include "Minion.h"
#include "Tower.h"
#include "Projectile.h"
#include "GridSquare.h"


struct GameModel{

public:

	const int MAX_MINIONS = 500;
	const int MAX_TOWERS = 100;
	const int MAX_PROJECTILES = 600;
	const int MAX_GRIDSQUARES = 128;
	const int MAX_BASE_HP = 300;

	unsigned int id;

	bool active;
	bool paused;

	Teams* teams;
	float team1mps;
	float team2mps;

	vector<Minion*> minions;
	vector<Tower*> towers;
	vector<Projectile*> projectiles;
	vector<GridSquare*> gridSquares;

	float base1HP;
	float base2HP;

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
		active = false;
		paused = false;
		base1HP = MAX_BASE_HP;
		base2HP = MAX_BASE_HP;
		for (size_t i = 0; i < MAX_MINIONS; i++)
		{
			Minion* minion = new Minion();
			minion->health = 100;
			minion->xPos = 10;
			minion->yPos = 20;
			minion->manaPerSecond = 10;
			minion->armour = 50;
			minion->speed = 3;
			minion->damage = 5.0f;
			minion->researchCost = 50;
			minion->level = 1;
			minion->name = "Generic Minion";
			minion->summonCost = 50;
			minions.push_back(minion);
		}
		for (size_t i = 0; i < MAX_TOWERS; i++)
		{
			Tower* tower = new Tower();
			tower->range = 20;
			tower->firingRate = 2.0f;
			tower->damage = 3.0f;
			tower->damagePerSecond = 6.0f;
			tower->attackType = 'd';
			tower->sellAmount = 50;
			tower->summonCost = 100;
			tower->zoneOfInfluence = 'v';
			tower->level = 1;
			tower->name = "generic tower";
			tower->researchCost = 100;
			tower->upgradeCost = 50;
			towers.push_back(tower);

		}
		for (size_t i = 0; i < MAX_PROJECTILES; i++)
		{
			Projectile* projectile = new Projectile();
			projectile->xPos = 0.0f;
			projectile->yPos = 0.0f;
			projectiles.push_back(projectile);
		}
		for (size_t i = 0; i < MAX_GRIDSQUARES; i++)
		{
			GridSquare* gridsquare = new GridSquare();
			gridsquare->id = i;
			gridsquare->xPos = i;
			gridsquare->yPos = i;
			gridSquares.push_back(gridsquare);
		}


	}
};


#endif

