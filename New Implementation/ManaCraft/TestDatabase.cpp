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

	DatabaseAPI::disconnectFromDatabase();

	std::cout << "Query tests complete. Successes: " << testSuccesses << "\tFailures: " << testFailures << std::endl;
	resetTestCounts();
}