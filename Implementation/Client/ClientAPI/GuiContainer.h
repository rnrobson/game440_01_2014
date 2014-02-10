#pragma once
#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H

#include "Includes.h"
#include "APIEvents.h"

#include "GuiElement.h"
#include "Button.h"
#include "Label.h"
#include "TextField.h"
#include "Checkbox.h"
#include "Slider.h"

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

	vector<std::string> checkboxKeys;
	vector<Checkbox*> checkboxes;

	vector<std::string> sliderKeys;
	vector<Slider*> sliders;

	SDL_Rect position;

	void(*onEscapeKeyPressed)();
	void(*onEnterKeyPressed)();

	void CleanMemory()
	{
		guiContainerKeys.clear();
		guiContainers.clear();

		guiElementKeys.clear();
		guiElements.clear();

		buttonKeys.clear();
		buttons.clear();

		textFieldKeys.clear();
		textFields.clear();

		labelKeys.clear();
		labels.clear();

		checkboxKeys.clear();
		checkboxes.clear();

		sliderKeys.clear();
		sliders.clear();
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

	void AddCheckbox(std::string _key, Checkbox* _checkbox)
	{
		checkboxKeys.push_back(_key);

		_checkbox->SetOffset(position);
		checkboxes.push_back(_checkbox);
	}

	void AddSlider(std::string _key, Slider* _slider)
	{
		labelKeys.push_back(_key);

		_slider->SetOffset(position);
		sliders.push_back(_slider);
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

	void RemoveCheckbox(std::string _key)
	{
		for (size_t i = 0; i < checkboxKeys.size(); i++)
		{
			if (checkboxKeys.at(i) == _key)
			{
				checkboxKeys.erase(checkboxKeys.begin() + i);
				checkboxes.erase(checkboxes.begin() + i);
				break;
			}
		}
	}

	void RemoveSlider(std::string _key)
	{
		for (size_t i = 0; i < sliderKeys.size(); i++)
		{
			if (sliderKeys.at(i) == _key)
			{
				sliderKeys.erase(sliderKeys.begin() + i);
				sliders.erase(sliders.begin() + i);
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
		return nullptr;
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
		return nullptr;
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
		return nullptr;
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
		return nullptr;
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
		return nullptr;
	}

	Checkbox* GetCheckbox(std::string _key)
	{
		for (size_t i = 0; i < checkboxKeys.size(); i++)
		{
			if (checkboxKeys.at(i) == _key)
			{
				return checkboxes.at(i);
			}
		}
		return nullptr;
	}

	Slider* GetSlider(std::string _key)
	{
		for (size_t i = 0; i < sliderKeys.size(); i++)
		{
			if (sliderKeys.at(i) == _key)
			{
				return sliders.at(i);
			}
		}
		return nullptr;
	}
#pragma endregion

	void CheckEvents(SDL_Event e);
	void Update(double time);
	void Draw();

	SDL_Rect GetPosition() { return position; }
	void SetPosition(SDL_Rect _position);

	void SubscribeOnEscapeKeyPressed(void(*func)()) { onEscapeKeyPressed = func; }
	void SubscribeOnEnterKeyPressed(void(*func)()) { onEnterKeyPressed = func; }

	void HandleMouseClickEvent();
	void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	void HandleMouseUpEvent(SDL_MouseButtonEvent e);

	void HandleEnterKeyPressed();
	void HandleEscapeKeyPressed();
	void HandleKeyboardDownEvent(SDL_KeyboardEvent e);
	void HandleKeyboardUpEvent(SDL_KeyboardEvent e);
	void HandleTextInputEvent(SDL_TextInputEvent e);
};

#endif