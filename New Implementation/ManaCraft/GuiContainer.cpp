#include "GuiContainer.h"

GuiContainer::GuiContainer()
{
	//guiContainerKeys = std::vector<std::string>{};
	//guiElementKeys = std::vector<std::string>{};

	//guiContainers = std::vector<GuiContainer*>{};
	//guiElements = std::vector<GuiElement*>{};

	guiContainers = std::map<std::string, GuiContainer*>{};
	guiElements = std::map<std::string, GuiElement*>{};

	onEscapeKeyPressed = nullptr;
	onEnterKeyPressed = nullptr;

	Active = true;
	Enabled = true;
	SetPosition({ 0, 0, 0, 0 });

	music = nullptr;
}

void GuiContainer::SetPosition(SDL_Rect _position)
{
	position = _position;

	for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
		it->second->SetPosition(_position);
	}
	/*for (size_t i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->SetPosition(_position);
	}*/

	for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
		it->second->SetOffset(_position);
	}
	/*for (size_t i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->SetOffset(_position);
	}*/
}

void GuiContainer::Update(double time)
{
	if (Active){
		/*for (size_t i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Update(time);
		}*/
		for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
			it->second->Update(time);
		}

		for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
			it->second->Update(time);
		}
		/*for (size_t i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Update(time);
		}*/
	}
}
void GuiContainer::Draw()
{
	if (Active) {
		/*for (size_t i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Draw();
		}*/
		for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
			it->second->Draw();
		}

		for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
			it->second->Draw();
		}

		/*for (size_t i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Draw();
		}*/
	}
}

void GuiContainer::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleMouseMotionEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnMouseMotion(e);

			if (element->second->Intersects({ e.x, e.y, 1, 1 })){
				element->second->OnMouseHover(e);
			}
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseMotion(e);

			if (element->Intersects({ e.x, e.y, 1, 1 })){
				element->OnMouseHover(e);
			}
		}
	}*/
}
void GuiContainer::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleMouseDownEvent(e);
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleMouseDownEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			if (element->second->Intersects(APIEvents::MousePosition))
				element->second->OnMouseDown(e);
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseDown(e);
		}
	}*/
}
void GuiContainer::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleMouseUpEvent(e);
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleMouseUpEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnMouseUp(e);
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseUp(e);
		}
	}*/
}
void GuiContainer::HandleMouseClickEvent()
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleMouseClickEvent();
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleMouseClickEvent();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			if (element->second->Intersects(APIEvents::MousePosition))
				element->second->OnMouseClick();
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseClick();
		}
	}*/
}

void GuiContainer::HandleTextInputEvent(SDL_TextInputEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleTextInputEvent(e);
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleTextInputEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnTextInput(e);
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnTextInput(e);
		}
	}*/
}
void GuiContainer::HandleKeyboardDownEvent(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleKeyboardDownEvent(e);
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleKeyboardDownEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnKeyboardDown(e);
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardDown(e);
		}
	}*/
}
void GuiContainer::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleKeyboardUpEvent(e);
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleKeyboardUpEvent(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnKeyboardUp(e);
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardUp(e);
		}
	}*/
}
void GuiContainer::HandleEnterKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEnterKeyPressed != NULL) {
			(*onEnterKeyPressed)(); 
	} 

	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleEnterKeyPressed();
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleEnterKeyPressed();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnEnterKeyPressed();
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEnterKeyPressed();
		}
	}*/
}
void GuiContainer::HandleEscapeKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEscapeKeyPressed != NULL) {
		(*onEscapeKeyPressed)(); 
	}


	//for each (GuiContainer* guic in guiContainers)
	//{
	//	if (guic->Active) {
	//		guic->HandleEscapeKeyPressed();
	//	}
	//}
	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->HandleEscapeKeyPressed();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnEscapeKeyPressed();
		}
	}
	/*for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEscapeKeyPressed();
		}
	}*/
}