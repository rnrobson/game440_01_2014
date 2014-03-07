#include "Tester.h"

using namespace ManaCraft::Testbed;

Tester::Tester() : mTests(0) {
}

void Tester::AddTest(Test& test) {
	mTests.push_back(&test);
}

void Tester::ClearTests() {
	mTests.clear();
}

void Tester::DeleteTests() {
	for (int i = mTests.size() - 1; i >= 0; --i) {
		delete mTests[i];
	}
	mTests.clear();
}

void Tester::RunTests() const {
	for (unsigned int i = 0; i < mTests.size(); ++i) {
		mTests[i]->Run();
		std::cout << std::endl;
	}
}