#include "Element.h"

Element::Element() { }

Element::~Element() { }

Element* Element::buildFromRow(mysqlpp::Row row) {
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

std::vector<Element> Element::fetchAllFromDB() {
	using namespace ManaCraft::Database;

	try {
		Query query = DatabaseAPI::queryDatabase("SELECT * FROM Elements");
		std::vector<Element> elements = std::vector<Element>();
		
		if (UseQueryResult result = query.use()) {
			Row row;
		
			while (row = result.fetch_row()) {
				Element* e = buildFromRow(row);
				elements.push_back(*e);
			}
		}
		return elements;
	}
	catch (Exception e) {
		// eventually DatabaseAPI::queryDatabase will throw notConnectedException of some sort
	}
}