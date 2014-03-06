#pragma once

#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"

class Element {
public:
	ManaCraft::Database::ElementTypes id;

	std::string type;
	std::string weakness;
	std::string strength;

	Element();
	~Element();

	static Element* loadFromDB(mysqlpp::Row row);
};
