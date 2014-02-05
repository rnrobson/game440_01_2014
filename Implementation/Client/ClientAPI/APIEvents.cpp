#include "APIEvents.h"

SDL_Event APIEvents::Event;
const Uint8 *APIEvents::CurrentKeyboardState;
const Uint8 *APIEvents::PreviousKeyboardState;
Uint32 APIEvents::CurrentMouseState;
Uint32 APIEvents::PreviousMouseState;
SDL_Rect APIEvents::MousePosition;