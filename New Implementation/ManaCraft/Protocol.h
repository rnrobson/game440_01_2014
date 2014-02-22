#ifndef PROTOCOL_H
#define PROTOCOL_H

namespace ManaCraft {
	namespace Networking {
		// Protocol documentation format is as follows:

		/// <summary> TODO
		/// <para>Data: TODO</para>
		/// </summary>

		// Due to issues with collaborative documents, this list here will be treated as the master list.
		// Note: This list is by no means complete as the requirements may change during the life time of the project, therefore
		// if a new protocol is required, then it can be easily added by contacting a member of the Networking team.

		/// <summary>The list of Server to Client protocols that will be sent over the network.</summary>

		const char* const SEC_HEAD = "MCFT";

		enum SC_Protocol : __int16 {
			// Connection type protocols are: 1150 - 1199
			// There are currently: 3/50
			
			/// <summary>Sends info to all clients in the case that someone disconnects
			/// <para>Data: [1] Username Length [N] Username </para>
			/// </summary>
			CLIENT_LOST = 1150,
			/// <summary>Sends info to all clients in the case someone reconnects
			/// <para>Data: [1] Username Length [N] Username </para>
			/// </summary> // Double check team 
			CLIENT_REJOIN,
			/// <summary>Returns information for successful/unsuccessful login
			/// <para>Data: [1] Username Length [N] Username [1] Successful/UnSuccessful</para>
			/// </summary> // Double check 
			RETURN_LOGIN_STATUS,



			// Chat oriented protocols are: 1225 - 1249
			// There are currently: 5/25

			/// <summary> Will send a message to all players in the specified game.
			/// <para> Data: [1] Username Length [N] Username [1] Length Of Message [N] Message</para>
			/// </summary>
			BROADCAST_MESSAGE_IG = 1225,
			/// <summary> Will send a message to all players within the same game lobby
			/// <para> Data: [1] Username Length [N] Username [1] Length Of Message [N] Message</para>
			/// </summary>
			BROADCAST_MESSAGE_GL,
			/// <summary>Sends the whisper to the client it was directed to
			/// <para>Data: [1] Username Length [N] Username [1] Reciever Name Length [N] Reciever Name</para>
			/// </summary>
			DISPLAY_WHISPER,
			/// <summary>Sends the message to all members of the party while in game.
			/// <para>Data: [1] Username Length [N] Username [1] Length Of Message [N] Message</para>
			/// </summary>
			BROADCAST_PARTY_MESSAGE_IG,
			/// <summary> Broadcasts the message to all players in the party while in the game lobby.
			/// <para> Data: [1] Username Length [N] Username [1] Length Of Message [N] Message</para>
			/// </summary>
			BROADCAST_PARTY_MESSAGE_GL,



			// Game Viewer oriented protocols are: 1275 - 1299
			// There are currently: 3/25

			/// <summary> Sends the current available games from the server to the client to be viewed
			/// <para>Data: TODO </para>
			/// </summary>
			POPULATE_GAMES = 1275,
			/// <summary> Sends over a notification letting the player know if they were able to join the selected game or not
			/// <para>Data: [1] Boolean, [4] GameID</para>
			/// </summary>
			RETURN_JOIN_GAME_STATUS,
			/// <summary> Sends over a notification letting the player know if their game was created or not.
			/// <para>Data: [1] Boolean, [4] GameID</para>
			/// </summary>
			RETURN_CREATED_GAME,



			// Game Lobby oriented protocols for Server are: 1350 - 1399
			// There are currently: 6/50

