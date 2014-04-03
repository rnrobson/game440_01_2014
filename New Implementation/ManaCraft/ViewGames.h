#pragma once
#include "Page.h"

namespace ManaCraft {
	namespace Client {
		class ViewGames :
			public Page
		{
		protected:
			ViewGames();

			static ViewGames* instance;

		public:
			static ViewGames* GetInstance();
			~ViewGames();

			virtual void Load();
			virtual void Update(double time);
			virtual void Draw();

			//============
			//--- Events 
			//============
			static void OnEnterPressed();
			static void OnEscapePressed();

			static void Click_checkbox();
			static void Click_join();
			static void Click_refresh();
			static void Click_backButton();
			static void Click_createGameButton();
		};
	}
}