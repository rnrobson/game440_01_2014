#ifndef TABLE_INFO_H
#define TABLE_INFO_H

/// This header assigns constants for the int values of the columns of each table.
/// Structs below are used by the DatabaseAPI methods which query the database,
/// create objects, and assign fields based on these consts.

/// A NOTE ON COPYPASTING - To get the tabs to line up, CTRL + V, then CTRL + Z

#include <string>

namespace ManaCraft {
	namespace Database {
		namespace TableInfo {

			const struct Resistances {
			public:
				static std::string TABLE_NAME() { return "Resistances"; }
				const static unsigned char ID				= 0;
				const static unsigned char TYPE				= 1;
				const static unsigned char WIND_RESISTANCE	= 2;
				const static unsigned char FIRE_RESISTANCE	= 3;
				const static unsigned char WATER_RESISTANCE	= 4;
				const static unsigned char EARTH_RESISTANCE = 5;
				const static unsigned char NORM_RESISTANCE	= 6;
			};

			const struct Elements {
			public:
				static std::string TABLE_NAME() { return "Elements"; }
				const static unsigned char ID				= 0;
				const static unsigned char TYPE				= 1;
				const static unsigned char WEAKNESS			= 2;
				const static unsigned char STRENGTH			= 3;
			};

			const struct Minions {
			public:
				static std::string TABLE_NAME() { return "Minions"; }
				const static unsigned char ID				= 0;
				const static unsigned char ELEMENT			= 1;
				const static unsigned char NAME				= 2;
				const static unsigned char LEVEL			= 3;
				const static unsigned char HEALTH			= 4;
				const static unsigned char DAMAGE			= 5;
				const static unsigned char ARMOUR			= 6;
				const static unsigned char SPEED			= 7;
				const static unsigned char MPS				= 8;
				const static unsigned char COST				= 9;
				const static unsigned char SUMMON_COST		= 10;
				const static unsigned char UPGRADE_COST		= 11;
				const static unsigned char RESEARCH_COST	= 12;
			};

			const struct Towers {
			public:
				static std::string TABLE_NAME() { return "Towers"; }
				const static unsigned char ID				= 0;
				const static unsigned char ELEMENT			= 1;
				const static unsigned char NAME				= 2;
				const static unsigned char DAMAGE			= 3;
				const static unsigned char RANGE			= 4;
				const static unsigned char FIRING_RATE		= 5;
				const static unsigned char ATTACK_TYPE		= 6;
				const static unsigned char COST				= 7;
				const static unsigned char SUMMON_COST		= 8;
				const static unsigned char UPGRADE_COST		= 9;
				const static unsigned char RESEARCH_COST	= 10;
				const static unsigned char SELL_PRICE		= 11;
			};

			const struct Game {
			public:
				static std::string TABLE_NAME() { return "Game"; }
				const static unsigned char ID				= 0;
				const static unsigned char NAME				= 1;
			};

			const struct GameTeam {
			public:
				static std::string TABLE_NAME() { return "Game_Teams"; }
				const static unsigned char GAME_ID			= 0;
				const static unsigned char TEAM_ID			= 1;
			};

			const struct Team {
			public:
				static std::string TABLE_NAME() { return "Team"; }
				const static unsigned char ID				= 0;
				const static unsigned char Name				= 1;
			};

			const struct TeamPlayers {
			public:
				static std::string TABLE_NAME() { return "Team_Players"; }
				const static unsigned char TEAM_ID			 = 0;
				const static unsigned char PLAYER_ID		 = 1;
			};

		};

	}
}

#endif