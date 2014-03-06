#ifndef TESTPROTOCOL_H
#define TESTPROTOCOL_H

#include "Protocol.h"
#include "Serialize.h"
#include <iostream>

namespace ManaCraft {
	namespace Testbed {
		// Will be testing the serialization and deserialization of the Game Lobby type protocols
		class TestProtocol {
		private:			
			unsigned int successCount;
			unsigned int failureCount;
			unsigned int testCount;
			const unsigned int MAX_TEST_COUNT = 10;
			const unsigned int MIN_TEST_COUNT = 1000;
			const unsigned int SC_RANGE_START = 1350, CS_RANGE_START = 2300;
			
			/// <summary>RunServerToClientTest
			/// <para>Will test the serialization/deserialization of a set of 6 protocols that are meant to be sent over to the client from the server.</para>
			/// </summary>
			void RunServerToClientTest();
			
			/// <summary>RunClientToServerTest
			/// <para>Will test the serialization/deserialization of a set of 6 protocols that are meant to be sent over to the server from the client.</para>
			/// </summary>
			void RunClientToServerTest();

			/// <summary>TestCSProtocols
			/// <para>Runs through a switch statement and checks if the given protocol is defined in the enum or not.</para>
			/// <para> [Protocol] The protocol to test the switch upon.</para>
			/// </summary>
			bool TestCSProtocols(ManaCraft::Networking::CS_Protocol protocol);
			

			/// <summary>TestSCProtocols
			/// <para> Runs through a switch statement and checks if the given protocol is defined in the enum or not.</para>
			/// <para> [Protocol] the protocol to the the switch upon.</para>
			/// </summary>
			bool TestSCProtocols(ManaCraft::Networking::SC_Protocol protocol);
		public:
			/// <summary>Creates an object of TestProtocol to enable one to test the serialization and deserialization of the protocols
			/// <para>[testCount] Is the amount of tests that will be run on each protocol</para>
			/// </summary>
			TestProtocol(unsigned int testCount);
			~TestProtocol();

			/// <summary>RunTests
			/// <para>Will call the methods to run tests for both Server to Client and Client to Server protocols.</para>
			/// </summary>
			void RunTests();
		};
	}
}
#endif