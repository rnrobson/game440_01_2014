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

		//add font
		API_Util::AddFont("OGWEAR", "Resources/Fonts/OGWEAR.ttf", 36);
		API_Util::AddFont("Systema_11", "Resources/Fonts/9SYSTEMA.ttf", 11);
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);
		//add colors to be used for buttons, labels, etc
		API_Util::AddColor("White", 255, 255, 255, 255);
		API_Util::AddColor("LightBlue", 0, 162, 232, 255);
		API_Util::AddColor("Red", 255, 0, 0, 255);
		
		//add textures
		API_Util::AddTexture("SmallBtnNormal", "Resources/GUITextures/smallBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnHover", "Resources/GUITextures/smallBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnDown", "Resources/GUITextures/smallBtnDown.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnHover", "Resources/GUITextures/medBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnDown", "Resources/GUITextures/medBtnDown.bmp", API_Util::BMP);

		//add labels
		API_Util::AddLabel("Illuminated", "The Illuminated", { 70, 50, 300, 100 }, "OGWEAR", "LightBlue");
		API_Util::AddLabel("DarkOnes", "The Dark Ones", { SCREEN_WIDTH - 340, 50, 300, 100 }, "OGWEAR", "Red");
		API_Util::AddLabel("Versus", "Versus", { (SCREEN_WIDTH / 2) - 60, 70, 200, 100 }, "OGWEAR", "White");

		//add join and leave buttons to container
		ClientAPI::AddGuiContainer("teamAllocBtnsCon", new GuiContainer());		
		API_Util::AddButtonToContainer("teamAllocBtnsCon", "JoinI", { 100, 450, 100, 50 }, "MedBtnNormal");
		API_Util::AddButtonToContainer("teamAllocBtnsCon", "JoinDO", { SCREEN_WIDTH - 200, 450, 100, 50 }, "MedBtnNormal");
		API_Util::AddButtonToContainer("teamAllocBtnsCon", "backToBench", { (SCREEN_WIDTH / 2) - 50, 490, 100, 60 }, "MedBtnNormal");
		//start with backToBench button disabled
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = false;

		//add hosting and game options buttons to container
		ClientAPI::AddGuiContainer("gameSetBtnsCon", new GuiContainer());
		API_Util::AddButtonToContainer("gameSetBtnsCon", "startGame", { 900, 600, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer("gameSetBtnsCon", "closeGame", { 900, 635, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer("gameSetBtnsCon", "gameOptions", { 900, 675, 100, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer("gameSetBtnsCon", "returnToMainMenu", { 900, 725, 100, 30 }, "MedBtnNormal");

		//add texts to buttons
		API_Util::AddLabelToContainerButton("teamAllocBtnsCon", "JoinI", "JOIN", "Systema_22", "LightBlue");
		API_Util::AddLabelToContainerButton("teamAllocBtnsCon", "JoinDO", "JOIN", "Systema_22", "Red");
		API_Util::AddLabelToContainerButton("teamAllocBtnsCon", "backToBench", "Leave Team", "Systema_22", "Black");
		
		API_Util::AddLabelToContainerButton("gameSetBtnsCon", "startGame", "Start Game", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton("gameSetBtnsCon", "closeGame", "Close Game", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton("gameSetBtnsCon", "gameOptions", "Game Options", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton("gameSetBtnsCon", "returnToMainMenu", "Back", "Systema_11", "Black");
		
		//position the texts on buttons
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			GetLabel()->SetPadding({ 18, 12, 0, 0 });
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			GetLabel()->SetPadding({ 18, 12, 0, 0 });
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			GetLabel()->SetPadding({ 12, 3, 0, 0 });
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			GetLabel()->SetPadding({ 12, 8, 0, 0 });
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			GetLabel()->SetPadding({ 11, 8, 0, 0 });
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			GetLabel()->SetPadding({ 7, 8, 0, 0 });
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			GetLabel()->SetPadding({ 29, 8, 0, 0 });

		//add events to buttons
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			SubscribeOnMouseClick(JoinITeam);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			SubscribeOnMouseClick(JoinDOTeam);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			SubscribeOnMouseClick(ReturnToBench);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			SubscribeOnMouseClick(StartGame);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			SubscribeOnMouseClick(CloseGame);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			SubscribeOnMouseClick(ShowGameOptions);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			SubscribeOnMouseClick(ReturnToMainMenu);
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
		printf("return to main menu\n");

		SDL_Delay(2000);
		Quit(); //temporary
	}

	static void EnableJoinBtns(bool _state)
	{
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->Enabled = _state;
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->Enabled = _state;
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->Enabled = !_state;
	}
};