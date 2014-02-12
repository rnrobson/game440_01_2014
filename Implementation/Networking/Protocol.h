// Protocol.h
#ifndef PROTOCOL_H
#define PROTOCOL_H

#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

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
		NETWORKING_API enum SC_Protocol {
			// Connection type protocols are: 150 - 199
			// There are currently: 3/50
			
			/// <summary>Sends info to all clients in the case that someone disconnects
			/// <para>Data: [1] Username Length [N] Username </para>
			/// </summary>
			CLIENT_LOST = 150,
			/// <summary>Sends info to all clients in the case someone reconnects
			/// <para>Data: [1] Username Length [N] Username </para>
			/// </summary> // Double check team 
			CLIENT_REJOIN,
			/// <summary>Returns information for successful/unsuccessful login
			/// <para>Data: [1] Username Length [N] Username [1] Successful/UnSuccessful</para>
			/// </summary> // Double check 
			RETURN_LOGIN_STATUS,


			// Chat oriented protocols are: 225 - 249
			// There are currently: 4/25

			/// <summary>Requests that all the clients that receive the message display it in the “All” chat room
			/// <para>Data: [1] Username Length [N] Username [1] Length Of Message [N] Message</para>
			/// </summary>
			BROADCAST_MESSAGE_TO_ALL = 225,
			/// <summary>Sends the whisper to the client it was directed to
			/// <para>Data: [1] Username Length [N] Username [1] Reciever Name Length [N] Reciever Name [1]</para>
			/// </summary>
			DISPLAY_WHISPER,
			/// <summary>Sends the message to all members of the party
			/// <para>Data: TODO</para>
			/// </summary>
			BROADCAST_PARTY_MESSAGE,
			/// <summary>Relays information about the person to be kicked to the host
			/// <para>Data: TODO</para>
			/// </summary>
			RETURN_KICK_STATUS,



			// Game Viewer oriented protocols are: 275 - 299
			// There are currently: /25
			// TODO add the game viewer server to client protocols



			// Game Lobby oriented protocols for Server are: 350 - 399
			// There are currently: 8/50

			/// <summary>Allows the server to send X game objects for the client to view
			/// <para>Data: TODO</para> 
			/// </summary>
			POPULATE_GAMES = 350,
			/// <summary>Allows the server to send the data of all the clients viewing/joined the selected game 
			/// <para>This is used to send over ready statues, and if the players are benched or on a specific team</para>
			/// <para>Data: TODO</para>
			/// </summary>
			POPULATE_CLIENTS,
			/// <summary>Returns this in the case that the bench or both teams are full
			/// <para>Data: TODO</para> 
			/// </summary>
			UNABLE_TO_JOIN,
			/// <summary>Gives the player that requested to host a game the information and control over the game created for them
			/// <para>Data: TODO</para> 
			/// </summary>
			GAME_CREATED,
			/// <summary>In the case that the server is unable to create the game – this can return the reasoning or be left blank
			/// <para>Data: TODO</para> 
			/// </summary>
			UNABLE_TO_CREATE_GAME,
			/// <summary>Sends information to all the clients in the now disbanded game
			/// <para>Data: TODO</para> 
			/// </summary>
			GAME_DISBANDED,
			/// <summary>In the case that the player is unable to join the team – either due to internal issues, or team capacity
			/// <para>Data: TODO</para> 
			/// </summary>
			UNABLE_TO_JOIN_TEAM,
			/// <summary>When the gameplay options are updated by the host, this will be sent to all the clients within that game and notify them of the changes
			/// <para>Data: TODO</para> 
			/// </summary>
			UPDATE_GAMEPLAY_OPTIONS,


			// Gameplay oriented protocols are: 500 - 599
			// There are currently: 13/100

			/// <summary>Sends a request to all players of the game to pause the active game
			/// <para>Data: TODO</para> 
			/// </summary>
			PAUSE_GAME = 500,
			/// <summary>Requests that all the clients of the game end the game and proceed to the load screen
			/// <para>Data: TODO</para> 
			/// </summary>
			END_GAME,
			/// <summary>Requests that the game commence again
			/// <para>Data: TODO</para>
			/// </summary>
			RESUME_GAME,
			/// <summary>Requests that the game ends and a notification is sent notifying the players they can resume at a later time/date
			/// <para>Data: TODO</para>
			/// </summary>
			SHUTDOWN_GAME,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			SUMMON_MINION_BC,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			SUMMON_MINION,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			PLACE_TOWER_BC,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			PLACE_TOWER,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			UPDATE_ECONOMY,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			UPDATE_BASE_HP,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			ASSIGN_RESOURCE_NODE,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			RESEARCH_MINION,
			/// <summary> TODO
			/// <para>Data: TODO</para>
			/// </summary>
			RESEARCH_TOWER
		};

		/// <summary>The list of Client to Server protocols that will be sent over the network.</summary>
		NETWORKING_API enum CS_Protocol {
			// Connection Type Protocols are: 100 - 149
			// There are currently: 3/50

			/// <summary>Will close the game for the player, and the connection with the server.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			CLOSE_GAME = 100,
			/// <summary>Sends a request to the server for the player to connect.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			LOGIN_PLAYER,
			/// <summary>Requests that the server disconnects the player.
			/// <para>Data: [1] Username Length, [N] Username </summary>
			LOGOUT_PLAYER,



			// Game Viewer oriented protocols are: 250 - 274
			// There are currently: 3/25

			/// <summary>Sends a request for a list of refreshed games in the Game Viewer scene.
			/// <para>Data: [1] Username Length, [1] Game Count, [N] Username, [N] Game Data </summary>
			REFRESH_GAMES = 250,
			/// <summary>Requests that the player joins the selected game.
			/// <para>Data: [4] GameID, [1] Username Length, [N] Username </summary>
			JOIN_GAME,
			/// <summary>Requests that the server create a game with the player as the host.
			/// <para>Data: [1] Username Length, [N] Username</summary>
			CREATE_GAME,



			// Game Lobby oriented protocols are: 300 - 349
			// There are currently: 6/50

			/// <summary>Requests that the player joins the team they have selected
			/// <para>Data: [4] LobbyID, [4] TeamID, [1] Username Length, [N] Username </summary>
			JOIN_TEAM = 300,
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



			// Chat oriented protocols are: 200 - 224
			// There are currently: 5/25

			/// <summary>Will send a message to the server meant for all the players within that game
			/// <para>Data: [4] GameID, [1] Username Length, [1] Message Length, [N] Username, [N] Message </summary>
			SEND_MESSAGE_IG = 200,
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
			


			// Gameplay oriented protocols are: 400 - 499
			//There are currently: 4/100
			
			/// <summary> Sends a requests to the server to place a tower in the designated spot.
			/// <para>Data: [4] GameID, [4] TowerID, [4] Gridspace, [1] Username Length, [N] Username </summary>
			PLACE_TOWER = 400,
			/// <summary> Sends a request to the server to place a minion at the starting portal.
			/// <para>Data: TODO </summary>
			SUMMON_MINION,
			/// <summary> Sends a request to research a minion for the team.
			/// <para>Data: TODO </summary>
			RESEARCH_MINION,
			/// <summary> Sends a request to research a tower for the team.
			/// <para>Data: TODO </summary>
			RESEARCH_TOWER,



			// In-Game Command oriented protocols are: 600 - 624
			// There are currently: 5/25
			
			/// <summary>Host Only - Requests to the server that a designated player is kicked from the match.
			/// <para>Data: TODO </summary>
			KICK_PLAYER = 600,
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