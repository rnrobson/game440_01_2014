// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "Waypoint.h"

//
//
// Waypoint()
//
//
Waypoint::Waypoint() {
}

//
//
// Waypoint()
//
//
Waypoint::Waypoint(Vec3f pos, int priority) {
	m_pos = pos;
	m_priority = priority;
}

//
//
// Waypoint::Next()
//
//
Waypoint* Waypoint::Next() {
	return e_next;
}

//
//
// Waypoint::Prev()
//
//
Waypoint* Waypoint::Prev() {
	return e_prev;
}

//
//
// Waypoint::Position()
//
//
const Vec3f& Waypoint::Position() const {
	return m_pos;
}

//
//
// Waypoint::IsFirstWaypoint()
//
//
const bool Waypoint::IsFirstWaypoint() const {
	return m_isFirstWaypoint;
}

//
//
// Waypoint::IsLastWaypoint()
//
//
const bool Waypoint::IsLastWaypoint() const {
	return m_isLastWaypoint;
}