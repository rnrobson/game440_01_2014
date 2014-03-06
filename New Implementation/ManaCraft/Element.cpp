#include "Element.h"

using namespace ManaCraft::DataStructures;

Element::Element() { }

Element::~Element() { }

Element* Element::loadFromDB(ManaCraft::Database::Row row) {
	using namespace ManaCraft::Database;

	try {
		//if (UseQueryResult result = query.use()) {
			//Row row;

			//while (row = result.fetch_row()) {

		Element* temp = new Element();
		temp->type = *(row[TableInfo::Elements::TYPE].c_str());	// I think *(c_str()) is right?
		temp->weakness = *(row[TableInfo::Elements::WEAKNESS].c_str());
		temp->strength = *(row[TableInfo::Elements::STRENGTH].c_str());

			//}
		
		
		return temp;
	}
	catch (Exception e) {
		// Eventually DatabaseAPI will throw custom notConnectedException
	}

	return nullptr;
}
