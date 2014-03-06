#include "Test.h"

using namespace ManaCraft::Testbed;

Test::Test(const unsigned int testCount) : mTestCount(testCount) {
}

Test::~Test() {
}

void Test::Run() {
}

void Test::ClearCounts() {
	mSuccessCount = 0;
}