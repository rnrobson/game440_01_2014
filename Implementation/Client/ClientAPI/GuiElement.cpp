#include "GuiElement.h"

void(*GuiElement::onMouseHoverFunc)(SDL_MouseMotionEvent e);
void(*GuiElement::onMouseClickFunc)();
void(*GuiElement::onMouseDownFunc)(SDL_MouseButtonEvent e);
void(*GuiElement::onMouseUpFunc)(SDL_MouseButtonEvent e);

void(*GuiElement::onKeyboardDownFunc)(SDL_KeyboardEvent e);
void(*GuiElement::onKeyboardUpFunc)(SDL_KeyboardEvent e);
void(*GuiElement::onTextInputFunc)(SDL_TextInputEvent e);