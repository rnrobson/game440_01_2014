#include "Minion.h"


Minion::Minion(void)
{
}


Minion::~Minion(void)
{
}

Minion* Minion::buildFromRow(mysqlpp::Row row) {
	using namespace ManaCraft::Database;

	try {
		//Create temporary minion pointer
		Minion* temp = new Minion();

		//Get Minion ID and cast it to MinionType
		int rowID = atoi(row[TableInfo::Minions::ID].c_str());
		temp->ID = static_cast<MinionTypes>(rowID);

		//Get Element ID and cast it to ElementType
		int elementId = atoi(row[TableInfo::Minions::ELEMENT].c_str());
		temp->elementID = static_cast<ElementTypes>(elementId);

		//Get name, converts it from char* to string
		temp->name = std::string(row[TableInfo::Minions::NAME].c_str());

		//Load rest of information
		temp->level = atoi(row[TableInfo::Minions::LEVEL].c_str());
		temp->health = atoi(row[TableInfo::Minions::HEALTH].c_str());
		temp->damage = atoi(row[TableInfo::Minions::DAMAGE].c_str());
		temp->armour = atoi(row[TableInfo::Minions::ARMOUR].c_str());
		temp->speed = atoi(row[TableInfo::Minions::SPEED].c_str());
		temp->manaPerSecond = (float) atof(row[TableInfo::Minions::MPS].c_str());
		temp->cost = atoi(row[TableInfo::Minions::COST].c_str());

		return temp;
	}
	catch (Exception e) {
		// If anything this would be some sort of access violation
	}

	return nullptr;
}

std::vector<Minion*> Minion::fetchAllFromDB() {
	using namespace ManaCraft::Database;

	try {
		std::cout << "Querying Minion Table\n";

		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "SELECT * FROM Minions";

		std::vector<Minion*> minions = std::vector<Minion*>();

		if (UseQueryResult result = query.use()) {
			std::cout << "Obtained Result from Minion query\n";
			Row row;
			
			while (row = result.fetch_row()) {
				Minion* e = buildFromRow(row);
				minions.push_back(e);
			}
		}
		return minions;
	}
	catch (Exception e) {
		// eventually DatabaseAPI::queryDatabase will throw notConnectedException of some sort
		std::cout << e.what() << "\n";
	}
}