#include "DatabaseAPI.h"

using namespace ManaCraft::Database;

Connection* DatabaseAPI::conn = new Connection(false);

std::string DatabaseAPI::db_Name = "Manacraft";
std::string DatabaseAPI::server = "198.167.139.145";
std::string DatabaseAPI::login = "manacraft";
std::string DatabaseAPI::password = "manacraft2014";

DatabaseAPI::~DatabaseAPI() {	// I suppose this unneccessary if it's private and everythings static?
	disconnectFromDatabase();
	delete conn;
	conn = NULL;
}

void DatabaseAPI::setConnectionParams(const std::string& _db_Name, const std::string& _server, const std::string& _login, const std::string& _password) {
	db_Name = _db_Name;
	server = _server;
	login = _login;
	password = _password;
}

bool DatabaseAPI::isConnected() {
	return conn->connected();
}

bool DatabaseAPI::connectToDatabase() {
	if (conn->connected()) {
		return true;
	}
	return conn->connect(db_Name.c_str(), server.c_str(), login.c_str(), password.c_str());
}

void DatabaseAPI::disconnectFromDatabase() {
	if (conn->connected()) {
		conn->disconnect();
	}
}

Query DatabaseAPI::getQuery() {
	if (conn->connected()) {
		try {
			return conn->query();
		}
		catch (Exception e) {
			throw e;
		}
	}
	else {
		// throw custom exception?
	}
}

Query DatabaseAPI::queryDatabase(const std::string& queryStr) {
	if (conn->connected()) {
		try {
			return conn->query(queryStr);
		}
		catch (Exception e) {
			throw e;
		}
	}
	else {
		// throw custom exception?
	}
}

void DatabaseAPI::getTowerInfo(const TowerTypes tower) { }

void DatabaseAPI::getAllTowerInfo() { }


void DatabaseAPI::getMinionInfo(const MinionTypes minion) { }

void DatabaseAPI::getAllMinionInfo() { }


//void DatabaseAPI::getElementInfo(const ElementTypes element) { }
//
//std::vector<Element> DatabaseAPI::getAllElementInfo() {
//	try {
//		Query query = DatabaseAPI::queryDatabase("SELECT * FROM Elements");
//		std::vector<Element> elements = std::vector<Element>();
//
//		if (UseQueryResult result = query.use()) {
//			Row row;
//
//			while (row = result.fetch_row()) {
//				Element* e = new Element();// Element::loadFromDB(row);
//				elements.push_back(*e);
//			}
//		}
//		return elements;
//	}
//	catch (Exception e) {
//		// eventually DatabaseAPI::queryDatabase will throw notConnectedException of some sort
//	}
//	
//}

void DatabaseAPI::getResistanceInfo(const ElementTypes element) { }

void DatabaseAPI::getAllResistanceInfo() { }


void DatabaseAPI::saveGame() { }

void DatabaseAPI::getSaveGame(const unsigned int& saveID) { }

void DatabaseAPI::getPlayerInfo(const std::string& name) { }