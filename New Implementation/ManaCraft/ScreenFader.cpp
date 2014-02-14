#include "ScreenFader.h"

SDL_Texture *ScreenFader::fader = NULL;
SDL_Color ScreenFader::color = { 0, 0, 0, 255 };
bool ScreenFader::isFadingIn = false;
bool ScreenFader::isFadingOut = true;
int ScreenFader::alpha = color.a;

void ScreenFader::Load()
{
	if (fader == NULL)
		fader = APIHelper::SolidColourTexture(Window::Box().w, Window::Box().h, color);
}

void ScreenFader::Update(double _time)
{
	if (isFadingOut)
		alpha > 0 ? alpha += (0 - alpha) / _time * 3 : isFadingOut = false;
	else if (isFadingIn)
		alpha < 255 ? alpha += (265 - alpha) / _time * 3 : isFadingIn = false;
	
	SDL_SetTextureAlphaMod(fader, alpha);
}

void ScreenFader::FadeIn()
{
	alpha = 0;
	isFadingIn = true;
}

void ScreenFader::FadeOut()
{
	alpha = 255;
	isFadingOut = true;
}

void ScreenFader::Draw()
{
	SDL_RenderCopy(Window::Renderer(), fader, NULL, NULL);
}

void ScreenFader::SetColor(SDL_Color _color) { 
	SDL_DestroyTexture(fader);
	fader = NULL;

	fader = APIHelper::SolidColourTexture(Window::Box().w, Window::Box().h, { _color.r, _color.g, _color.b, alpha });
}
bool ScreenFader::IsFadingIn(){ return isFadingIn; }
bool ScreenFader::IsFadingOut(){ return isFadingOut; }
