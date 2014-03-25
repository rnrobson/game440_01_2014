#include "ClientAPI.h"

#pragma region Private Variable Initalizations
std::map<std::string, TTF_Font*> ClientAPI::fonts;
std::map<std::string, SDL_Texture*> ClientAPI::textures;
std::map<std::string, Mix_Chunk*> ClientAPI::audio;
std::map<std::string, SDL_Color> ClientAPI::colours;
std::map<std::string, SDL_Rect> ClientAPI::rects;

//-- API Objects
std::map<std::string, GuiContainer*> ClientAPI::guiContainers;
std::map<std::string, GuiElement*> ClientAPI::guiElements;

void (*ClientAPI::CustomUpdateFunc)(double);
void (*ClientAPI::CustomDrawFunc)();
void(*ClientAPI::EnterKeyPressedFunc)();
void(*ClientAPI::EscapeKeyPressedFunc)();

FrameLimiter* ClientAPI::frameLimiter;

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
		if (!frameLimiter->Limit()) {
			Update(frameLimiter->GetFPS());
			Draw();
		}
	}
}

void ClientAPI::Update(double time)
{
	CheckEvents();

	#pragma region Update All Elements
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		it->second->Update(time);
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		it->second->Update(time);
	}
	#pragma endregion

	//-- Run Custom Update if it exists
	if (CustomUpdateFunc != NULL) { (*CustomUpdateFunc)(time); }
}
void ClientAPI::Draw()
{
	Window::Clear();

	#pragma region Draw All Elements
	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		it->second->Draw();
	}

	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		it->second->Draw();
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
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleMouseMotionEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnMouseMotion(e);
		}
	}
}
void ClientAPI::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleMouseDownEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			if (it->second->Intersects(APIEvents::MousePosition))
				it->second->OnMouseDown(e);
		}
	}
}
void ClientAPI::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleMouseUpEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnMouseUp(e);
		}
	}
}
void ClientAPI::HandleMouseClickEvent()
{
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleMouseClickEvent();
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			if (it->second->Intersects(APIEvents::MousePosition))
				it->second->OnMouseClick();
		}
	}
}

void ClientAPI::HandleTextInputEvent(SDL_TextInputEvent e)
{
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleTextInputEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnTextInput(e);
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

	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleKeyboardDownEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnKeyboardDown(e);
		}
	}
}
void ClientAPI::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{
	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleKeyboardUpEvent(e);
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnKeyboardUp(e);
		}
	}
}
void ClientAPI::HandleEnterKeyPressed()
{
	APIEvents::EnterPressed = !APIEvents::EnterPressed;

	if (EnterKeyPressedFunc != NULL) {
		(*EnterKeyPressedFunc)();
	}

	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleEnterKeyPressed();
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnEnterKeyPressed();
		}
	}
}
void ClientAPI::HandleEscapeKeyPressed()
{
	APIEvents::EscapePressed = !APIEvents::EscapePressed;

	if (EscapeKeyPressedFunc != NULL) {
		(*EscapeKeyPressedFunc)();
	}

	for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
	{
		if (it->second->Active) {
			it->second->HandleEscapeKeyPressed();
		}
	}

	for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
	{
		if (it->second->Active) {
			it->second->OnEscapeKeyPressed();
		}
	}
}