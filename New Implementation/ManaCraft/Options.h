#pragma once
#include "Page.h"
#include "ClientAPI.h"
class Options :
	public Page
{
protected:
	Options();

	static Options* instance;

public:
	static Options* GetInstance();
	~Options();

	virtual void Load();
	virtual void Update(double time);
	virtual void Draw();

	//============
	//--- Events 
	//============
	static void OnEnterPressed();
	static void OnEscapePressed();

	static void ReturnToMainMenu();
	static void MuteAll();
};

