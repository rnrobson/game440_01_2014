// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "NavMap.h"

#include <algorithm>
//#include <gl/glut.h>

//
//
// NavMap
//
//
NavMap::NavMap() {
}

//
//
// NavMap::AddWaypoint()
//
//
void NavMap::AddWaypoint(Vec3f pos, int weight) {
	Waypoint* wp = new Waypoint(pos, weight);

	if (m_waypoints.size() > 0) {
		m_waypoints.back()->e_next = wp;
		wp->e_prev = m_waypoints.back();
		m_waypoints.back()->m_isLastWaypoint = false;
	}

	wp->m_isLastWaypoint = true;
	m_waypoints.push_back(wp);
	mapTree.Insert(wp);

	if (!m_waypoints.front()->m_isFirstWaypoint) {
		m_waypoints.front()->m_isFirstWaypoint = true;
	}
}

//
//
// NavMap::AddWaypointObserver()
//
//
void NavMap::AddWaypointObserver(Observer* observer, Vec3f pos) {
	Waypoint* wp = mapTree.NearestWaypoint(pos);

	Waypoint* entry = wp, *exit = wp;

	// Find the entry point
	for (int i = 0; i < MAX_WAYPOINT_DIST; ++i) {
		if (entry->e_prev) {
			entry = entry->e_prev;
		}
	}
	entry->RegisterObserver(observer, NavEventType::ARRIVE);
	observer->SetEntryPoint(entry);

	// Find the exit point
	for (int i = 0; i < MAX_WAYPOINT_DIST; ++i) {
		if (exit->e_next) {
			exit = exit->e_next;
		}
	}
	exit->RegisterObserver(observer, NavEventType::LEAVE);
	observer->SetExitPoint(exit);
}

//
//
// NavMap::First()
//
//
Waypoint* NavMap::First() {
	return m_waypoints.front();
}

//
//
// NavMap::NearestWaypoint()
//
//
Waypoint* NavMap::NearestWaypoint(Vec3f pos) {
	return mapTree.NearestWaypoint(pos);
}

//
//
// NavMap::GetNavigatorsInRange()
//
//
void NavMap::GetNavigatorsInRange(Waypoint* entry, Waypoint* exit, std::vector<Navigator*>& container) {
	Waypoint* currWP = entry;
	while (currWP != exit->e_next) {
		std::vector<Navigator*> navigatorsAtWP = currWP->GetNavigators();

		if (navigatorsAtWP.size() > 0) {
			for (unsigned int i = 0; i < navigatorsAtWP.size(); ++i) {
				// This isn't the best way to approach this, I don't think... but stuff needs to get implementedddddd
				std::vector<Navigator*>::iterator navigatorFound = std::find(container.begin(), container.end(), navigatorsAtWP[i]);

				if (navigatorFound == container.end()) {
					container.push_back(navigatorsAtWP[i]);
				}
			}
		}

		currWP = currWP->e_next;
	}
}

//int NavMap::GetNavigatorsInRange(Waypoint* entry, Waypoint* exit, Navigator*** navBuf) {
//	std::vector<Navigator*> navigators;
//
//	Waypoint* currWP = entry;
//	while (currWP != exit->e_next) {
//		std::vector<Navigator*> waypointNavs = currWP->GetNavigators();
//
//		if (waypointNavs.size() > 0) {
//			for (unsigned int j = 0; j < waypointNavs.size(); ++j) {
//				std::vector<Navigator*>::iterator navigator = std::find(navigators.begin(), navigators.end(), waypointNavs[j]);
//
//				if (navigator == navigators.end()) {
//					navigators.push_back(waypointNavs[j]);
//				}
//			}
//		}
//
//		currWP = currWP->e_next;
//	}
//
//	const int numNavs = navigators.size();
//	*navBuf = new Navigator*[numNavs];
//
//	// TODO: Why is this throwing an access violation @ 0xCCCCCCCCCC
//	for (unsigned int i = 0; i < numNavs; ++i) {
//		*navBuf[i] = navigators[i];
//	}
//
//	return numNavs;
//}