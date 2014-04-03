// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "Observer.h"
#include "Waypoint.h"

//
//
// Observer()
//
//
Observer::Observer() {

}

//
//
// Observer::SetEntryPoint()
//
//
void Observer::SetEntryPoint(Waypoint* entry) {
	if (entry != NULL) {
		m_pEntryPoint = entry;
	}
}

//
//
// Observer::GetEntryPoint()
//
//
Waypoint* Observer::GetEntryPoint() const {
	return m_pEntryPoint;
}

//
//
// Observer::SetExitPoint()
//
//
void Observer::SetExitPoint(Waypoint* exit) {
	if (exit != NULL) {
		m_pExitPoint = exit;
	}
}

//
//
// Observer::GetExitPoint()
//
//
Waypoint* Observer::GetExitPoint() const {
	return m_pExitPoint;
}	