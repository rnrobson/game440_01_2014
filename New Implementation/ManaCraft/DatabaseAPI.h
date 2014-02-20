#ifndef DATABASE_API_H
#define DATABASE_API_H

#include <string>
#include <vector>
#include <mysql++.h>
#include "DataDefinitions.h"
#include "TableInfo.h"

//-- Data Structures
#include "Element.h"

//		NOTES FROM VINNY
////////////////////////////////////////////////////////////
//	- Could rename functions for default data to "fetch..." to avoid confusion between default values and saved values.
//	- Possibly add DBNotConnectedException for functions? or sumin'
//	- Consider removing connectToDatabase parameters and using private constants

namespace ManaCraft {
	namespace Database {

		using namespace mysqlpp;
		class DatabaseAPI {

		private:
			Connection conn;

		public:
			DatabaseAPI();
			~DatabaseAPI();

			/// <summary> Establishes a connection to a database.
			/// <para>[string] Name of the data base to connect to. </para>
			/// <para>[string] Server IP Address to connect to. </para>
			/// <para>[string] Login account name. </para>
			/// <para>[string] Login password. </para>
			/// <returns>[Returns] a bool. True if connection was established. </returns>
			/// </summary>
			bool connectToDatabase(const std::string& db_Name, const std::string& server, const std::string& login, const std::string& password);

			/// <summary> Disconnects from the database if a connection is already established. </summary>
			void disconnectFromDatabase();

			/// <summary> Get information of specific tower of TowerType. </summary>
			void getTowerInfo(const TowerTypes tower);
			/// <summary> Get information on all the Towers. </summary>
			void getAllTowerInfo();

			/// <summary> Get information of specific minion of MinionType. </summary>
			void getMinionInfo(const MinionTypes minion);
			// <summary> Get information on all Minions. </summary>
			void getAllMinionInfo();

			/// <summary> Get information of specific element of ElementType. </summary>
			void getElementInfo(const ElementTypes element);
			// <summary> Get information on all Elements. </summary>
			std::vector<Element> getAllElementInfo();

			/// <summary> Get information of specific Resistance of ElementType. </summary>
			void getResistanceInfo(const ElementTypes element);
			// <summary> Get information on all Resistances. </summary>
			void getAllResistanceInfo();

			/// <summary> Saves the current game being played. </summary>
			void saveGame(); //TODO: lol figure how this is going to work
			/// <summary> Pulls information for a Save Game
			void getSaveGame(const unsigned int& saveID);

			/// <summary> Get a players information from the database.
			/// <para>[string] Username of the player.
			/// </summary>
			void getPlayerInfo(const std::string& name);

		};
	}
}
#endif