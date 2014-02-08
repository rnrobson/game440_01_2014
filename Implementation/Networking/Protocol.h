// Protocol.h
#ifndef PROTOCOL_H
#define PROTOCOL_H

#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

/// TODO calculate the protocols/total protocols for each section

namespace ManaCraft {
	namespace Networking {
		// BRIAN
		// This is the format for the comments for each protocol

		/// <summary>
		/// Data format: TODO </summary>

		//Please use the descripts here and in the master list. Since some here are outta date, and some
		//in the list are fucking weird and make no sense. 


		/// <summary> The list of Server to client protocols that will be sent over the network.</summary>
		NETWORKING_API enum SC_Protocol {
			// Connection type protocols are: 150 - 199
			// There are currently: 3/49
			
			/// <summary>Sends info to all clients in the case that someone disconnects</summary>
			CLIENT_LOST = 150,
			/// <summary>Sends into to all clients in the case someone reconnects</summary>
			CLIENT_REJOIN,
			/// <summary>Returns information for successful/unsuccessful login</summary>
			RETURN_LOGIN_STATUS,


			// Chat oriented protocols are: 225 - 249
			// There are currently: 4/24

			/// <summary>Requests that all the clients that receive the message display it in the “All” chat room</summary>
			BROADCAST_MESSAGE = 350,
			/// <summary>Sends the whisper to the client it was directed to</summary>
			DISPLAY_WHISPER = 351,
			/// <summary>Sends the message to all members of the party</summary>
			BROADCAST_PARTY_MESSAGE = 352,
			/// <summary>Relays information about the person to be kicked to the host</summary>
			SC_RETURN_KICK_STATUS = 353,



			// Game Viewer oriented protocols are: 275 - 299
			// There are currently: /24
			// TODO add the game viewer server to client protocols



			// Game Lobby oriented protocols for Server are: 350 - 399
			// There are currently: TODO/49

			///<summary>Allows the server to send X game objects for the client to view</summary>
			POPULATE_GAMES = 350,
			///<summary>Allows the server to send the data of all the clients viewing/joined the selected game 
			///This is used to send over ready statues, and if the players are benched or on a specific team</summary>
			POPULATE_CLIENTS,
			///<summary>Returns this in the case that the bench or both teams are full</summary>
			UNABLE_TO_JOIN,
			///<summary>Gives the player that requested to host a game the information and control over the game created for them</summary>
			GAME_CREATED,
			///<summary>In the case that the server is unable to create the game – this can return the reasoning or be left blank</summary>
			UNABLE_TO_CREATE_GAME,
			///<summary>Sends information to all the clients in the now disbanded game</summary>
			GAME_DISBANDED,
			///<summary>In the case that the player is unable to join the team – either due to internal issues, or team capacity</summary>
			UNABLE_TO_JOIN_TEAM,
			///<summary>When the gameplay options are updated by the host, this will be sent to all the clients within that game and notify them of the changes</summary>
			UPDATE_GAMEPLAY_OPTIONS,


			// Gameplay oriented protocols are: 500 - 599
			// There are currently: TODO/99

			/// <summary>
			/// Data format: TODO </summary>
			///<summary>Sends a request to all players of the game to pause the active game</summary>
			PAUSE_GAME = 500,
			///<summary>Requests that all the clients of the game end the game and proceed to the load screen</summary>
			END_GAME,
			///<summary>Requests that the game commence again</summary>
			RESUME_GAME,
			///<summary>Requests that the game ends and a notification is sent notifying the players they can resume at a later time/date</summary>
			SHUTDOWN_GAME



			// The internal server commands that shouldn't be here are: 1000 - 1100
			// There are currently: 0/100

		};


