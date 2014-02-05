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

class ClientAPI
{
private:
	#pragma region Resources
	//-- Fonts, Textures & Colours
	static vector<std::string> fontKeys;
	static vector<TTF_Font*> fonts;
	
	static vector<std::string> textureKeys;
	static vector<SDL_Texture*> textures;

	static vector<std::string> colourKeys;
	static vector<SDL_Color> colours;

	//-- API Objects
	static vector<std::string> guiContainerKeys;
	static vector<GuiContainer*> guiContainers;

	static vector<std::string> guiElementKeys;
	static vector<GuiElement*> guiElements;

	static vector<std::string> buttonKeys;
	static vector<Button*> buttons;

	static vector<std::string> textFieldKeys;
	static vector<TextField*> textFields;

	static vector<std::string> labelKeys;
	static vector<Label*> labels;

	static bool quit;

	static void (*CustomUpdateFunc)(double);
	static void (*CustomDrawFunc)();

	static void SetupHelper(){
		fontKeys = vector<std::string>{};
		textureKeys = vector<std::string>{};
		colourKeys = vector<std::string>{};
		guiContainerKeys = vector<std::string>{};
		guiElementKeys = vector<std::string>{};
		buttonKeys = vector<std::string>{};
		textFieldKeys = vector<std::string>{};
		labelKeys = vector<std::string>{};

		fonts = vector<TTF_Font*>{};
		textures = vector<SDL_Texture*>{};
		colours = vector<SDL_Color>{};
		guiContainers = vector<GuiContainer*>{};
		guiElements = vector<GuiElement*>{};
		buttons = vector<Button*>{};
		textFields = vector<TextField*>{};
		labels = vector<Label*>{};

		CustomUpdateFunc = nullptr;
		CustomDrawFunc = nullptr;

		APIEvents::PreviousKeyboardState = SDL_GetKeyboardState(NULL);
		APIEvents::PreviousMouseState = SDL_GetMouseState(NULL, NULL);
		APIEvents::MousePosition = { -2, -2, 1, 1 };
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
		Window::Quit(); 
	}
	
	static void SetCustomUpdate(void(*updateFunc)(double)) { CustomUpdateFunc = updateFunc; }
	static void SetCustomDraw(void(*drawFunc)()) { CustomDrawFunc = drawFunc; }

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

	static void AddButton(std::string _key, Button* _button)
	{
		buttonKeys.push_back(_key);
		buttons.push_back(_button);
	}

	static void AddTextField(std::string _key, TextField* _textField)
	{
		textFieldKeys.push_back(_key);
		textFields.push_back(_textField);
	}

	static void AddLabel(std::string _key, Label* _label)
	{
		labelKeys.push_back(_key);
		labels.push_back(_label);
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

	static void RemoveButton(std::string _key)
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

	static void RemoveTextField(std::string _key)
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

	static void RemoveLabel(std::string _key)
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
	static TTF_Font* GetFont(std::string _key)
	{
		for (size_t i = 0; i < fontKeys.size(); i++)
		{
			if (fontKeys.at(i) == _key)
			{
				return fonts.at(i);
			}
		}
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
	}

	static Button* GetButton(std::string _key)
	{
		for (size_t i = 0; i < buttonKeys.size(); i++)
		{
			if (buttonKeys.at(i) == _key)
			{
				return buttons.at(i);
			}
		}
	}

	static TextField* GetTextField(std::string _key)
	{
		for (size_t i = 0; i < textFieldKeys.size(); i++)
		{
			if (textFieldKeys.at(i) == _key)
			{
				return textFields.at(i);
			}
		}
	}

	static Label* GetLabel(std::string _key)
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
	
	static void BeginMainLoop();
	static void ExitMainLoop()
	{
		quit = true;
	}


};
#endif