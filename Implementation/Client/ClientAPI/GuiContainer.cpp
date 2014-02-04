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
	SetOffset({ 0, 0, 0, 0 });
}

void GuiContainer::SetOffset(SDL_Rect _offset)
{
	offset = _offset;

	for (int i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->SetOffset(_offset);
	}

	for (int i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->SetOffset(_offset);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->SetOffset(_offset);
	}

	for (int i = 0; i < textFields.size(); i++)
	{
		textFields.at(i)->SetOffset(_offset);
	}

	for (int i = 0; i < labels.size(); i++)
	{
		labels.at(i)->SetOffset(_offset);
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