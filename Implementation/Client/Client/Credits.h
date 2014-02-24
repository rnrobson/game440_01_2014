#pragma once
#include <ClientAPI.h>

class Credits
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int LABEL_SPACE_Y = 25;
		const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

		std::string clientStrings[9] = { "Andrew Godfroy", "Cassandra Siewert", "Christian Adao", "David Vo", "Geordie Powers", "Neil Schlachter", "Tyler Remazki", "Deanna Sowa" };
		std::string networkStrings[7] = { "Joshua O'Donnell", "Philip Diehl", "Dean Watts", "Suleyman Tahirli", "Brian Lefrancois", "Sarah Childs", "Mitch Andrews" };
		std::string serverStrings[7] = { "Rohun Banerji", "Justin Kan", "Jordan Kjaer", "Patrick Barahona-Griffiths", "Chris Devlieger", "Alex McCann", "Wayne Gauthier" };
		std::string databaseStrings[5] = { "Robert Evola", "Matt Mayo", "Vinny Crupi", "Kyle Nokes", "Jordan Hurst" };

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		ClientAPI::AddFont("Systema", systema);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		//-- Load Textures
		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/backgroundPlain.png");
		SDL_Texture *logoTex = APIHelper::LoadPNGTexture("Resources/Images/ManaCraftLogoCredits.png");
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");

		ClientAPI::AddTexture("BackgroundPlain", backgroundTex);
		ClientAPI::AddTexture("GameLogoSmall", logoTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//-- Other rects
		SDL_Rect backBtnRect = APIHelper::RectHelper(BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);
		SDL_Rect clientRect = APIHelper::RectHelper(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 3, 0, 0);
		SDL_Rect networkRect = APIHelper::RectHelper(SCREEN_WIDTH - (SCREEN_WIDTH / 5) * 2, SCREEN_HEIGHT / 3, 0, 0);
		SDL_Rect serverRect = APIHelper::RectHelper(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 5, 0, 0);
		SDL_Rect databaseRect = APIHelper::RectHelper(SCREEN_WIDTH - (SCREEN_WIDTH / 5) * 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 5, 0, 0);

		//-- Add in credits assets
		ClientAPI::AddGuiContainer("Credits", new GuiContainer());
		ClientAPI::GetGuiContainer("Credits")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
		ClientAPI::GetGuiContainer("Credits")->AddGuiContainer("ClientCredits", new GuiContainer());
		ClientAPI::GetGuiContainer("Credits")->AddGuiContainer("NetworkCredits", new GuiContainer());
		ClientAPI::GetGuiContainer("Credits")->AddGuiContainer("ServerCredits", new GuiContainer());
		ClientAPI::GetGuiContainer("Credits")->AddGuiContainer("DatabaseCredits", new GuiContainer());

		ClientAPI::GetGuiContainer("Credits")->AddButton("BackBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), backBtnRect));
		ClientAPI::GetGuiContainer("Credits")->GetButton("BackBtn")->AddLabel("Back", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("Credits")->GetButton("BackBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		ClientAPI::GetGuiContainer("Credits")->GetButton("BackBtn")->SubscribeOnMouseClick(Credits::Click_backButton);
		ClientAPI::GetGuiContainer("Credits")->GetButton("BackBtn")->SubscribeOnEscapeKeyPressed(Credits::Click_backButton);

		ClientAPI::GetGuiContainer("Credits")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogoSmall"), APIHelper::RectHelper(SCREEN_WIDTH / 2 - 250, 0, 500, 250)));

		ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("ClientCredits")->AddLabel("ClientHeader", new Label("Client Team", APIHelper::RectHelper(clientRect.x, clientRect.y - LABEL_SPACE_Y * 2, clientRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		for (int i = 0; i < 9; i++)
		{
			ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("ClientCredits")->AddLabel("c" + i, new Label(clientStrings[i],
				APIHelper::RectHelper(clientRect.x, clientRect.y + (i * LABEL_SPACE_Y), clientRect.w, LABEL_SPACE_Y),
				ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		}

		ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("NetworkCredits")->AddLabel("NetworkHeader", new Label("Networking Team", APIHelper::RectHelper(networkRect.x, networkRect.y - LABEL_SPACE_Y * 2, networkRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		for (int i = 0; i < 7; i++)
		{
			ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("NetworkCredits")->AddLabel("n" + i, new Label(networkStrings[i],
				APIHelper::RectHelper(networkRect.x, networkRect.y + (i * LABEL_SPACE_Y), networkRect.w, LABEL_SPACE_Y),
				ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		}

		ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("ServerCredits")->AddLabel("ServerHeader", new Label("Server Team", APIHelper::RectHelper(serverRect.x, serverRect.y - LABEL_SPACE_Y * 2, serverRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		for (int i = 0; i < 7; i++)
		{
			ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("ServerCredits")->AddLabel("s" + i, new Label(serverStrings[i],
				APIHelper::RectHelper(serverRect.x, serverRect.y + (i * LABEL_SPACE_Y), serverRect.w, LABEL_SPACE_Y),
				ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		}

		ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("DatabaseCredits")->AddLabel("DatabaseHeader", new Label("Database Team", APIHelper::RectHelper(databaseRect.x, databaseRect.y - LABEL_SPACE_Y * 2, databaseRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		for (int i = 0; i < 5; i++)
		{
			ClientAPI::GetGuiContainer("Credits")->GetGuiContainer("DatabaseCredits")->AddLabel("d" + i, new Label(databaseStrings[i],
				APIHelper::RectHelper(databaseRect.x, databaseRect.y + (i * LABEL_SPACE_Y), databaseRect.w, LABEL_SPACE_Y),
				ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		}
		ClientAPI::GetGuiContainer("Credits")->Active = false;
	}

	static void Click_backButton()
	{
		std::cout << "Back to main menu.\n";
		ClientAPI::GetGuiContainer("Credits")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		ScreenFader::FadeOut();
	}
};
