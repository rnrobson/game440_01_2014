#include "TextField.h"


TextField::TextField(SDL_Rect _rect, TTF_Font* _font, SDL_Color _textColour)
:Label("", _rect, _font, _textColour)
{
	backgroundTexture = APIHelper::SolidColourTexture(_rect.w, _rect.h, { 255, 255, 255, 155 });
}

TextField::~TextField()
{
	SDL_DestroyTexture(backgroundTexture);

	GuiElement::~GuiElement();
}

void TextField::Update(double _time)
{
	if (Active) {
		if (Enabled) {
			GuiElement::Update(_time);
		}
	}
}

void TextField::Draw()
{
	if (Active) {
		SDL_RenderCopyEx(Window::Renderer(), backgroundTexture, NULL, &rect, 0, NULL, flip);
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

void TextField::OnEnterKeyPressed()
{
	if (Active && Enabled)
	{
		Label::OnEnterKeyPressed();
	}
}
void TextField::OnKeyboardDown(SDL_KeyboardEvent e)
{
	if (Active && Enabled)
	{
		cout << "KeyPressed" << endl;

		//Handle backspace
		if (e.keysym.sym == SDLK_BACKSPACE)
		{
			//lop off character
			RemoveLastCharacterFromString();

			cout << "Backspace Pressed" << endl;
		}

		Label::OnKeyboardDown(e);
	}
}
void TextField::OnKeyboardUp(SDL_KeyboardEvent e)
{
	if (Active && Enabled)
	{
		Label::OnKeyboardUp(e);
	}
}
void TextField::OnTextInput(SDL_TextInputEvent e)
{
	if (Active && Enabled)
	{
		cout << "Text Input" << endl;

		//Not pasting
		if (!((e.text[0] == 'v' || e.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL))
		{
			//Append character
			AddToString(*e.text); // inputText += e.text.text;
								  // renderText = true;
		}

		Label::OnTextInput(e);
	}
}