#ifndef TEST_H
#define TEST_H

#include <iostream>

namespace ManaCraft {
	namespace Testbed {
		/// <summary>[Test]
		/// <para>This class is intended to be used as the basis for testing functionality.</para>
		/// </summary>
		class Test {
		protected:
			unsigned int mTestCount;
			unsigned int mSuccessCount;

		public:
			/// <summary>[Test]
			/// <para>Creates a Test class.</para>
			/// <para>[testCount] Represents how many tests will be ran.</para>
			/// </summary>
			Test(const unsigned int testCount);

			/// <summary>[~Test]
			/// <para>Automatically frees any necessary memory for derived classes.</para>
			/// </summary>
			virtual ~Test();

			/// <summary>[Run]
			/// <para>Runs the implemented tests for a given class.</para>
			/// </summary>
			virtual void Run();

			/// <summary>[ClearCounts]
			/// <para>Resets the success count back to 0.</para>
			/// </summary>
			void ClearCounts();
		};
	}
}


#endif