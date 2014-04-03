#include "GameLobby.h"
#include "MainMenu.h"

#include "ClientAPI.h"
#include "API_Util.h"
#include "ScreenFader.h"
#include <algorithm>
using namespace ManaCraft::Client;

GameLobby* GameLobby::instance;

GameLobby::GameLobby()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

	Load();
}

GameLobby* GameLobby::GetInstance()
{
	if (GameLobby::instance == nullptr) { GameLobby::instance = new GameLobby(); }

	return GameLobby::instance;
}

GameLobby::~GameLobby()
{
	Page::~Page();
}

void GameLobby::Load()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;

	//add main container
	ClientAPI::AddGuiContainer("GameLobby", content);
	
	API_Util::AddColor("Blue", 0, 135, 193, 255);

	//add textures specific to gamelobby
	API_Util::AddSolidTexture("popupBackground", { 0, 0, 0, 100 }, 400, 280);
	API_Util::AddSolidTexture("gLobbyCover", { 0, 0, 0, 155 }, SCREEN_WIDTH, SCREEN_HEIGHT);
	API_Util::AddSolidTexture("ITeamBg", { 0, 162, 232, 20 }, 300, 250);
	API_Util::AddSolidTexture("DOTeamBg", { 255, 0, 0, 20 }, 300, 250);
	API_Util::AddSolidTexture("chatBoxBg", { 0, 0, 0, 70 }, 1000, 250);

	//add background
	API_Util::AddGuiElementToContainer(content, "bg", "Background", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });

	//add labels
	content->AddGuiContainer("lblCon", new GuiContainer());
	API_Util::AddLabelToContainer(content->GetGuiContainer("lblCon"),
		"Illuminated", "The Illuminated", { 70, 50, 300, 100 }, "OGWEAR", "Blue");
	API_Util::AddLabelToContainer(content->GetGuiContainer("lblCon"),
		"DarkOnes", "The Dark Ones", { SCREEN_WIDTH - 345, 50, 300, 100 }, "OGWEAR", "Red");
	API_Util::AddLabelToContainer(content->GetGuiContainer("lblCon"),
		"Versus", "Versus", { (SCREEN_WIDTH / 2) - 60, 200, 200, 100 }, "OGWEAR", "White");
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("lblCon"),
		"ITeamBg", "ITeamBg", { 60, 80, 300, 300 });
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("lblCon"),
		"DOTeamBg", "DOTeamBg", { SCREEN_WIDTH - 360, 80, 300, 300 });

	//add join and leave buttons to container
	content->AddGuiContainer("teamAllocBtnsCon", new GuiContainer());
	API_Util::AddButtonToContainer(content->GetGuiContainer("teamAllocBtnsCon"),
		"JoinI", { 100, 480, 100, 50 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("teamAllocBtnsCon"),
		"JoinDO", { SCREEN_WIDTH - 200, 480, 100, 50 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("teamAllocBtnsCon"),
		"backToBench", { (SCREEN_WIDTH / 2) - 48, 520, 100, 60 }, "MedBtnNormal");
	content->GetGuiContainer("teamAllocBtnsCon")->SetPosition({ 0, -80, 0, 0 });
	//start with backToBench button disabled
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = false;

	////add hosting and game options buttons to container
	content->AddGuiContainer("gameSetBtnsCon", new GuiContainer());
	API_Util::AddButtonToContainer(content->GetGuiContainer("gameSetBtnsCon"),
		"startGame", { 900, 620, 100, 30 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("gameSetBtnsCon"),
		"closeGame", { 900, 650, 100, 30 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("gameSetBtnsCon"),
		"gameOptions", { 900, 680, 100, 30 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("gameSetBtnsCon"),
		"returnToMainMenu", { 900, 720, 100, 30 }, "MedBtnNormal");
	content->GetGuiContainer("gameSetBtnsCon")->SetPosition({ 8, 0, 0, 0 });

	//add game start menu to container
	content->AddGuiContainer("startGameCon", new GuiContainer());
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("startGameCon"),
		"gSBackground", "popupBackground", { (SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) - 90, 400, 180 });
	API_Util::AddButtonToContainer(content->GetGuiContainer("startGameCon"),
		"exitStartGame", { (SCREEN_WIDTH / 2) + 90, (SCREEN_HEIGHT / 2) + 50, 100, 30 }, "MedBtnNormal");
	API_Util::AddLabelToContainer(content->GetGuiContainer("startGameCon"),
		"gStartLbl", "Start Game", { (SCREEN_WIDTH / 2) - 190, (SCREEN_HEIGHT / 2) - 110, 200, 30 }, "Systema_22", "White");

	//add chat textfield to container
	content->AddGuiContainer("chatBoxCon", new GuiContainer());
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("chatBoxCon"),
		"chatBoxBg", "chatBoxBg", { 10, SCREEN_HEIGHT - 250, 880, 250 });
	API_Util::AddButtonToContainer(content->GetGuiContainer("chatBoxCon"),
		"globalChatBtn", { 10, SCREEN_HEIGHT - 285, 80, 30 }, "MedBtnNormal");
	API_Util::AddButtonToContainer(content->GetGuiContainer("chatBoxCon"),
		"teamChatBtn", { 90, SCREEN_HEIGHT - 280, 80, 30 }, "MedBtnNormal");

	//start with the global chat disabled since it's the default chat
	content->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->Enabled = false;

	//add game options menu to container
	content->AddGuiContainer("gameOptionsCon", new GuiContainer());
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("gameOptionsCon"),
		"gOBackground", "popupBackground", { (SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) - 90, 400, 180 });
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("gameOptionsCon"),
		"gLobbyCover", "gLobbyCover", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	API_Util::AddLabelToContainer(content->GetGuiContainer("gameOptionsCon"),
		"optionsLbl", "Options", { (SCREEN_WIDTH / 2) - 190, (SCREEN_HEIGHT / 2) - 110, 100, 30 }, "Systema_22", "White");
	API_Util::AddButtonToContainer(content->GetGuiContainer("gameOptionsCon"),
		"exitOptions", { (SCREEN_WIDTH / 2) + 90, (SCREEN_HEIGHT / 2) + 50, 100, 30 }, "MedBtnNormal");

	//game start and game options should be disabled at start
	content->GetGuiContainer("startGameCon")->Active = false;
	content->GetGuiContainer("gameOptionsCon")->Active = false;

	//add texts to buttons
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("teamAllocBtnsCon"),
		"JoinI", "JOIN", "Systema_22", "Blue");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("teamAllocBtnsCon"),
		"JoinDO", "JOIN", "Systema_22", "Red");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("teamAllocBtnsCon"),
		"backToBench", "Leave Team", "Systema_22", "Black");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("gameSetBtnsCon"),
		"startGame", "Start Game", "Systema_11", "Black");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("gameSetBtnsCon"),
		"closeGame", "Close Game", "Systema_11", "Black");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("gameSetBtnsCon"),
		"gameOptions", "Game Options", "Systema_11", "Black");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("gameSetBtnsCon"),
		"returnToMainMenu", "Back", "Systema_11", "Black");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("chatBoxCon"),
		"globalChatBtn", "Global", "Systema_11", "Black");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("chatBoxCon"),
		"teamChatBtn", "Team", "Systema_11", "Black");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("startGameCon"),
		"exitStartGame", "Exit", "Systema_11", "Black");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("gameOptionsCon"),
		"exitOptions", "Exit", "Systema_11", "Black");

	//position the texts on buttons
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
		GetLabel()->SetPadding({ 18, 12, 0, 0 });
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
		GetLabel()->SetPadding({ 18, 12, 0, 0 });
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
		GetLabel()->SetPadding({ 12, 3, 0, 0 });
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
		GetLabel()->SetPadding({ 12, 8, 0, 0 });
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
		GetLabel()->SetPadding({ 11, 8, 0, 0 });
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
		GetLabel()->SetPadding({ 7, 8, 0, 0 });
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
		GetLabel()->SetPadding({ 29, 8, 0, 0 });

	content->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->
		GetLabel()->SetPadding({ 18, 8, 0, 0 });
	content->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->
		GetLabel()->SetPadding({ 18, 8, 0, 0 });

	content->GetGuiContainer("startGameCon")->GetButton("exitStartGame")->
		GetLabel()->SetPadding({ 32, 8, 0, 0 });
	content->GetGuiContainer("gameOptionsCon")->GetButton("exitOptions")->
		GetLabel()->SetPadding({ 32, 8, 0, 0 });

	//add events to buttons
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
		SubscribeOnMouseClick(JoinITeam);
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
		SubscribeOnMouseClick(JoinDOTeam);
	content->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
		SubscribeOnMouseClick(ReturnToBench);
	content->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->
		SubscribeOnMouseClick(TalkInGlobalChat);
	content->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->
		SubscribeOnMouseClick(TalkInTeamChat);
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
		SubscribeOnMouseClick(CloseGame);
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
		SubscribeOnMouseClick(ShowGameStart);
	content->GetGuiContainer("startGameCon")->GetButton("exitStartGame")->
		SubscribeOnMouseClick(ExitGameStart);
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
		SubscribeOnMouseClick(ShowGameOptions);
	content->GetGuiContainer("gameOptionsCon")->GetButton("exitOptions")->
		SubscribeOnMouseClick(ExitOptions);
	content->GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
		SubscribeOnMouseClick(ReturnToMainMenu);

	//start with Game Lobby not active
	//when the player clicks "Create Game" in the Main Menu, make Game Lobby active
	//content->Active = false;
}

