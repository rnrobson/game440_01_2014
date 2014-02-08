#pragma once
#include <ClientAPI.h>

//will add more to it, maybe

class API_Util
{
public:
	static enum TextureExtension
	{
		PNG,
		BMP
	};

	static void AddButton(string _btnName, SDL_Rect _rect, string _texName = "")
	{
		(_texName == "") ?
			ClientAPI::AddButton(_btnName, new Button(_rect)) :
			ClientAPI::AddButton(_btnName, new Button(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddButtonToContainer(GuiContainer *_cName, string _btnName, SDL_Rect _rect, string _texName = "")
	{
		(_texName == "") ?
			_cName->AddButton(_btnName, new Button(_rect)) :
			_cName->AddButton(_btnName, new Button(ClientAPI::GetTexture(_texName), _rect));
	}

	static void AddColor(string _clrName, int _r, int _g, int _b, int _a)
	{
		ClientAPI::AddColour(_clrName, { _r, _g, _b, _a });
	}

	static void AddFont(string _fontName, string _filePath, int _fontSize)
	{
		ClientAPI::AddFont(_fontName, Window::LoadFont(_filePath, _fontSize));
	}

	static void AddLabel(string _lblName, string _text, SDL_Rect _rect, string _fontName, string _clrName)
	{
		ClientAPI::AddLabel(_lblName, new Label(_text, _rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName)));
	}

	static void AddLabelToContainer(GuiContainer *_cName, string _lblName, string _text, SDL_Rect _rect, string _fontName, string _clrName)
	{
		_cName->AddLabel(_lblName, new Label(_text, _rect, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName)));
	}

	static void AddLabelToContainerButton(GuiContainer *_cName, string _btnName, string _lblName, string _fontName, string _clrName, bool _center = false)
	{
		_cName->GetButton(_btnName)->
			AddLabel(_lblName, ClientAPI::GetFont(_fontName), ClientAPI::GetColor(_clrName), _center);
	}

	static void AddTexture(string _texName, string _filePath, TextureExtension _ext)
	{
		(_ext == BMP) ?
			ClientAPI::AddTexture(_texName, APIHelper::LoadBMPImage(_filePath)) :
			ClientAPI::AddTexture(_texName, APIHelper::LoadPNGTexture(_filePath));
	}

	static void AddTextField(string _tfName, SDL_Rect _rect, string _fontName)
	{
		ClientAPI::AddTextField(_tfName, new TextField(_rect, ClientAPI::GetFont(_fontName)));
	}
};