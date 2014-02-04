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
		NETWORKING_API enum Protocol {
			//Connection Type Protocols are: 100 - 199

			//CLIENT TO SERVER ORIENTED
			///<summary>Will close the game for the player, and the connection with the server</summary>
			CLOSE_GAME = 100,
			///<summary>Sends a request to the server when the player tries to login</summary>
			LOGIN_PLAYER = 101,
			///<summary>Sends a request to the server when the player tries to logout</summary>
			LOGOUT_PLAYER = 102,

			//SERVER TO CLIENT ORIENTED
			///<summary>Sends info to all clients in the case that someone disconnects</summary>
			CLIENT_LOST = 103,
			///<summary>Sends into to all clients in the case someone reconnects</summary>
			CLIENT_REJOIN = 104,
			///<summary>Returns information for successful/unsuccessful login</summary>
			RETURN_LOGIN_STATUS = 105,


			//Game Lobby oriented protocols are: 200 - 299

			//CLIENT TO SERVER ORIENTED
			///<summary>Used to refresh games in the scene where player views active games</summary>
			REFRESH_GAMES = 200,
			///<summary>Requests that the player joins the selected game from within the game selection screen</summary>
			JOIN_GAME = 201,
			///<summary>Requests that the player leave from the game they are currently in</summary>
			LEAVE_GAME = 202,
			///<summary>Request sent to the server to create a game with the player as the host</summary>
			CREATE_GAME = 203,
			///<summary>Requests that the game the player is a host of is disbanded</summary>
			DISBAND_GAME = 204,
			///<summary>Requests that the player joins the team they have selected</summary>
			JOIN_TEAM = 205,
			///<summary>Sends a message confirming to the server that the player is ready to play</summary>
			READY_STATUS = 206,
			///<summary>Requests that the player is sent back to the bench if they are currently on a team</summary>
			BENCH_PLAYER = 207,
			///<summary>Host of game only. Will send to the server the new gameplay options for the players</summary>
			SET_GAMEPLAY_OPTIONS = 208,

			//SERVER TO CLIENT ORIENTED
			///<summary>Allows the server to send X game objects for the client to view</summary>
			POPULATE_GAMES = 250,
			///<summary>Allows the server to send the data of all the clients viewing/joined the selected game 
			///This is used to send over ready statues, and if the players are benched or on a specific team</summary>
			POPULATE_CLIENTS = 251,
			///<summary>Returns this in the case that the bench or both teams are full</summary>
			UNABLE_TO_JOIN = 252,
			///<summary>Gives the player that requested to host a game the information and control over the game created for them</summary>
			GAME_CREATED = 253,
			///<summary>In the case that the server is unable to create the game – this can return the reasoning or be left blank</summary>
			UNABLE_TO_CREATE_GAME = 254,
			///<summary>Sends information to all the clients in the now disbanded game</summary>
			GAME_DISBANDED = 255,
			///<summary>In the case that the player is unable to join the team – either due to internal issues, or team capacity</summary>
			UNABLE_TO_JOIN_TEAM = 256,
			///<summary>When the gameplay options are updated by the host, this will be sent to all the clients within that game and notify them of the changes</summary>
			UPDATE_GAMEPLAY_OPTIONS = 257,


			//Chat oriented protocols are: 300 - 399

			//CLIENT TO SERVER ORIENTED
			///<summary>Will send a message to the server – meant for all players</summary>
			SEND_MESSAGE = 300,
			///<summary>Will send a whisper request to the server for the specified person</summary>
			SEND_WHISPER = 301,
			///<summary>Will send a message to the server – meant for players only in the same party</summary>
			SEND_PARTY_WHISPER = 302,
			///<summary>Will send a request to kick the designated player from the match – host only</summary>
			SC_KICK = 303,
			///<summary>Sends a request to pause the current game – host only</summary>
			SC_PAUSEGAME = 304,
			///<summary>Sends a request to end the game prematurely and display the results. – host only</summary>
			SC_ENDGAME = 305,
			///<summary>Sends a request to end game and save it to resume from later. – host only</summary>
			SC_SHUTDOWN = 306,
			///<summary>Sends a request to resume the game with a given delay time - Host only</summary>
			SC_RESUME = 307,

			//SERVER TO CLIENT ORIENTED
			///<summary>Requests that all the clients that receive the message display it in the “All” chat room</summary>
			BROADCAST_MESSAGE = 350,
			///<summary>Sends the whisper to the client it was directed to</summary>
			DISPLAY_WHISPER = 351,
			///<summary>Sends the message to all members of the party</summary>
			BROADCAST_PARTY_MESSAGE = 352,
			///<summary>Relays information about the person to be kicked to the host</summary>
			SC_RETURN_KICK_STATUS = 353,

			//Gameplay oriented protocols are: 400 - 599

			//SERVER TO CLIENT ORIENTED
			///<summary>Sends a request to all players of the game to pause the active game</summary>
			PAUSE_GAME = 500,
			///<summary>Requests that all the clients of the game end the game and proceed to the load screen</summary>
			END_GAME = 501,
			///<summary>Requests that the game commence again</summary>
			RESUME_GAME = 502,
			///<summary>Requests that the game ends and a notification is sent notifying the players they can resume at a later time/date</summary>
			SHUTDOWN_GAME = 503
		};
	}
}
#endif