			/// <summary>Allows the server to send the data of all the clients viewing/joined the selected game 
			/// <para>This is used to send over ready statues, and if the players are benched or on a specific team</para>
			/// <para>Data: TODO</para>
			/// </summary>
			REFRESH_LOBBY = 1350,
			/// <summary>Returns the response to the host if the game was disbanded or not.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_DISBAND_GAME,
			/// <summary> Will notify all other players in the game lobby that the game has been disbanded, and should return to the game viewer.
			/// <para>Data: TODO</para>
			/// </summary>
			BROADCAST_DISBAND_GAME,
			/// <summary> Returns a response to the player if they were able to join the team or not.
			/// <para>Data: [1] Boolean</para> 
			/// </summary>
			RETURN_JOIN_TEAM,
			/// <summary>Returns a response to the player that requested to be benched, and if it was successful/unsucessful.
			/// <para>Data: [1] Boolean </para>
			/// </summary>
			RETURN_BENCH_PLAYER,
			/// <summary>When the gameplay options are updated by the host, this will be sent to all the clients within that game and notify them of the changes
			/// <para>Data: [1] Username Length [n] Username </para> 
			/// </summary>
			UPDATE_GAMEPLAY_OPTIONS,



			// Gameplay oriented protocols are: 1500 - 1599
			// There are currently: 9/100

			/// <summary> Notifies the player if the server was able to summon the minion or not
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			MINION_SUMMONED = 1500,
			/// <summary> Broadcasts the information of the minions being summoned to all the players in the game.
			/// <para>Data: [1] Minion Name [1] Position X [1] Position Y [1] TeamID</para>
			/// </summary>
			BROADCAST_SUMMON_MINION,
			/// <summary> Notifies the player if the server was unable or able to place the tower.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			TOWER_PLACED,
			/// <summary> Broadcasts the information of the tower to all the players in the game if the placement was successful.
			/// <para>Data: [1] Tower Name [1] Position X [1] Position Y [1] TeamID</para>
			/// </summary>
			BROADCAST_TOWER_PLACED,
			/// <summary> Updates the player's economy
			/// <para>Data: [1] Username Length [n] Username [1] Economy Value</para>
			/// </summary>
			UPDATE_ECONOMY,
			/// <summary> Broadcasts the information of a teams Base HP to all players in the game
			/// <para>Data: [1] TeamID [1] HP Value </para>
			/// </summary>
			UPDATE_BASE_HP,
			/// <summary>Returns the results if the minion was successfully researched or not.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			ASSIGN_RESOURCE_NODE,
			/// <summary>Returns the results if the tower was successfully researched or not.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_RESEARCH_MINION,
			/// <summary>Returns the results if the tower was successfully researched or not.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_RESEARCH_TOWER,



			// Gameplay Command oriented protocols are: 1625 - 1649
			// There are currently: 5/25
			// Double check, some of these may require no data as the command itself is the data
			
			/// <summary>Relays information about the person to be kicked to the host
			/// <para>Data: [1] Username Length [n] Username</para>
			/// </summary>
			RETURN_KICK_STATUS = 1625,
			/// <summary>Relays information back to the player requesting to pause the game.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_PAUSE_GAME,
			/// <summary>Relays information back to the player requesting to end the game.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_END_GAME,
			/// <summary>Relays information back to the player requestion to resume the game
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_RESUME_GAME,
			/// <summary>Relays the response to the player that requested to quit the game.
			/// <para>Data: [1] Boolean</para>
			/// </summary>
			RETURN_QUIT_GAME
		};


		/// <summary>The list of Client to Server protocols that will be sent over the network.</summary>
		enum CS_Protocol : __int16 {
			// Connection Type Protocols are: 2100 - 2149
			// There are currently: 3/50

			/// <summary>Will close the game for the player, and the connection with the server.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			CLOSE_GAME = 2100,
			/// <summary>Sends a request to the server for the player to connect.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			LOGIN_PLAYER,
			/// <summary>Requests that the server disconnects the player.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			LOGOUT_PLAYER,


			// Chat oriented protocols are: 2200 - 2224
			// There are currently: 5/25

