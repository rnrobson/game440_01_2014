#pragma once
#include "ClientAPI.h"
#include "NetworkCommands.h"

namespace ManaCraft {
	namespace Client {
		class LoginPopup
		{
		public:
			static void Load()
			{
				const int SCREEN_WIDTH = Window::Box().w;
				const int SCREEN_HEIGHT = Window::Box().h;


				SDL_Rect loginBtn = APIHelper::RectHelper(33, 0, 95, 35);
				SDL_Rect cancelBtn = APIHelper::RectHelper(190, 0, 95, 35);

				//-- Create the Container
				ClientAPI::AddGuiContainer("LoginPopup", new GuiContainer());

				//-- Add the Login Bar
				ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("Background", new GuiElement(APIHelper::SolidColourTexture(300, 150, APIHelper::ColourHelper(0, 0, 0, 225)), APIHelper::RectHelper(10, -100, 300, 150)));
				ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("Username", new Label("Username", APIHelper::RectHelper(102, -80, 200, 100), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));

				//-- Setup the text field
				ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("UsernameField", new TextField(APIHelper::RectHelper(35, -50, 250, 20), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
				ClientAPI::GetGuiContainer("LoginPopup")->GetTextField("UsernameField")->CharacterLimit = 20;

				//-- Add in Login and Cancel Buttons
				ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("Login", new Button(ClientAPI::GetTexture("MedBtnNormal"), loginBtn));
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->AddLabel("Login", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->GetLabel()->SetPadding(APIHelper::RectHelper(12, 2, 0, 0));

				ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("Cancel", new Button(ClientAPI::GetTexture("MedBtnNormal"), cancelBtn));
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->AddLabel("Cancel", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));

				//-- Subscribe to Events
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->SubscribeOnMouseClick(LoginPopup::Click_Login);
				ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->SubscribeOnMouseClick(LoginPopup::Click_Cancel);
				ClientAPI::GetGuiContainer("LoginPopup")->SubscribeOnEscapeKeyPressed(LoginPopup::ButtonPress_Escape);
				ClientAPI::GetGuiContainer("LoginPopup")->SubscribeOnEnterKeyPressed(LoginPopup::ButtonPress_Enter);

				//-- Set Menu Position
				ClientAPI::GetGuiContainer("LoginPopup")->SetPosition(APIHelper::RectHelper((int)(SCREEN_WIDTH / 2.9), (int)(SCREEN_HEIGHT / 2.5), 0, 0));

				// Turn off
				ClientAPI::GetGuiContainer("LoginPopup")->Active = false;
			}

			static void Click_Login()
			{
				//needs to be tested
				NetworkCommands::LogIn(ClientAPI::GetGuiContainer("LoginPopup")->GetTextField("UsernameField")->GetText());
			}

			static void Click_Cancel()
			{
				ClientAPI::GetGuiContainer("LoginPopup")->Active = false;
				ClientAPI::GetGuiContainer("MainMenu")->Enabled = true;
			}

			static void ButtonPress_Escape()
			{
				ClientAPI::GetGuiContainer("LoginPopup")->Active = false;
				ClientAPI::GetGuiContainer("MainMenu")->Enabled = true;
			}

			static void ButtonPress_Enter()
			{
				//needs to be tested
				NetworkCommands::LogIn(ClientAPI::GetGuiContainer("LoginPopup")->GetTextField("UsernameField")->GetText());
				
			}
		};
	}
}