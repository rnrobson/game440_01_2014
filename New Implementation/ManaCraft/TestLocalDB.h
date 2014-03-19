#ifndef TEST_LOCAL_DB_H
#define TEST_LOCAL_DB_H

#include "Test.h"
#include "LocalDB.h"

namespace ManaCraft {
	namespace Testbed {
		/// <summary>[SerializeTester]
		/// <para>This class is used to ensure that the Serialize class is working as intended.</para>
		/// </summary>
		class TestLocalDB : public ManaCraft::Testbed::Test {
		public:
			/// <summary>[TestLocalDB]
			/// <para>Creates LocalDB class with a specifiable test count parameter.</para>
			/// <para>[testCount] Represents how many tests will be run </para> 
			/// </summary>
			TestLocalDB(const unsigned int testCount);

			/// <summary>[Run]
			/// <para>Runs tests on the LocalDB</para>
			/// </summary>
			void Run();

		private:

			LocalDB* testLocalDB;

			/// <summary>[RunInitTest]
			/// <para>Test the database connectivity</para>
			/// </summary>
			void RunInitTest();

			/// <summary>[RunDestroyTest]
			/// <para>Test the database destruction</para>
			/// </summary>
			void RunDestroyTest();

			/// <summary>[RunSaveGameTest]
			/// <para>Test the database save game functionality</para>
			/// </summary>
			void RunSaveGameTest();

			/// <summary>[RunLoadGameTest]
			/// <para>Test the database load game functionality</para>
			/// </summary>
			void RunLoadGameTest();

			/// <summary>[RunUnLoadGameTest]
			/// <para>Test the database unload game functionality</para>
			/// </summary>
			void RunUnLoadGameTest();

			/// <summary>[resetTestCounts]
			/// <para>resets the test counts</para>
			/// </summary>
			void resetTestCounts();
		};
	}
}

#endif