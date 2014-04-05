#include "GamePage.h"
#include "ClientAPI.h"
#include "ClientSettings.h"
#include "Client.h"
#include "ScreenFader.h"

using namespace ManaCraft::Client;

GamePage* GamePage::instance;

GamePage::GamePage() : Page()
{
	content->SubscribeOnEnterKeyPressed(ButtonPress_OnEscapePressed);
	content->SubscribeOnEnterKeyPressed(ButtonPress_OnEnterPressed);

	Load();
	mana = 0;
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
	LoadInGamePause();
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

	const int btnsX = 640;
	const int btnsY = 707;

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

	//add button to open the purchase tower tab and make it open the tower tab when clicked
	API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyTowerBtn", { btnsX + 40, btnsY + 0, 40, 30 }, "MedBtnNormal");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyTowerBtn", "T", "Systema_22", "Black");
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyTowerBtn")->GetLabel()->SetOffset({ 10, 0, 0, 0 });
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyTowerBtn")->SubscribeOnMouseClick(OpenTowerPurchaseTab);

	//add button to open purchase minion tab and make it open the minions tab when clicked
	API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyMinionBtn", { btnsX + 80, btnsY + 0, 40, 30 }, "MedBtnNormal");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyMinionBtn", "M", "Systema_22", "Black");
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyMinionBtn")->GetLabel()->SetOffset({ 5, 0, 0, 0 });
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyMinionBtn")->SubscribeOnMouseClick(OpenMinionPurchaseTab);

	//|reserved for the research page|

	//|---------end reserve----------|

	//add purchase tower container
	SDL_Rect pTowerBGRect = { (SCREEN_WIDTH / 2) - 310, (SCREEN_HEIGHT / 2) - 90, 400, 180 };
	content->GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseTowerCon", new GuiContainer());
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
		"purchaseTowerBG", "purchaseTowerCover", pTowerBGRect);
	API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
		"towerLbl", "Tower", { pTowerBGRect.x + 5, pTowerBGRect.y - 20, 100, 40 }, "Systema_22", "White");
	API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
		"closeTPurchaseTab", { pTowerBGRect.x + pTowerBGRect.w - 27, pTowerBGRect.y + 2, 25, 25 }, "MedBtnNormal");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "closeTPurchaseTab", "X", "Systema_22", "Black");
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("closeTPurchaseTab")->GetLabel()->SetPadding({ 2, 0, 0, 0 });

	API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "manaLeft", "Mana: 0",
	{ pTowerBGRect.x + 20, pTowerBGRect.y + 15, 500, 60 }, "Systema_22", "White");

	for (size_t tType = 0; tType < 4; tType++)
	{
		std::string towerName = types[tType] + "Tower";
		API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "Lbl", types[tType],
		{ pTowerBGRect.x + 65 + (70 * tType), pTowerBGRect.y + 50, 100, 60 }, "Systema_11", "White");
		API_Util::AddGuiElementToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName, "towerIcon",
		{ pTowerBGRect.x + 65 + (70 * tType), pTowerBGRect.y + 65, 60, 60 });
		API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "SelectBtn",
		{ pTowerBGRect.x + 65 + (70 * tType), pTowerBGRect.y + pTowerBGRect.h - 40, 60, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "SelectBtn",
			"Select", "Systema_11", "Black");
		content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton(towerName + "SelectBtn")->GetLabel()->SetPadding({ 7, 8, 0, 0 });
	}
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("closeTPurchaseTab")->SubscribeOnMouseClick(CloseTowerPurchaseTab);
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = false;

	//add purchase minion container
	SDL_Rect pMinionBGRect = { (SCREEN_WIDTH / 2) - 310, (SCREEN_HEIGHT / 2) - 90, 400, 180 };
	content->GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseMinionCon", new GuiContainer());
	API_Util::AddGuiElementToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
		"purchaseMinionBG", "purchaseMinionCover", pMinionBGRect);
	API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
		"minionLbl", "Minions", { pMinionBGRect.x + 5, pMinionBGRect.y - 20, 100, 40 }, "Systema_22", "White");
	API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
		"closeMPurchaseTab", { pMinionBGRect.x + pMinionBGRect.w - 27, pMinionBGRect.y + 2, 25, 25 }, "MedBtnNormal");
	API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "closeMPurchaseTab", "X", "Systema_22", "Black");
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("closeMPurchaseTab")->GetLabel()->SetPadding({ 2, 0, 0, 0 });

	API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "manaLeft", "Mana: 0",
	{ pTowerBGRect.x + 20, pTowerBGRect.y + 15, 300, 30 }, "Systema_22", "White");

	for (size_t mType = 0; mType < 4; mType++)
	{
		std::string minionName = types[mType] + "Tower";
		API_Util::AddLabelToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "Lbl", types[mType],
		{ pTowerBGRect.x + 65 + (70 * mType), pTowerBGRect.y + 50, 100, 60 }, "Systema_11", "White");
		API_Util::AddGuiElementToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName, "minionIcon",
		{ pTowerBGRect.x + 65 + (70 * mType), pTowerBGRect.y + 65, 60, 60 });
		API_Util::AddButtonToContainer(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "SelectBtn",
		{ pTowerBGRect.x + 65 + (70 * mType), pTowerBGRect.y + pTowerBGRect.h - 40, 60, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "SelectBtn",
			"Select", "Systema_11", "Black");
		content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton(minionName + "SelectBtn")->GetLabel()->SetPadding({ 7, 8, 0, 0 });
	}
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("closeMPurchaseTab")->SubscribeOnMouseClick(CloseMinionPurchaseTab);
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;
}

