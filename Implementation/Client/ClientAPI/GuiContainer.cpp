#include "GuiContainer.h"

GuiContainer::GuiContainer()
{
	guiContainerKeys = vector<std::string>{};
	guiElementKeys = vector<std::string>{};
	buttonKeys = vector<std::string>{};
	textFieldKeys = vector<std::string>{};
	labelKeys = vector<std::string>{};
	checkboxKeys = vector<std::string>{};

	guiContainers = vector<GuiContainer*>{};
	guiElements = vector<GuiElement*>{};
	buttons = vector<Button*>{};
	textFields = vector<TextField*>{};
	labels = vector<Label*>{};
	checkboxes = vector<Checkbox*>{};

	Active = true;
	Enabled = true;
	SetPosition({ 0, 0, 0, 0 });
}

void GuiContainer::SetPosition(SDL_Rect _position)
{
	position = _position;

	for (int i = 0; i < guiContainers.size(); i++)
	{
		guiContainers.at(i)->SetPosition(_position);
	}

	for (int i = 0; i < guiElements.size(); i++)
	{
		guiElements.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < textFields.size(); i++)
	{
		textFields.at(i)->SetOffset(_position);
	}

	for (int i = 0; i < labels.size(); i++)
	{
		labels.at(i)->SetOffset(_position);
	}

	for (size_t i = 0; i < checkboxes.size(); i++)
	{
		checkboxes.at(i)->SetOffset(_position);
	}

}

void GuiContainer::Update(double time)
{
	if (Active){
		for (int i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Update(time);
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			buttons.at(i)->Update(time);
		}

		for (int i = 0; i < textFields.size(); i++)
		{
			textFields.at(i)->Update(time);
		}

		for (int i = 0; i < labels.size(); i++)
		{
			labels.at(i)->Update(time);
		}

		for (size_t i = 0; i < checkboxes.size(); i++)
		{
			checkboxes.at(i)->Update(time);
		}

		for (size_t i = 0; i < sliders.size(); i++)
		{
			sliders.at(i)->Update(time);
		}

		for (int i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Update(time);
		}
	}
}
void GuiContainer::Draw()
{
	if (Active) {
		for (int i = 0; i < guiElements.size(); i++)
		{
			guiElements.at(i)->Draw();
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			buttons.at(i)->Draw();
		}

		for (int i = 0; i < textFields.size(); i++)
		{
			textFields.at(i)->Draw();
		}

		for (int i = 0; i < labels.size(); i++)
		{
			labels.at(i)->Draw();
		}

		for (size_t i = 0; i < checkboxes.size(); i++)
		{
			checkboxes.at(i)->Draw();
		}

		for (size_t i = 0; i < sliders.size(); i++)
		{
			sliders.at(i)->Draw();
		}

		for (int i = 0; i < guiContainers.size(); i++)
		{
			guiContainers.at(i)->Draw();
		}
	}
}

void GuiContainer::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseMotionEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseMotion(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnMouseHover(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnMouseHover(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active) {
			textField->OnMouseHover(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnMouseHover(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnMouseHover(e);
		}
	}
}
void GuiContainer::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseDownEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseDown(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			if (button->Intersects(APIEvents::MousePosition))
				button->OnMouseDown(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			if (label->Intersects(APIEvents::MousePosition))
				label->OnMouseDown(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active) {
			if (textField->Intersects(APIEvents::MousePosition))
				textField->OnMouseDown(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			if (checkbox->Intersects(APIEvents::MousePosition))
				checkbox->OnMouseDown(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			if (slider->Intersects(APIEvents::MousePosition))
				slider->OnMouseDown(e);
		}
	}
}
void GuiContainer::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseUpEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnMouseUp(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnMouseUp(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnMouseUp(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active) {
			textField->OnMouseUp(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnMouseUp(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnMouseUp(e);
		}
	}
}
void GuiContainer::HandleMouseClickEvent()
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleMouseClickEvent();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			if (element->Intersects(APIEvents::MousePosition))
				element->OnMouseClick();
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			if (button->Intersects(APIEvents::MousePosition))
				button->OnMouseClick();
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			if (label->Intersects(APIEvents::MousePosition))
				label->OnMouseClick();
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active) {
			if (textField->Intersects(APIEvents::MousePosition))
				textField->OnMouseClick();
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			if (checkbox->Intersects(APIEvents::MousePosition))
				checkbox->OnMouseClick();
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			if (slider->Intersects(APIEvents::MousePosition))
				slider->OnMouseClick();
		}
	}
}

void GuiContainer::HandleTextInputEvent(SDL_TextInputEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleTextInputEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnTextInput(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnTextInput(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnTextInput(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active && textField->Enabled) {
			textField->OnTextInput(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnTextInput(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnTextInput(e);
		}
	}
}
void GuiContainer::HandleKeyboardDownEvent(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleKeyboardDownEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardDown(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnKeyboardDown(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnKeyboardDown(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active && textField->Enabled) {
			textField->OnKeyboardDown(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnKeyboardDown(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnKeyboardDown(e);
		}
	}
}
void GuiContainer::HandleKeyboardUpEvent(SDL_KeyboardEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleKeyboardUpEvent(e);
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnKeyboardUp(e);
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnKeyboardUp(e);
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnKeyboardUp(e);
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active && textField->Enabled) {
			textField->OnKeyboardUp(e);
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnKeyboardUp(e);
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnKeyboardUp(e);
		}
	}
}
void GuiContainer::HandleEnterKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEnterKeyPressed != NULL) {
			(*onEnterKeyPressed)(); 
	} 

	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleEnterKeyPressed();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEnterKeyPressed();
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnEnterKeyPressed();
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnEnterKeyPressed();
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active && textField->Enabled) {
			textField->OnEnterKeyPressed();
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnEnterKeyPressed();
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnEnterKeyPressed();
		}
	}
}
void GuiContainer::HandleEscapeKeyPressed()
{
	if (!Active) return;
	if (!Enabled) return;

	if (onEscapeKeyPressed != NULL) {
		(*onEscapeKeyPressed)(); 
	}


	for each (GuiContainer* guic in guiContainers)
	{
		if (guic->Active) {
			guic->HandleEscapeKeyPressed();
		}
	}

	for each (GuiElement* element in guiElements)
	{
		if (element->Active) {
			element->OnEscapeKeyPressed();
		}
	}

	for each (Button* button in buttons)
	{
		if (button->Active) {
			button->OnEscapeKeyPressed();
		}
	}

	for each (Label* label in labels)
	{
		if (label->Active) {
			label->OnEscapeKeyPressed();
		}
	}

	for each (TextField* textField in textFields)
	{
		if (textField->Active && textField->Enabled) {
			textField->OnEscapeKeyPressed();
		}
	}

	for each (Checkbox* checkbox in checkboxes)
	{
		if (checkbox->Active) {
			checkbox->OnEscapeKeyPressed();
		}
	}

	for each (Slider* slider in sliders)
	{
		if (slider->Active) {
			slider->OnEscapeKeyPressed();
		}
	}
}