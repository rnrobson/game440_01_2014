#include "Entity.h"


Entity::Entity(void)
{
}


Entity::~Entity(void)
{
}


bool Entity::Serialize(byte* data, Data requiredData) {
	switch (requiredData) {
	case Data::EVERYTHING:
		SerializeInt8(data, requiredData);
		data += sizeof(Data);
		SerializeUInt32(data, level);
		data += sizeof(unsigned int);
		SerializeUInt32(data, damage);
		data += sizeof(unsigned int);
		SerializeUInt32(data, summonCost);
		data += sizeof(unsigned int);
		SerializeUInt32(data, upgradeCost);
		data += sizeof(unsigned int);
		SerializeUInt32(data, researchCost);
		return true;
	default:
		throw UnsupportedOperationException();
	}
}

int Entity::SerializedSize(Data requiredData) const {
	switch (requiredData) {
	case Data::EVERYTHING:
		return sizeof(Data) + sizeof(unsigned int) * 5;
	default:
		throw UnsupportedOperationException();
	}
}

bool Entity::Deserialize(byte* data) {
	Data requiredData = (Data)data[0];
	data += sizeof(Data);

	switch (requiredData) {
	case Data::EVERYTHING:
		level = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		damage = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		summonCost = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		upgradeCost = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		researchCost = DeserializeUInt32(data);
		return true;
	default:
		throw UnsupportedOperationException();
	}
}