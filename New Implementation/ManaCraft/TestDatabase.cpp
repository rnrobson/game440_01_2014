#include "TestDatabase.h"

using namespace ManaCraft::Database;

unsigned int TestDatabase::testSuccesses = 0;
unsigned int TestDatabase::testFailures = 0;
unsigned int TestDatabase::totalSuccesses = 0;
unsigned int TestDatabase::totalFailures = 0;

void TestDatabase::resetTestCounts() {
	totalSuccesses += testSuccesses;
	totalFailures += testFailures;

	testSuccesses = testFailures = 0;
}

void TestDatabase::runTests() {
	testConnection();
	testQuery();
	testLoadMinions();
	testLoadTowers();
	testLoadElements();
	testLoadResistances();
	//testSaveLoadGame();

	//testDelete();
	testSave();

	DatabaseAPI::disconnectFromDatabase();

	std::cout << "Database tests complete. Successes: " << totalSuccesses << "\tFailures: " << totalFailures << std::endl;
	totalSuccesses = totalFailures = testSuccesses = testFailures = 0; // reset all test counts after they've been reported
}

void TestDatabase::testConnection() {
	if (DatabaseAPI::connectToDatabase()) {
		++testSuccesses;
	}
	else ++testFailures;

	DatabaseAPI::disconnectFromDatabase();
	if (!DatabaseAPI::isConnected()) {
		++testSuccesses;
	}
	else ++testFailures;

	std::cout << "Connection tests complete. Successes: " << testSuccesses << "\tFailures: " << testFailures << std::endl;
	resetTestCounts();
}

void TestDatabase::testQuery() {
	DatabaseAPI::connectToDatabase();

	Query query = DatabaseAPI::getQuery();

	try {																		// No errors on CREATE TABLE
		query << "CREATE TABLE testTable ( num int, str varchar(4) )";
		query.execute();
		++testSuccesses;
	}
	catch (Exception e) {
		++testFailures;
	}

	try {																		// No errors on INSERT
		query.clear();
		query << "INSERT INTO testTable VALUES (" << mysqlpp::quote << 1 << ", " << mysqlpp::quote << "one" << ")";
		query.execute();
		++testSuccesses;
	}
	catch (Exception e) {
		++testFailures;
	}

	try {																		// No errors on SELECT
		query.clear();
		query << "SELECT * FROM testTable";
		UseQueryResult result = query.use();
		Row row;

		if (row = result.fetch_row()) {											// Row was inserted
			++testSuccesses;

			if (row[0] == "1") {												// Proper int inserted
				++testSuccesses;
			}
			else ++testFailures;

			if (row[1] == "one") {												// Proper string inserted
				++testSuccesses;
			}
			else ++testFailures;
		}
		else ++testFailures;
	}
	catch (Exception e) {
		++testFailures;
		std::cout << "EXC" << std::endl;
	}

	try {																		// No errors on DROP TABLE
		query.clear();
		query << "DROP TABLE testTable";
		query.execute();
		++testSuccesses;
	}
	catch (Exception e) {
		++testFailures;
	}

	std::cout << "Query tests complete. Successes: " << testSuccesses << "\tFailures: " << testFailures << std::endl;
	resetTestCounts();
}

void TestDatabase::testLoadMinions()
{
	DatabaseAPI::connectToDatabase();
	
	std::vector<Minion*> minions = Minion::fetchAllFromDB();

	if (minions.size() <= 0)
	{
		std::cout << "Vector of Minions empty!\n";
	}
	else if (!DatabaseAPI::isConnected())
	{
		std::cout << "Database not Connected!\n";
	}
	else
	{
		std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < minions.size(); ++i)
		{
			
			std::cout << "ID: " << minions[i]->ID;
			std::cout << ", Name: " << minions[i]->name;
			std::cout << ", Level: " << minions[i]->level;
			std::cout << ", Health: " << minions[i]->health;
			std::cout << ", Damage: " << minions[i]->damage;
			std::cout << ", Armour: " << minions[i]->armour;
			std::cout << ", Speed: " << minions[i]->speed;
			std::cout << ", MPS: " << minions[i]->manaPerSecond;
			std::cout << ", Cost: " << minions[i]->cost;
			std::cout << "\n\n";
		}
		std::cout << "\n-------------------------------------------------\n";
	}
}

