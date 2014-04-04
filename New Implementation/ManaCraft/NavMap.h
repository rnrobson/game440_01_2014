// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include <list>

#include "NavMapKDTree.h"
#include "Waypoint.h"
#include "Vec3f.h"

class NavMap {
private:
	const int MAX_WAYPOINT_DIST = 2;

	std::list<Waypoint*> m_waypoints;
	NavMapKDTree m_mapTree;

	void CleanUp();

public:
	NavMap();
	~NavMap();

	void AddWaypoint(Vec3f pos, int weight);
	void AddWaypointObserver(Observer* observer, Vec3f pos);

	Waypoint* First();
	Waypoint* NearestWaypoint(Vec3f pos);
	void GetNavigatorsInRange(Waypoint* entry, Waypoint* exit, std::vector<Navigator*>& container);
};