#include "TestDatabase.h"

using namespace ManaCraft::Database;

void TestDatabase::resetTestCounts() {
	totalSuccesses += testSuccesses;
	totalFailures += testFailures;

	testSuccesses = testFailures = 0;
}

void TestDatabase::runTests() {

	std::cout << "Database tests complete. Successes: " << totalSuccesses << "\tFailures: " << totalFailures;
	totalSuccesses = totalFailures = testSuccesses = testFailures = 0; // reset all test counts after they've been reported
}

void TestDatabase::testConnection() {
	if (DatabaseAPI::connectToDatabase()) {
		++testSuccesses;
	}
	else ++testFailures;

	DatabaseAPI::disconnectFromDatabase();
	if (DatabaseAPI::isConnected()) {
		++testSuccesses;
	}
	else ++testFailures;

	std::cout << "Connection tests complete. Successes: " << testSuccesses << "\tFailures: " << testFailures;
	resetTestCounts();
}