#include <ClientAPI.h>

//-- Helper Functions
#include "ScreenFader.h"

//-- Load Menus
#include "GameLobby.h"
#include "MainMenu.h"
#include "LoginPopup.h"
#include "Credits.h"
#include "Options.h"
#include "GUI.h"


//-- Function Prototypes
void Update(double time);
void Draw();
void OnEscapePressed();
void OnEnterPressed();

int main(int argc, char* args[])
{
	////-- Initialize the API
	ClientAPI::Init();

	// Set Custom Events
	ClientAPI::SubscribeCustomUpdate(Update);
	ClientAPI::SubscribeCustomDraw(Draw);
	ClientAPI::SubscribeEnterKeyFunc(OnEscapePressed);
	ClientAPI::SubscribeEscapeKeyFunc(OnEnterPressed);

	//--Call individual load methods
	ScreenFader::Load();
	MainMenu::Load();
	LoginPopup::Load();
	GUI::Load();
	//Options::Load();
	Credits::Load();
	GameLobby::Load();


	//==============================================================================================================================\\
	//==============================================================================================================================\\
	//-- Example of New GUI since Last ClientAPI change
	//ClientAPI::AddGuiContainer("cnt", new GuiContainer());

	////-- Checkboxes
	//ClientAPI::GetGuiContainer("cnt")->AddCheckbox("chk", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
	//ClientAPI::GetGuiContainer("cnt")->GetCheckbox("chk")->Checked = true;

	////-- TextField Events
	//ClientAPI::GetGuiContainer("cnt")->AddTextField("txt field", new TextField(APIHelper::RectHelper(0, 0, 1000, 30), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black")));
	//==============================================================================================================================\\
	//==============================================================================================================================\\
	

	//-- Start the APIs main loop
	ClientAPI::BeginMainLoop();

	//-- Quit the API once the APIs Main loop is over
	ClientAPI::Quit();
	return 0;
}

void Update(double time)
{
	ScreenFader::Update(time);
	//cout << "Entering Custom Update" << endl;
}

void Draw()
{
	ScreenFader::Draw();
	//cout << "Entering Custom Draw" << endl;
}

void OnEscapePressed()
{

}
void OnEnterPressed()
{

}