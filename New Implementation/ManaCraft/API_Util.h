#pragma once
#include "ClientAPI.h"

//will add more to it, maybe

class API_Util
{
public:
	static enum TextureExtension
	{
		PNG,
		BMP
	};

	static void AddButtonToContainer(GuiContainer *_cName, std::string _btnName, SDL_Rect _rect, std::string _texName = "")
	{
		(_texName == "") ?
			_cName->AddGuiElement(_btnName, new Button(_rect)) :
			_cName->AddGuiElement(_btnName, new Button(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddCheckBoxToContainer(GuiContainer *_cName, std::string _cbName, SDL_Rect _rect, SDL_Color _checkColor, SDL_Color _outlineColor)
	{
		_cName->AddGuiElement(_cbName, new Checkbox(_rect, _checkColor, _outlineColor));
	}

	static void AddColor(std::string _clrName, int _r, int _g, int _b, int _a)
	{
		ClientAPI::AddColour(_clrName, { _r, _g, _b, _a });
	}

	static void AddFont(std::string _fontName, std::string _filePath, int _fontSize)
	{
		ClientAPI::AddFont(_fontName, Window::LoadFont(_filePath, _fontSize));
	}

	static void AddGuiElementToContainer(GuiContainer *_cName, std::string _guiName, std::string _texName, SDL_Rect _rect)
	{
		_cName->AddGuiElement(_guiName, new GuiElement(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddLabelToContainer(GuiContainer *_cName, std::string _lblName, std::string _text, SDL_Rect _rect, std::string _fontName, std::string _clrName)
	{
		_cName->AddGuiElement(_lblName, new Label(_text, _rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName)));
	}

	static void AddLabelToContainerButton(GuiContainer *_cName, std::string _btnName, std::string _lblText, std::string _fontName, std::string _clrName, bool _center = false)
	{
		_cName->GetButton(_btnName)->
			AddLabel(_lblText, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName), _center);
	}

	static void AddSolidTexture(std::string _texName, SDL_Color _color, int _width, int _height)
	{
		ClientAPI::AddTexture(_texName, APIHelper::SolidColourTexture(_width, _height, _color));
	}

	static void AddTexture(std::string _texName, std::string _filePath, TextureExtension _ext)
	{
		(_ext == BMP) ?
			ClientAPI::AddTexture(_texName, APIHelper::LoadBMPImage(_filePath)) :
			ClientAPI::AddTexture(_texName, APIHelper::LoadPNGTexture(_filePath));
	}

	static void AddTextFieldToContainer(GuiContainer *_cName, std::string _tfName, SDL_Rect _rect, std::string _fontName, std::string _fontColour)
	{
		_cName->AddGuiElement(_tfName, new TextField(_rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_fontColour)));
	}
};