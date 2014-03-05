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

	bool active;
	bool paused;

	Teams* teams;
	float team1mps;
	float team2mps;

	vector<Minion> minions;
	vector<Tower> towers;
	vector<Projectile> projectiles;
	vector<GridSquare> gridSquares;

	float base1HP;
	float base2HP;

	GameModel()
	{
	
	}
	~GameModel(){}

};


#endif

