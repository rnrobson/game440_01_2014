#pragma once
#ifndef CLIENT_API_H
#define CLIENT_API_H

#include "Includes.h"
#include "APIHelper.h"
#include "APIEvents.h"

#include "Window.h"
#include "GuiContainer.h"
#include "GuiElement.h"
#include "Button.h"
#include "Label.h"
#include "TextField.h"
#include "Checkbox.h"
#include "Slider.h"

class ClientAPI
{
private:
	#pragma region Resources
	//-- Fonts, Textures & Colours
	static std::vector<std::string> fontKeys;
	static std::vector<TTF_Font*> fonts;
	
	static std::vector<std::string> textureKeys;
	static std::vector<SDL_Texture*> textures;

	static std::vector<std::string> colourKeys;
	static std::vector<SDL_Color> colours;

	static std::vector<std::string> rectKeys;
	static std::vector<SDL_Rect> rects;

	//-- API Objects
	static std::vector<std::string> guiContainerKeys;
	static std::vector<GuiContainer*> guiContainers;

	static std::vector<std::string> guiElementKeys;
	static std::vector<GuiElement*> guiElements;

	static bool quit;

	static void (*CustomUpdateFunc)(double);
	static void (*CustomDrawFunc)();
	static void(*EnterKeyPressedFunc)();
	static void(*EscapeKeyPressedFunc)();

	static void SetupHelper(){
		fontKeys = std::vector<std::string>{};
		textureKeys = std::vector<std::string>{};
		colourKeys = std::vector<std::string>{};
		rectKeys = std::vector<std::string>{};

		guiContainerKeys = std::vector<std::string>{};
		guiElementKeys = std::vector<std::string>{};

		fonts = std::vector<TTF_Font*>{};
		textures = std::vector<SDL_Texture*>{};
		colours = std::vector<SDL_Color>{};
		rects = std::vector<SDL_Rect>{};

		guiContainers = std::vector<GuiContainer*>{};
		guiElements = std::vector<GuiElement*>{};

		CustomUpdateFunc = nullptr;
		CustomDrawFunc = nullptr;
		EnterKeyPressedFunc = nullptr;
		EscapeKeyPressedFunc = nullptr;

		APIEvents::PreviousKeyboardState = SDL_GetKeyboardState(NULL);
		APIEvents::PreviousMouseState = SDL_GetMouseState(NULL, NULL);
		APIEvents::MousePosition = { -2, -2, 1, 1 };
		APIEvents::EnterPressed = false;
		APIEvents::EscapePressed = false;
		APIEvents::SDLTextInputEnabled = false;

		APIHelper::ToggleTextInput();
	}
	static void CleanMemory()
	{
		fontKeys.clear();
		for (size_t i = 0; i < fonts.size(); i++)
		{
			TTF_CloseFont(fonts.at(i));
		}
		fonts.clear();

		textureKeys.clear();
		for (size_t i = 0; i < textures.size(); i++)
		{
			SDL_DestroyTexture(textures.at(i));
		}
		textures.clear();

		colourKeys.clear();
		colours.clear();

		rectKeys.clear();
		rects.clear();

		guiElementKeys.clear();
		guiElements.clear();
	}

	static void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	static void HandleMouseClickEvent();
	static void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	static void HandleMouseUpEvent(SDL_MouseButtonEvent e);

	static void HandleKeyboardDownEvent(SDL_KeyboardEvent e);
	static void HandleKeyboardUpEvent(SDL_KeyboardEvent e);
	static void HandleEnterKeyPressed();
	static void HandleEscapeKeyPressed();
	static void HandleTextInputEvent(SDL_TextInputEvent e);
	#pragma endregion

	static void CheckEvents();
	static void Update(double time);
	static void Draw();
public:
	static void Init(std::string title = "Window", int width = 1024, int height = 768) 
	{ 
		Window::Init(title, width, height); 
		SetupHelper();
	}
	static void Exit() { Quit(); }
	static void Quit() 
	{ 
		CleanMemory();
		APIHelper::ToggleTextInput();
		Window::Quit(); 
	}
	
	static void SubscribeCustomUpdate(void(*updateFunc)(double)) { CustomUpdateFunc = updateFunc; }
	static void SubscribeCustomDraw(void(*drawFunc)()) { CustomDrawFunc = drawFunc; }
	static void SubscribeEnterKeyFunc(void(*enterKeyFunc)()) { EnterKeyPressedFunc = enterKeyFunc; }
	static void SubscribeEscapeKeyFunc(void(*escapeKeyFunc)()) { EscapeKeyPressedFunc = escapeKeyFunc; }

