#pragma once

#include "Connection.h"
#include "Protocol.h"

/// <summary> author : Brian Lefrancois   //WORK IN PROGRESS
/// <para>NetworkCommands are used to send messages over the network aswell as it will execute messages that are recieved from the network</para>
/// <para>For Sending: Will require the protocol(Networking/Protocol.h) as well as the data if required. for example: a LogIn command would</para>
/// <para>require the username the client typed in. While a LogOut command would require just the protocol since the server knows the client's</para>
/// <para>username.
/// </summary>

class NetworkCommands
{
public:
	/// <summary> 
	/// <para>ReciveMessage(short protocol, byte* data)</para>
	/// <para>Used only by the ServerLiason. (located at Client/ServerLiasion.cpp)</para>
	/// <para>When a message is recieved from the network it will place the protocol in a switch and parse the byte array to extract the data.</para>
	/// <para>Will always call a method on the client such as a player joining the room, or a player has set his status to "Ready to Play" in the Lobby</para>
	/// </summary>

	//void RecieveMessage(short protocol, byte* data);

	/// <summary>
	/// <para>Following Commands are for Client to send messages over the network to the server</para>
	/// </summary>
	//Sending messages to the server
	//Used by client. for example, after LogIn is pressed, NetorkCommands::LogIn(*UserInputedTextField); would be called

	//Main Connection
	void LogIn(std::string userName); //will connect to server and give the username
	void LogOut(); //will close connection and clear username
	void CloseGame();//will close connection and close the entire game

	//LobbyView
	void RefreshLobbies();//Will ask server to give current room created
	void CreateLobby();
	void JoinLobby();

	//Lobby
	void PickTeam(short team);
	void BenchMe();
	void ToggleReadyStatus();
	void UpdateOptions();
	void LeaveLobby();
	void CloseLobby(); //used only by Host
	void SetOptions(); //used only by Host
	void StartTheGame();//used only by Host

	//Chat
	void SendLobbyMessage(std::string *message);
	void SendPartyMessage(std::string *message);
	void SendWhisperMessage(std::string *recieverUserName, std::string *message);

	//Gameplay
	void Pause();
	void Unpause();
	void RequestPlaceTower(short TowerType, float posX, float posY);//TODO::FIX dont know how client is handling towerType or positions
	void RequestSpawnMinion(short MinionType, short PathChosen);//PathChosen cause i think players can spawn minions in 3 positions
	void ResearchTower();
	void ResearchMinion();
	void KillMinion(short UniqueID);//TODO:FIX dont know if server will need a unique ID to remove minion




private:
	/// <summary>
	/// <para>The following Commands are for when the Client recieves messages</para>
	/// <para>All of these will be called from RecieveMessage method at the top</para>
	/// <para>the Clients ServerLiaison.cpp will call RecieveMessage</para>

	/// <para>TODO:Ultimately, these commands should be in specific classes within the client rather than here</para>
	/// <para>So if a messages comes in with protocol SPAWN_MINION, this class will </para>
	/// <para>call a method like GamePlayManager::PlaceMinion(Username, MinionType, Position); 
	/// </summary>








};