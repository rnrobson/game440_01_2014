#pragma once
#ifndef PAGE_H
#define PAGE_H

#include "ClientAPI.h"
//#include "ScreenFader.h"

class Page
{
protected:
	GuiContainer* content;

public:
	Page() { content = new GuiContainer(); };
	virtual ~Page() { delete content; }

	//===================
	//-- Must Impliment
	//===================
	virtual void Load() {};
	virtual void Update(double time) {};
	virtual void Draw() {};

	//===================
	//-- Helper Methods
	//===================
	GuiContainer* GetContent() { return content; }
};
#endif