#include "Teams.h"
#include "ServerIncludes.h"
Teams::Teams(int teamSize)
{
	PlayerCount = 0;
	MaxPlayers = 2 * teamSize;
}

Teams::Teams()
{
	PlayerCount = 0;
	MaxPlayers = 0;
}

Teams::~Teams(void)
{
}

void Teams::EnterNewPlayer(ServerPlayer *player)
{
	//If game is not full:
	//++ player count.
	//Add player to bench.
	if (PlayerCount < MaxPlayers)
	{
		PlayerCount++;
		Bench.push_back(player);
		player->Team = &Bench;
	}
}

void Teams::PlayerChangeTeam(ServerPlayer *player, vector<ServerPlayer*> *toTeam)
{
	//If target team is not full:
	//If player exists in a team:
	//Remove player from team.
	//Add to target team.

	unsigned int teamCap;
	if (toTeam == &Bench)
	{
		teamCap = MaxPlayers;
	}
	else
	{
		teamCap = MaxPlayers / 2;
	}

	if (toTeam->size() < teamCap)
	{
		if (FindAndRemove(player))
		{
			toTeam->push_back(player);
			player->Team = toTeam;
		}
	}
}

void Teams::KickPlayer(ServerPlayer *player)
{
	//If player exists in a team:
	//Remove player from team.
	//-- player count.
	if (FindAndRemove(player))
	{
		PlayerCount--;
	}
}

bool Teams::FindAndRemove(ServerPlayer *player)
{
	for (unsigned int i = 0; i < Team1.size(); i++)
	{
		if (Team1.at(i) == player)
		{
			Team1.erase(Team1.begin() + i);
			player->Team = NULL;
			return true;
		}
	}

	for (unsigned int i = 0; i < Team2.size(); i++)
	{
		if (Team2.at(i) == player)
		{
			Team2.erase(Team2.begin() + i);
			player->Team = NULL;
			return true;
		}
	}

	for (unsigned int i = 0; i < Bench.size(); i++)
	{
		if (Bench.at(i) == player)
		{
			Bench.erase(Bench.begin() + i);
			player->Team = NULL;
			return true;
		}
	}

	return false;
}

Teams* Teams::LoadTeamsByIDs(int _team1ID, int _team2ID) {
	using namespace ManaCraft::Database;
	
	// Create teams
	Teams* temp = new Teams();

	temp->Team1 = vector<ServerPlayer*>();
	temp->team1ID = _team1ID;

	temp->Team2 = vector<ServerPlayer*>();
	temp->team2ID = _team2ID;

	try {
		Query query = DatabaseAPI::getQuery();
		
		// Team_Players table
		for (int i = 0; i < 2; ++i) {	// for each team
			query.clear();
			query << "SELECT * FROM Team_Players WHERE TeamID = " << mysqlpp::quote << (i == 0 ? temp->team1ID : temp->team2ID);

			if (UseQueryResult result = query.use()) {
				for (int j = 0; j < 3; ++j) {	// for each possible player
					if (Row row = result.fetch_row()) {

						// Create player
						ServerPlayer* player;
						int playerID = atoi(row[TableInfo::TeamPlayers::PLAYER_ID].c_str());

						player = ServerPlayer::LoadPlayerByID(playerID);
						player->Team = (i == 0 ? &(temp->Team1) : &(temp->Team2));

						if (i == 0) {
							temp->Team1.push_back(player);
						}
						else {
							temp->Team2.push_back(player);
						}

					}
					// First row fetch with no result means no result returned from DB, IDNotFound
					else if (j == 0) {
						throw DatabaseAPI::IDNotFoundException();
					}
				}
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

void Teams::DeleteTeams() {
	using namespace ManaCraft::Database;

	try {
		for (int i = 0; i < 2; ++i) {	// for each team
			Query query = DatabaseAPI::getQuery();
			query.clear();
			query << "DELETE FROM Team WHERE ID =" << mysqlpp::quote << (i == 0 ? this->team1ID : this->team2ID);
			query.execute();

			query = DatabaseAPI::getQuery();
			query.clear();
			query << "DELETE FROM Team_PLayers WHERE ID =" << mysqlpp::quote << (i == 0 ? this->team1ID : this->team2ID);
			query.execute();
		}

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

void Teams::SaveTeams(unsigned int GameID) {
	using namespace ManaCraft::Database;

	try {
		for (int i = 0; i < 2; ++i) {	// for each team
			
			Query query = DatabaseAPI::getQuery();
			query.clear();
			query << "INSERT INTO Team VALUES (" << mysqlpp::quote << (i == 0 ? this->team1ID : this->team2ID) << ", " << mysqlpp::quote << "Team LEEET" << ")";
			query.execute();

			query = DatabaseAPI::getQuery();
			query.clear();
			query << "INSERT INTO Game_Teams VALUES (" << mysqlpp::quote << GameID << ", " << mysqlpp::quote << (i == 0 ? this->team1ID : this->team2ID) << ")";
			query.execute();

			if (i == 0)
			{
				for (ServerPlayer* p : Team1)
				{
					p->SavePlayer(team1ID);
				}
			}
			else
			{
				for (ServerPlayer* p : Team2)
				{
					p->SavePlayer(team2ID);
				}
			}
		}

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