void GameLobby::Update(double time)
{
	Page::Update(time);
}

void GameLobby::Draw()
{
	Page::Draw();
}

//===================
//----------- Events
//===================

void GameLobby::OnEnterPressed()
{

}

void GameLobby::OnEscapePressed()
{

}

void GameLobby::JoinITeam()
{
	EnableJoinBtns(false);
	SDL_SetTextureAlphaMod(ClientAPI::GetTexture("ITeamBg"), 50);

	printf("clicked join illuminated\n");
}
void GameLobby::JoinDOTeam()
{
	EnableJoinBtns(false);
	SDL_SetTextureAlphaMod(ClientAPI::GetTexture("DOTeamBg"), 50);

	printf("clicked join dark ones\n");
}
void GameLobby::ReturnToBench()
{
	EnableJoinBtns(true);
	SDL_SetTextureAlphaMod(ClientAPI::GetTexture("ITeamBg"), 20);
	SDL_SetTextureAlphaMod(ClientAPI::GetTexture("DOTeamBg"), 20);
	printf("left team\n");
}

void GameLobby::TalkInGlobalChat()
{
	IsInGlobalChat(true);
}

void GameLobby::TalkInTeamChat()
{
	IsInGlobalChat(false);
}

void GameLobby::CloseGame()
{
	printf("host closed the game\n");

	//when host leaves, select another player to be host
}

