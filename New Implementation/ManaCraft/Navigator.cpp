// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "Navigator.h"
#include "Waypoint.h"

//
//
// Navigator()
//
//
Navigator::Navigator() {

}

//
//
// Navigator::SetWaypoint()
//
//
void Navigator::SetWaypoint(Waypoint* waypoint) {
	m_pWaypoint = waypoint;
}

//
//
// Nagivator::GetWaypoint()
//
//
Waypoint* Navigator::GetCurrentWaypoint() const {
	return m_pWaypoint;
}

//
//
// Navigator::SetDestination()
//
//
void Navigator::SetDestination(Vec3f dest) {
	m_dest = dest;
}

//
//
// Navigator::GetCurrentDestination()
//
//
const Vec3f& Navigator::GetCurrentDestination() const {
	return m_dest;
}