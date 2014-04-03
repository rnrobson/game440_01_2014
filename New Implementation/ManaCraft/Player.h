#pragma once

#include <vector>

#include "Minion.h"
#include "Tower.h"
#include "InfluenceSquare.h"
#include "DatabaseAPI.h"

using namespace std;

class Player {
private:
	vector<InfluenceSquare*> infSquares;	//the diagram says Player has an Influence Square
											//I'm guessing it's supposed to be a list of Influence Squares?
public:
	uint id;
	uint mana;
	uint totalManaPerSecond;
	vector<Player*> *Team;

	vector<Tower*> towers;
	vector<Minion*> minions;

	Player();
	Player(uint _id);
	~Player();

	static Player* LoadPlayerByID(int _id);
	void SavePlayer(unsigned int TeamID);
};

