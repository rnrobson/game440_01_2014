#include "GameModel.h"
#include "Element.h"
#include <algorithm>

static int lastID = -1;
int GameModel::nextID = 0;

GameModel::GameModel()
{
	id = 1;
	Init();
}
GameModel::GameModel(unsigned int _id)
{
	id = _id;
	Init();
}
GameModel::~GameModel(){}

void GameModel::PlaceTower()
{
	Tower* tower = new Tower();
	towers.push_back(tower);
	//add to navpath
}

void GameModel::UpdateMinions()
{
	//iterating backwards since we could be removing minions
	for (unsigned i = minions.size(); i-- > 0;)
	{
		//update pos -- not pathing right now because no map or pathing info exists
		minions[i]->xPos += minions[i]->speed;
		minions[i]->yPos += minions[i]->speed;

		//make sure collider is updated with position
		//casting minion position as ints for now - not sure what the game will require
		minions[i]->collisionBox->x = (int)round(minions[i]->xPos) - minions[i]->colWidth / 2;
		minions[i]->collisionBox->y = (int)round(minions[i]->yPos) - minions[i]->colHeight / 2;

		if (minions[i]->health <= 0)
		{
			//remove MpS bonus from player who had spawned it

			//find all the towers' target lists this minion is in and remove itself from them
			for (size_t j = 0; j < towers.size(); j++)
			{
				towers[i]->targetList.remove(minions[i]);
			}
			minions.erase(minions.begin() + i);
			continue;
		}

		//get reference to player to find out which base this minion should do damage to
		//assuming this is a light minion - will do damage to dark base
		SDL_Rect result;
		if (SDL_IntersectRect(darkBase->collisionBox, minions[i]->collisionBox, &result))
		{
			darkBase->TakeDamage(minions[i]->damage);
			//remove MpS bonus from player who had spawned it
			minions.erase(minions.begin() + i);
			continue;
		}
	}
	//let the clients in this game know to update it's minions (& playerbase?)

}
void GameModel::UpdateTowers(Uint32 dt)
{
	//loop through all the towers in this game
	for (size_t i = 0; i < towers.size(); i++)
	{
		//get the tower's position
		uint towerXPos=towers[i]->infSquare->xPos;
		uint towerYPos = towers[i]->infSquare->yPos;
		uint towerRange = towers[i]->range;

		//loop through all the minions in the game
		for (size_t j = 0; j < minions.size(); j++)
		{
			//difference in x coodrinates
			float xDif = abs(minions[i]->xPos - towerXPos);
			
			bool inRange = false;//will be flipped to true if a minion is in range

			//check if the minion is already present in the tower's list
			list<Minion*>::iterator findMinion = std::find(towers[i]->targetList.begin(), towers[i]->targetList.end(), minions[i]);

			//optimising distance search
			//minion won't be in range if the x value diff is greater than range
			if (xDif <= towerRange)
			{
				float yDif = abs(minions[i]->yPos - towerYPos);
				//same for y
				if (yDif <= towerRange)
				{
					//finally doing a dist check for accuracy
					float dist = sqrt(xDif*xDif + yDif * yDif);
					if (dist <= towerRange)
					{
						inRange = true;
					}
				}
			}

			//minion was not found in the tower's target list
			if (findMinion == towers[i]->targetList.end())
			{
				//if a minion is not present in the targetlist and is in range, it gets added to the list
				if (inRange)
				{
					towers[i]->targetList.push_back(minions[i]);
				}
			}
			//minion is already in the tower's target list
			else
			{
				//if minion moves past tower's range, remove it from the target list
				if (!inRange)
				{
					towers[i]->targetList.remove(minions[i]);
				}
			}
		}
		//check if the tower's reload timer is up
		Uint32 reloadTimer = (uint)round(1000 * towers[i]->firingRate);
		if (towers[i]->timer >= reloadTimer)
		{
			//the tower fires at the first minion in it's target list
			if (!towers[i]->targetList.empty())
			{
				towers[i]->FireAtMinion(towers[i]->targetList.front());
				towers[i]->timer = 0;
			}
		}
		towers[i]->timer += dt;
	}

	//let the clients in this game know to update it's towers (& minions?)
}
void GameModel::UpdateProjectiles()
{
	//iterating backwards since we could be removing projectiles
	for (unsigned i = projectiles.size(); i-- > 0;)
	{
		//move projectile
		projectiles[i]->xPos += projectiles[i]->xDir;
		projectiles[i]->yPos += projectiles[i]->yDir;

		//unoptimized linear collision check for now
		SDL_Rect result;
		for (size_t j = 0; j < minions.size(); j++)
		{
			if (SDL_IntersectRect(projectiles[i]->collisionBox, minions[j]->collisionBox, &result))
			{
				//projectile has hit the minion - do damage calculations

				//projectiles origin tower
				Tower* tower = projectiles[i]->origin;
				float towerBaseDamage = (float)tower->damage;
				//get the resist value to check based on tower's element
				int resist;
				switch (tower->elementID)
				{
				case ManaCraft::Database::ElementTypes::FIRE:
					resist = minions[i]->resists->fireResistance;
					break;
				case ManaCraft::Database::ElementTypes::EARTH:
					resist = minions[i]->resists->earthResistance;
					break;
				case ManaCraft::Database::ElementTypes::WATER:
					resist = minions[i]->resists->waterResistance;
					break;
				case ManaCraft::Database::ElementTypes::WIND:
					resist = minions[i]->resists->windResistance;
					break;
				default:
					resist = 0;
					break;
				}
				//reducing damage based on % reists
				float damageAfterResists = towerBaseDamage*(100 - resist) / 100;
				//reducing damage based on armour (out of 10)
				float finalDamage = damageAfterResists*(10 - minions[i]->armour) / 10;

				//converting damage to int for now beacause health is treated as an int
				int dmgToApply = (int)round(finalDamage);

				//applying damage to minion
				//minion health is setup as a uint so should not go below zero
				if (minions[i]->health >= dmgToApply)
					minions[i]->health -= dmgToApply;
				else
					minions[i]->health = 0;

				//despawn projectile after doing damage
				projectiles.erase(projectiles.begin() + i);
				continue;
			}
		}//minion loop ends

	}//projectile loop ends
	
}
void GameModel::UpdateEconomy(Uint32 dt)
{
		//loop through all players in the gameID
			//add MpS value to total mana
	
}


