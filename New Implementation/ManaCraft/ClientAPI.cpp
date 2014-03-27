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

Page* ClientAPI::focus;
FrameLimiter* ClientAPI::frameLimiter;
GuiAPIMode ClientAPI::guiAPIMode;

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

	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
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
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->Update(time);
		break;
	}


	//-- Run Custom Update if it exists
	if (CustomUpdateFunc != NULL) { (*CustomUpdateFunc)(time); }
}
void ClientAPI::Draw()
{
	Window::Clear();

	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
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
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->Draw();
		break;
	}

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
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseMotion(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseMotion(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnMouseMotion(e);
		break;
	}
	
}
void ClientAPI::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseDown(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				if (it->second->Intersects(APIEvents::MousePosition))
					it->second->OnMouseDown(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnMouseDown(e);
		break;
	}

}
void ClientAPI::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseUp(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseUp(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnMouseUp(e);
		break;
	}

}
void ClientAPI::HandleMouseClickEvent()
{
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnMouseClick();
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				if (it->second->Intersects(APIEvents::MousePosition))
					it->second->OnMouseClick();
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnMouseClick();
		break;
	}
	
}

void ClientAPI::HandleTextInputEvent(SDL_TextInputEvent e)
{
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnTextInput(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnTextInput(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnTextInput(e);
		break;
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

	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnKeyboardDown(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnKeyboardDown(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnKeyboardDown(e);
		break;
	}
	
}
void ClientAPI::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{
	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnKeyboardUp(e);
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnKeyboardUp(e);
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnKeyboardUp(e);
		break;
	}
}
void ClientAPI::HandleEnterKeyPressed()
{
	APIEvents::EnterPressed = !APIEvents::EnterPressed;

	if (EnterKeyPressedFunc != NULL) {
		(*EnterKeyPressedFunc)();
	}

	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnEnterKeyPressed();
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnEnterKeyPressed();
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnEnterKeyPressed();
		break;
	}
}
void ClientAPI::HandleEscapeKeyPressed()
{
	APIEvents::EscapePressed = !APIEvents::EscapePressed;

	if (EscapeKeyPressedFunc != NULL) {
		(*EscapeKeyPressedFunc)();
	}

	switch (ClientAPI::guiAPIMode)
	{
	default:
	case GuiAPIMode::APIHandleMode:
		for (std::map<std::string, GuiContainer*>::iterator it = guiContainers.begin(); it != guiContainers.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnEscapeKeyPressed();
			}
		}

		for (std::map<std::string, GuiElement*>::iterator it = guiElements.begin(); it != guiElements.end(); ++it)
		{
			if (it->second->Active) {
				it->second->OnEscapeKeyPressed();
			}
		}
		break;
	case GuiAPIMode::ProgrammerHandleMode:
		focus->OnEscapeKeyPressed();
		break;
	}
}