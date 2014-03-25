#include "Tower.h"


Tower::Tower(void)
{
	timer = 0;
}


Tower::~Tower(void)
{
}

Tower* Tower::buildFromRow(mysqlpp::Row& row) {
	using namespace ManaCraft::Database;

	Tower* temp = new Tower();

	try {
		
		int rowID = atoi(row[TableInfo::Towers::ID].c_str());
		temp->ID = static_cast<TowerTypes>(rowID);

		int elementId = atoi(row[TableInfo::Towers::ELEMENT].c_str());
		temp->elementID = static_cast<ElementTypes>(elementId);

		temp->name = std::string(row[TableInfo::Towers::NAME].c_str());
		temp->attackType = std::string(row[TableInfo::Towers::ATTACK_TYPE].c_str());

		temp->damage = atoi(row[TableInfo::Towers::DAMAGE].c_str());
		temp->range = atoi(row[TableInfo::Towers::RANGE].c_str());
		temp->firingRate = (float) atof(row[TableInfo::Towers::FIRING_RATE].c_str());
		temp->cost = atoi(row[TableInfo::Towers::COST].c_str());
		return temp;
	}
	catch (mysqlpp::BadConversion e) {
		std::cout << e.what() << "\n";
	}
	catch (mysqlpp::BadIndex e) {
		std::cout << e.what() << "\n";
	}

	delete temp;
	return nullptr;
}

std::vector<Tower*> Tower::fetchAllFromDB() {
	using namespace ManaCraft::Database;

	try {
		std::cout << "Querying Tower Table\n";

		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "SELECT * FROM Towers";

		std::vector<Tower*> towers = std::vector<Tower*>();

		if (UseQueryResult result = query.use()) {
			std::cout << "Obtained Result from Tower query\n";
			Row row;

			while (row = result.fetch_row()) {
				Tower* e = buildFromRow(row);
				towers.push_back(e);
			}
		}
		return towers;
	}
	catch (Exception e) {
		throw e;
	}

	return std::vector<Tower*>();
}

void Tower::FireAtMinion(Minion* minion)
{
	//check if reload timer is up
		//create a projectile and launch it towers minion

	//calculating reload timer based on firing rate
	Uint32 reloadTimer = (uint)round(1000*firingRate);
	if (timer >= reloadTimer)
	{
		//fire

		timer = 0;
	}
	
}