void GamePage::LoadInGamePause()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;
	const int MARGIN_Y = 20;
	const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

	//-- Convienient rects
	SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
	SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
	SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
	SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

	//-- Additional rects
	SDL_Rect pauseMenuRect = APIHelper::RectHelper(0, 0, 400, 300);

	//-- Add in menu assets
	ClientAPI::AddGuiContainer("IngamePause", new GuiContainer());

	//-- Background
	ClientAPI::GetGuiContainer("IngamePause")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("PausedBackground"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	//-- Secondary container
	ClientAPI::GetGuiContainer("IngamePause")->AddGuiContainer("PauseMenu", new GuiContainer());
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiElement("Backing", new GuiElement(ClientAPI::GetTexture("ContainerBacking"), pauseMenuRect));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->SetPosition(APIHelper::RectHelper(centerRect.x - 200, centerRect.y - 150, 400, 300));

	//-- Header
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiElement("Header",
		new GuiElement(ClientAPI::GetTexture("PausedHeader"), APIHelper::RectHelper(pauseMenuRect.x + pauseMenuRect.w / 2 - 62, pauseMenuRect.y + MARGIN_Y, 125, 40)));

	//-- Buttons
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiContainer("BtnHolder", new GuiContainer());
	SDL_Rect containerPos = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetPosition();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(containerPos.x + (pauseMenuRect.w / 2 - longBtnRect.w / 2), containerPos.y + 65, 0, 0));

	int xBtn, btnIndex = 0;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("ResumeBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->GetX();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->AddLabel("Resume", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("SaveQuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->GetX();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->AddLabel("Save & Quit", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("QuitMenuBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->GetX();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->AddLabel("Quit > Menu", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("QuitDesktopBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->GetX();
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->AddLabel("Quit > Desktop", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->SubscribeOnMouseClick(Click_resume);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(Click_options);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->SubscribeOnMouseClick(Click_save);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->SubscribeOnMouseClick(Click_quitMenu);
	ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->SubscribeOnMouseClick(Click_quitDesktop);

	isPaused = false;
}

void GamePage::ButtonPress_OnEscapePressed()
{

}

void GamePage::ButtonPress_OnEnterPressed()
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
	//disabled for now. no idea what goes in here. the research idea has been removed, I think?
	printf("opens research page. Disabled.\n");
}

void GamePage::CloseResearchPage()
{

}

void GamePage::OpenTowerPurchaseTab()
{
	printf("opens tower tab.\n");
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = true;
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = false;
}

void GamePage::CloseTowerPurchaseTab()
{
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = false;
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
}

void GamePage::OpenMinionPurchaseTab()
{
	printf("opens minions tab.\n");
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = true;
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = false;
}

void GamePage::CloseMinionPurchaseTab()
{
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;
	GamePage::GetInstance()->GetContent()->GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
}

void GamePage::Click_resume()
{
	printf("resume game\n");
}

void GamePage::Click_options()
{
	printf("go to options\n");
}

void GamePage::Click_save()
{
	printf("save game\n");
}

void GamePage::Click_quitMenu()
{
	printf("quit to menu\n");
	ClientAPI::SetFocus(MainMenu::GetInstance());
}

void GamePage::Click_quitDesktop()
{
	ClientAPI::ExitMainLoop();
}
void GamePage::Update(double time)
{
	UpdateManaText();
}

void GamePage::Draw()
{
	Page::Draw();
}

void GamePage::UpdateManaText()
{
	//temporary(for testing)
	mana++;

	std::string manaLeft = "MP:" + std::to_string(mana);

	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetLabel("manaLeft")->text = manaLeft;
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetLabel("manaLeft")->RenderText();
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetLabel("manaLeft")->text = manaLeft;
	content->GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetLabel("manaLeft")->RenderText();
}