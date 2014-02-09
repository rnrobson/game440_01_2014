#pragma once
#include <vector>
#include <Serializable.h>
#include <Serialize.h>

using namespace ManaCraft::Networking;

class GridLayer : public Serializable, public Deserializable
{
public:
	char tileSize;
	unsigned int rows;
	unsigned int columns;

	GridLayer(void);
	~GridLayer(void);
	GridLayer(char tileSize, unsigned int rows, unsigned int columns);

	bool Serialize(char* byte, Data requiredData);
	int SerializedSize(Data dataType);
	bool Deserialize(char* data);
};

