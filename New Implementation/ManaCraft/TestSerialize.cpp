#include "TestSerialize.h"

using namespace ManaCraft::Networking;

SerializeTester::SerializeTester(const unsigned int testCount) : 
mTestCount(testCount), mSuccessCount(0), mFailureCount(0), MIN_TEST_COUNT(1000), MAX_TEST_COUNT(100000) {
	mTestCount = (mTestCount > MAX_TEST_COUNT) ? MAX_TEST_COUNT :
				 (mTestCount < MIN_TEST_COUNT) ? MIN_TEST_COUNT :
				  mTestCount;
	srand((unsigned int)time(nullptr));
}

void SerializeTester::RunTests() {
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

void SerializeTester::ClearCounts() {
	mSuccessCount = 0;
	mFailureCount = 0;
}

void SerializeTester::RunInt8Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int8 tempInt8 = rand() % CHAR_MAX;
		__int8 result = 0;
		char data[sizeof(__int8)];

		tempInt8 = (i % 2 == 0) ? tempInt8 : -tempInt8;
		SerializeInt8(data, tempInt8);
		result = DeserializeInt8(data);

		if (tempInt8 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunInt8Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunInt16Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int16 tempInt16 = rand() % SHRT_MAX;
		__int16 result = 0;
		char data[sizeof(__int16)];

		tempInt16 = (i % 2 == 0) ? tempInt16 : -tempInt16;
		SerializeInt16(data, tempInt16);
		result = DeserializeInt16(data);

		if (tempInt16 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunInt16Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunInt32Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int32 tempInt32 = rand() % INT_MAX;
		__int32 result = 0;
		char data[sizeof(__int32)];

		tempInt32 = (i % 2 == 0) ? tempInt32 : -tempInt32;
		SerializeInt32(data, tempInt32);
		result = DeserializeInt32(data);

		if (tempInt32 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunInt32Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunInt64Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		__int64 tempInt64 = rand() % LLONG_MAX;
		__int64 result = 0;
		char data[sizeof(__int64)];

		tempInt64 = (i % 2 == 0) ? tempInt64 : -tempInt64;
		SerializeInt64(data, tempInt64);
		result = DeserializeInt64(data);

		if (tempInt64 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunInt64Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunUInt8Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int8 tempUInt8 = rand() % UCHAR_MAX;
		unsigned __int8 result = 0;
		char data[sizeof(unsigned __int8)];

		SerializeUInt8(data, tempUInt8);
		result = DeserializeUInt8(data);

		if (tempUInt8 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunUInt8Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunUInt16Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int16 tempUInt16 = rand() % USHRT_MAX;
		unsigned __int16 result = 0;
		char data[sizeof(unsigned __int16)];

		SerializeUInt16(data, tempUInt16);
		result = DeserializeUInt16(data);

		if (tempUInt16 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunUInt16Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunUInt32Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int32 tempUInt32 = rand() % UINT_MAX;
		unsigned __int32 result = 0;
		char data[sizeof(unsigned __int32)];

		SerializeUInt32(data, tempUInt32);
		result = DeserializeUInt32(data);

		if (tempUInt32 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunUInt32Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunUInt64Tests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		unsigned __int64 tempUInt64 = rand() % ULLONG_MAX;
		unsigned __int64 result = 0;
		char data[sizeof(unsigned __int64)];

		SerializeUInt64(data, tempUInt64);
		result = DeserializeUInt64(data);

		if (tempUInt64 == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunUInt64Tests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunFloatTests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		float tempFloat = rand() / 10000.0f + rand();
		float result = 0;
		char data[sizeof(float)];

		tempFloat = (i % 2 == 0) ? tempFloat : -tempFloat;
		SerializeFloat(data, tempFloat);
		result = DeserializeFloat(data);

		if (tempFloat == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunFloatTests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}

void SerializeTester::RunDoubleTests() {
	ClearCounts();
	for (unsigned int i = 0; i < mTestCount; ++i) {
		double tempDouble = rand() / 10000.0 + rand();
		double result = 0;
		char data[sizeof(double)];

		tempDouble = (i % 2 == 0) ? tempDouble : -tempDouble;
		SerializeDouble(data, tempDouble);
		result = DeserializeDouble(data);

		if (tempDouble == result) {
			++mSuccessCount;
		}
		else {
			++mFailureCount;
		}
	}
	std::cout << "RunDoubleTests() complete.  " << mSuccessCount << " of " << mTestCount << " succeeded.  " << mFailureCount << " failed." << std::endl;
}
