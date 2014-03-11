#pragma once

#include <string>

/// <summary> author : Brian Lefrancois   
/// <para>NetworkCommands are used by the client send messages over the network aswell as execute messages </para>
/// <para>that are recieved from the network</para>
/// <para> for the most part complete. need to verify data to pass over network
/// </summary>

class NetworkCommands
{
public:
	/// <summary> 
	/// <para>ReciveMessage(short protocol, byte* data)</para>
	/// <para>Used only by the ServerLiason. (located at Client/ServerLiasion.cpp)</para>
	/// </summary>
	
	//Main connection updates
	void ClientDropped(std::string username);
	void ClientJoined(std::string username);
	void ClientRejoin(std::string username);
	void ReturnLogInStatus(bool status);

	//Incoming Chat messages
	void RecievePartyMessage(std::string username, std::string message);
	void RecieveLobbyMessage(std::string username, std::string message);
	void RecieveWhisper(std::string username, std::string message);

	//get a single game lobby at a time with hostName and num of Players
	void RefreshLobby(short gameID, short numOfPlayers, std::string hostName);
	
	//GameLobby incoming commands
	void ReturnJoinGameStatus(bool status);
	void ReturnCreateGameStatus(bool status);
	void ReturnDisbandGame();
	void ReturnJoinTeam(short TeamID, std::string username);
	void ReturnBenchPlayer(std::string username);
	void UpdateGamePlayOptions();//TODO What commands

	



	



	/// <summary>
	/// <para>Following Commands are for Client to send messages over the network to the server</para>
	/// Example::Used by client only. for example, after LogIn Button is </para>
	/// <para>pressed, NetworkCommands::LogIn(*UserInputedTextField); would be called </para>
	/// </summary>
	
	//Main Connection
	void LogIn(std::string userName); //will connect to server and give the username
	void LogOut(); //will close connection and clear username
	void CloseGame();//will close connection and close the entire game

	//LobbyView
	void RefreshLobbies();//Will ask server to give current rooms created
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












};