#include "TestLocalDB.h"

using namespace ManaCraft;

unsigned int successes = 0;
unsigned int failures = 0;

ManaCraft::Testbed::TestLocalDB::TestLocalDB(const unsigned int testCount) : Test(testCount)
{

}

void ManaCraft::Testbed::TestLocalDB::Run() 
{
	int numTests = 2; // gotta change this if you add tests

	for (unsigned int i = 0; i < mTestCount; ++i) 
	{
		RunInitTest();

		//GameModel* testGameModel = new GameModel();
		//next step. make a test game and save it
		//then. unload it.
		//then. load it from the DB and add to the Server's game list
		//then unload it

		RunDestroyTest();


		
		std::cout << "[LocalDB]: Test " << (i + 1) << " complete. Expecting " << numTests << " Success. Success: " << successes << "\tFailure: " << failures << std::endl;
		successes = failures = 0; // reset all test counts after they've been reported
	}
	
}

void ManaCraft::Testbed::TestLocalDB::RunInitTest()
{
	testLocalDB = new LocalDB();
	ManaCraft::Database::DatabaseAPI* dbConnection = testLocalDB->getDbConnection();
	if (dbConnection->isConnected)
	{
		++successes;
	}
}

void ManaCraft::Testbed::TestLocalDB::RunDestroyTest()
{
	delete testLocalDB;
	if (testLocalDB)
	{
		++successes;
	}
}

void ManaCraft::Testbed::TestLocalDB::RunSaveGameTest()
{
	//waiting on databaseAPI
}

void ManaCraft::Testbed::TestLocalDB::RunLoadGameTest()
{
	//waiting on databaseAPI
}

void ManaCraft::Testbed::TestLocalDB::RunUnLoadGameTest()
{
	//waiting on databaseAPI
}

