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

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
			ExitMainLoop();
		if (event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&APIEvents::MousePosition.x, &APIEvents::MousePosition.y);

		// Begin Event Code
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			HandleMouseMotionEvent(event.motion);
			break;
		case SDL_MOUSEBUTTONDOWN:
			HandleMouseDownEvent(event.button);
			break;
		case SDL_MOUSEBUTTONUP:
			HandleMouseUpEvent(event.button);
			break;
		case SDL_TEXTINPUT:
			HandleTextInputEvent(event.text);
			break;
		case SDL_KEYDOWN:
			HandleKeyboardDownEvent(event.key);
			break;
		case SDL_KEYUP:
			HandleKeyboardUpEvent(event.key);
			break;
		}
	}

	if (APIEvents::DidMouseClick()) {
		HandleMouseClickEvent();
	}

	APIEvents::PreviousKeyboardState = APIEvents::CurrentKeyboardState;
	APIEvents::PreviousMouseState = APIEvents::CurrentMouseState;
}

void ClientAPI::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseMotionEvent(e);
		}
	}
	for each (Button* b in buttons)
	{
		if (b->Active) {
			b->OnMouseHover(e);
		}
	}
}
void ClientAPI::HandleTextInputEvent(SDL_TextInputEvent e)
{

}
void ClientAPI::HandleMouseClickEvent()
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseClickEvent();
		}
	}
	for each (Button* b in buttons)
	{
		if (b->Active) {
			if (b->Intersects(APIEvents::MousePosition))
				b->OnMouseClick();
		}
	}
}
void ClientAPI::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseDownEvent(e);
		}
	}
	for each (Button* b in buttons)
	{
		if (b->Active) {
			if (b->Intersects(APIEvents::MousePosition))
				b->OnMouseDown(e);
		}
	}
}
void ClientAPI::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseUpEvent(e);
		}
	}
	for each (Button* b in buttons)
	{
		if (b->Active) {
			if (b->Intersects(APIEvents::MousePosition))
				b->OnMouseUp(e);
		}
	}
}
void ClientAPI::HandleKeyboardDownEvent(SDL_KeyboardEvent e)
{

}
void ClientAPI::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{

}