#include "Element.h"

Element::Element() { }

Element::~Element() { }

std::vector<Element>  Element::fetchTypesFromDB() {
	using namespace ManaCraft::Database;

	try {
		Query query = DatabaseAPI::queryDatabase("SELECT * FROM Elements");
		std::vector<Element> elements = std::vector<Element>();

		if (UseQueryResult result = query.use()) {
			Row row;
			std::vector<Element> elements = std::vector<Element>();

			while (row = result.fetch_row()) {
				Element* e = new Element();
				e->type = *(row[TableInfo::Elements::TYPE].c_str());	// I think *(c_str()) is right?
				e->weakness = *(row[TableInfo::Elements::WEAKNESS].c_str());
				e->strength = *(row[TableInfo::Elements::STRENGTH].c_str());

				elements.push_back(*e);
			}
		}
		return elements;
	}
	catch (Exception e) {
		// Eventually DatabaseAPI will throw custom notConnectedException
	}
}
