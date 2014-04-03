// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include <vector>

#include "Subject.h"
#include "Navigator.h"
#include "Observer.h"
#include "Vec3f.h"

class Waypoint : public Subject {
private:
	Waypoint* e_next;
	Waypoint* e_prev;

	Vec3f m_pos;

	int m_priority;

	bool m_isFirstWaypoint;
	bool m_isLastWaypoint;

	friend class NavMap;

protected:
public:
	Waypoint();
	Waypoint(Vec3f pos, int priority);

	const bool IsLastWaypoint() const;
	const bool IsFirstWaypoint() const;

	Waypoint* Next();
	Waypoint* Prev();

	const Vec3f& Position() const;
};