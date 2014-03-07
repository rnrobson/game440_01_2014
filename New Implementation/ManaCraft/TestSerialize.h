#ifndef TESTSERIALIZE_H
#define TESTSERIALIZE_H

#include "Test.h"
#include "Serialize.h"
#include <iostream>

namespace ManaCraft {
	namespace Testbed {
		/// <summary>[SerializeTester]
		/// <para>This class is used to ensure that the Serialize class is working as intended.</para>
		/// </summary>
		class SerializeTester : public Test {
		public:
			/// <summary>[SerializeTester]
			/// <para>Creates Serialize class tester with a specifiable test count parameter.</para>
			/// <para>[testCount] Represents how many tests will be ran.</para>
			/// </summary>
			SerializeTester(const unsigned int testCount);

			/// <summary>[RunTests]
			/// <para>Runs tests on the Serialize class with the current parameters.</para>
			/// </summary>
			void Run();

		private:
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