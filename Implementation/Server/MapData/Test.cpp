#include "MapData.h"

MapData* mapData;

int main(int argc, char ** argv)
{
	
	mapData = new MapData();
	mapData->ReadMapXML();
	mapData->DisplayMapData();

	getchar();
	return 0;
}