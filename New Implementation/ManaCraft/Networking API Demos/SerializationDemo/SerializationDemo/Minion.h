#pragma once
#include "Entity.h"
#include "Resistances.h"

class Minion : public Entity
{
private:
	Resistances* res; //not sure if this is correct

public:
	unsigned int health;
	float xPos;
	float yPos;
	float manaPerSecond;
	unsigned int armour;
	unsigned int speed;

	Minion(void);
	~Minion(void);

	virtual bool Serialize(byte* data, Data requiredData);
	virtual int SerializedSize(Data requiredData) const;
	virtual bool Deserialize(byte* data);
};

