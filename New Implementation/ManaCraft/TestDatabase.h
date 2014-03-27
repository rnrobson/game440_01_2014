#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H

#include <iostream>
#include "DatabaseAPI.h"
#include "Minion.h"
#include "Tower.h"
#include "Element.h"
#include "Resistances.h"
#include "GameModel.h"

namespace ManaCraft {
	namespace Database {
		class TestDatabase {
		private:
			static unsigned int testSuccesses, testFailures;
			static unsigned int totalSuccesses, totalFailures;

			/// <summary>Resets success and failure counts for the last test.
			/// <para>Also updates total successes and failures.</para>
			/// <para>Call this function after every test.</para>
			/// </summary>
			static void resetTestCounts();

			/// <summary>Runs tests to connect and disconnect from database.
			/// <para>Functions include:</para>
			/// <para>connectToDatabase</para>
			/// <para>disconnectFromDatabase</para>
			/// </summary>
			static void testConnection();

			/// <summary>Runs tests to query database.
			/// <para>Functions include:</para>
			/// <para>queryDatabase</para>
			/// </summary>
			static void testQuery();

			static void testLoadMinions();
			static void testLoadTowers();
			static void testLoadElements();
			static void testLoadResistances();

			static void testSaveLoadGame();

			static void testDelete();

		public:
			/// <summary>
			/// <para>Runs tests on the DatabaseAPI with the default connection parameters.</para>
			/// </summary>
			static void runTests();

		};

	}
}

#endif