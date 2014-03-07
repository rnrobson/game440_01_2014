#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


#include <vector>
#include "GameModel.h"

class GameManager {
private:

	unsigned int numRunningGames = 0;
	
	void Init();


public:
	static const int MAX_GAMES;
	static std::vector<GameModel*> games;
	GameManager();
	GameManager(unsigned int id);
	~GameManager();

};

#endif
