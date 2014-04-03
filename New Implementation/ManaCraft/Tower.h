#pragma once
#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"
#include "Entity.h"
#include "InfluenceSquare.h"
#include "Minion.h"
#include <list>


class Tower : public Entity
{
private:
	static Tower* buildFromRow(mysqlpp::Row& row);

public:
	int xPos;
	int yPos;
	ManaCraft::Database::TowerTypes towerType;
	std::string attackType;
	InfluenceSquare* infSquare;
	unsigned int range;
	float firingRate;
	unsigned int sellAmount;
	char zoneOfInfluence;
	std::list<Minion*> targetList;
	Uint32 timer; //timer used to check if the tower can fire

	Tower(void);
	~Tower(void);

	static std::vector<Tower*> fetchAllFromDB();

	void FireAtMinion(Minion* minion);
};

