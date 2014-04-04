#pragma once
#include "Page.h"
#include "ClientAPI.h"

namespace ManaCraft
{
	namespace Client
	{
		class GamePage : public Page
		{
		private:
			void LoadGUI();
			void LoadInGameGUI();
			void LoadInGamePause();
		protected:
			GamePage();

			static GamePage* instance;
		public:
			bool isTutorial;
			static GamePage* GetInstance();
			~GamePage();

			virtual void Load();
			virtual void Update(double time);
			virtual void Draw();

			// Standard Events
			static void ButtonPress_OnEscapePressed();
			static void ButtonPress_OnEnterPressed();

			//GUI events
			static void Click_scrollUpButton();
			static void Click_scrollDownButton();

			//inGameGUI events
			static void OpenResearchPage();
			static void ConfirmResearchAllocation();
			static void CancelResearchAllocation();
			static void CloseResearchAllocation();
			static void OpenTowerPurchaseTab();
			static void ConfirmTowerPurchase();
			static void CancelTowerPurchase();
			static void CloseTowerPurchaseTab();
			static void OpenMinionPurchaseTab();
			static void ConfirmMinionPurchase();
			static void CancelMinionPurchase();
			static void CloseMinionPurchaseTab();

			//inGamePause events
		};
	}
}