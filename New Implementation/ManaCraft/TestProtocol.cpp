#include "TestProtocol.h"

using namespace ManaCraft::Networking;
using namespace std;

TestProtocol::TestProtocol(unsigned int numTests) 
: testCount(numTests), successCount(0), failureCount(0) {
	
	if (testCount > MAX_TEST_COUNT)
		testCount = MAX_TEST_COUNT;
	else if (testCount < MIN_TEST_COUNT)
		testCount = MIN_TEST_COUNT;


}


TestProtocol::~TestProtocol() { }


void TestProtocol::RunTests() {
	RunClientToServerTest();
}


void TestProtocol::RunClientToServerTest() {
	for (int i = 0; i < testCount; i++) {
		// Set the current protocol to the start of the range
		int currProtocol = CS_RANGE_START;
		bool endOfProtocols = false;

		while (!endOfProtocols) {
			// Take the protocol and make sure it's in the range
			bool inRange = TestCSProtocols(CS_Protocol(currProtocol));
			
			if (inRange) { // If it is in range continue on
				// Serialize it
				char protocolData[sizeof(__int16)];
				Serialize::Int16(protocolData, CS_Protocol(currProtocol));

				// Deserialize it
				CS_Protocol deserializedData;
				deserializedData = CS_Protocol(Deserialize::Int16(protocolData));

				// run it through the test and see if it's in range again
				bool isSuccess = TestCSProtocols(deserializedData);
				if (isSuccess)
					successCount++;
				else
					failureCount++;

				// Increment protocol and repeat
				currProtocol++;
			}
			
			else { // If it's not in range, break the loop
				endOfProtocols = true;
				break;
			}
		}
	}

	cout << "Client to Server Test - Tests Run on 6 Protocols: " << testCount << " Successes: " << successCount << " Failures: " << failureCount << endl;
}

bool TestProtocol::TestCSProtocols(CS_Protocol protocol) {
	bool flag;

	switch (protocol) {
		//Game Lobby Protocols
		case CS_Protocol::JOIN_TEAM:
		case CS_Protocol::LEAVE_GAME:
		case CS_Protocol::BENCH_PLAYER:
		case CS_Protocol::READY_STATUS:
		case CS_Protocol::DISBAND_GAME:
		case CS_Protocol::SET_GAMEPLAY_OPTIONS:
			flag = true;
			break;
		default:
			flag = false;
			break;
	}

	return flag;
}