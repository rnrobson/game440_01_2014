#pragma once

#include <vector>
#include "DatabaseAPI.h"

class Element {
public:
	char type;
	char weakness;
	char strength;

	Element();
	~Element();

	std::vector<Element> fetchTypesFromDB();
};

