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

	static void AddButton(std::string _containerName, std::string _btnName, SDL_Rect _rect, std::string _texName = "")
	{
		(_texName == "") ?
			ClientAPI::GetGuiContainer(_containerName)->AddButton(_btnName, new Button(_rect)) :
			ClientAPI::GetGuiContainer(_containerName)->AddButton(_btnName, new Button(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddButtonToContainer(GuiContainer *_cName, std::string _btnName, SDL_Rect _rect, std::string _texName = "")
	{
		(_texName == "") ?
			_cName->AddButton(_btnName, new Button(_rect)) :
			_cName->AddButton(_btnName, new Button(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddColor(std::string _clrName, int _r, int _g, int _b, int _a)
	{
		ClientAPI::AddColour(_clrName, { _r, _g, _b, _a });
	}

	static void AddFont(std::string _fontName, std::string _filePath, int _fontSize)
	{
		ClientAPI::AddFont(_fontName, Window::LoadFont(_filePath, _fontSize));
	}

	static void AddLabel(std::string _containerName, std::string _lblName, std::string _text, SDL_Rect _rect, std::string _fontName, std::string _clrName)
	{
		ClientAPI::GetGuiContainer(_containerName)->AddLabel(_lblName, new Label(_text, _rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName)));
	}

	static void AddLabelToContainer(GuiContainer *_cName, std::string _lblName, std::string _text, SDL_Rect _rect, std::string _fontName, std::string _clrName)
	{
		_cName->AddLabel(_lblName, new Label(_text, _rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName)));
	}

	static void AddLabelToContainerButton(GuiContainer *_cName, std::string _btnName, std::string _lblName, std::string _fontName, std::string _clrName, bool _center = false)
	{
		_cName->GetButton(_btnName)->
			AddLabel(_lblName, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName), _center);
	}

	static void AddTexture(std::string _texName, std::string _filePath, TextureExtension _ext)
	{
		(_ext == BMP) ?
			ClientAPI::AddTexture(_texName, APIHelper::LoadBMPImage(_filePath)) :
			ClientAPI::AddTexture(_texName, APIHelper::LoadPNGTexture(_filePath));
	}

	static void AddTextField(std::string _containerName, std::string _tfName, SDL_Rect _rect, std::string _fontName, std::string _fontColour)
	{
		ClientAPI::GetGuiContainer(_containerName)->AddTextField(_tfName, new TextField(_rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_fontColour)));
	}
};