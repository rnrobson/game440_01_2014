#pragma once
#include <ClientAPI.h>

class MainMenu
{
public:
	static void Load()
	{
		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *smallBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnHover.bmp");
		SDL_Texture *smallBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnDown.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *medBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnHover.bmp");
		SDL_Texture *medBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnDown.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");
		SDL_Texture *longBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnHover.bmp");
		SDL_Texture *longBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnDown.bmp");

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);

		//-- Add in some Sample Assets
		ClientAPI::AddColour("Black", black);
		ClientAPI::AddFont("Systema", systema);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddButton("PlayBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), medBtnRect));
		ClientAPI::GetButton("PlayBtn")->AddLabel("Play", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	}
};