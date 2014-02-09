#pragma once
#include <ClientAPI.h>
#include "API_Util.h"

class GameLobby
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//add main container
		ClientAPI::AddGuiContainer("GameLobby", new GuiContainer());

		//add font
		API_Util::AddFont("OGWEAR", "Resources/Fonts/OGWEAR.ttf", 36);
		API_Util::AddFont("Systema_11", "Resources/Fonts/9SYSTEMA.ttf", 11);
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//add colors to be used for buttons, labels, etc
		API_Util::AddColor("White", 255, 255, 255, 255);
		API_Util::AddColor("LightBlue", 0, 162, 232, 255);
		API_Util::AddColor("Red", 255, 0, 0, 255);
		
		//add textures
		API_Util::AddTexture("Background", "Resources/Images/background.png", API_Util::PNG);
		API_Util::AddTexture("SmallBtnNormal", "Resources/GUITextures/smallBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnHover", "Resources/GUITextures/smallBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnDown", "Resources/GUITextures/smallBtnDown.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnHover", "Resources/GUITextures/medBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnDown", "Resources/GUITextures/medBtnDown.bmp", API_Util::BMP);

		//add background
		ClientAPI::GetGuiContainer("GameLobby")->AddGuiElement("bg", new GuiElement(ClientAPI::GetTexture("Background"), { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }));

		//add labels
		ClientAPI::GetGuiContainer("GameLobby")->AddGuiContainer("lblCon", new GuiContainer());
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("lblCon"),
			"Illuminated", "The Illuminated", { 70, 50, 300, 100 }, "OGWEAR", "LightBlue");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("lblCon"),
			"DarkOnes", "The Dark Ones", { SCREEN_WIDTH - 340, 50, 300, 100 }, "OGWEAR", "Red");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("lblCon"),
			"Versus", "Versus", { (SCREEN_WIDTH / 2) - 60, 70, 200, 100 }, "OGWEAR", "White");

		//add join and leave buttons to container
		ClientAPI::GetGuiContainer("GameLobby")->AddGuiContainer("teamAllocBtnsCon", new GuiContainer());
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"JoinI", { 100, 480, 100, 50 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"JoinDO", { SCREEN_WIDTH - 200, 480, 100, 50 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"backToBench", { (SCREEN_WIDTH / 2) - 50, 520, 100, 60 }, "MedBtnNormal");

		//start with backToBench button disabled
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = false;

		////add hosting and game options buttons to container
		ClientAPI::AddGuiContainer("gameSetBtnsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("GameLobby")->AddGuiContainer("gameSetBtnsCon", new GuiContainer());
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"startGame", { 900, 620, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"closeGame", { 900, 650, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"gameOptions", { 900, 680, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"returnToMainMenu", { 900, 720, 100, 30 }, "MedBtnNormal");

		//add texts to buttons
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"JoinI", "JOIN", "Systema_22", "LightBlue");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"JoinDO", "JOIN", "Systema_22", "Red");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon"),
			"backToBench", "Leave Team", "Systema_22", "Black");
				
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"startGame", "Start Game", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"closeGame", "Close Game", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"gameOptions", "Game Options", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon"),
			"returnToMainMenu", "Back", "Systema_11", "Black");
				
		//position the texts on buttons
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			GetLabel()->SetPadding({ 18, 12, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			GetLabel()->SetPadding({ 18, 12, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			GetLabel()->SetPadding({ 12, 3, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			GetLabel()->SetPadding({ 12, 8, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			GetLabel()->SetPadding({ 11, 8, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			GetLabel()->SetPadding({ 7, 8, 0, 0 });
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			GetLabel()->SetPadding({ 29, 8, 0, 0 });

		//add events to buttons
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			SubscribeOnMouseClick(JoinITeam);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			SubscribeOnMouseClick(JoinDOTeam);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			SubscribeOnMouseClick(ReturnToBench);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			SubscribeOnMouseClick(StartGame);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			SubscribeOnMouseClick(CloseGame);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			SubscribeOnMouseClick(ShowGameOptions);
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			SubscribeOnMouseClick(ReturnToMainMenu);

		//start with Game Lobby not active
		//when the player clicks "Create Game" in the Main Menu, make Game Lobby active
		ClientAPI::GetGuiContainer("GameLobby")->Active = false;
	}
	static void Update(double _time) //might not be needed
	{
		//if this player is the host:
			//enable startGame and closeGame buttons
		//else
			//buttons are disabled
	}
	static void Quit()
	{
		ClientAPI::ExitMainLoop();
	}

	static void JoinITeam()
	{
		EnableJoinBtns(false);
		
		printf("clicked join illuminated\n");
	}
	static void JoinDOTeam()
	{
		EnableJoinBtns(false);

		printf("clicked join dark ones\n");
	}
	static void ReturnToBench()
	{
		EnableJoinBtns(true);

		printf("left team\n");
	}

	static void StartGame()
	{
		printf("host started the game\n");

		//check if all players have locked in to start the game
	}
	static void CloseGame()
	{
		printf("host closed the game\n");
		
		//when host leaves, select another player to be host
	}
	static void ShowGameOptions()
	{
		printf("show game options\n");
		//pop up the game options
	}
	static void ReturnToMainMenu()
	{
		ClientAPI::GetGuiContainer("GameLobby")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
	}

	static void EnableJoinBtns(bool _state)
	{
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->Enabled = _state;
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->Enabled = _state;
		ClientAPI::GetGuiContainer("GameLobby")->GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = !_state;
	}
};