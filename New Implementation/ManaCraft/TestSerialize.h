#ifndef TESTSERIALIZE_H
#define TESTSERIALIZE_H

#include "Serialize.h"
#include <iostream>
#include <random>
#include <ctime>

namespace ManaCraft {
	namespace Networking {
		/// <summary>[SerializeTester]
		/// <para>This class is used to ensure that the Serialize class is working as intended.</para>
		/// </summary>
		class SerializeTester {
		public:
			/// <summary>[SerializeTester]
			/// <para>Creates Serialize class tester with a specifiable test count parameter.</para>
			/// <para>[testCount] Represents how many tests will be ran.  This value will be clamped to a min value of MIN_TEST_COUNT and a max value of MAX_TEST_COUNT.</para>
			/// </summary>
			SerializeTester(const unsigned int testCount);

			/// <summary>[RunTests]
			/// <para>Runs tests on the Serialize class with the current parameters.</para>
			/// </summary>
			void RunTests();

		private:
			const unsigned int MAX_TEST_COUNT;
			const unsigned int MIN_TEST_COUNT;
			unsigned int mTestCount;
			unsigned int mSuccessCount;
			unsigned int mFailureCount;

			/// <summary>[ClearCounts]
			/// <para>Resets the success and failure count back to 0.</para>
			/// </summary>
			void ClearCounts();

			/// <summary>[RunInt8Tests]
			/// <para>Runs serialization and deserialization tests on a 8 bit integer data type.</para>
			/// </summary>
			void RunInt8Tests();

			/// <summary>[RunInt16Tests]
			/// <para>Runs serialization and deserialization tests on a 16 bit integer data type.</para>
			/// </summary>
			void RunInt16Tests();

			/// <summary>[RunInt32Tests]
			/// <para>Runs serialization and deserialization tests on a 32 bit integer data type.</para>
			/// </summary>
			void RunInt32Tests();

			/// <summary>[RunInt64Tests]
			/// <para>Runs serialization and deserialization tests on a 64 bit integer data type.</para>
			/// </summary>
			void RunInt64Tests();

			/// <summary>[RunUInt8Tests]
			/// <para>Runs serialization and deserialization tests on a 8 bit unsigned integer data type.</para>
			/// </summary>
			void RunUInt8Tests();

			/// <summary>[RunUInt16Tests]
			/// <para>Runs serialization and deserialization tests on a 16 bit unsigned integer data type.</para>
			/// </summary>
			void RunUInt16Tests();

			/// <summary>[RunUInt32Tests]
			/// <para>Runs serialization and deserialization tests on a 32 bit unsigned integer data type.</para>
			/// </summary>
			void RunUInt32Tests();

			/// <summary>[RunUInt64Tests]
			/// <para>Runs serialization and deserialization tests on a 64 bit unsigned integer data type.</para>
			/// </summary>
			void RunUInt64Tests();

			/// <summary>[RunFloatTests]
			/// <para>Runs serialization and deserialization tests on a 32 bit floating point data type.</para>
			/// </summary>
			void RunFloatTests();

			/// <summary>[RunDoubleTests]
			/// <para>Runs serialization and deserialization tests on a 64 bit floating point data type.</para>
			/// </summary>
			void RunDoubleTests();
		};
	}
}

#endif