#pragma once

class ServerToDatabase:
{
	//public variables or methods
public:
	//constructor
	ServerToDatabase();

	//destructor
	~ServerToDatabase();

	///<summary>establish a connection between server and database
	///database could ask for key so that not just any server can access database </summary>
	void connectToDatabase();

	//Once the program is closed, connection will end
	void disconnectToDatabase();

	///<summary>basic sending and getting data from the connected database to be used for testing
	///these will later be more specific once we confirm what we want to send and take from database
	///obtained data will be sent to where it would be used
	///sent data will be stored in the apporpriate places</summary>
	void getData();
	void sendData();	
}