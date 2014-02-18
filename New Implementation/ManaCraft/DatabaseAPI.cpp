#include "DatabaseAPI.h"

using namespace ManaCraft::Database;

DatabaseAPI::DatabaseAPI() {
	conn = Connection(false);
}

DatabaseAPI::~DatabaseAPI() {
	disconnectFromDatabase();
}

bool DatabaseAPI::connectToDatabase(const std::string& db_Name, const std::string& server, const std::string& login, const std::string& password) {
	return conn.connect(db_Name.c_str(), server.c_str(), login.c_str(), password.c_str());
}

void DatabaseAPI::disconnectFromDatabase() {
	if (conn.connected()) {
		conn.disconnect();
	}
}

void  DatabaseAPI::getTowerInfo(const TowerTypes tower) {
}

void  DatabaseAPI::getAllTowerInfo() { }


void  DatabaseAPI::getMinionInfo(const MinionTypes minion) { }

void  DatabaseAPI::getAllMinionInfo() { }


void  DatabaseAPI::getElementInfo(const ElementTypes element) { }

std::vector<Element>  DatabaseAPI::getAllElementInfo() {
	// create helper method for this probably, it'll be repeated a lot

	if (conn.connected()) {
		try {
			Query query = conn.query("SELECT * FROM Elements");
			if (UseQueryResult result = query.use()) {
				Row row;
				std::vector<Element> elements = std::vector<Element>();	// do something with this vector
				
				while (row = result.fetch_row()) {
					Element* e = new Element();
					e->type = *(row[TableInfo::Elements::TYPE].c_str());	// I think *(c_str()) is right?
					e->weakness = *(row[TableInfo::Elements::WEAKNESS].c_str());
					e->strength = *(row[TableInfo::Elements::STRENGTH].c_str());

					elements.push_back(*e);
				}
				return elements;
			}
		}
		catch (Exception e) {
			throw e;
		}
	}
	else {
		// throw custom exception?
	}
}

void  DatabaseAPI::getResistanceInfo(const ElementTypes element) { }

void  DatabaseAPI::getAllResistanceInfo() { }


void  DatabaseAPI::saveGame() { }

void  DatabaseAPI::getSaveGame(const unsigned int& saveID) { }

void  DatabaseAPI::getPlayerInfo(const std::string& name) { }