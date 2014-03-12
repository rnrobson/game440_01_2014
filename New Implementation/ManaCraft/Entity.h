#pragma once

#include "Element.h"

#include "Serializable.h"
#include "Serialize.h"
#include <iostream>

typedef unsigned int uint;

class Entity : public ManaCraft::Networking::Serializable
{
private:

public:
	ManaCraft::Database::ElementTypes elementID;

	std::string name;
	unsigned int damage;
	unsigned int level;
	unsigned int cost;
	unsigned int summonCost;
	unsigned int upgradeCost;
	unsigned int researchCost;
	
	Entity();
	Entity(const ManaCraft::Database::ElementTypes _elementID, const std::string& _name, const uint _damage, const uint _level, const uint _cost, const uint _summonCost, const uint _upgradeCost, const uint _researchCost);
	virtual ~Entity();

	virtual bool Serialize(char* data, Uint16 dataFlags);
	virtual int SerializedSize(Uint16 dataFlags) const;
	virtual bool Deserialize(char* data);

	void DebugDisplay() const;

	bool operator==(const Entity& rhs);
	bool operator!=(const Entity& rhs);
};

