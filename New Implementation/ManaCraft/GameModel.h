#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "DatabaseAPI.h"
#include "Teams.h"
#include "Minion.h"
#include "Tower.h"
#include "Projectile.h"
#include "GridSquare.h"
#include "PlayerBase.h"

class GameModel{

public:
	unsigned int id;
	bool paused;
	ServerPlayer* host;
	Teams* teams;
	float team1mps;
	float team2mps;

	vector<Minion*> minions;
	vector<Tower*> towers;
	vector<Projectile*> projectiles;
	vector<GridSquare*> gridSquares;

	PlayerBase* darkBase;
	PlayerBase* lightBase;

	static bool CompareGamesByID(GameModel *gameOne, GameModel *gameTwo);
	static GameModel* LoadGameByID(unsigned int _id);
	static void LoadNextID();

	void SaveGame();
	void DeleteGame();

	void UpdateMinions();
	void UpdateTowers(Uint32 dt);
	void UpdateProjectiles();
	void UpdateEconomy(Uint32 dt);

	GameModel();
	GameModel(unsigned int _id);
	~GameModel();

private:
	static int nextID;

	const int MAX_MINIONS = 500;
	const int MAX_TOWERS = 100;
	const int MAX_PROJECTILES = 600;
	const int MAX_GRIDSQUARES = 128;
	const float MAX_BASE_HP = 300.0f;

	void Init();
	static int GetNextID();
};


#endif

