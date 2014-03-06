#include "TestSerialize.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Testbed;

SerializeTester::SerializeTester(const unsigned int testCount) : 
Test(testCount) {
}

void SerializeTester::Run() {
	RunInt8Tests();
	RunInt16Tests();
	RunInt32Tests();
	RunInt64Tests();

	RunUInt8Tests();
	RunUInt16Tests();
	RunUInt32Tests();
	RunUInt64Tests();

	RunFloatTests();
	RunDoubleTests();
}

void SerializeTester::RunInt8Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int8 tempInt8 = rand() % CHAR_MAX;
		__int8 result = 0;
		char data[sizeof(__int8)];

		tempInt8 = (i % 2 == 0) ? tempInt8 : -tempInt8;
		Serialize::Int8(data, tempInt8);
		result = Deserialize::Int8(data);

		if (tempInt8 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunInt8Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunInt16Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int16 tempInt16 = rand() % SHRT_MAX;
		__int16 result = 0;
		char data[sizeof(__int16)];

		tempInt16 = (i % 2 == 0) ? tempInt16 : -tempInt16;
		Serialize::Int16(data, tempInt16);
		result = Deserialize::Int16(data);

		if (tempInt16 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunInt16Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunInt32Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int32 tempInt32 = rand() % INT_MAX;
		__int32 result = 0;
		char data[sizeof(__int32)];

		tempInt32 = (i % 2 == 0) ? tempInt32 : -tempInt32;
		Serialize::Int32(data, tempInt32);
		result = Deserialize::Int32(data);

		if (tempInt32 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunInt32Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunInt64Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int64 tempInt64 = rand() % LLONG_MAX;
		__int64 result = 0;
		char data[sizeof(__int64)];

		tempInt64 = (i % 2 == 0) ? tempInt64 : -tempInt64;
		Serialize::Int64(data, tempInt64);
		result = Deserialize::Int64(data);

		if (tempInt64 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunInt64Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunUInt8Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int8 tempUInt8 = rand() % UCHAR_MAX;
		unsigned __int8 result = 0;
		char data[sizeof(unsigned __int8)];

		Serialize::UInt8(data, tempUInt8);
		result = Deserialize::UInt8(data);

		if (tempUInt8 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunUInt8Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunUInt16Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int16 tempUInt16 = rand() % USHRT_MAX;
		unsigned __int16 result = 0;
		char data[sizeof(unsigned __int16)];

		Serialize::UInt16(data, tempUInt16);
		result = Deserialize::UInt16(data);

		if (tempUInt16 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunUInt16Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunUInt32Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int32 tempUInt32 = rand() % UINT_MAX;
		unsigned __int32 result = 0;
		char data[sizeof(unsigned __int32)];

		Serialize::UInt32(data, tempUInt32);
		result = Deserialize::UInt32(data);

		if (tempUInt32 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunUInt32Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunUInt64Tests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int64 tempUInt64 = rand() % ULLONG_MAX;
		unsigned __int64 result = 0;
		char data[sizeof(unsigned __int64)];

		Serialize::UInt64(data, tempUInt64);
		result = Deserialize::UInt64(data);

		if (tempUInt64 == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunUInt64Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunFloatTests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		float tempFloat = rand() / 10000.0f + rand();
		float result = 0;
		char data[sizeof(float)];

		tempFloat = (i % 2 == 0) ? tempFloat : -tempFloat;
		Serialize::Float(data, tempFloat);
		result = Deserialize::Float(data);

		if (tempFloat == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunFloatTests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}

void SerializeTester::RunDoubleTests() {
	Test::ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		double tempDouble = rand() / 10000.0 + rand();
		double result = 0;
		char data[sizeof(double)];

		tempDouble = (i % 2 == 0) ? tempDouble : -tempDouble;
		Serialize::Double(data, tempDouble);
		result = Deserialize::Double(data);

		if (tempDouble == result) {
			++mSuccessCount;
		}
	}
	std::cout << "SeriaizeTester::RunDoubleTests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded." << std::endl;
}
