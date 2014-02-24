// Main.cpp
// Example test code.  Tests involve serializing one object with its variables randomly set, 
// then deserializing that data into a different object before testing if the objects are the same.
// These tests are not profiled for speed.  It's simply a functionality test.
// These tests are currently messy, and this will be cleaned up in the future when the
// equality and inequality operators are implemented inside each data structure (as well
// as various constructors).
#include <iostream>
#include <random>
#include <ctime>

#define TEST_COUNT 100000
#define ENTITY_TEST 1
#define MINION_TEST 1

#if ENTITY_TEST
#include "Entity.h"
void TestEntity();
#endif

#if MINION_TEST
#include "Minion.h"
void TestMinion();
#endif

int main() {
	srand((unsigned int)time(nullptr));
#if ENTITY_TEST
	TestEntity();
#endif
#if MINION_TEST
	TestMinion();
#endif

	std::cin.get();
	return 0;
}

#if ENTITY_TEST
void TestEntity() {
	int successCount = 0;
	int failCount = 0;
	Entity e1;
	Entity e2;

	for (int i = 0; i < TEST_COUNT; ++i) {
		e1.level = rand() % UINT_MAX;
		e1.damage = rand() % UINT_MAX;
		e1.summonCost = rand() % UINT_MAX;
		e1.upgradeCost = rand() % UINT_MAX;
		e1.researchCost = rand() % UINT_MAX;

		char* data = new char[e1.SerializedSize(Data::EVERYTHING)];
		if (!e1.Serialize(data, Data::EVERYTHING)) {
			std::cout << "Serialization failed." << std::endl;
			return;
		}

		e2.Deserialize(data);
		delete[] data;

		if (e1.level == e2.level &&
			e1.damage == e2.damage &&
			e1.summonCost == e2.summonCost &&
			e1.upgradeCost == e2.upgradeCost &&
			e1.researchCost == e2.researchCost) {
			++successCount;
		}
		else {
			++failCount;
		}
	}

	std::cout << "Entity Results: " << successCount << " succeeded.  " << failCount << " failed." << std::endl;
}
#endif

#if MINION_TEST
void TestMinion() {
	int successCount = 0;
	int failCount = 0;

	Minion m1;
	Minion m2;

	for (int i = 0; i < TEST_COUNT; ++i) {
		m1.level = rand() % UINT_MAX;
		m1.damage = rand() % UINT_MAX;
		m1.summonCost = rand() % UINT_MAX;
		m1.upgradeCost = rand() % UINT_MAX;
		m1.researchCost = rand() % UINT_MAX;

		m1.health = rand() % UINT_MAX;
		m1.armour = rand() % UINT_MAX;
		m1.speed = rand() % UINT_MAX;
		m1.xPos = rand() * 1.0f;
		m1.yPos = rand() * 1.0f;
		m1.manaPerSecond = rand() * 1.0f;

		char* data = new char[m1.SerializedSize(Data::EVERYTHING)];
		if (!m1.Serialize(data, Data::EVERYTHING)) {
			++failCount;
			delete[] data;
			continue;
		}

		m2.Deserialize(data);
		delete[] data;

		if (m1.health == m2.health &&
			m1.armour == m2.armour &&
			m1.speed == m2.speed &&
			m1.xPos == m2.xPos &&
			m1.yPos == m2.yPos &&
			m1.manaPerSecond == m2.manaPerSecond && 

			m1.level == m2.level &&
			m1.damage == m2.damage &&
			m1.summonCost == m2.summonCost &&
			m1.upgradeCost == m2.upgradeCost &&
			m1.researchCost == m2.researchCost) {
			++successCount;
		}
		else {
			++failCount;
		}
	}

	std::cout << "Minion Results: " << successCount << " succeeded.  " << failCount << " failed." << std::endl;
}
#endif