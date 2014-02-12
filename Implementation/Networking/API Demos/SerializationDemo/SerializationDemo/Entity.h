#pragma once
#include <string>

#include "Element.h"

#include "Serializable.h"
#include "Serialization.h"

using namespace ManaCraft::Networking;

class Entity : public Serializable
{
private:
	Element* element;

public:
	std::string name;
	unsigned int level;
	unsigned int damage;
	unsigned int summonCost;
	unsigned int upgradeCost;
	unsigned int researchCost;

	Entity(void);
	~Entity(void);

	virtual bool Serialize(byte* data, Data requiredData);
	virtual int SerializedSize(Data requiredData) const;
	virtual bool Deserialize(byte* data);
};

