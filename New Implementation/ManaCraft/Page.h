#pragma once
#ifndef PAGE_H
#define PAGE_H

#include "GuiContainer.h"
//#include "ScreenFader.h"

class Page
{
protected:	
	GuiContainer* content;

public:
	Page() { content = new GuiContainer(); };
	virtual ~Page() { delete content; };

	//===================
	//-- Must Impliment
	//===================
	virtual void Load() {};
	virtual void Update(double time) { content->Update(time); };
	virtual void Draw() { content->Draw(); };

	//===================
	//-- Helper Methods
	//===================
	GuiContainer* GetContent() { return content; };

	//===========
	//-- Events
	//===========
	void OnMouseClick(){ content->OnMouseClick(); };
	void OnMouseMotion(SDL_MouseMotionEvent e){ content->OnMouseMotion(e); };
	void OnMouseDown(SDL_MouseButtonEvent e){ content->OnMouseDown(e); };
	void OnMouseUp(SDL_MouseButtonEvent e){ content->OnMouseUp(e); };

	void OnEnterKeyPressed(){ content->OnEnterKeyPressed(); };
	void OnEscapeKeyPressed(){ content->OnEscapeKeyPressed(); };
	void OnKeyboardDown(SDL_KeyboardEvent e){ content->OnKeyboardDown(e); };
	void OnKeyboardUp(SDL_KeyboardEvent e){ content->OnKeyboardUp(e); };
	void OnTextInput(SDL_TextInputEvent e){ content->OnTextInput(e); };
};
#endif