#pragma once
#include "Page.h"
class GameLobby :
	public Page
{
protected:
	GameLobby();

	static GameLobby* instance;

public:
	static GameLobby* GetInstance();
	~GameLobby();

	virtual void Load();
	virtual void Update(double time);
	virtual void Draw();

	//============
	//--- Events 
	//============
	static void OnEnterPressed();
	static void OnEscapePressed();

	static void JoinITeam();
	static void JoinDOTeam();
	static void ReturnToBench();
	static void TalkInGlobalChat();
	static void TalkInTeamChat();
	static void CloseGame();
	static void ShowGameStart();
	static void ExitGameStart();
	static void ShowGameOptions();
	static void ExitOptions();
	static void ReturnToMainMenu();
	static void IsInGlobalChat(bool _state);
	static void EnableJoinBtns(bool _state);
	static void EnableGameStart(bool _state);
	static void EnableGameOptions(bool _state);
};