	#pragma region Adds
	static void AddFont(std::string _key, TTF_Font* _font)
	{
		fontKeys.push_back(_key);
		fonts.push_back(_font);
	}

	static void AddTexture(std::string _key, SDL_Texture* _textures)
	{
		textureKeys.push_back(_key);
		textures.push_back(_textures);
	}

	static void AddColour(std::string _key, SDL_Color _colour)
	{
		colourKeys.push_back(_key);
		colours.push_back(_colour);
	}

	static void AddRect(std::string _key, SDL_Rect _colour)
	{
		rectKeys.push_back(_key);
		rects.push_back(_colour);
	}

	static void AddGuiContainer(std::string _key, GuiContainer* _guiContainer)
	{
		guiContainerKeys.push_back(_key);
		guiContainers.push_back(_guiContainer);
	}

	static void AddGuiElement(std::string _key, GuiElement* _guiElement)
	{
		guiElementKeys.push_back(_key);
		guiElements.push_back(_guiElement);
	}
	#pragma endregion
	#pragma region Removes
	static void RemoveFont(std::string _key)
	{
		for (size_t i = 0; i < fontKeys.size(); i++)
		{
			if (fontKeys.at(i) == _key)
			{
				fontKeys.erase(fontKeys.begin() + i);
				TTF_CloseFont(fonts.at(i));
				fonts.erase(fonts.begin() + i);
				break;
			}
		}
	}

	static void RemoveTexture(std::string _key)
	{
		for (size_t i = 0; i < textureKeys.size(); i++)
		{
			if (textureKeys.at(i) == _key)
			{
				textureKeys.erase(textureKeys.begin() + i);
				SDL_DestroyTexture(textures.at(i));
				textures.erase(textures.begin() + i);
				break;
			}
		}
	}

	static void RemoveColour(std::string _key)
	{
		for (size_t i = 0; i < colourKeys.size(); i++)
		{
			if (colourKeys.at(i) == _key)
			{
				colourKeys.erase(colourKeys.begin() + i);
				colours.erase(colours.begin() + i);
				break;
			}
		}
	}

	static void RemoveRect(std::string _key)
	{
		for (size_t i = 0; i < rectKeys.size(); i++)
		{
			if (rectKeys.at(i) == _key)
			{
				rectKeys.erase(rectKeys.begin() + i);
				rects.erase(rects.begin() + i);
				break;
			}
		}
	}

	static void RemoveGuiContainer(std::string _key)
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

	static void RemoveGuiElement(std::string _key)
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
	#pragma endregion
	#pragma region Gets
	static TTF_Font* GetFont(std::string _key)
	{
		for (size_t i = 0; i < fontKeys.size(); i++)
		{
			if (fontKeys.at(i) == _key)
			{
				return fonts.at(i);
			}
		}
		return nullptr;
	}

	static SDL_Texture* GetTexture(std::string _key)
	{
		for (size_t i = 0; i < textureKeys.size(); i++)
		{
			if (textureKeys.at(i) == _key)
			{
				return textures.at(i);
			}
		}
		return nullptr;
	}

	static SDL_Color GetColor(std::string _key)
	{
		for (size_t i = 0; i < colourKeys.size(); i++)
		{
			if (colourKeys.at(i) == _key)
			{
				return colours.at(i);
			}
		}
		return { 0, 0, 0, 0 };
	}

	static SDL_Rect GetRect(std::string _key)
	{
		for (size_t i = 0; i < rectKeys.size(); i++)
		{
			if (rectKeys.at(i) == _key)
			{
				return rects.at(i);
			}
		}
		return{ 0, 0, 0, 0 };
	}

	static void SetAllGuiContainersInactive()
	{
		for (size_t i = 0; i < guiContainerKeys.size(); i++)
		{
			guiContainers.at(i)->Active = false;
		}
	}

	static GuiContainer* GetGuiContainer(std::string _key)
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

	static GuiElement* GetGuiElement(std::string _key)
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
	#pragma endregion
	
	static void BeginMainLoop();
	static void ExitMainLoop()
	{
		quit = true;
	}


};
#endif