bool GameModel::CompareGamesByID(GameModel *gameOne, GameModel *gameTwo)
{
	return gameOne->id > gameTwo->id;
}


void GameModel::Init()
{
	minions.reserve(MAX_MINIONS);
	towers.reserve(MAX_TOWERS);
	projectiles.reserve(MAX_PROJECTILES);
	gridSquares.reserve(MAX_GRIDSQUARES);
	teams = new Teams(3);
	team1mps = 0.0f;
	team2mps = 0.0f;
	paused = false;

	darkBase = new PlayerBase(-100, 0, 1000, 20, 30);
	lightBase = new PlayerBase(80, 0, 1000, 20, 30);

	for (int i = 0; i < MAX_MINIONS; i++)
	{
		Minion* minion = new Minion();
		minion->id = i;
		minion->name = "Generic Minion";
		minion->health = 100;
		minion->xPos = 10.0f;
		minion->yPos = 20.0f;
		minion->colWidth = 10;
		minion->colHeight = 20;
		minion->collisionBox->x = (int)round(minion->xPos);// -minion->colWidth / 2;
		minion->collisionBox->y = (int)round(minion->yPos);// -minion->colHeight / 2;
		minion->collisionBox->w = minion->colWidth;
		minion->collisionBox->h = minion->colHeight;

		minion->manaPerSecond = 10.0f;
		minion->armour = 50;
		minion->speed = 3;
		minion->damage = 5;
		minion->researchCost = 50;
		minion->level = 1;
		minion->summonCost = 50;
		minions.push_back(minion);
	}
	for (int i = 0; i < MAX_TOWERS; i++)
	{
		Tower* tower = new Tower();
		tower->name = "Generic Tower";
		tower->id = i;
		tower->range = 20;
		tower->firingRate = 2.0f;
		tower->damage = 3;
		tower->attackType = 'd';
		tower->sellAmount = 50;
		tower->summonCost = 100;
		tower->zoneOfInfluence = 'v';
		tower->level = 1;
		tower->researchCost = 100;
		tower->upgradeCost = 50;
		tower->infSquare = new InfluenceSquare();
		tower->infSquare->xPos = 0;
		tower->infSquare->yPos = 0;
		towers.push_back(tower);

	}
	/*for (int i = 0; i < MAX_PROJECTILES; i++)
	{
		Projectile* projectile = new Projectile();
		projectiles.push_back(projectile);
	}*/
	for (int i = 0; i < MAX_GRIDSQUARES; i++)
	{
		GridSquare* gridsquare = new GridSquare();
		gridsquare->id = i;
		gridsquare->xPos = i;
		gridsquare->yPos = i;
		gridSquares.push_back(gridsquare);
	}


}

