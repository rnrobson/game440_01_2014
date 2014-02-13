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

void (*ClientAPI::CustomUpdateFunc)(double);
void (*ClientAPI::CustomDrawFunc)();
void(*ClientAPI::EnterKeyPressedFunc)();
void(*ClientAPI::EscapeKeyPressedFunc)();

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
		Update(33);
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
	#pragma endregion

	//-- Run Custom Update if it exists
	if (CustomUpdateFunc != NULL) { (*CustomUpdateFunc)(time); }
}

void ClientAPI::Draw()
{
	Window::Clear();

	#pragma region Draw All Elements
	for (size_t i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->Draw();
	}

	for (size_t i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->Draw();
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

	if (APIHelper::DidKeyGetPressed(SDL_SCANCODE_RETURN)) {

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

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseMotion(e);
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

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseDown(e);
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

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseUp(e);
		}
	}
}
void ClientAPI::HandleMouseClickEvent()
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseClickEvent();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseClick();
		}
	}
}

void ClientAPI::HandleTextInputEvent(SDL_TextInputEvent e)
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleTextInputEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnTextInput(e);
		}
	}
}
void ClientAPI::HandleKeyboardDownEvent(SDL_KeyboardEvent e)
{
	if (e.keysym.sym == SDLK_RETURN ||
		e.keysym.sym == SDLK_RETURN2 ||
		e.keysym.sym == SDLK_KP_ENTER) 
	{
		HandleEnterKeyPressed();
	}

	if (e.keysym.sym == SDLK_ESCAPE)
	{
		HandleEscapeKeyPressed();
	}

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleKeyboardDownEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardDown(e);
		}
	}
}
void ClientAPI::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{
	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleKeyboardUpEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardUp(e);
		}
	}
}
void ClientAPI::HandleEnterKeyPressed()
{
	APIEvents::EnterPressed = !APIEvents::EnterPressed;

	if (EnterKeyPressedFunc != NULL) {
		(*EnterKeyPressedFunc)();
	}

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleEnterKeyPressed();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEnterKeyPressed();
		}
	}
}
void ClientAPI::HandleEscapeKeyPressed()
{
	APIEvents::EscapePressed = !APIEvents::EscapePressed;

	if (EscapeKeyPressedFunc != NULL) {
		(*EscapeKeyPressedFunc)();
	}

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleEscapeKeyPressed();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEscapeKeyPressed();
		}
	}
}