#include "ClientAPI.h"

#pragma region Private Variable Initalizations
vector<std::string> ClientAPI::fontKeys;
vector<TTF_Font*> ClientAPI::fonts;

vector<std::string> ClientAPI::textureKeys;
vector<SDL_Texture*> ClientAPI::textures;

vector<std::string> ClientAPI::colourKeys;
vector<SDL_Color> ClientAPI::colours;

vector<std::string> ClientAPI::guiContainerKeys;
vector<GuiContainer*> ClientAPI::guiContainers;

vector<std::string> ClientAPI::guiElementKeys;
vector<GuiElement*> ClientAPI::guiElements;

vector<std::string> ClientAPI::buttonKeys;
vector<Button*> ClientAPI::buttons;

vector<std::string> ClientAPI::textFieldKeys;
vector<TextField*> ClientAPI::textFields;

vector<std::string> ClientAPI::labelKeys;
vector<Label*> ClientAPI::labels;

void (*ClientAPI::CustomUpdateFunc)(double);
void (*ClientAPI::CustomDrawFunc)();

bool ClientAPI::quit;
#pragma endregion

void ClientAPI::BeginMainLoop()
{
	// Initialize quit to false so that the loop will run indefinately
	quit = false;

	//Pre-Draw screen before entering loop
	Draw();

	//-- Begin Main Loop
	while (!quit)
	{
		Update(30);
		Draw();
	}
}

void ClientAPI::Update(double time)
{
	CheckEvents();

	#pragma region Update All Elements
	for (size_t i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->Update(time);
	}

	for (size_t i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->Update(time);
	}

	for (size_t i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->Update(time);
	}

	for (size_t i = 0; i < textFields.size(); i++)
	{
		textFields.at(i)->Update(time);
	}

	for (size_t i = 0; i < labels.size(); i++)
	{
		labels.at(i)->Update(time);
	}
	#pragma endregion

	//-- Run Custom Update if it exists
	if (CustomUpdateFunc != NULL) { (*CustomUpdateFunc)(time); }
}

void ClientAPI::Draw()
{
	Window::Clear();

	#pragma region Draw All Elements
	for (size_t i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->Draw();
	}

	for (size_t i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->Draw();
	}

	for (size_t i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->Draw();
	}

	for (size_t i = 0; i < textFields.size(); i++)
	{
		textFields.at(i)->Draw();
	}

	for (size_t i = 0; i < labels.size(); i++)
	{
		labels.at(i)->Draw();
	}
	#pragma endregion

	//-- Run Custom Update if it exists
	if (CustomDrawFunc != NULL) { (*CustomDrawFunc)(); }

	Window::Present();
}

void ClientAPI::CheckEvents()
{
	APIEvents::CurrentKeyboardState = SDL_GetKeyboardState(NULL);
	APIEvents::CurrentMouseState = SDL_GetMouseState(NULL,NULL);

	while (SDL_PollEvent(&APIEvents::Event))
	{
		if (APIEvents::Event.type == SDL_QUIT)
			ExitMainLoop();
		if (APIEvents::Event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&APIEvents::MousePosition.x, &APIEvents::MousePosition.y);

		//if (APIEvents::Event.type == SDL_MOUSEBUTTONDOWN)
	}

	APIEvents::PreviousKeyboardState = APIEvents::CurrentKeyboardState;
	APIEvents::PreviousMouseState = APIEvents::CurrentMouseState;
}