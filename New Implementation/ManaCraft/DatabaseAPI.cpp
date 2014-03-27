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
	
	try{
		conn->connect(db_Name.c_str(), server.c_str(), login.c_str(), password.c_str());
	}
	catch (mysqlpp::ConnectionFailed e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}

void DatabaseAPI::disconnectFromDatabase() {
	if (conn->connected()) {
		conn->disconnect();
	}
	else {
		std::cout << "A database connection is not currently established.";
	}
}

Query DatabaseAPI::getQuery() {
	if (conn->connected()) {
		try {
			return conn->query();
		}
		catch (mysqlpp::BadQuery e) {
			std::cout << e.what() << "\n";
		}
	}

	return NULL;
}

Query DatabaseAPI::queryDatabase(const std::string& queryStr) {
	if (conn->connected()) {
		try {
			return conn->query(queryStr);
		}
		catch (mysqlpp::BadQuery e) {
			std::cout << e.what() << "\n";
		}
	}

	return NULL;
}

