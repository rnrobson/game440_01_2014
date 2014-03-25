#include "Minion.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Database;

Minion::Minion() : Entity(), xPos(0), yPos(0),
manaPerSecond(0), health(0), armour(0), speed(0) {
	collisionBox = new SDL_Rect();
}

Minion::~Minion() {
}

bool Minion::Serialize(char* data, Uint16 dataFlags) {
	data = Serialize::UInt16(data, dataFlags);

	if (dataFlags & NetData::FLAG_01) {
		data = Serialize::Int32(data, ID);
	}
	if (dataFlags & NetData::FLAG_02) {
		data = Serialize::Float(data, xPos);
	}
	if (dataFlags & NetData::FLAG_03) {
		data = Serialize::Float(data, yPos);
	}
	if (dataFlags & NetData::FLAG_04) {
		data = Serialize::Float(data, manaPerSecond);
	}
	if (dataFlags & NetData::FLAG_05) {
		data = Serialize::UInt32(data, health);
	}
	if (dataFlags & NetData::FLAG_06) {
		data = Serialize::UInt32(data, armour);
	}
	if (dataFlags & NetData::FLAG_07) {
		data = Serialize::UInt32(data, speed);
	}

	return true;
}

int Minion::SerializedSize(Uint16 dataFlags) const {
	int size = sizeof(Uint16); // data flags

	if (dataFlags & NetData::FLAG_01) {
		size += sizeof(int); // id
	}
	if (dataFlags & NetData::FLAG_02) {
		size += sizeof(float); // x pos
	}
	if (dataFlags & NetData::FLAG_03) {
		size += sizeof(float); // y pos
	}
	if (dataFlags & NetData::FLAG_04) {
		size += sizeof(float); // mana per second
	}
	if (dataFlags & NetData::FLAG_05) {
		size += sizeof(unsigned int); // health
	}
	if (dataFlags & NetData::FLAG_06) {
		size += sizeof(unsigned int); // armour
	}
	if (dataFlags & NetData::FLAG_07) {
		size += sizeof(unsigned int); // speed
	}

	return size;
}

bool Minion::Deserialize(char* data) {
	Uint16 dataFlags = Deserialize::UInt16(data);
	data += sizeof(Uint16);

	if (dataFlags & NetData::FLAG_01) {
		ID = (MinionTypes)Deserialize::Int32(data);
		data += sizeof(int);
	}
	if (dataFlags & NetData::FLAG_02) {
		xPos = Deserialize::Float(data);
		data += sizeof(float);
	}
	if (dataFlags & NetData::FLAG_03) {
		yPos = Deserialize::Float(data);
		data += sizeof(float);
	}
	if (dataFlags & NetData::FLAG_04) {
		manaPerSecond = Deserialize::Float(data);
		data += sizeof(float);
	}
	if (dataFlags & NetData::FLAG_05) {
		health = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_06) {
		armour = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}
	if (dataFlags & NetData::FLAG_07) {
		speed = Deserialize::UInt32(data);
		data += sizeof(unsigned int);
	}

	return true;
}

Minion* Minion::buildFromRow(mysqlpp::Row& row) {
	using namespace ManaCraft::Database;

	//Create temporary minion pointer
	Minion* temp = new Minion();

	try {
		

		//Get Minion ID and cast it to MinionType
		int rowID = atoi(row[TableInfo::Minions::ID].c_str());
		temp->ID = static_cast<MinionTypes>(rowID);

		//Get Element ID and cast it to ElementType
		int elementId = atoi(row[TableInfo::Minions::ELEMENT].c_str());
		temp->elementID = static_cast<ElementTypes>(elementId);

		//Get name, converts it from char* to string
		temp->name = std::string(row[TableInfo::Minions::NAME].c_str());

		//Load rest of information
		temp->level = atoi(row[TableInfo::Minions::LEVEL].c_str());
		temp->health = atoi(row[TableInfo::Minions::HEALTH].c_str());
		temp->damage = atoi(row[TableInfo::Minions::DAMAGE].c_str());
		temp->armour = atoi(row[TableInfo::Minions::ARMOUR].c_str());
		temp->speed = atoi(row[TableInfo::Minions::SPEED].c_str());
		temp->manaPerSecond = (float) atof(row[TableInfo::Minions::MPS].c_str());
		temp->cost = atoi(row[TableInfo::Minions::COST].c_str());

		return temp;
	}
	catch (mysqlpp::BadConversion e) {
		std::cout << e.what() << "\n";
	}
	catch (mysqlpp::BadIndex e) {
		std::cout << e.what() << "\n";
	}

	delete temp;
	return nullptr;
}

std::vector<Minion*> Minion::fetchAllFromDB() {
	using namespace ManaCraft::Database;

	try {
		std::cout << "Querying Minion Table\n";

		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "SELECT * FROM Minions";

		std::vector<Minion*> minions = std::vector<Minion*>();

		if (UseQueryResult result = query.use()) {
			std::cout << "Obtained Result from Minion query\n";
			Row row;
			
			while (row = result.fetch_row()) {
				Minion* e = buildFromRow(row);
				minions.push_back(e);
			}
		}
		return minions;
	}
	catch (Exception e) {
		throw e;
	}
	return std::vector<Minion*>();
}

bool Minion::operator==(const Minion& rhs) {
	return ID == rhs.ID &&
		xPos == rhs.xPos &&
		yPos == rhs.yPos &&
		manaPerSecond == rhs.manaPerSecond &&
		health == rhs.health &&
		armour == rhs.armour &&
		speed == rhs.speed &&
		Entity::operator==(rhs);
}

bool Minion::operator!=(const Minion& rhs) {
	return !(*this == rhs);
}