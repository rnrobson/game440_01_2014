#pragma once
#include "ClientAPI.h"
#include "API_Util.h"

class InGameGUI
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		const int btnsX = 30;
		const int btnsY = 50;

		//add font
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//add color
		API_Util::AddColor("White", 255, 255, 255, 255);

		//add textures
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		API_Util::AddSolidTexture("researchPopUpBG", { 100, 100, 100, 100 }, 700, 400);
		API_Util::AddSolidTexture("purchaseTowerCover", { 100, 100, 100, 100 }, 400, 180);
		API_Util::AddSolidTexture("purchaseMinionCover", { 100, 100, 100, 100 }, 400, 180);

		//add main container
		ClientAPI::AddGuiContainer("InGameGUI", new GuiContainer());

		//add container for research, tower, and minion btns
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("btnsCon", new GuiContainer());

		//add button to open the research tab and make it open the research tab when clicked
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "researchBtn", { btnsX + 0, btnsY + 0, 40, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "researchBtn", "R", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("researchBtn")->GetLabel()->SetOffset({ 8, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("researchBtn")->SubscribeOnMouseClick(OpenResearchPage);

		//add button to open the purchase tower tab and make it open the tower tab when clicked
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyTowerBtn", { btnsX + 40, btnsY + 0, 40, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyTowerBtn", "T", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyTowerBtn")->GetLabel()->SetOffset({ 10, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyTowerBtn")->SubscribeOnMouseClick(OpenTowerPurchaseTab);

		//add button to open purchase minion tab and make it open the minions tab when clicked
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyMinionBtn", { btnsX + 80, btnsY + 0, 40, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon"), "buyMinionBtn", "M", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyMinionBtn")->GetLabel()->SetOffset({ 5, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->GetButton("buyMinionBtn")->SubscribeOnMouseClick(OpenMinionPurchaseTab);


		/*
		Notes: 
		-change the gui stuff so that they are positioned relative to the background of their container
		-
		*/


		//add research container
		SDL_Rect researchCoverRect = { (SCREEN_WIDTH / 2) - 350, (SCREEN_HEIGHT / 2) - 300, 700, 400 };
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("ResearchPageCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"researchCover", "researchPopUpBG", researchCoverRect);
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"researchLbl", "Research", { (SCREEN_WIDTH / 2) - 345, (SCREEN_HEIGHT / 2) - 315, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"closeResearchPage", { SCREEN_WIDTH - 195, 90, 25, 25 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"confirmChanges", { researchCoverRect.x + researchCoverRect.w - 90, researchCoverRect.y + researchCoverRect.h - 75, 80, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"cancelChanges", { researchCoverRect.x + researchCoverRect.w - 90, researchCoverRect.y + researchCoverRect.h - 40, 80, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "confirmChanges", "Confirm", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "cancelChanges", "Cancel", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"closeResearchPage", "X", "Systema_22", "Black");
		
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->
			GetButton("closeResearchPage")->GetLabel()->SetPadding({ 1, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->Active = false;

		//add purchase tower container
		SDL_Rect pTowerBGRect = { (SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) - 90, 400, 180 };
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseTowerCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"purchaseTowerBG", "purchaseTowerCover", pTowerBGRect);
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"towerLbl", "Tower", { (SCREEN_WIDTH / 2) - 196, (SCREEN_HEIGHT / 2) - 105, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"closeTPurchaseTab", { (SCREEN_WIDTH / 2) + 169, (SCREEN_HEIGHT / 2) - 85, 25, 25 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "confirmChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 75, 80, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"closeTPurchaseTab", "X", "Systema_22", "Black");

		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "cancelChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 40, 80, 30 }, "MedBtnNormal");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->
			GetButton("closeTPurchaseTab")->GetLabel()->SetPadding({ 1, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = false;

		//add purchase minion container
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseMinionCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"purchaseMinionBG", "purchaseMinionCover", { (SCREEN_WIDTH / 2) - 200, (SCREEN_HEIGHT / 2) - 90, 400, 180 });
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"minionLbl", "Minions", { (SCREEN_WIDTH / 2) - 196, (SCREEN_HEIGHT / 2) - 105, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"closeMPurchaseTab", { (SCREEN_WIDTH / 2) + 169, (SCREEN_HEIGHT / 2) - 85, 25, 25 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"closeMPurchaseTab", "X", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->
			GetButton("closeMPurchaseTab")->GetLabel()->SetPadding({ 1, 0, 0, 0 });
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;

		//add events to buttons to close the tabs
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("closeResearchPage")->SubscribeOnMouseClick(CloseResearchPage);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("closeTPurchaseTab")->SubscribeOnMouseClick(CloseTowerPurchaseTab);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("closeMPurchaseTab")->SubscribeOnMouseClick(CloseMinionPurchaseTab);
	}

	static void Update(double _time)
	{

	}

	static void OpenResearchPage()
	{
		std::cout << "research page opened" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = false;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->Active = true;
	}

	static void UpgradeAirMinions()
	{

	}

	static void UpgradeEarthMinions()
	{

	}

	static void UpgradeFireMinions()
	{
		
	}

	static void UpgradeWaterMinions()
	{

	}

	static void CloseResearchPage()
	{
		std::cout << "research page closed" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->Active = false;
	}

	//tower tab btn events
	static void OpenTowerPurchaseTab()
	{
		std::cout << "tower tab opened" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = false;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = true;
	}

	static void BuyTower()
	{

	}

	static void CancelTowerPurchase()
	{

	}

	static void CloseTowerPurchaseTab()
	{
		std::cout << "tower tab closed" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = false;
	}

	//minion tab btn events
	static void OpenMinionPurchaseTab()
	{
		std::cout << "minion tab opened" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = false;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = true;
	}

	static void BuyMinion()
	{

	}

	static void CancelMinionPurchase()
	{

	}

	static void CloseMinionPurchaseTab()
	{
		std::cout << "minion tab close" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;
	}
};

