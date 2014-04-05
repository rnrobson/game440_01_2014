#pragma once
#include "Page.h"
#include "ClientAPI.h"
#include <sstream>

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

			void UpdateManaText();

			int mana;
		protected:
			GamePage();

			static GamePage* instance;
		public:
			bool isTutorial;
			bool isPaused;
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
			static void OpenResearchPage();
			static void CloseResearchPage();
			static void OpenTowerPurchaseTab();
			static void CloseTowerPurchaseTab();
			static void OpenMinionPurchaseTab();
			static void CloseMinionPurchaseTab();

			//inGamePause events
			static void Click_resume();
			static void Click_options();
			static void Click_save();
			static void Click_quitMenu();
			static void Click_quitDesktop();
		};
	}
}