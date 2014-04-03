// ManaCraft AI/Navigation
// Josh O'Donnell
// April 2014

#pragma once

#include <vector>

class Observer;
class Navigator;
enum NavEventType;

class Subject {
private:
	std::vector<Observer*> m_observersArrive;
	std::vector<Observer*> m_observersLeave;
	std::vector<Navigator*> m_navigators;

public:
	void RegisterObserver(Observer* observer, NavEventType type);
	void RegisterNavigator(Navigator* navigator);
	void UnRegisterNavigator(Navigator* navigator);

	void BroadcastArrive(Navigator* navigator);
	void BroadcastLeave(Navigator* navigator);

	const std::vector<Navigator*>& GetNavigators() const;
};