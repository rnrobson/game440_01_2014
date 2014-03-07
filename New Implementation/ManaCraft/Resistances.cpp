#include "Resistances.h"


Resistances::Resistances(void)
{
}


Resistances::~Resistances(void)
{
}

Resistances* Resistances::buildFromRow(mysqlpp::Row row) {
	using namespace ManaCraft::Database;

	try {
		Resistances* temp = new Resistances();
		int rowID = atoi(row[TableInfo::Resistances::ID].c_str());
		temp->elementID = static_cast<ElementTypes>(rowID);

		temp->windResistance = atoi(row[TableInfo::Resistances::WIND_RESISTANCE].c_str());
		temp->fireResistance = atoi(row[TableInfo::Resistances::FIRE_RESISTANCE].c_str());
		temp->waterResistance = atoi(row[TableInfo::Resistances::WATER_RESISTANCE].c_str());
		temp->earthResistance = atoi(row[TableInfo::Resistances::EARTH_RESISTANCE].c_str());
		temp->normalResistance = atoi(row[TableInfo::Resistances::NORM_RESISTANCE].c_str());
		return temp;
	}
	catch (Exception e) {
		// If anything this would be some sort of access violation
	}

	return nullptr;
}

std::vector<Resistances*> Resistances::fetchAllFromDB() {
	using namespace ManaCraft::Database;

	try {
		std::cout << "Querying Resistances Table\n";

		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "SELECT * FROM Resistances";

		std::vector<Resistances*> resistances = std::vector<Resistances*>();

		if (UseQueryResult result = query.use()) {
			std::cout << "Obtained Result from Resistances query\n";
			Row row;

			while (row = result.fetch_row()) {
				Resistances* e = buildFromRow(row);
				resistances.push_back(e);
			}
		}
		return resistances;
	}
	catch (Exception e) {
		// eventually DatabaseAPI::queryDatabase will throw notConnectedException of some sort
	}
}