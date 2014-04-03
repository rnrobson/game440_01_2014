#pragma once

#include <vector>
#include <string>
#include "DatabaseAPI.h"

using namespace std;

class ServerPlayer
{
public:
	unsigned int id;
	string username;

	ServerPlayer();
	ServerPlayer(unsigned int _id);
	~ServerPlayer();
};