		/// <summary>The list of all the protocols that will be relayed from Client to Server by the network.</summary>
		NETWORKING_API enum CS_Protocol {
			// Connection Type Protocols are: 100 - 149
			// There are currently: 3/49

			/// <summary>Will close the game for the player, and the connection with the server.
			/// Data format: [1] Player Name Length [N] Player Name </summary>
			CLOSE_GAME = 100,
			///<summary>Sends a request to the server for the player to connect.
			/// Data format: [1] Player Name Length [N] Player Name </summary>
			LOGIN_PLAYER,
			///<summary>Requests that the server disconnects the player.
			/// Data format: [1] Player Name Length [N] Player Name </summary>
			LOGOUT_PLAYER,



			// Game Viewer oriented protocols are: 250 - 274
			// There are currently: 3/24

			/// <summary>Sends a request for a list of refreshed games in the Game Viewer scene.
			/// Data format: [1] Player Name Length, [N] Player Name, [4] LobbyID </summary>
			REFRESH_GAMES = 250,
			/// <summary>Requests that the player joins the selected game.
			/// Data format: [1] Player Name Length, [N] Player Name, [4] GameID </summary>
			JOIN_GAME,
			/// <summary>Requests that the server create a game with the player as the host.
			/// Data format: [1] Player Name Length, [N] Player Name</summary>
			CREATE_GAME,



			// Game Lobby oriented protocols are: 300 - 349
			// There are currently: /49

			/// <summary>Requests that the player joins the team they have selected
			/// Data format: TODO </summary>
			JOIN_TEAM,
			/// <summary>Requests that the player leave from the game they are currently in. 
			/// Data format: TODO </summary>
			LEAVE_GAME = 300,
			/// <summary>Requests that the player is sent back to the bench if they are currently on a team
			/// Data format: TODO </summary>
			BENCH_PLAYER,
			/// <summary>Updates the player's ready status and sends it to the server.
			/// Data format: TODO </summary>
			READY_STATUS,
			/// <summary>Host Only - Requests that the game the player is a host of is disbanded
			/// Data format: TODO </summary>
			DISBAND_GAME,
			/// <summary>Host Only - Will send to the server the new gameplay options for the players
			/// Data format: TODO </summary>
			SET_GAMEPLAY_OPTIONS,



			// Chat oriented protocols are: 200 - 224
			// There are currently: 3/24

			/// <summary>Will send a message to the server meant for all the players within that game
			/// Data format: TODO </summary>
			SEND_MESSAGE_IG = 200,
			/// <summary>Will send a message to the server meant for all the players within the game prep. lobby
			/// Data format: TODO </summary>
			SEND_MESSAGE_GL,
			/// <summary>Will send a message to the server meant for all the players within the game prep. lobby
			/// Data format: TODO </summary>
			SEND_WHISPER,
			/// <summary>Will send a message to the server meant for players in the same party - while in game.
			/// Data format: TODO </summary>
			SEND_PARTY_MSG_IG,
			/// <summary>Will send a message to the server meant for players in the same party - while in the game lobby.
			/// Data format: TODO </summary>
			SEND_PARTY_MSG_GL,
			


			// Gameplay oriented protocols are: 400 - 499
			//There are currently: 4/99
			
			/// <summary> Sends a requests to the server to place a tower in the designated spot.
			/// Data format: TODO </summary>
			PLACE_TOWER = 400,
			/// <summary> Sends a request to the server to place a minion at the starting portal.
			/// Data format: TODO </summary>
			SUMMON_MINION,
			/// <summary> Sends a request to research a minion for the team.
			/// Data format: TODO </summary>
			RESEARCH_MINION,
			/// <summary> Sends a request to research a tower for the team.
			/// Data format: TODO </summary>
			RESEARCH_TOWER,



			// In-Game Command oriented protocols are: 600 - 624
			// There are currently: 5/24
			
			/// <summary>Host Only - Requests to the server that a designated player is kicked from the match.
			/// Data format: TODO </summary>
			KICK_PLAYER,
			/// <summary>A request sent to the server to pause the game. - When two are received in X amount of time the game will pause
			/// Data format: TODO </summary>
			PAUSE_GAME,
			/// <summary>Host Only - will request that the server save and quit the current game, will be able to resume at a later time. 
			/// Data format: TODO </summary>
			END_GAME,
			/// <summary> Host Only - Requests that the server resume the game from a paused status. 
			/// Data format: TODO </summary>
			RESUME_GAME,
			/// <summary> Notifies the server that a player has left the game.
			/// Data format: TODO </summary>
			QUIT_GAME,
		};
	}
}
#endif