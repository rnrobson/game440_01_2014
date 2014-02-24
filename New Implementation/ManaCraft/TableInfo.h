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
				const static unsigned int ID				= 0;
				const static unsigned int TYPE				= 1;
				const static unsigned int WEAKNESS			= 2;
				const static unsigned int STRENGTH			= 3;
			};

			const static struct Minion {
			public:
				const static unsigned int ID				= 0;
				const static unsigned int NAME				= 1;
				const static unsigned int X_POS				= 2;
				const static unsigned int Y_POS				= 3;
				const static unsigned int COST				= 4;
				const static unsigned int DAMAGE			= 5;
				const static unsigned int ATTACK_RANGE		= 6;
				const static unsigned int FIRING_RATE		= 7;
				const static unsigned int DPS				= 8;
				const static unsigned int ATTACK_TYPE		= 9;
				const static unsigned int ELEMENT			= 10;
				const static unsigned int SELL_AMOUNT		= 11;
				const static unsigned int SUMMON_COST		= 12;
				const static unsigned int UPGRADE_COST		= 13;
				const static unsigned int RESEARCH_COST		= 14;
				const static unsigned int RESISTANCES		= 15;
				const static unsigned int HEALTH			= 16;
			};

		};

	}
}

#endif