#pragma once
#include <ClientAPI.h>

class GUI
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//GUI Element Dimensions
		const int SIDEBAR_WIDTH = 207;
		const int SIDEBAR_HEIGHT = 471;

		const int MINIMAP_WIDTH = 201;
		const int MINIMAP_HEIGHT = 200;

		const int CHATBOX_WIDTH = 522;
		const int CHATBOX_HEIGHT = 148;

		const int CHATBACKING_WIDTH = 583;
		const int CHATBACKING_HEIGHT = 196;

		const int MESSAGEBACK_WIDTH = 522;
		const int MESSAGEBACK_HEIGHT = 26;

		const int SCROLLBAR_WIDTH = 21;
		const int SCROLLBAR_HEIGHT = 122;

		const int MANACOUNTER_WIDTH = 52;
		const int MANACOUNTER_HEIGHT = 90;

		const int MPSCOUNTER_WIDTH = 77;
		const int MPSCOUNTER_HEIGHT = 62;


		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);
		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		//Convenient Rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//Load in the necessary textures
			//GUI Container
		SDL_Texture *borderOverlay = APIHelper::LoadPNGTexture("Resources/GUITextures/overlay.png");
		SDL_Texture *sideBar = APIHelper::LoadPNGTexture("Resources/GUITextures/sidebar.png");
		SDL_Texture *miniMap = APIHelper::LoadPNGTexture("Resources/GUITextures/minimap.png");
		SDL_Texture *manaCounter = APIHelper::LoadPNGTexture("Resources/GUITextures/manaCounter.png");
		SDL_Texture *mpsCounter = APIHelper::LoadPNGTexture("Resources/GUITextures/manaPerSecCounter.png");



			//Chat Container
		SDL_Texture *gameChatBacking = APIHelper::LoadPNGTexture("Resources/GUITextures/gameChatBacking.png");
		SDL_Texture *chatBox = APIHelper::LoadPNGTexture("Resources/GUITextures/chatBoxBacking.png");
		SDL_Texture *messageField = APIHelper::LoadPNGTexture("Resources/GUITextures/messageFieldBacking.png");
		SDL_Texture *scrollBarBacking = APIHelper::LoadPNGTexture("Resources/GUITextures/scrollbarBacking.png");
		SDL_Texture *scrollBarUp = APIHelper::LoadPNGTexture("Resources/GUITextures/scrollUpButton.png");
		SDL_Texture *scrollBarDown = APIHelper::LoadPNGTexture("Resources/GUITextures/scrollDownButton.png");



		//Add the textures
			//GUI Container
		ClientAPI::AddTexture("borderOverlay", borderOverlay);
		ClientAPI::AddTexture("sideBar", sideBar);
		ClientAPI::AddTexture("miniMap", miniMap);
		ClientAPI::AddTexture("manaCounter", manaCounter);
		ClientAPI::AddTexture("mpsCounter", mpsCounter);



			//Chat Container
		ClientAPI::AddTexture("chatBox", chatBox);
		ClientAPI::AddTexture("chatBacking", gameChatBacking);
		ClientAPI::AddTexture("messageBacking", messageField);
		ClientAPI::AddTexture("scrollBarBacking", scrollBarBacking);
		ClientAPI::AddTexture("scrollUpButton", scrollBarUp);
		ClientAPI::AddTexture("scrollDownButton", scrollBarDown);



		//Container Framework
		ClientAPI::AddGuiContainer("GUI", new GuiContainer());
		ClientAPI::GetGuiContainer("GUI")->AddGuiContainer("Chat", new GuiContainer());

		//Add the GUI Elements to their respective containers
			//GUI Container
		ClientAPI::GetGuiContainer("GUI")->AddGuiElement("Overlay", new GuiElement(ClientAPI::GetTexture("borderOverlay"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->AddGuiElement("Sidebar", new GuiElement(ClientAPI::GetTexture("sideBar"), APIHelper::RectHelper(SCREEN_WIDTH - SIDEBAR_WIDTH - 17, SCREEN_HEIGHT - SIDEBAR_HEIGHT - 32, SIDEBAR_WIDTH, SIDEBAR_HEIGHT))); //17 and 32 are arbitrary values used to position the sidebar
		ClientAPI::GetGuiContainer("GUI")->AddGuiElement("Minimap", new GuiElement(ClientAPI::GetTexture("miniMap"), APIHelper::RectHelper(SCREEN_WIDTH - MINIMAP_WIDTH - 19, 60, MINIMAP_WIDTH, MINIMAP_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->AddGuiElement("ManaCounter", new GuiElement(ClientAPI::GetTexture("manaCounter"), APIHelper::RectHelper(64, 0, MANACOUNTER_WIDTH, MANACOUNTER_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->AddGuiElement("MPSCounter", new GuiElement(ClientAPI::GetTexture("mpsCounter"), APIHelper::RectHelper(128, 0, MPSCOUNTER_WIDTH, MPSCOUNTER_HEIGHT)));




			//Chat Container
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ChatBacking", new GuiElement(ClientAPI::GetTexture("chatBacking"), APIHelper::RectHelper(32, SCREEN_HEIGHT - CHATBACKING_HEIGHT - 32, CHATBACKING_WIDTH, CHATBACKING_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ChatBox", new GuiElement(ClientAPI::GetTexture("chatBox"), APIHelper::RectHelper(40, SCREEN_HEIGHT - CHATBOX_HEIGHT - 60, CHATBOX_WIDTH, CHATBOX_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("MessageBacking", new GuiElement(ClientAPI::GetTexture("messageBacking"), APIHelper::RectHelper(40, SCREEN_HEIGHT - MESSAGEBACK_HEIGHT - 36, MESSAGEBACK_WIDTH, MESSAGEBACK_HEIGHT)));
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ScrollBarBacking", new GuiElement(ClientAPI::GetTexture("scrollBarBacking"), APIHelper::RectHelper(40 + CHATBOX_WIDTH, SCREEN_HEIGHT - CHATBOX_HEIGHT - 48, SCROLLBAR_WIDTH, SCROLLBAR_HEIGHT)));

			//Chat Buttons
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddButton("scrollUpButton", new Button(ClientAPI::GetTexture("scrollUpButton"), APIHelper::RectHelper(42+CHATBOX_WIDTH, SCREEN_HEIGHT - SCROLLBAR_HEIGHT - 48 - 36, 17, 9)));
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddButton("scrollDownButton", new Button(ClientAPI::GetTexture("scrollDownButton"), APIHelper::RectHelper(42 + CHATBOX_WIDTH, SCREEN_HEIGHT - 48 - 25, 17, 9)));

			//Button Listeners
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->GetButton("scrollUpButton")->SubscribeOnMouseClick(GUI::Click_scrollUpButton);
		ClientAPI::GetGuiContainer("GUI")->GetGuiContainer("Chat")->GetButton("scrollDownButton")->SubscribeOnMouseClick(GUI::Click_scrollDownButton);




		//Set Active to false by default
		ClientAPI::GetGuiContainer("GUI")->Active = false;
	}

	static void Click_scrollUpButton(){
		//Move the chat up
	}

	static void Click_scrollDownButton(){
		//Move the chat up
	}
};