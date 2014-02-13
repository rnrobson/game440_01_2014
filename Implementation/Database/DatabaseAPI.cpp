#include "DatabaseAPI.h"

using namespace ManaCraft::Database;

bool DatabaseAPI::connectToDatabase(const std::string& db_Name, const std::string& server, const std::string& login, const std::string& password);
{}

void  DatabaseAPI::disconnectFromDatabase()
{}


void  DatabaseAPI::getTowerInfo(const TowerTypes tower)
{}

void  DatabaseAPI::getAllTowerInfo()
{}


void  DatabaseAPI::getMinionInfo(const MinionTypes minion)
{}

void  DatabaseAPI::getAllMinionInfo()
{}


void  DatabaseAPI::getElementInfo(const ElementTypes element)
{}

void  DatabaseAPI::getAllElementInfo()
{}

void  DatabaseAPI::getResistanceInfo(const ElementTypes element)
{}

void  DatabaseAPI::getAllResistanceInfo()
{}


void  DatabaseAPI::saveGame()
{}

void  DatabaseAPI::getSaveGame(const unsigned int saveID)
{}

void  DatabaseAPI::getPlayerInfo(const std::string& name)
{}