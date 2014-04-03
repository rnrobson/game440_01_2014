#pragma once
#ifndef CLIENT_SETTINGS_H
#define CLIENT_SETTINGS_H

#include <string>
#include <vector>
#include "Gamestate.h"

class ClientSettings
{
public:
	ClientSettings();
	~ClientSettings();

	Gamestate GameState = GS_None;

	static std::string Username;
	bool loggedIn;
	bool isHost;
};

#endif