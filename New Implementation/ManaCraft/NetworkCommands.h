#pragma once
#include <iostream>
#include "Packet.h"
#include "NetClient.h"
#include "BlockingQueue.h"

#include <string>
typedef char Byte;
/// <summary> author : Brian Lefrancois   
/// <para>NetworkCommands are used by the client send messages over the network aswell as execute messages </para>
/// <para>that are recieved from the network</para>
/// <para> for the most part complete. need to verify data to pass over network
/// </summary>

namespace ManaCraft {
	namespace Client {
		class NetworkCommands
		{
		public:
			/// <summary> 
			/// <para>The following is a list of commands that will be triggered by recieved</para>
			/// <para>messages over the network.
			/// <para>Used only by the ServerLiason. (located at Client/ServerLiasion.cpp)</para>
			/// </summary>

			//Main connection updates
			//void ClientDropped(std::string username);
			//void ClientJoined(std::string username); //this refers to a player joining the game you are in
			//void ClientRejoin(std::string username);//was in GDD, incase a player drops and rejoins. 
			//void ReturnLogInStatus(bool status);

			//Incoming Chat messages
			//void RecievePartyMessage(std::string username, std::string message);
			//void RecieveLobbyMessage(std::string username, std::string message);
			//void RecieveWhisper(std::string username, std::string message);

			//get a single game lobby at a time (up to 5 games)with hostName and num of Players.
			//GameLobby
			//void RecieveRefreshedLobby(std::string hostName, short gameID, short numOfPlayers); 

			//Pre-GameLobby incoming commands
			//void ReturnJoinGameStatus(bool status);
			//void ReturnGameData(short gameID, int options);//TODO::not sure how options will be handles


			//void ReturnCreateGameStatus(bool status);

			//GameLobby incoming commands
			//void ReturnDisbandGame();
			//void ReturnPlayerReadyStatus(std::string username);
			//void ReturnJoinTeam(short TeamID, std::string username);
			//void ReturnBenchPlayer(std::string username);
			//void UpdateGamePlayOptions();//TODO What commands


			/// <summary>
			/// <para>Following Commands are for Client to send messages over the network to the server</para>
			/// <para>Used by client only. for example, after LogIn Button is </para>
			/// <para>pressed, NetworkCommands::LogIn(UserInputedTextField); would be called </para>
			/// </summary>

			//Main Connection
			static void LogIn(std::string userName); //will connect to server and give the username
			static void LogOut(); //will close connection and clear username
			static void CloseGame();//will close connection and close the entire game

			//LobbyView
			static void RefreshGames();//Will ask server to give 5 rooms already created
			static void CreateGame();
			static void JoinGame(int gameID);

			//Lobby
			void PickTeam(short team);
			void BenchMe();
			void ToggleReadyStatus();
			void UpdateOptions();
			void LeaveGame(int gameID);
			void DisbandGame(int gameID); //used only by Host
			void SetOptions(); //used only by Host
			void StartTheGame();//used only by Host

			//Chat
			void SendLobbyMessage(std::string *message);
			void SendPartyMessage(std::string *message);
			void SendWhisperMessage(std::string *recieverUserName, std::string *message);

			//Gameplay
			void Pause();//TODO::aparently 2 people need to requests pause so maybe get username
			void Unpause();
			void RequestPlaceTower(short TowerType, float posX, float posY);//TODO::FIX dont know how client is handling towerType or positions//UniqueID?
			void RequestSpawnMinion(short MinionType, short PathChosen);//PathChosen cause i think players can spawn minions at 3 positions
			void ResearchTower();
			void ResearchMinion();
			void KillMinion(short UniqueID);//TODO::FIX dont know if server will need a unique ID to remove minion












		};
	}
};