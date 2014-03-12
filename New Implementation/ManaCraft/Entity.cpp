#include "Entity.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Database;

Entity::Entity() : 
elementID(ElementTypes::FIRE), 
name(""), damage(0), 
level(0), cost(0), 
summonCost(0), upgradeCost(0), researchCost(0){
}

Entity::Entity(const ElementTypes _elementID, 
				const std::string& _name, const uint _damage, 
				const uint _level, const uint _cost, 
				const uint _summonCost,	const uint _upgradeCost, const uint _researchCost)	:
				elementID(_elementID), 
				name(_name), damage(_damage),
				level(_level), cost(_cost), 
				summonCost(_summonCost), upgradeCost(_upgradeCost), researchCost(_researchCost) {
}


Entity::~Entity() {
}

bool Entity::Serialize(char* data, Uint16 dataFlags) {
	data = Serialize::UInt16(data, dataFlags);

	if (dataFlags & NetData::FLAG_01) {
		data = Serialize::Int32(data, elementID);
	}
	if (dataFlags & NetData::FLAG_02) {
		data = Serialize::UInt16(data, (Uint16)name.length());

		for (unsigned int i = 0; i < name.length(); ++i) {
			data[i] = name[i];
		}
		data += name.length();
	}
	if (dataFlags & NetData::FLAG_03) {
		data = Serialize::UInt32(data, damage);
	}
	if (dataFlags & NetData::FLAG_04) {
		data = Serialize::UInt32(data, level);
	}
	if (dataFlags & NetData::FLAG_05) {
		data = Serialize::UInt32(data, cost);
	}
	if (dataFlags & NetData::FLAG_06) {
		data = Serialize::UInt32(data, summonCost);
	}
	if (dataFlags & NetData::FLAG_07) {
		data = Serialize::UInt32(data, upgradeCost);
	}
	if (dataFlags & NetData::FLAG_08) {
		data = Serialize::UInt32(data, researchCost);
	}

	return true;
}

int Entity::SerializedSize(Uint16 dataFlags) const {
	int size = 0;

	size += sizeof(Uint16); // data flags

	if (dataFlags & NetData::FLAG_01) {
		size += sizeof(int); // element id
	}
	if (dataFlags & NetData::FLAG_02) {
		size += sizeof(Uint16); // string length
		size += sizeof(char) * name.length(); // string contents
	}
	if (dataFlags & NetData::FLAG_03) {
		size += sizeof(unsigned int); // damage
	}
	if (dataFlags & NetData::FLAG_04) {
		size += sizeof(unsigned int); // level
	}
	if (dataFlags & NetData::FLAG_05) {
		size += sizeof(unsigned int); // cost
	}
	if (dataFlags & NetData::FLAG_06) {
		size += sizeof(unsigned int); // summon cost
	}
	if (dataFlags & NetData::FLAG_07) {
		size += sizeof(unsigned int); // upgrade cost
	}
	if (dataFlags & NetData::FLAG_08) {
		size += sizeof(unsigned int); // research cost
	}
	
	return size;
}

bool Entity::Deserialize(char* data) {
	Uint16 dataFlags = Deserialize::UInt16(data);
	data += sizeof(Uint16);

	if (dataFlags & NetData::FLAG_01) {
		elementID = (ElementTypes) Deserialize::Int32(data);
		data += sizeof(int);
	}
	if (dataFlags & NetData::FLAG_02) {
		Uint16 len = Deserialize::UInt16(data);
		data += sizeof(Uint16);
		name = "";
		for (Uint16 i = 0; i < len; ++i) {
			name += data[i];
		}
		data += len;
	}
	if (dataFlags & NetData::FLAG_03) {
		damage = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_04) {
		level = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_05) {
		cost = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_06) {
		summonCost = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_07) {
		upgradeCost = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_08) {
		researchCost = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}

	return true;
}

void Entity::DebugDisplay() const {
	std::cout << "Name: " << name << std::endl
			  << "ID: " << elementID << ", Dmg: " << damage << ", Lvl: " << level << std::endl
			  << "Cost: " << cost << ", S Cost: " << summonCost << ", U Cost: " << upgradeCost << ", R Cost: " << researchCost << std::endl;		
}

bool Entity::operator==(const Entity& rhs) {
	return elementID == rhs.elementID &&
			name == rhs.name &&
			damage == rhs.damage &&
			level == rhs.level &&
			cost == rhs.cost &&
			summonCost == rhs.summonCost &&
			researchCost == rhs.researchCost &&
			upgradeCost == rhs.upgradeCost;
}

bool Entity::operator!=(const Entity& rhs) {
	return !(*this == rhs);
}