			/// <summary>Will send a message to the server meant for all the players within that game
			/// <para>Data: [4] GameID, [1] Username Length, [1] Message Length, [N] Username, [N] Message </summary>
			SEND_MESSAGE_IG = 2200,
			/// <summary>Will send a message to the server meant for all the players within the game prep. lobby
			/// <para>Data: [4] LobbyID, [1] Username Length, [1] Message Length, [N] Username, [N] Message </summary>
			SEND_MESSAGE_GL,
			/// <summary>Will send a message to the server meant for all the players within the game prep. lobby
			/// <para>Data: [1] Username Length (S), [1] Username Length (R), [1] Message Length, [N] Username (S), [N] Username (R), [N] Message </summary>
			SEND_WHISPER,
			/// <summary>Will send a message to the server meant for players in the same party - while in game.
			/// <para>Data: [4] GameID, [4] TeamID, [1] Username Length, [1] Message Length, [N] Username, [N] Message </summary>
			SEND_PARTY_MSG_IG,
			/// <summary>Will send a message to the server meant for players in the same party - while in the game lobby.
			/// <para>Data: [4] LobbyID, [1] Username Length, [1] Message Length, [N] Username, [N] Message </summary>
			SEND_PARTY_MSG_GL,



			// Game Viewer oriented protocols are: 2250 - 2274
			// There are currently: 3/25

			/// <summary>Sends a request for a list of refreshed games in the Game Viewer scene.
			/// <para>Data: [1] Username Length, [1] Game Count, [N] Username, [N] Game Data </summary>
			REFRESH_GAMES = 2250,
			/// <summary>Requests that the player joins the selected game.
			/// <para>Data: [4] GameID, [1] Username Length, [N] Username </summary>
			JOIN_GAME,
			/// <summary>Requests that the server create a game with the player as the host.
			/// <para>Data: [1] Username Length, [N] Username</summary>
			CREATE_GAME,



			// Game Lobby oriented protocols are: 2300 - 2349
			// There are currently: 6/50

			/// <summary>Requests that the player joins the team they have selected
			/// <para>Data: [4] LobbyID, [4] TeamID, [1] Username Length, [N] Username </summary>
			JOIN_TEAM = 2300,
			/// <summary>Requests that the player leave from the game they are currently in. 
			/// <para>Data: [4] LobbyID, [1] Username Length, [N] Username </summary>
			LEAVE_GAME,
			/// <summary>Requests that the player is sent back to the bench if they are currently on a team
			/// <para>Data: [4] LobbyID, [1] Username Length, [N] Username </summary>
			BENCH_PLAYER,
			/// <summary>Updates the player's ready status and sends it to the server.
			/// <para>Data: [1] Ready Status, [1] Username Length, [N] Username </summary>
			READY_STATUS,
			/// <summary>Host Only - Requests that the host's game be disbanded.
			/// <para>Data: [4] GameID </summary>
			DISBAND_GAME,
			/// <summary>Host Only - Will send to the server the new gameplay options for the players
			/// <para>Data: [4] GameID, [???] OptionsData </summary>
			SET_GAMEPLAY_OPTIONS,
			


			// Gameplay oriented protocols are: 2400 - 2499
			//There are currently: 4/100
			
			/// <summary> Sends a requests to the server to place a tower in the designated spot.
			/// <para>Data: [4] GameID, [4] TowerID, [4] Gridspace, [1] Username Length, [N] Username </summary>
			PLACE_TOWER = 2400,
			/// <summary> Sends a request to the server to place a minion at the starting portal.
			/// <para>Data: TODO </summary>
			SUMMON_MINION,
			/// <summary> Sends a request to research a minion for the team.
			/// <para>Data: TODO </summary>
			RESEARCH_MINION,
			/// <summary> Sends a request to research a tower for the team.
			/// <para>Data: TODO </summary>
			RESEARCH_TOWER,



			// In-Game Command oriented protocols are: 2600 - 2624
			// There are currently: 5/25
			
			/// <summary>Host Only - Requests to the server that a designated player is kicked from the match.
			/// <para>Data: TODO </summary>
			KICK_PLAYER = 2600,
			/// <summary>A request sent to the server to pause the game. - When two are received in X amount of time the game will pause
			/// <para>Data: TODO </summary>
			PAUSE_GAME,
			/// <summary>Host Only - will request that the server save and quit the current game, will be able to resume at a later time. 
			/// <para>Data: TODO </summary>
			END_GAME,
			/// <summary> Host Only - Requests that the server resume the game from a paused status. 
			/// <para>Data: TODO </summary>
			RESUME_GAME,
			/// <summary> Notifies the server that a player has left the game.
			/// <para>Data: TODO </summary>
			QUIT_GAME,
		};
	}
}
#endif