void GameLobby::ShowGameStart()
{
	//pop up the start game menu
	EnableGameStart(true);
}
void GameLobby::ExitGameStart()
{
	EnableGameStart(false);
}

void GameLobby::ShowGameOptions()
{
	//pop up the game options
	EnableGameOptions(true);
}

void GameLobby::ExitOptions()
{
	EnableGameOptions(false);
}

void GameLobby::ReturnToMainMenu()
{
	//GameLobby::GetInstance()->GetContent()->Active = false;
	//ClientAPI::GetGuiContainer("MainMenu")->Active = true;
	ClientAPI::SetFocus(MainMenu::GetInstance());

	IsInGlobalChat(true);
	ScreenFader::GetInstance()->FadeOut();
}

void GameLobby::IsInGlobalChat(bool _state)
{
	if (_state)
	{
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->SetOffset({ 0, 0, 0, 0 });
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->SetOffset({ 0, 0, 0, 0 });
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->Enabled = false;
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->Enabled = true;
	}
	else if (!_state)
	{
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->SetOffset({ 0, 5, 0, 0 });
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->SetOffset({ 0, -5, 0, 0 });
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("teamChatBtn")->Enabled = false;
		GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->GetButton("globalChatBtn")->Enabled = true;
	}
}

void GameLobby::EnableJoinBtns(bool _state)
{
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->Enabled = _state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->Enabled = _state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = !_state;

	//_state ? SDL_SetTextureAlphaMod(ClientAPI::GetTexture("ITeamBg"), 40) : SDL_SetTextureAlphaMod(ClientAPI::GetTexture("ITeamBg"), 100);
}

void GameLobby::EnableGameStart(bool _state)
{
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("startGameCon")->Active = _state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("teamAllocBtnsCon")->Enabled = !_state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("gameSetBtnsCon")->Enabled = !_state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->Enabled = !_state;
}

void GameLobby::EnableGameOptions(bool _state)
{
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("gameOptionsCon")->Active = _state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("teamAllocBtnsCon")->Enabled = !_state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("gameSetBtnsCon")->Enabled = !_state;
	GameLobby::GetInstance()->GetContent()->GetGuiContainer("chatBoxCon")->Enabled = !_state;
}

void GameLobby::AddToLog(std::string message, MessageType type)
{
	Message newMessage = Message(message, type);

	switch (type)
	{
	case MessageType::Team:
		//Change color to team font color
		teamLog.push_back(newMessage);
		break;
	case MessageType::Global:
		//Change color to global font color
		globalLog.push_back(newMessage);
		break;
	case MessageType::Whisper:
		//Change color to whisper font color
		teamLog.push_back(newMessage);
		globalLog.push_back(newMessage);
		break;
	}
}

void GameLobby::PrintMessage()
{
	//Print a message to the game chat container
}