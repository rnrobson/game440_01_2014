#pragma once

#include <vector>
#include "DatabaseAPI.h"

using namespace std;

class ServerPlayer
{
public:
	unsigned int id;

	ServerPlayer();
	~ServerPlayer();
	vector<ServerPlayer*> *Team;

	static ServerPlayer* LoadPlayerByID(int _id);
};

