#pragma once
#include <vector>
#include "DatabaseAPI.h"
#include "DataDefinitions.h"
#include "Entity.h"
#include "Resistances.h"
#include "Navigator.h"
#include "Waypoint.h"

class Minion : public Entity, public Navigator
{
private:
	static Minion* buildFromRow(mysqlpp::Row& row);

public:
	ManaCraft::Database::MinionTypes minionType;

	
	float xPos;
	float yPos;
	float manaPerSecond;
	unsigned int health;
	unsigned int armour;
	Resistances* resists;
	unsigned int speed;

	SDL_Rect* collisionBox;
	unsigned int colWidth;
	unsigned int colHeight;

	Minion();
	~Minion();

	void OnWaypointArrive();

	virtual bool Serialize(char* data, Uint16 dataFlags);
	virtual int SerializedSize(Uint16 dataFlags) const;
	virtual bool Deserialize(char* data);

	static std::vector<Minion*> fetchAllFromDB();

	bool operator==(const Minion& rhs);
	bool operator!=(const Minion& rhs);
};

