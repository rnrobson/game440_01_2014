#pragma once
#include "Page.h"
#include "ClientAPI.h"

class Credits :
	public Page
{
protected:
	Credits();

	static Credits* instance;

public:
	static Credits* GetInstance();
	~Credits();

	virtual void Load();
	virtual void Update(double time);
	virtual void Draw();

	//============
	//--- Events 
	//============
	static void OnEnterPressed();
	static void OnEscapePressed();

	static void Click_backButton();
};

