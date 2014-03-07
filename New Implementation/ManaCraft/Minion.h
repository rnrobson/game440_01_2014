#pragma once
#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"
#include "Entity.h"
#include "Resistances.h"

class Minion : public Entity
{
private:
	static Minion* buildFromRow(mysqlpp::Row row);

public:
	ManaCraft::Database::MinionTypes ID;

	
	float xPos;
	float yPos;
	float manaPerSecond;
	unsigned int health;
	unsigned int armour;
	unsigned int speed;

	Minion(void);
	~Minion(void);

	static std::vector<Minion*> fetchAllFromDB();
};

