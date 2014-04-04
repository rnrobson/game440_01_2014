// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include "NavEvent.h"

class Waypoint;
class Navigator;

class Observer {
private:
	Waypoint* m_pEntryPoint;
	Waypoint* m_pExitPoint;

public:
	Observer();

	void SetEntryPoint(Waypoint* entry);
	void SetExitPoint(Waypoint* exit);
	
	virtual void Execute(NavEvent n_evt) = 0;

	Waypoint* GetEntryPoint() const;
	Waypoint* GetExitPoint() const;

};