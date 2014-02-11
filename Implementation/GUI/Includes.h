#pragma once
#ifdef GUI_EXPORTS
#define GUI_API __declspec(dllexport)
#else
#define GUI_API __declspec(dllimport)
#endif

#ifndef INCLUDES_H
#define INCLUDES_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//#include "Window.h"
#endif
