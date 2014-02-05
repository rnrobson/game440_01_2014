#pragma once
#include <ClientAPI.h>

class GameLobby
{
public:
	static void Load()
	{
		ClientAPI::AddFont("OGWEAR", Window::LoadFont("Resources/Fonts/OGWEAR.ttf", 24));//TTF_Font* font = Window::LoadFont("OGWEAR.ttf", 24);

		//add colors to be used for buttons, labels, etc
		ClientAPI::AddColour("White", APIHelper::ColourHelper(255, 255, 255, 255));
		ClientAPI::AddColour("Grey", APIHelper::ColourHelper(240, 240, 240, 50));
		ClientAPI::AddColour("LightBlue", APIHelper::ColourHelper(0, 162, 232, 255));
		ClientAPI::AddColour("DarkBlue", APIHelper::ColourHelper(0, 110, 155, 50));
		ClientAPI::AddColour("Red", APIHelper::ColourHelper(255, 0, 0, 255));
		ClientAPI::AddColour("DarkRed", APIHelper::ColourHelper(165, 0, 0, 50));

		//background
		//ClientAPI::AddTexture("bg", APIHelper::LoadPNGTexture("bg.png"));

		//add labels to containers
		//"Illuminated" text and its shadow
		ClientAPI::AddGuiContainer("iCon", new GuiContainer());
		ClientAPI::GetGuiContainer("iCon")->AddLabel(
			"Illuminated_b", new Label("The Illuminated", APIHelper::RectHelper(71, 51, 200, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("DarkBlue"))
			);
		ClientAPI::GetGuiContainer("iCon")->AddLabel(
			"Illuminated", new Label("The Illuminated", APIHelper::RectHelper(70, 50, 200, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("LightBlue"))
			);

		//"Dark Ones" text and its shadow
		ClientAPI::AddGuiContainer("doCon", new GuiContainer());
		ClientAPI::GetGuiContainer("doCon")->AddLabel(
			"DarkOnes_b", new Label("The Dark Ones", APIHelper::RectHelper(775, 51, 200, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("DarkRed"))
			);
		ClientAPI::GetGuiContainer("doCon")->AddLabel(
			"DarkOnes", new Label("The Dark Ones", APIHelper::RectHelper(774, 50, 200, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Red"))
			);

		//"VS" text and its shadow
		ClientAPI::AddGuiContainer("vsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("vsCon")->AddLabel(
			"VS_b", new Label("- VS -", APIHelper::RectHelper(473, 180, 100, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Grey"))
			);
		ClientAPI::GetGuiContainer("vsCon")->AddLabel(
			"VS", new Label("- VS -", APIHelper::RectHelper(472, 181, 100, 100),
			ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("White"))
			);

		//add join and leave buttons to container
		ClientAPI::AddGuiContainer("teamAllocBtnsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->AddButton(
			"JoinI", new Button(APIHelper::RectHelper(100, 450, 100, 50))
			);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->AddButton(
			"JoinDO", new Button(APIHelper::RectHelper(814, 450, 100, 50))
			);
		ClientAPI::GetGuiContainer("teamAllocBtnsCon")->AddButton(
			"backToBench", new Button(APIHelper::RectHelper(462, 490, 100, 50))
			);

		//add hosting and game options buttons to container
		ClientAPI::AddGuiContainer("gameSetBtnsCon", new GuiContainer());
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->AddButton(
			"startGame", new Button(APIHelper::RectHelper(900, 625, 100, 20))
			);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->AddButton(
			"closeGame", new Button(APIHelper::RectHelper(900, 650, 100, 20))
			);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->AddButton(
			"gameOptions", new Button(APIHelper::RectHelper(900, 675, 100, 20))
			);
		ClientAPI::GetGuiContainer("gameSetBtnsCon")->AddButton(
			"returnToMainMenu", new Button(APIHelper::RectHelper(900, 725, 100, 20))
			);

		//adjust the containers
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

	}
};

