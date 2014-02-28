#ifndef TABLE_INFO_H
#define TABLE_INFO_H

/// This header assigns constants for the int values of the columns of each table.
/// Structs below are used by the DatabaseAPI methods which query the database,
/// create objects, and assign fields based on these consts.

/// A NOTE ON COPYPASTING - To get the tabs to line up, CTRL + V, then CTRL + Z

namespace ManaCraft {
	namespace Database {
		namespace TableInfo {

			const static struct Elements {
			public:
				const static unsigned char ID				= 0;
				const static unsigned char TYPE				= 1;
				const static unsigned char WIND_RESISTANCE	= 2;
				const static unsigned char FIRE_RESISTANCE	= 3;
				const static unsigned char WATER_RESISTANCE	= 4;
				const static unsigned char EARTH_RESISTANCE = 5;
				const static unsigned char NORM_RESISTANCE	= 6;
			};

			const static struct Elements {
			public:
				const static unsigned char ID				= 0;
				const static unsigned char TYPE				= 1;
				const static unsigned char WEAKNESS			= 2;
				const static unsigned char STRENGTH			= 3;
			};

			const static struct Minions {
			public:
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

			const static struct Towers {
			public:
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

		};

	}
}

#endif