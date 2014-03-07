#pragma once
#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"
#include "Entity.h"
#include "InfluenceSquare.h"

class Tower : public Entity
{
private:
	InfluenceSquare* infSquare;
	static Tower* buildFromRow(mysqlpp::Row row);

public:
	ManaCraft::Database::TowerTypes ID;
	std::string attackType;

	unsigned int range;
	float firingRate;
	unsigned int sellAmount;
	char zoneOfInfluence;

	Tower(void);
	~Tower(void);

	static std::vector<Tower*> fetchAllFromDB();
};

