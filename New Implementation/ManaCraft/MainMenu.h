#pragma once
#include "Page.h"
#include "ClientAPI.h"

namespace ManaCraft {
	namespace Client {
		class MainMenu :
			public Page
		{
		private:
			void LoadMainMenu();
			void LoadLoginPopup();

		protected:
			MainMenu();

			static MainMenu* instance;

		public:
			static MainMenu* GetInstance();
			~MainMenu();

			virtual void Load();
			virtual void Update(double time);
			virtual void Draw();

			enum NetIndicator
			{
				Red, Green
			};
			static NetIndicator netIndicator;
			static void PlayerLoggedIn(std::string _username);

			//============
			//--- Events 
			//============
			static void OnEnterPressed();
			static void OnEscapePressed();

			static void Click_loginButton();
			static void Click_viewButton();
			static void Click_optionsButton();
			static void Click_tutorialButton();
			static void Click_quitButton();
			static void Click_creditsButton();

			static void Click_LoginPopup_Cancel();
			static void Click_LoginPopup_Login();
		};

	}
}