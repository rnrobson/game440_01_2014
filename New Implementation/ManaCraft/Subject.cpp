// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#include "Subject.h"
#include "Navigator.h"
#include "NavEvent.h"
#include "Observer.h"

//
//
// Subject::RegisterObserver()
//
//
void Subject::RegisterObserver(Observer* observer, NavEventType type) {
	// TODO: Make sure doesn't already exist
	switch (type) {
	case NavEventType::ARRIVE:
		m_observersArrive.push_back(observer);
		break;

	case NavEventType::LEAVE:
		m_observersLeave.push_back(observer);
		break;
	}
}

//
//
// Subject::RegisterNavigator()
//
//
void Subject::RegisterNavigator(Navigator* navigator) {
	m_navigators.push_back(navigator);
}

//
//
// Subject::UnregisterNavigator()
//
//
void Subject::UnRegisterNavigator(Navigator* navigator) {
	std::vector<Navigator*>::iterator navObject = std::find(m_navigators.begin(), m_navigators.end(), navigator);

	if (navObject != m_navigators.end()) {
		m_navigators.erase(navObject);
	}
}

//
//
// Subject::BroadcastArrive()
//
//
void Subject::BroadcastArrive(Navigator* navigator) {
	NavEvent n_evt;
	n_evt.type = NavEventType::ARRIVE;
	n_evt.navigator = navigator;

	for (int i = 0; i < m_observersArrive.size(); ++i) {
		m_observersArrive[i]->Execute(n_evt);
	}
}

//
//
// Subject::BroadcastLeave()
//
//
void Subject::BroadcastLeave(Navigator* navigator) {
	NavEvent n_evt;
	n_evt.type = NavEventType::LEAVE;
	n_evt.navigator = navigator;

	for (int i = 0; i < m_observersLeave.size(); ++i) {
		m_observersLeave[i]->Execute(n_evt);
	}
}

//
//
// Subject::GetNavigators()
//
//
const std::vector<Navigator*>& Subject::GetNavigators() const {
	return m_navigators;
}