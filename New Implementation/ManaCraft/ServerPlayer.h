#pragma once

#include <vector>

using namespace std;

class ServerPlayer
{
public:
	ServerPlayer();
	~ServerPlayer();
	vector<ServerPlayer*> *Team;
};

