#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


#include <vector>
#include "GameModel.h"

class GameManager {
private:
	
	void Init();

public:
	static const unsigned int MAX_GAMES;
	
	static std::vector<GameModel*> games;
	
	static GameModel* FindGame(uint _gameID);
	
	GameManager();
	~GameManager();
};

#endif
