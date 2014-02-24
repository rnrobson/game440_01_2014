#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

class MapData
{
public:
	int tileSize;
	int width;
	int height;
	char* levelName;

	MapData(){}
	~MapData(){}

	void ReadMapXML()
	{
		stringstream sTileSize, sWidth, sHeight,sLevelName;
		xml_document<> doc;
		xml_node<>* root_node;
		ifstream file("MapData.xml");
		vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		buffer.push_back('\0');

		doc.parse<0>(&buffer[0]);

		root_node = doc.first_node("Map");
		sTileSize << root_node->first_attribute("tileSize")->value();
		sTileSize >> tileSize;
		sWidth << root_node->first_attribute("width")->value();
		sWidth >> width;
		sHeight << root_node->first_attribute("height")->value();
		sHeight >> height;
		int charSize = strlen(root_node->first_attribute("levelName")->value()) + 1;
		levelName = new char[charSize];
		int i;
		for (i = 0; i < charSize-1; i++)
		{
			levelName[i] = root_node->first_attribute("levelName")->value()[i];
		}
		levelName[i] = '\0';
	}
	void DisplayMapData()
	{
		printf("Map info: Tile Size: %i, Width: %i, Height : %i, Level Name : %s\n",
			tileSize, width, height, levelName);
	}
};