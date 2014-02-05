#include "GuiContainer.h"

GuiContainer::GuiContainer()
{
	guiContainerKeys = vector<std::string>{};
	guiElementKeys = vector<std::string>{};
	buttonKeys = vector<std::string>{};
	textFieldKeys = vector<std::string>{};
	labelKeys = vector<std::string>{};

	guiContainers = vector<GuiContainer*>{};
	guiElements = vector<GuiElement*>{};
	buttons = vector<Button*>{};
	textFields = vector<TextField*>{};
	labels = vector<Label*>{};

	Active = true;
	SetPosition({ 0, 0, 0, 0 });
}

void GuiContainer::SetPosition(SDL_Rect _position)
{
	position = _position;

	for (int i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->SetPosition(_position);
	}

	for (int i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < textFields.size(); i++)
	{
		textFields.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < labels.size(); i++)
	{
		labels.at(i)->SetOffset(_position);
	}

}

void GuiContainer::Update(double time)
{
	if (Active){
		for (int i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Update(time);
		}

		for (int i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Update(time);
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			buttons.at(i)->Update(time);
		}

		for (int i = 0; i < textFields.size(); i++)
		{
			textFields.at(i)->Update(time);
		}

		for (int i = 0; i < labels.size(); i++)
		{
			labels.at(i)->Update(time);
		}
	}
}

void GuiContainer::Draw()
{
	if (Active) {
		for (int i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Draw();
		}

		for (int i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Draw();
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			buttons.at(i)->Draw();
		}

		for (int i = 0; i < textFields.size(); i++)
		{
			textFields.at(i)->Draw();
		}

		for (int i = 0; i < labels.size(); i++)
		{
			labels.at(i)->Draw();
		}
	}
}

void GuiContainer::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
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
void GuiContainer::HandleTextInputEvent(SDL_TextInputEvent e)
{

}
void GuiContainer::HandleMouseClickEvent()
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
void GuiContainer::HandleMouseDownEvent(SDL_MouseButtonEvent e)
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
void GuiContainer::HandleMouseUpEvent(SDL_MouseButtonEvent e)
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
			b->OnMouseUp(e);
		}
	}
}
void GuiContainer::HandleKeyboardDownEvent(SDL_KeyboardEvent e)
{

}
void GuiContainer::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{

}