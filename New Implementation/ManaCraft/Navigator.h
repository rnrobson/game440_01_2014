// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include "Vec3f.h"

class Waypoint;

class Navigator {
private:
	Waypoint* m_pWaypoint;

	Vec3f m_dest;

protected:
	virtual void OnWaypointArrive() = 0;

	void SetDestination(Vec3f dest);

	Waypoint* GetCurrentWaypoint() const;
	const Vec3f& GetCurrentDestination() const;

public:
	Navigator();

	void SetWaypoint(Waypoint* wp);
};