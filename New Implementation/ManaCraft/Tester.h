#ifndef TESTER_H
#define TESTER_H

#include <vector>
#include "Test.h"

namespace ManaCraft {
	namespace Testbed {
		/// <summary>[Tester]
		/// <para>This class is intended to be used as a container for all of the Tests for a program.</para>
		/// <para>This class does not deallocate memory unless specified with the DeleteTests method</para>
		/// </summary>
		class Tester {
		private:
			std::vector<Test*> mTests;

		public:
			/// <summary>[Tester]
			/// <para>Creates a Tester class with 0 tests to be processed.</para>
			/// </summary>
			Tester();

			/// <summary>[AddTest]
			/// <para>Adds a test class that is to be tested.</para>
			/// </summary>
			void AddTest(Test& test);

			/// <summary>[ClearTests]
			/// <para>Clears all of the tests that were added.</para>
			/// </summary>
			void ClearTests();

			/// <summary>[DeleteTests]
			/// <para>Deletes all of the tests that were added.</para>
			/// </summary>
			void DeleteTests();

			/// <summary>[RunTests]
			/// <para>Iterates through all of the tests that were added and run each object's tests.</para>
			/// </summary>
			void RunTests() const;
		};
	}
}

#endif