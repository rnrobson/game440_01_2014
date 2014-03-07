#pragma once
#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"
class Resistances
{
private:
	static Resistances* buildFromRow(mysqlpp::Row row);

public:
	ManaCraft::Database::ElementTypes elementID;

	int windResistance;
	int fireResistance;
	int waterResistance;
	int earthResistance;
	int normalResistance;

	Resistances(void);
	~Resistances(void);

	static std::vector<Resistances*> fetchAllFromDB();
};

