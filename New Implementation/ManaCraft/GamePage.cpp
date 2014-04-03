#include "GamePage.h"
#include "ClientAPI.h"
#include "ClientSettings.h"
#include "Client.h"
#include "ScreenFader.h"

using namespace ManaCraft::Client;

GamePage* GamePage::instance;

GamePage::GamePage() : Page()
{
	Load();
}

GamePage* GamePage::GetInstance()
{
	if (GamePage::instance == nullptr)
		GamePage::instance = new GamePage();

	return GamePage::instance;
}

GamePage::~GamePage()
{
	Page::~Page();
}

void GamePage::Load()
{
	content->AddGuiContainer("GUI", new GuiContainer());
	content->AddGuiContainer("InGameGUI", new GuiContainer());
	content->AddGuiContainer("InGamePause", new GuiContainer());

	LoadGUI();
	LoadInGameGUI();
	LoadInGamePause();

	//start with gamepage disabled
	content->Active = false;
}

void GamePage::LoadGUI()
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

	//Convenient Rects
	SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
	SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
	SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
	SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

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

	content->GetGuiContainer("GUI")->AddGuiElement("Overlay", new GuiElement(ClientAPI::GetTexture("borderOverlay"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
	content->GetGuiContainer("GUI")->AddGuiElement("Sidebar", new GuiElement(ClientAPI::GetTexture("sideBar"), APIHelper::RectHelper(SCREEN_WIDTH - SIDEBAR_WIDTH - 17, SCREEN_HEIGHT - SIDEBAR_HEIGHT - 32, SIDEBAR_WIDTH, SIDEBAR_HEIGHT))); //17 and 32 are arbitrary values used to position the sidebar
	content->GetGuiContainer("GUI")->AddGuiElement("Minimap", new GuiElement(ClientAPI::GetTexture("miniMap"), APIHelper::RectHelper(SCREEN_WIDTH - MINIMAP_WIDTH - 19, 60, MINIMAP_WIDTH, MINIMAP_HEIGHT)));
	content->GetGuiContainer("GUI")->AddGuiElement("ManaCounter", new GuiElement(ClientAPI::GetTexture("manaCounter"), APIHelper::RectHelper(64, 0, MANACOUNTER_WIDTH, MANACOUNTER_HEIGHT)));
	content->GetGuiContainer("GUI")->AddGuiElement("MPSCounter", new GuiElement(ClientAPI::GetTexture("mpsCounter"), APIHelper::RectHelper(128, 0, MPSCOUNTER_WIDTH, MPSCOUNTER_HEIGHT)));

	content->GetGuiContainer("GUI")->AddGuiContainer("Chat", new GuiContainer());
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ChatBacking", new GuiElement(ClientAPI::GetTexture("chatBacking"), APIHelper::RectHelper(32, SCREEN_HEIGHT - CHATBACKING_HEIGHT - 32, CHATBACKING_WIDTH, CHATBACKING_HEIGHT)));
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ChatBox", new GuiElement(ClientAPI::GetTexture("chatBox"), APIHelper::RectHelper(40, SCREEN_HEIGHT - CHATBOX_HEIGHT - 60, CHATBOX_WIDTH, CHATBOX_HEIGHT)));
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("MessageBacking", new GuiElement(ClientAPI::GetTexture("messageBacking"), APIHelper::RectHelper(40, SCREEN_HEIGHT - MESSAGEBACK_HEIGHT - 36, MESSAGEBACK_WIDTH, MESSAGEBACK_HEIGHT)));
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("ScrollBarBacking", new GuiElement(ClientAPI::GetTexture("scrollBarBacking"), APIHelper::RectHelper(40 + CHATBOX_WIDTH, SCREEN_HEIGHT - CHATBOX_HEIGHT - 48, SCROLLBAR_WIDTH, SCROLLBAR_HEIGHT)));

	//Chat Buttons
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("scrollUpButton", new Button(ClientAPI::GetTexture("scrollUpButton"), APIHelper::RectHelper(42 + CHATBOX_WIDTH, SCREEN_HEIGHT - SCROLLBAR_HEIGHT - 48 - 36, 17, 9)));
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->AddGuiElement("scrollDownButton", new Button(ClientAPI::GetTexture("scrollDownButton"), APIHelper::RectHelper(42 + CHATBOX_WIDTH, SCREEN_HEIGHT - 48 - 25, 17, 9)));

	//Button Listeners
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->GetButton("scrollUpButton")->SubscribeOnMouseClick(GamePage::Click_scrollUpButton);
	content->GetGuiContainer("GUI")->GetGuiContainer("Chat")->GetButton("scrollDownButton")->SubscribeOnMouseClick(GamePage::Click_scrollDownButton);
}

void GamePage::LoadInGameGUI()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;

	const int btnsX = 640;
	const int btnsY = 707;

	//temporary backgrounds for research, tower, and minion pages
	API_Util::AddSolidTexture("researchPopUpBG", { 100, 100, 100, 100 }, 700, 400);
	API_Util::AddSolidTexture("purchaseTowerCover", { 100, 100, 100, 100 }, 400, 180);
	API_Util::AddSolidTexture("purchaseMinionCover", { 100, 100, 100, 100 }, 400, 180);
	API_Util::AddSolidTexture("researchIcon", { 255, 0, 0, 255 }, 60, 60);
	API_Util::AddSolidTexture("towerIcon", { 0, 255, 0, 255 }, 60, 60);
	API_Util::AddSolidTexture("minionIcon", { 0, 0, 255, 255 }, 60, 60);

	//types of elements
	std::string types[4] = { "Air", "Earth", "Fire", "Water" };

	content->GetGuiContainer("InGameGUI")->AddGuiContainer("btnsCon", new GuiContainer());

	//add button to open the research tab and make it open the research tab when clicked
	API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "researchBtn", { btnsX + 0, btnsY + 0, 40, 30 }, "MedBtnNormal");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "researchBtn", "R", "Systema_22", "Black");
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("researchBtn")->GetLabel()->SetOffset({ 8, 0, 0, 0 });
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("researchBtn")->SubscribeOnMouseClick(OpenResearchPage);
}

void GamePage::LoadInGamePause()
{

}

void GamePage::Click_scrollUpButton()
{
	//move chat up
}

void GamePage::Click_scrollDownButton()
{
	//move chat down
}

void GamePage::OpenResearchPage()
{

}

void GamePage::ConfirmResearchAllocation()
{

}

void GamePage::CancelResearchAllocation()
{

}

void GamePage::CloseResearchAllocation()
{

}

void GamePage::OpenTowerPurchaseTab()
{

}

void GamePage::ConfirmTowerPurchase()
{

}

void GamePage::CancelTowerPurchase()
{

}

void GamePage::CloseTowerPurchaseTab()
{

}

void GamePage::OpenMinionPurchaseTab()
{

}

void GamePage::ConfirmMinionPurchase()
{

}

void GamePage::CancelMinionPurchase()
{

}

void GamePage::CloseMinionPurchaseTab()
{

}

void GamePage::Update(double time)
{

}

void GamePage::Draw()
{
	Page::Draw();
}