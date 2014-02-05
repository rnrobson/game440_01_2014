#pragma once
#include <ClientAPI.h>

class GameLobby
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//add font
		ClientAPI::AddFont("OGWEAR", Window::LoadFont("Resources/Fonts/OGWEAR.ttf", 36));//TTF_Font* font = Window::LoadFont("OGWEAR.ttf", 24);
		ClientAPI::AddFont("Systema_11", Window::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 11));
		ClientAPI::AddFont("Systema_22", Window::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22));
		//add colors to be used for buttons, labels, etc
		ClientAPI::AddColour("White", APIHelper::ColourHelper(255, 255, 255, 255));
		ClientAPI::AddColour("LightBlue", APIHelper::ColourHelper(0, 162, 232, 255));
		ClientAPI::AddColour("Red", APIHelper::ColourHelper(255, 0, 0, 255));
		
		//load button textures for different states
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *smallBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnHover.bmp");
		SDL_Texture *smallBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnDown.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *medBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnHover.bmp");
		SDL_Texture *medBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnDown.bmp");

		//add the textures
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("SmallBtnHover", smallBtnHoverTex);
		ClientAPI::AddTexture("SmallBtnDown", smallBtnDownTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("MedBtnHover", medBtnHoverTex);
		ClientAPI::AddTexture("MedBtnDown", medBtnDownTex);

		//"Illuminated" text
		ClientAPI::AddLabel("Illuminated", 
			new Label("The Illuminated", APIHelper::RectHelper(70, 50, 300, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("LightBlue")));

		//"Dark Ones" text
		ClientAPI::AddLabel("DarkOnes", 
			new Label("The Dark Ones", APIHelper::RectHelper(SCREEN_WIDTH - 340, 50, 300, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Red")));

		//"vs" text
		ClientAPI::AddLabel("Versus",
			new Label("Versus", APIHelper::RectHelper((SCREEN_WIDTH / 2) - 60, 70, 200, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("White")));

		//add join and leave buttons to container
		ClientAPI::AddGuiContainer("teamAllocBtnsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->
			AddButton("JoinI", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(100, 450, 100, 50)));
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->
			AddButton("JoinDO", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(SCREEN_WIDTH - 200, 450, 100, 50)));
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->
			AddButton("backToBench", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper((SCREEN_WIDTH / 2) - 50, 490, 100, 60)));

		//add hosting and game options buttons to container
		ClientAPI::AddGuiContainer("gameSetBtnsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->
			AddButton("startGame", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(900, 600, 100, 30)));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->
			AddButton("closeGame", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(900, 635, 100, 30)));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->
			AddButton("gameOptions", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(900, 675, 100, 30)));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->
			AddButton("returnToMainMenu", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(900, 725, 100, 30)));

		//add texts to buttons
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			AddLabel("JOIN", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("LightBlue"), false);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			AddLabel("JOIN", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Red"), false);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			AddLabel("Leave Team", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), false);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			AddLabel("Start Game", ClientAPI::GetFont("Systema_11"), ClientAPI::GetColor("Black"), false);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			AddLabel("Close Game", ClientAPI::GetFont("Systema_11"), ClientAPI::GetColor("Black"), false);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			AddLabel("Game Options", ClientAPI::GetFont("Systema_11"), ClientAPI::GetColor("Black"), false);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			AddLabel("Back", ClientAPI::GetFont("Systema_11"), ClientAPI::GetColor("Black"), false);
		
		//position the texts on buttons
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinI")->
			GetLabel()->SetPadding(APIHelper::RectHelper(18, 12, 0, 0));
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("JoinDO")->
			GetLabel()->SetPadding(APIHelper::RectHelper(18, 12, 0, 0));
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->GetButton("backToBench")->
			GetLabel()->SetPadding(APIHelper::RectHelper(12, 3, 0, 0));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("startGame")->
			GetLabel()->SetPadding(APIHelper::RectHelper(12, 8, 0, 0));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("closeGame")->
			GetLabel()->SetPadding(APIHelper::RectHelper(11, 8, 0, 0));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("gameOptions")->
			GetLabel()->SetPadding(APIHelper::RectHelper(7, 8, 0, 0));
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			GetLabel()->SetPadding(APIHelper::RectHelper(29, 8, 0, 0));

		//add events to buttons
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->GetButton("returnToMainMenu")->
			SubscribeOnMouseClick(Quit);
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
};