void TestDatabase::testLoadTowers()
{
	DatabaseAPI::connectToDatabase();

	std::vector<Tower*> towers = Tower::fetchAllFromDB();

	if (towers.size() <= 0)
	{
		std::cout << "Vector of Towers empty!\n";
	}
	else if (!DatabaseAPI::isConnected())
	{
		std::cout << "Database not Connected!\n";
	}
	else
	{
		std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < towers.size(); ++i)
		{

			std::cout << "ID: " << towers[i]->ID;
			std::cout << ", ElementID: " << towers[i]->elementID;
			std::cout << ", Name: " << towers[i]->name;
			std::cout << ", AtkType: " << towers[i]->attackType;
			std::cout << ", Damage: " << towers[i]->damage;
			std::cout << ", Range: " << towers[i]->range;
			std::cout << ", FireRate: " << towers[i]->firingRate;
			std::cout << ", Cost: " << towers[i]->cost;
			std::cout << "\n\n";
		}
		std::cout << "\n-------------------------------------------------\n";
	}
}

void TestDatabase::testLoadElements()
{
	DatabaseAPI::connectToDatabase();

	std::vector<Element*> elements = Element::fetchAllFromDB();

	if (elements.size() <= 0)
	{
		std::cout << "Vector of Minions empty!\n";
	}
	else if (!DatabaseAPI::isConnected())
	{
		std::cout << "Database not Connected!\n";
	}
	else
	{
		std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < elements.size(); ++i)
		{

			std::cout << "ID: " << elements[i]->ID;
			std::cout << ", Type: " << elements[i]->type;
			std::cout << ", Weakness: " << elements[i]->weakness;
			std::cout << ", Strength: " << elements[i]->strength;
			std::cout << "\n\n";
		}
		std::cout << "\n-------------------------------------------------\n";
	}
}

void TestDatabase::testLoadResistances()
{
	DatabaseAPI::connectToDatabase();

	std::vector<Resistances*> resistances = Resistances::fetchAllFromDB();

	if (resistances.size() <= 0)
	{
		std::cout << "Vector of Minions empty!\n";
	}
	else if (!DatabaseAPI::isConnected())
	{
		std::cout << "Database not Connected!\n";
	}
	else
	{
		std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < resistances.size(); ++i)
		{

			std::cout << "ElementID: " << resistances[i]->elementID;
			std::cout << ", Wind: " << resistances[i]->windResistance;
			std::cout << ", Fire: " << resistances[i]->fireResistance;
			std::cout << ", Water: " << resistances[i]->waterResistance;
			std::cout << ", Earth: " << resistances[i]->earthResistance;
			std::cout << ", Normal: " << resistances[i]->normalResistance;
			std::cout << "\n\n";
		}
		std::cout << "\n-------------------------------------------------\n";
	}
}

void TestDatabase::testSaveLoadGame() {
	DatabaseAPI::connectToDatabase();
	int id = 23;

	// SAVE HERE

	// WIP
	
	GameModel* g = GameModel::LoadGameByID(id);
	if (g->id == id) {
		std::cout << "GameModel Success!" << std::endl;
		std::cout << "Team 1 ID: " << g->teams->team1ID << std::endl;
		for (ServerPlayer* p : g->teams->Team1)
		{
			std::cout << "\tPlayer " << p->id << "Loaded" << std::endl;
		}

		std::cout << "\nTeam 2 ID: " << g->teams->team2ID << std::endl;
		for (ServerPlayer* p : g->teams->Team2)
		{
			std::cout << "\tPlayer " << p->id << "Loaded" << std::endl;
		}
	}
	else {
		std::cout << "GameModel Failure!" << std::endl;
	}

	delete g;	// Make sure other tests delete results
}

void TestDatabase::testDelete()
{
	DatabaseAPI::connectToDatabase();

	Query query = DatabaseAPI::getQuery();
	query.clear();
	query << "DELETE FROM Test_Table WHERE ID = 1";
	query.execute();

	query = DatabaseAPI::getQuery();
	query.clear();
	query << "DELETE FROM Test_Table WHERE ID = 2";
	query.execute();
}

void TestDatabase::testSave()
{
	DatabaseAPI::connectToDatabase();

	GameModel* game = new GameModel(8008);
	game->teams->team1ID = 666;
	game->teams->team2ID = 999;

	ServerPlayer* player1 = new ServerPlayer(220);
	ServerPlayer* player2 = new ServerPlayer(225);
	game->teams->Team1.push_back(player1);
	game->teams->Team2.push_back(player2);

	game->SaveGame();

	game->teams->Team1.clear();
	game->teams->Team2.clear();

	delete player1;
	delete player2;
	delete game;


}