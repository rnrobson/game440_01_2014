#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


#include <vector>
#include "GameModel.h"

class GameManager {
private:
	
	void Init();

public:
	static const unsigned int MAX_GAMES;
	static unsigned int numRunningGames;
	static std::vector<GameModel*> games;
	
	GameManager();
	~GameManager();
};

#endif
