#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
using namespace ManaCraft::Client;

class InGameGUI
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		const int btnsX = 640;
		const int btnsY = 707;

		//add font
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//add color
		API_Util::AddColor("White", 255, 255, 255, 255);

		//add textures
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		//temporary backgrounds for research, tower, and minion pages
		API_Util::AddSolidTexture("researchPopUpBG", { 100, 100, 100, 100 }, 700, 400);
		API_Util::AddSolidTexture("purchaseTowerCover", { 100, 100, 100, 100 }, 400, 180);
		API_Util::AddSolidTexture("purchaseMinionCover", { 100, 100, 100, 100 }, 400, 180);
		API_Util::AddSolidTexture("researchIcon", { 255, 0, 0, 255 }, 60, 60);
		API_Util::AddSolidTexture("towerIcon", { 0, 255, 0, 255 }, 60, 60);
		API_Util::AddSolidTexture("minionIcon", { 0, 0, 255, 255 }, 60, 60);

		//types of elements
		std::string types[4] = { "Air", "Earth", "Fire", "Water" };

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

		//add research container
		SDL_Rect researchCoverRect = { (SCREEN_WIDTH / 2) - 455, (SCREEN_HEIGHT / 2) - 250, 700, 400 };
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("ResearchPageCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"researchCover", "researchPopUpBG", researchCoverRect);
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"researchLbl", "Research", { researchCoverRect.x + 5, researchCoverRect.y - 20, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"closeResearchPage", { researchCoverRect.x + researchCoverRect.w - 27, researchCoverRect.y + 2, 25, 25 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"confirmChanges", { researchCoverRect.x + researchCoverRect.w - 90, researchCoverRect.y + researchCoverRect.h - 75, 80, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"),
			"cancelChanges", { researchCoverRect.x + researchCoverRect.w - 90, researchCoverRect.y + researchCoverRect.h - 40, 80, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "confirmChanges", "Confirm", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "cancelChanges", "Cancel", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "closeResearchPage", "X", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("closeResearchPage")->GetLabel()->SetPadding({ 2, 0, 0, 0 });

		//--------------------------
		//how would I concat a string and an int/size_t?
		//--------------------------

		for (size_t type = 0; type < 4; type++)
		{
			API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), types[type], types[type],
			{ researchCoverRect.x + 80 + (130 * type), researchCoverRect.y + 25, 100, 60 }, "Systema_11", "White");

			for (int tier = 0; tier < 4; tier++)
			{
				std::string iconName = "rIcon" + types[type];
				API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), iconName, "researchIcon",
				{ researchCoverRect.x + 80 + (130 * type), researchCoverRect.y + 60 + (75 * tier), 60, 60 });
			}
		}

		SDL_Rect upgradeBtns[4] = {
			{ researchCoverRect.x + 80, researchCoverRect.y + researchCoverRect.h - 40, 60, 25 },
			{ researchCoverRect.x + 210, researchCoverRect.y + researchCoverRect.h - 40, 60, 25 },
			{ researchCoverRect.x + 340, researchCoverRect.y + researchCoverRect.h - 40, 60, 25 },
			{ researchCoverRect.x + 470, researchCoverRect.y + researchCoverRect.h - 40, 60, 25 },
		};

		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeAirMinion", upgradeBtns[0], "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeEarthMinion", upgradeBtns[1], "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeFireMinion", upgradeBtns[2], "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeWaterMinion", upgradeBtns[3], "MedBtnNormal");

		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeAirMinion", "Upgrade", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeEarthMinion", "Upgrade", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeFireMinion", "Upgrade", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon"), "upgradeWaterMinion", "Upgrade", "Systema_11", "Black");

		SDL_Rect upgradeBtnPadding = { 1, 4, 0, 0 };
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeAirMinion")->GetLabel()->SetPadding(upgradeBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeEarthMinion")->GetLabel()->SetPadding(upgradeBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeFireMinion")->GetLabel()->SetPadding(upgradeBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeWaterMinion")->GetLabel()->SetPadding(upgradeBtnPadding);

		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->Active = false;

		//add purchase tower container
		SDL_Rect pTowerBGRect = { (SCREEN_WIDTH / 2) - 310, (SCREEN_HEIGHT / 2) - 90, 400, 180 };
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseTowerCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"purchaseTowerBG", "purchaseTowerCover", pTowerBGRect);
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"towerLbl", "Tower", { pTowerBGRect.x + 5, pTowerBGRect.y - 20, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"),
			"closeTPurchaseTab", { pTowerBGRect.x + pTowerBGRect.w - 27, pTowerBGRect.y + 2, 25, 25 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "confirmChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 75, 80, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "cancelChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 40, 80, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "confirmChanges", "Confirm", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "cancelChanges", "Cancel", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), "closeTPurchaseTab", "X", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("closeTPurchaseTab")->GetLabel()->SetPadding({ 2, 0, 0, 0 });
		
		for (size_t tType = 0; tType < 4; tType++)
		{
			std::string towerName = types[tType] + "Tower";
			API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName, "towerIcon",
				{ pTowerBGRect.x + 25 + (70 * tType), pTowerBGRect.y + 25, 60, 60 });
			API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "Lbl", types[tType],
				{ pTowerBGRect.x + 25 + (70 * tType), pTowerBGRect.y + 10, 100, 60 }, "Systema_11", "White");
			API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "SelectBtn",
			{ pTowerBGRect.x + 25 + (70 * tType), pTowerBGRect.y + pTowerBGRect.h - 40, 60, 30 }, "MedBtnNormal");
			API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon"), towerName + "SelectBtn",
				"Select", "Systema_11", "Black");
			ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton(towerName + "SelectBtn")->GetLabel()->SetPadding({ 7, 8, 0, 0 });
		}

		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->Active = false;

		//add purchase minion container
		SDL_Rect pMinionBGRect = { (SCREEN_WIDTH / 2) - 310, (SCREEN_HEIGHT / 2) - 90, 400, 180 };
		ClientAPI::GetGuiContainer("InGameGUI")->AddGuiContainer("PurchaseMinionCon", new GuiContainer());
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"purchaseMinionBG", "purchaseMinionCover", pMinionBGRect);
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"minionLbl", "Minions", { pMinionBGRect.x + 5, pMinionBGRect.y - 20, 100, 40 }, "Systema_22", "White");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"),
			"closeMPurchaseTab", { pMinionBGRect.x + pMinionBGRect.w - 27, pMinionBGRect.y + 2, 25, 25 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "confirmChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 75, 80, 30 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "cancelChanges",
		{ pTowerBGRect.x + pTowerBGRect.w - 90, pTowerBGRect.y + pTowerBGRect.h - 40, 80, 30 }, "MedBtnNormal");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "confirmChanges", "Confirm", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "cancelChanges", "Cancel", "Systema_11", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), "closeMPurchaseTab", "X", "Systema_22", "Black");
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("closeMPurchaseTab")->GetLabel()->SetPadding({ 2, 0, 0, 0 });

		for (size_t mType = 0; mType < 4; mType++)
		{
			std::string minionName = types[mType] + "Tower";
			API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName, "minionIcon",
			{ pTowerBGRect.x + 25 + (70 * mType), pTowerBGRect.y + 25, 60, 60 });
			API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "Lbl", types[mType],
			{ pTowerBGRect.x + 25 + (70 * mType), pTowerBGRect.y + 10, 100, 60 }, "Systema_11", "White");
			API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "SelectBtn",
			{ pTowerBGRect.x + 25 + (70 * mType), pTowerBGRect.y + pTowerBGRect.h - 40, 60, 30 }, "MedBtnNormal");
			API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon"), minionName + "SelectBtn",
				"Select", "Systema_11", "Black");
			ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton(minionName + "SelectBtn")->GetLabel()->SetPadding({ 7, 8, 0, 0 });
		}

		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;

		//set padding for confirm and cancel buttons
		SDL_Rect confirmBtnPadding = { 12, 8, 0, 0 };
		SDL_Rect cancelBtnPadding = { 15, 8, 0, 0 };

		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("confirmChanges")->GetLabel()->SetPadding(confirmBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("cancelChanges")->GetLabel()->SetPadding(cancelBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("confirmChanges")->GetLabel()->SetPadding(confirmBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("cancelChanges")->GetLabel()->SetPadding(cancelBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("confirmChanges")->GetLabel()->SetPadding(confirmBtnPadding);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("cancelChanges")->GetLabel()->SetPadding(cancelBtnPadding);

		//add events to buttons to close the tabs
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("closeResearchPage")->SubscribeOnMouseClick(CloseResearchPage);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("closeTPurchaseTab")->SubscribeOnMouseClick(CloseTowerPurchaseTab);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("closeMPurchaseTab")->SubscribeOnMouseClick(CloseMinionPurchaseTab);

		//add event to confirm buttons
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("confirmChanges")->SubscribeOnMouseClick(ConfirmResearchAllocation);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("confirmChanges")->SubscribeOnMouseClick(ConfirmTowerPurchase);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("confirmChanges")->SubscribeOnMouseClick(ConfirmMinionPurchase);

		//add event to cancel buttons
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("cancelChanges")->SubscribeOnMouseClick(CancelResearchAllocation);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("cancelChanges")->SubscribeOnMouseClick(CancelTowerPurchase);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->GetButton("cancelChanges")->SubscribeOnMouseClick(CancelMinionPurchase);

		//add upgrade events to research buttons
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeAirMinion")->SubscribeOnMouseClick(UpgradeAirMinions);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeEarthMinion")->SubscribeOnMouseClick(UpgradeEarthMinions);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeFireMinion")->SubscribeOnMouseClick(UpgradeFireMinions);
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("ResearchPageCon")->GetButton("upgradeWaterMinion")->SubscribeOnMouseClick(UpgradeWaterMinions);

		//add select events to tower select buttons
		/*ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("AirSelectBtn")->SubscribeOnMouseClick();
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("EarthSelectBtn")->SubscribeOnMouseClick();
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("FireSelectBtn")->SubscribeOnMouseClick();
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseTowerCon")->GetButton("WaterSelectBtn")->SubscribeOnMouseClick();*/

		//add select events to minion select buttons

		//start with InGameGUI disabled
		ClientAPI::GetGuiContainer("InGameGUI")->Active = false;
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
		std::cout << "upgrade air minion" << std::endl;
	}

	static void UpgradeEarthMinions()
	{
		std::cout << "upgrade earth minion" << std::endl;
	}

	static void UpgradeFireMinions()
	{
		std::cout << "upgrade fire minion" << std::endl;
	}

	static void UpgradeWaterMinions()
	{
		std::cout << "upgrade water minion" << std::endl;
	}

	static void ConfirmResearchAllocation()
	{
		std::cout << "confirm allocation to a research" << std::endl;
	}

	static void CancelResearchAllocation()
	{
		std::cout << "cancel allocation" << std::endl;
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

	static void SelectTower(std::string _towerType)
	{
		std::cout << "selected " << _towerType << " tower" << std::endl;
	}

	static void ConfirmTowerPurchase()
	{
		std::cout << "purchase selected tower" << std::endl;
	}

	static void CancelTowerPurchase()
	{
		std::cout << "cancel purchase of tower" << std::endl;
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

	static void ConfirmMinionPurchase()
	{
		std::cout << "purchase selected minion" << std::endl;
	}

	static void CancelMinionPurchase()
	{
		std::cout << "cancel purchase of minion" << std::endl;
	}

	static void CloseMinionPurchaseTab()
	{
		std::cout << "minion tab close" << std::endl;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("btnsCon")->Enabled = true;
		ClientAPI::GetGuiContainer("InGameGUI")->GetGuiContainer("PurchaseMinionCon")->Active = false;
	}
};

