#pragma once
#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H

#include "Includes.h"
#include "GuiElement.h"
#include "Button.h"
#include "Label.h"
#include "TextField.h"

class GuiContainer
{
private:
	vector<std::string> guiContainerKeys;
	vector<GuiContainer*> guiContainers;

	vector<std::string> guiElementKeys;
	vector<GuiElement*> guiElements;

	vector<std::string> buttonKeys;
	vector<Button*> buttons;

	vector<std::string> textFieldKeys;
	vector<TextField*> textFields;

	vector<std::string> labelKeys;
	vector<Label*> labels;

	SDL_Rect position;

	void CleanMemory()
	{
		guiElementKeys.clear();
		guiElements.clear();

		buttonKeys.clear();
		buttons.clear();

		textFieldKeys.clear();
		textFields.clear();

		labelKeys.clear();
		labels.clear();

		//delete &fontKeys;
		//delete &fonts;
		//delete &textureKeys;
		//delete &textures;
		//delete &guiElementKeys;
		//delete &guiElements;
		//delete &buttonKeys;
		//delete &buttons;
		//delete &textFieldKeys;
		//delete &textFields;
		//delete &labelKeys;
		//delete &labels;
	}

public:
	bool Active;

	GuiContainer();
	~GuiContainer() { CleanMemory(); }

#pragma region Adds
	void AddGuiContainer(std::string _key, GuiContainer* _guiContainer)
	{
		guiContainerKeys.push_back(_key);

		_guiContainer->SetPosition(position);
		guiContainers.push_back(_guiContainer);
	}

	void AddGuiElement(std::string _key, GuiElement* _guiElement)
	{
		guiElementKeys.push_back(_key);

		_guiElement->SetOffset(position);
		guiElements.push_back(_guiElement);
	}

	void AddButton(std::string _key, Button* _button)
	{
		buttonKeys.push_back(_key);

		_button->SetOffset(position);
		buttons.push_back(_button);
	}

	void AddTextField(std::string _key, TextField* _textField)
	{
		textFieldKeys.push_back(_key);
	
		_textField->SetOffset(position);
		textFields.push_back(_textField);
	}

	void AddLabel(std::string _key, Label* _label)
	{
		labelKeys.push_back(_key);

		_label->SetOffset(position);
		labels.push_back(_label);
	}
#pragma endregion
#pragma region Removes
	void RemoveGuiContainer(std::string _key)
	{
		for (size_t i = 0; i < guiContainerKeys.size(); i++)
		{
			if (guiContainerKeys.at(i) == _key)
			{
				guiContainerKeys.erase(guiContainerKeys.begin() + i);
				guiContainers.erase(guiContainers.begin() + i);
				break;
			}
		}
	}

	void RemoveGuiElement(std::string _key)
	{
		for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				guiElementKeys.erase(guiElementKeys.begin() + i);
				guiElements.erase(guiElements.begin() + i);
				break;
			}
		}
	}

	void RemoveButton(std::string _key)
	{
		for (size_t i = 0; i < buttonKeys.size(); i++)
		{
			if (buttonKeys.at(i) == _key)
			{
				buttonKeys.erase(buttonKeys.begin() + i);
				buttons.erase(buttons.begin() + i);
				break;
			}
		}
	}

	void RemoveTextField(std::string _key)
	{
		for (size_t i = 0; i < textFieldKeys.size(); i++)
		{
			if (textFieldKeys.at(i) == _key)
			{
				textFieldKeys.erase(textFieldKeys.begin() + i);
				textFields.erase(textFields.begin() + i);
				break;
			}
		}
	}

	void RemoveLabel(std::string _key)
	{
		for (size_t i = 0; i < labelKeys.size(); i++)
		{
			if (labelKeys.at(i) == _key)
			{
				labelKeys.erase(labelKeys.begin() + i);
				labels.erase(labels.begin() + i);
				break;
			}
		}
	}
#pragma endregion
#pragma region Gets
	GuiContainer* GetGuiContainer(std::string _key)
	{
		for (size_t i = 0; i < guiContainerKeys.size(); i++)
		{
			if (guiContainerKeys.at(i) == _key)
			{
				return guiContainers.at(i);
			}
		}
	}

	GuiElement* GetGuiElement(std::string _key)
	{
		for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return guiElements.at(i);
			}
		}
	}

	Button* GetButton(std::string _key)
	{
		for (size_t i = 0; i < buttonKeys.size(); i++)
		{
			if (buttonKeys.at(i) == _key)
			{
				return buttons.at(i);
			}
		}
	}

	TextField* GetTextField(std::string _key)
	{
		for (size_t i = 0; i < textFieldKeys.size(); i++)
		{
			if (textFieldKeys.at(i) == _key)
			{
				return textFields.at(i);
			}
		}
	}

	Label* GetLabel(std::string _key)
	{
		for (size_t i = 0; i < labelKeys.size(); i++)
		{
			if (labelKeys.at(i) == _key)
			{
				return labels.at(i);
			}
		}
	}
#pragma endregion

	void CheckEvents(SDL_Event e);
	void Update(double time);
	void Draw();

	SDL_Rect GetPosition() { return position; }
	void SetPosition(SDL_Rect _position);
};

#endif