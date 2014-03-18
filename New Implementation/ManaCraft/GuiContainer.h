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
#include "GuiGridLayer.h"

class GuiContainer
{
private:
	//std::vector<std::string> guiContainerKeys;
	//std::vector<GuiContainer*> guiContainers;

	//std::vector<std::string> guiElementKeys;
	//std::vector<GuiElement*> guiElements;

	std::map<std::string, GuiContainer*> guiContainers;
	std::map<std::string, GuiElement*> guiElements;

	Mix_Chunk* music;

	SDL_Rect position;

	void(*onEscapeKeyPressed)();
	void(*onEnterKeyPressed)();

	void CleanMemory()
	{
		//guiContainerKeys.clear();
		guiContainers.clear();

		//guiElementKeys.clear();
		guiElements.clear();
	}

public:
	bool Active;
	bool Enabled;

	GuiContainer();
	~GuiContainer() { CleanMemory(); }

	void SetBackgroundAudio(Mix_Chunk* _music) { music = _music; }
	void Play() { if (music != nullptr) Mix_PlayChannel(AudioChannel::MusicChannel, music, -1); }
	void Pause(){ Mix_Pause(AudioChannel::MusicChannel); }

#pragma region Adds
	void AddGuiContainer(std::string _key, GuiContainer* _guiContainer)
	{
		_guiContainer->SetPosition(position);

		guiContainers.emplace(_key, _guiContainer);
		//guiContainerKeys.push_back(_key);
		//guiContainers.push_back(_guiContainer);
	}

	void AddGuiElement(std::string _key, GuiElement* _guiElement)
	{
		_guiElement->SetOffset(position);

		guiElements.emplace(_key, _guiElement);
		//guiElementKeys.push_back(_key);
		//guiElements.push_back(_guiElement);
	}

#pragma endregion
#pragma region Removes
	void RemoveGuiContainer(std::string _key)
	{
		guiContainers.erase(_key);
		/*for (size_t i = 0; i < guiContainerKeys.size(); i++)
		{
			if (guiContainerKeys.at(i) == _key)
			{
				guiContainerKeys.erase(guiContainerKeys.begin() + i);
				guiContainers.erase(guiContainers.begin() + i);
				break;
			}
		}*/
	}

	void RemoveGuiElement(std::string _key)
	{
		guiElements.erase(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				guiElementKeys.erase(guiElementKeys.begin() + i);
				guiElements.erase(guiElements.begin() + i);
				break;
			}
		}*/
	}
#pragma endregion
#pragma region Gets
	GuiContainer* GetGuiContainer(std::string _key)
	{
		return guiContainers.at(_key);
		/*for (size_t i = 0; i < guiContainerKeys.size(); i++)
		{
			if (guiContainerKeys.at(i) == _key)
			{
				return guiContainers.at(i);
			}
		}
		return nullptr;*/
	}

	GuiElement* GetGuiElement(std::string _key)
	{
		return guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	GuiGridLayer* GetGridLayer(std::string _key)
	{
		return (GuiGridLayer*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (GuiGridLayer*)guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	Button* GetButton(std::string _key)
	{
		return (Button*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (Button*)guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	TextField* GetTextField(std::string _key)
	{
		return (TextField*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (TextField*)guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	Label* GetLabel(std::string _key)
	{
		return (Label*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (Label*)guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	Checkbox* GetCheckbox(std::string _key)
	{
		return (Checkbox*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (Checkbox*)guiElements.at(i);
			}
		}
		return nullptr;*/
	}

	Slider* GetSlider(std::string _key)
	{
		return (Slider*)guiElements.at(_key);
		/*for (size_t i = 0; i < guiElementKeys.size(); i++)
		{
			if (guiElementKeys.at(i) == _key)
			{
				return (Slider*)guiElements.at(i);
			}
		}
		return nullptr;*/
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