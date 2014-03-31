#include "ServerPlayer.h"


ServerPlayer::ServerPlayer()
{
}


ServerPlayer::~ServerPlayer()
{
}

ServerPlayer* ServerPlayer::LoadPlayerByID(int _id) {
	using namespace ManaCraft::Database;

	// Create player
	ServerPlayer* temp = new ServerPlayer();
	temp->id = _id;

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

void ServerPlayer::SavePlayer(unsigned int TeamID)
{
	using namespace ManaCraft::Database;

	try {
		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "INSERT INTO Team_Players VALUES (" << TeamID << ", " << mysqlpp::quote << id << ")";
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
