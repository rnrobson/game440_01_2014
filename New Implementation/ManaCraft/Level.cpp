#include "Level.h"


Level::Level(void)
{
	int pathSize = 10;
	//top path: starts at 10,10 and increase in the x by 70 each step
	//mid: starts at 10,50
	//bot: starts at 10,90
	for (size_t i = 0; i < pathSize; i++)
	{
		navPathTop.AddWaypoint(Vec3f(10.0f + i*70.0f, 10.0f), 0);
		navPathMid.AddWaypoint(Vec3f(10.0f + i*70.0f, 50.0f), 0);
		navPathBottom.AddWaypoint(Vec3f(10.0f + i*70.0f, 90.0f), 0);
	}
	
}


Level::~Level(void)
{
}
