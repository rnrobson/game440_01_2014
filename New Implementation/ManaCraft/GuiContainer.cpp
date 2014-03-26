#include "GuiContainer.h"

GuiContainer::GuiContainer() : GuiObject()
{
	guiContainers = std::map<std::string, GuiContainer*>{};
	guiElements = std::map<std::string, GuiElement*>{};

	onEscapeKeyPressed = nullptr;
	onEnterKeyPressed = nullptr;

	SetPosition({ 0, 0, 0, 0 });

	music = nullptr;
}

void GuiContainer::SetPosition(SDL_Rect _position)
{
	position = _position;

	for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
		it->second->SetPosition(_position);
	}

	for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
		it->second->SetOffset(_position);
	}
}

void GuiContainer::Update(double time)
{
	if (Active){
		GuiObject::Update(time);

		for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
			it->second->Update(time);
		}

		for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
			it->second->Update(time);
		}
	}
}
void GuiContainer::Draw()
{
	if (Active) {
		GuiObject::Draw();

		for (auto it = guiElements.begin(); it != guiElements.end(); ++it) {
			it->second->Draw();
		}

		for (auto it = guiContainers.begin(); it != guiContainers.end(); ++it) {
			it->second->Draw();
		}
	}
}

void GuiContainer::OnMouseMotion(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnMouseMotion(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnMouseMotion(e);

			if (element->second->Intersects({ e.x, e.y, 1, 1 })){
				element->second->OnMouseHover(e);
			}
		}
	}
}
void GuiContainer::OnMouseDown(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnMouseDown(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			if (element->second->Intersects(APIEvents::MousePosition))
				element->second->OnMouseDown(e);
		}
	}
}
void GuiContainer::OnMouseUp(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnMouseUp(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnMouseUp(e);
		}
	}
}
void GuiContainer::OnMouseClick()
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnMouseClick();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			if (element->second->Intersects(APIEvents::MousePosition))
				element->second->OnMouseClick();
		}
	}
}

void GuiContainer::OnTextInput(SDL_TextInputEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnTextInput(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnTextInput(e);
		}
	}
}
void GuiContainer::OnKeyboardDown(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnKeyboardDown(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnKeyboardDown(e);
		}
	}
}
void GuiContainer::OnKeyboardUp(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnKeyboardUp(e);
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnKeyboardUp(e);
		}
	}
}
void GuiContainer::OnEnterKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEnterKeyPressed != NULL) {
			(*onEnterKeyPressed)(); 
	} 

	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnEnterKeyPressed();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnEnterKeyPressed();
		}
	}
}
void GuiContainer::OnEscapeKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEscapeKeyPressed != NULL) {
		(*onEscapeKeyPressed)(); 
	}


	for (auto container = guiContainers.begin(); container != guiContainers.end(); ++container) {
		if (container->second->Active) {
			container->second->OnEscapeKeyPressed();
		}
	}

	for (auto element = guiElements.begin(); element != guiElements.end(); ++element) {
		if (element->second->Active) {
			element->second->OnEscapeKeyPressed();
		}
	}
}