#include "GridLayer.h"


GridLayer::GridLayer(void)
{
}

GridLayer::GridLayer(char tileSize, unsigned int rows, unsigned int columns)
{
	this->tileSize = tileSize;
	this->rows = rows;
	this->columns = columns;
}

GridLayer::~GridLayer(void)
{

}

int GridLayer::SerializedSize(Data datatype){

	if (datatype == Data::EVERYTHING){

		return sizeof(__int32) +sizeof(__int32) + sizeof(char);  //The size of 2 unsigned int32s and 1 char representing the tilesize


	}
	else return 0;


}

bool GridLayer::Serialize(char* bytes, Data data){

	if (data == Data::EVERYTHING){

		char* bytesResult = new char[SerializedSize(Data::EVERYTHING)];
		bytesResult[0] = tileSize;
		char* rowBytes = new char[4];
		char* columnBytes = new char[4];
		SerializeInt32(rowBytes, rows);
		SerializeInt32(columnBytes, columns);
		for (int i = 0; i < 4; i++){

			bytesResult[1 + i] = rowBytes[i];
			bytesResult[4 + i] = columnBytes[i];

		}

		bytes = bytesResult;

		//Cleaning up
		delete[] rowBytes;
		delete[] columnBytes;

		return true;
	}
	else return false; // there is no health / position available in this class
	

	


}

bool GridLayer::Deserialize(char* data){

	if (std::strlen(data) < SerializedSize(Data::EVERYTHING))
	{
		return false;
	
	}
	else{

		tileSize = data[0];
		char* rowData = new char[4];
		char* columnData = new char[4];

		for (int i = 0; i < 4; i++){

			rowData[i] = data[1 + i];
			columnData[i] = data[4 + i];


		}

		rows = DeserializeInt32(rowData);
		columns = DeserializeInt32(columnData);

		//Cleaning up
		delete[] rowData;
		delete[] columnData;

		return true;
	}
}