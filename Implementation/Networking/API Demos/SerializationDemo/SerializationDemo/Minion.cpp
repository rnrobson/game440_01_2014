#include "Minion.h"


Minion::Minion(void)
{
}


Minion::~Minion(void)
{
}

bool Minion::Serialize(byte* data, Data requiredData) {
	Entity::Serialize(data, requiredData);
	data += Entity::SerializedSize(requiredData);

	switch (requiredData) {
	case Data::EVERYTHING:
		SerializeInt8(data, requiredData);
		data += sizeof(Data);
		SerializeUInt32(data, health);
		data += sizeof(unsigned int);
		SerializeUInt32(data, armour);
		data += sizeof(unsigned int);
		SerializeUInt32(data, speed);
		data += sizeof(unsigned int);
		SerializeFloat(data, xPos);
		data += sizeof(float);
		SerializeFloat(data, yPos);
		data += sizeof(float);
		SerializeFloat(data, manaPerSecond);
		return true;
	default:
		throw UnsupportedOperationException();
	}
}

int Minion::SerializedSize(Data requiredData) const {
	switch (requiredData) {
	case Data::EVERYTHING:
		return Entity::SerializedSize(requiredData) + 
			   sizeof(Data) + 
			   sizeof(unsigned int)* 3 + 
			   sizeof(float)* 3;
	default:
		throw UnsupportedOperationException();
	}
}

bool Minion::Deserialize(byte* data) {
	Data requiredData = (Data)data[0];
	Entity::Deserialize(data);
	data += Entity::SerializedSize(requiredData);

	requiredData = (Data)data[0];
	data += sizeof(Data);

	switch (requiredData) {
	case Data::EVERYTHING:
		health = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		armour = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		speed = DeserializeUInt32(data);
		data += sizeof(unsigned int);
		xPos = DeserializeFloat(data);
		data += sizeof(float);
		yPos = DeserializeFloat(data);
		data += sizeof(float);
		manaPerSecond = DeserializeFloat(data);
		return true;
	default:
		throw UnsupportedOperationException();
	}
}