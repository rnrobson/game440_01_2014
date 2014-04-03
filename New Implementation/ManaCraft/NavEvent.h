// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include <iostream>

class Navigator;

enum NavEventType {
	ARRIVE,
	LEAVE
};

typedef struct NavEvent {
	NavEventType type;
	Navigator* navigator;

	NavEvent() {}

	NavEvent(NavEvent& evt) {
		type = evt.type;
		navigator = evt.navigator;
	}
} NavEvent;