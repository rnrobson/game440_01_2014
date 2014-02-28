#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H

namespace ManaCraft {
	namespace Database {

		/// <summary> Enumeration of the different types of towers in the game. </summary>
		enum TowerTypes
		{
			FLAME = 1,
			FIREBALL,
			IGNITER,
			WATER_BLAST,
			TIDAL_WAVE,
			FROST_BEAM,
			ROCK_SHARD,
			EARTHQUAKE,
			BOULDER,
			GUST,
			LIGHTNING,
			WIND_SLASH,
			ARROW,
			CANNON,
			BALLISTA
		};

		/// <summary> Enumeration of the different types of Minions in the game. </summary>
		enum MinionTypes
		{
			BLAZELINGS = 1,
			BLAZE_ELEMENTAL,
			FIRE_LORDS,
			SEA_SPRAY,
			WATER_ELEMENTAL,
			TIDAL_LORD,
			PEBBLE,
			ROCK_ELEMENTAL,
			GRANITE_LORD,
			GUST_M,
			EIND_ELEMENTAL,
			STORM_LORD,
			GARDEN_SPIDER,
			TARANTULA,
			GOLIATH_SPIDER
		};

		/// <summary> Enumeration of the different types of Elements in the game. </summary>
		enum ElementTypes
		{
			FIRE = 1,
			WATER,
			WIND,
			EARTH,
			NORMAL
		};
	}
}
#endif