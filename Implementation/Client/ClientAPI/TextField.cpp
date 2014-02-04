#include "TextField.h"


TextField::TextField(SDL_Rect _rect, TTF_Font* _font)
:Label("", _rect, _font, { 0, 0, 0, 255 })
{
	//-- Hover Texture
	SDL_Surface *backgroundSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, _rect.w, _rect.h, 8, 0, 0, 0, 1);
	SDL_FillRect(backgroundSurface, NULL, SDL_MapRGB(backgroundSurface->format, 0, 0, 0));

	SDL_Texture *hoverTexture = SDL_CreateTextureFromSurface(Window::Renderer(), backgroundSurface);
	SDL_SetTextureAlphaMod(hoverTexture, 155);
	backgroundTexture = hoverTexture;
	SDL_FreeSurface(backgroundSurface);
}

TextField::~TextField()
{
	delete backgroundTexture;
}

void TextField::Update(double _time)
{
	if (Active) {
		GuiElement::Update(_time);
	}
}

void TextField::Draw()
{
	if (Active) {
		SDL_RenderCopyEx(Window::Renderer(), backgroundTexture, NULL, &rect, 0., NULL, flip);
		Label::Draw();
	}
}
void TextField::AddToString(char _added)
{
	printf("Character Pressed: %c\n", _added);

	text.push_back(_added);
	//text += _added;

	RenderText();
}

void TextField::RemoveLastCharacterFromString()
{
	if (GetStringSize() == 0)
		return;
	
	text.pop_back();
	//text.erase(text.length() - 1);
	
	RenderText();
}

string TextField::GetText()
{
	return text;
}

int TextField::GetStringSize()
{
	return text.length();
}