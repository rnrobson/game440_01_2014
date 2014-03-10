#pragma once
#include <ClientAPI.h>


class LogoutPopUp
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//Create the Container
		ClientAPI::AddGuiContainer("LogoutPopUp", new GuiContainer());

		ClientAPI::GetGuiContainer("LogoutPopUp")->AddGuiElement("Background", new GuiElement(APIHelper::SolidColourTexture(300, 150, APIHelper::ColourHelper(0, 0, 0, 225)), 
			APIHelper::RectHelper(0, 0, 300, 150)));

		//Position the pop up
		ClientAPI::GetGuiContainer("LogoutPopUp")->SetPosition(APIHelper::RectHelper(SCREEN_WIDTH / 2.9, SCREEN_HEIGHT / 2.5, 0, 0));
		
		//Logout question text
		ClientAPI::GetGuiContainer("LogoutPopUp")->AddLabel("Logout", new Label("Are you sure you want to logout?", APIHelper::RectHelper(50, 20, 200, 100), 
			ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));

		//Buttons
		ClientAPI::GetGuiContainer("LogoutPopUp")->AddButton("Logout", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(40, 90, 95, 35)));
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Logout")->AddLabel("Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Logout")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));

		ClientAPI::GetGuiContainer("LogoutPopUp")->AddButton("Cancel", new Button(ClientAPI::GetTexture("MedBtnNormal"), APIHelper::RectHelper(150, 90, 95, 35)));
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Cancel")->AddLabel("Cancel", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Cancel")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		
		//Events for the buttons
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Logout")->SubscribeOnMouseClick(LogoutPopUp::ClickLogout);
		ClientAPI::GetGuiContainer("LogoutPopUp")->GetButton("Cancel")->SubscribeOnMouseClick(LogoutPopUp::ClickCancel);

		ClientAPI::GetGuiContainer("LogoutPopUp")->Active = false;
	}

	static void ClickCancel()
	{
		ClientAPI::GetGuiContainer("LogoutPopUp")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Enabled = true;
	}
	static void ClickLogout()
	{

	}
};