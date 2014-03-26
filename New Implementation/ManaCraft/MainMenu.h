#pragma once
#include "Page.h"
class MainMenu :
	public Page
{
public:
	MainMenu();
	~MainMenu();


	virtual void Load();
	virtual void Update(double time);
	virtual void Draw();

	//============
	//--- Events 
	//============
	static void OnEnterPressed();
	static void OnEscapePressed();

	static void Click_loginButton();
	static void Click_viewButton();
	static void Click_optionsButton();
	static void Click_tutorialButton();
	static void Click_quitButton();
	static void Click_creditsButton();
};

