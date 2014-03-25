#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"

class Element {
private:
	static Element* buildFromRow(mysqlpp::Row& row);

public:
	ManaCraft::Database::ElementTypes ID;

	std::string type;
	std::string weakness;
	std::string strength;

	Element();
	~Element();

	static std::vector<Element*> fetchAllFromDB();
};

#endif
