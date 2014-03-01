#include "DatabaseAPI.h"

using namespace ManaCraft::Database;

Connection* DatabaseAPI::conn = new Connection(false);

std::string DatabaseAPI::_db_Name = "Manacraft";
std::string DatabaseAPI::_server = "198.167.139.145";
std::string DatabaseAPI::_login = "manacraft";
std::string DatabaseAPI::_password = "manacraft2014";

DatabaseAPI::~DatabaseAPI() {	// I suppose this unneccessary if it's private and everythings static?
	disconnectFromDatabase();
	delete conn;
	conn = NULL;
}

void DatabaseAPI::setConnectionParams(const std::string& db_Name, const std::string& server, const std::string& login, const std::string& password) {
	_db_Name = db_Name;
	_server = server;
	_login = login;
	_password = password;
}

bool DatabaseAPI::isConnected() {
	return conn->connected();
}

bool DatabaseAPI::connectToDatabase() {
	if (conn->connected()) {
		return true;
	}
	return conn->connect(_db_Name.c_str(), _server.c_str(), _login.c_str(), _password.c_str());
}

void DatabaseAPI::disconnectFromDatabase() {
	if (conn->connected()) {
		conn->disconnect();
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


void DatabaseAPI::getElementInfo(const ElementTypes element) { }

void DatabaseAPI::getAllElementInfo() { }

void DatabaseAPI::getResistanceInfo(const ElementTypes element) { }

void DatabaseAPI::getAllResistanceInfo() { }


void DatabaseAPI::saveGame() { }

void DatabaseAPI::getSaveGame(const unsigned int& saveID) { }

void DatabaseAPI::getPlayerInfo(const std::string& name) { }