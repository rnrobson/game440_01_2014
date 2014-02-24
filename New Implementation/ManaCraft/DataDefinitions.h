#ifndef DATA_DEFINITIONS_H
#define DATA_DEFINITIONS_H

namespace ManaCraft {
	namespace Database {

		/// <summary> Enumeration of the different types of towers in the game. </summary>
		enum TowerTypes
		{
			ARROW,
			CANNON,
			BALLISTA,
			FLAME,
			FIREBALL,
			IGNITER,
			WATER_BLAST,
			TIDAL_WAVE,
			FROST_BEAM,
			ROCK_SHARD,
			EARTHQUAKE,
			BOULDER,
			GUST_T,
			LIGHTNING,
			WIND_SLASH
		};

		/// <summary> Enumeration of the different types of Minions in the game. </summary>
		enum MinionTypes
		{
			GARDEN_SPIDER,
			TARANTULA,
			GOLIATH_SPIDER,
			BLAZELINGS,
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
			STORM_LORD
		};

		/// <summary> Enumeration of the different types of Elements in the game. </summary>
		enum ElementTypes
		{
			NORMAL,
			FIRE,
			WATER,
			WIND,
			EARTH
		};
	}
}
#endif