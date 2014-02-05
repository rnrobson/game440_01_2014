#include <ClientAPI.h>

#include "GameLobby.h"
#include "MainMenu.h"

//-- Function Prototypes
void Update(double time);
void Draw();

int main(int argc, char* args[])
{
	////-- Initialize the API
	ClientAPI::Init();

	ClientAPI::SetCustomUpdate(Update);
	ClientAPI::SetCustomDraw(Draw);

	//--Call individual load methods
	MainMenu::Load();
	GameLobby::Load();
	

	//-- Start the APIs main loop
	ClientAPI::BeginMainLoop();
	//-- Quit the API once the APIs Main loop is over
	ClientAPI::Quit();
	return 0;
}

void Update(double time)
{
	cout << "Entering Custom Update" << endl;

	SDL_Delay(1000);
	ClientAPI::ExitMainLoop();
}

void Draw()
{
	cout << "Entering Custom Draw" << endl;
}