#include "Element.h"

Element::Element() { }

Element::~Element() { }

Element* Element::loadFromDB(mysqlpp::Row row) {
	using namespace ManaCraft::Database;

	try {
		Element* temp = new Element();
		temp->type = *(row[TableInfo::Elements::TYPE].c_str());
		temp->weakness = *(row[TableInfo::Elements::WEAKNESS].c_str());
		temp->strength = *(row[TableInfo::Elements::STRENGTH].c_str());
		
		return temp;
	}
	catch (Exception e) {
		// If anything this would be some sort of access violation
	}

	return nullptr;
}
