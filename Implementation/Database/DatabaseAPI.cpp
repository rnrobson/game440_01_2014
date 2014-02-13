#include "DatabaseAPI.h"

using namespace ManaCraft::Database;

bool DatabaseAPI::connectToDatabase(std::string db_Name, std::string server, std::string login, std::string password)
{}

void  DatabaseAPI::disconnectFromDatabase()
{}


void  DatabaseAPI::getTowerInfo(TowerTypes tower)
{}

void  DatabaseAPI::getAllTowerInfo()
{}


void  DatabaseAPI::getMinionInfo(MinionTypes minion)
{}

void  DatabaseAPI::getAllMinionInfo()
{}


void  DatabaseAPI::getElementInfo(ElementTypes element)
{}

void  DatabaseAPI::getAllElementInfo()
{}

void  DatabaseAPI::getResistanceInfo(ElementTypes element)
{}

void  DatabaseAPI::getAllResistanceInfo()
{}


void  DatabaseAPI::saveGame()
{}

void  DatabaseAPI::getSaveGame(unsigned int saveID)
{}

void  DatabaseAPI::getPlayerInfo(std::string name)
{}