GameModel* GameModel::LoadGameByID(unsigned int _id) {
	using namespace ManaCraft::Database;

	GameModel* temp = new GameModel();
	temp->id = _id;

	try {
		Query query = DatabaseAPI::getQuery();
		
		// Game Table
		query.clear();
		query << "SELECT * FROM Game WHERE ID = " << mysqlpp::quote << _id;

		if (UseQueryResult result = query.use()) {
			if (Row row = result.fetch_row()) {
				// ASSIGN VALUES HERE once there is something to assign
			}
			else {
				throw DatabaseAPI::IDNotFoundException();
			}
		}

		// Game_Teams table
		int teamIDs[2];
		query.clear();
		query << "SELECT * FROM Game_Teams WHERE GameID = " << mysqlpp::quote << _id;

		if (UseQueryResult result = query.use()) {
			for (int i = 0; i < 2; ++i) {
				if (Row row = result.fetch_row()) {
					teamIDs[i] = atoi(row[TableInfo::GameTeam::TEAM_ID].c_str());	// Save team IDs
				}
				else {
					throw DatabaseAPI::IDNotFoundException();
				}
			}
		}

		// Load teams
		temp->teams = Teams::LoadTeamsByIDs(teamIDs[0], teamIDs[1]);

		if (temp->teams == nullptr) {
			// it dun broke, throw jank
		}

		// For each team
		for (int i = 0; i < 2; ++i) {
			vector<Player*>* team = &(i == 0 ? temp->teams->Team1 : temp->teams->Team2);
			
			// For each player
			for (size_t i = 0; i < team->size(); ++i) {
				Player* player = team->at(i);

				// Load towers
				query.clear();
				query << "SELECT * FROM Game_Player_Towers WHERE GameID = " << mysqlpp::quote << _id << "AND PlayerID = " << mysqlpp::quote << player->id;

				if (UseQueryResult result = query.use()) {
					while (Row row = result.fetch_row()) {
						Tower* tower = new Tower();
						tower->id = atoi(row[TableInfo::GamePlayerTowers::TOWER_ID].c_str());
						tower->xPos = atoi(row[TableInfo::GamePlayerTowers::X_POS].c_str());
						tower->yPos = atoi(row[TableInfo::GamePlayerTowers::Y_POS].c_str());

						// Add to lists
						player->towers.push_back(tower);
						temp->towers.push_back(tower);

						// After the GameModel is loaded, base tower info, which was loaded from the DB on startup, must be passed into their respective towers
						// This cannot be done from this static implementation
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

void GameModel::DeleteGame() {
	using namespace ManaCraft::Database;

	try {

		this->teams->DeleteTeams();

		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "DELETE FROM Game WHERE ID = " << mysqlpp::quote << this->id;
		query.execute();

		query = DatabaseAPI::getQuery();
		query.clear();
		query << "DELETE FROM Game_Teams WHERE ID = " << mysqlpp::quote << this->id;
		query.execute();

		query = DatabaseAPI::getQuery();
		query.clear();
		query << "DELETE FROM Game_Player_Towers WHERE ID = " << mysqlpp::quote << this->id;
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

void GameModel::SaveGame()
{
	using namespace ManaCraft::Database;

	// Game Table
	Query query = DatabaseAPI::getQuery();
	query.clear();
	query << "SELECT * FROM Game WHERE ID = " << mysqlpp::quote << id;

	if (UseQueryResult result = query.use()) {
		if (Row row = result.fetch_row()) {
			DeleteGame();
		}
	}

	try {
		query = DatabaseAPI::getQuery();
		query.clear();
		query << "INSERT INTO Game VALUES(" << mysqlpp::quote << id << ", " << mysqlpp::quote << "Another Game" << ")";
		query.execute();

		teams->SaveTeams(id);
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

void GameModel::LoadNextID() {
	using namespace ManaCraft::Database;

	try {
		Query query = DatabaseAPI::getQuery();
		query.clear();
		query << "SELECT MAX(ID) FROM Game";

		if (UseQueryResult result = query.use()) {
			if (Row row = result.fetch_row()) {
				nextID = atoi(row[TableInfo::Game::ID].c_str());
			}
			else {	// Table is empty
				nextID = 0;
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

int GameModel::GetNextID() {
	if (GameModel::nextID == -1) {
		// Databse hasn't been loaded yet silly billy
		// throw an error or something
	}
	else {
		return GameModel::nextID++;
	}
}