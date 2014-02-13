#pragma once
#include "ClientAPI.h"

class LoginPopup
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//-- Create the Container
		ClientAPI::AddGuiContainer("LoginPopup", new GuiContainer());

		//-- Add the Login Bar
		ClientAPI::GetGuiContainer("LoginPopup")->AddGuiElement("Background", new GuiElement(APIHelper::SolidColourTexture(300, 150, APIHelper::ColourHelper(0, 0, 0, 225)), APIHelper::RectHelper(0,0,300,150)));
		ClientAPI::GetGuiContainer("LoginPopup")->AddLabel("Username", new Label("Username", APIHelper::RectHelper(90, 20, 200, 100), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));

		//-- Setup the text field
		ClientAPI::GetGuiContainer("LoginPopup")->AddTextField("UsernameField", new TextField(APIHelper::RectHelper(10, 50, 275, 20), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
		ClientAPI::GetGuiContainer("LoginPopup")->GetTextField("UsernameField")->CharacterLimit = 20;

		//-- Add in Login and Cancel Buttons
		ClientAPI::GetGuiContainer("LoginPopup")->AddButton("Login", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(40, 90, 95, 35)));
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->AddLabel("Login", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));

		ClientAPI::GetGuiContainer("LoginPopup")->AddButton("Cancel", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(150, 90, 95, 35)));
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->AddLabel("Cancel", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	
		//-- Subscribe to Events
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Login")->SubscribeOnMouseClick(LoginPopup::Click_Login);
		ClientAPI::GetGuiContainer("LoginPopup")->GetButton("Cancel")->SubscribeOnMouseClick(LoginPopup::Click_Cancel);
		ClientAPI::GetGuiContainer("LoginPopup")->SubscribeOnEscapeKeyPressed(LoginPopup::ButtonPress_Escape);
		ClientAPI::GetGuiContainer("LoginPopup")->SubscribeOnEnterKeyPressed(LoginPopup::ButtonPress_Enter);

		//-- Set Menu Position
		ClientAPI::GetGuiContainer("LoginPopup")->SetPosition(APIHelper::RectHelper(SCREEN_WIDTH / 2.9, SCREEN_HEIGHT / 2.5, 0, 0));
	
		// Turn off
		ClientAPI::GetGuiContainer("LoginPopup")->Active = false;
	}

	static void Click_Login()
	{

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

	}
};