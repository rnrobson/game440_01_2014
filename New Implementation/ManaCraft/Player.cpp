#include "Player.h"

Player::Player() { }

Player::Player(uint _id) : id(_id), towers(vector<Tower*>()), minions(vector<Minion*>()), infSquares(vector<InfluenceSquare*>()) { }

Player::~Player() { }


Player* Player::LoadPlayerByID(int _id) {
	using namespace ManaCraft::Database;

	// Create player
	Player* temp = new Player(_id);

	try {
		Query query = DatabaseAPI::getQuery();

		// Players table
		query.clear();
		query << "SELECT * FROM Player WHERE ID = " << mysqlpp::quote << _id;

		if (UseQueryResult result = query.use()) {
			if (Row row = result.fetch_row()) {
				// ASSIGN VALUES HERE once there is something to assign
			}
			else {
				throw DatabaseAPI::IDNotFoundException();
			}
		}

		return temp;
	}
	catch (mysqlpp::BadConversion e) {
		std::cout << e.what() << "\n";
	}
	catch (mysqlpp::BadIndex e) {
		std::cout << e.what() << "\n";
	}
	catch (Exception e) {
		throw e;
	}

	delete temp;
	return nullptr;
}

void Player::SavePlayer(unsigned int TeamID) {
	using namespace ManaCraft::Database;

	try {
		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "INSERT INTO Team_Players VALUES(" << mysqlpp::quote << TeamID << ", " << mysqlpp::quote << id << ")";
		query.execute();

	}
	catch (mysqlpp::BadConversion e) {
		std::cout << e.what() << "\n";
	}
	catch (mysqlpp::BadIndex e) {
		std::cout << e.what() << "\n";
	}
	catch (Exception e) {
		throw e;
	}
}
