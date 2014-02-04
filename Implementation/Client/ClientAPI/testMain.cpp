#include "ClientAPI.h"
//#include "Window.h"

//-- Function Prototypes
void Update(double time);
void Draw();

int testmain(int argc, char* args[])
{
	//-- Initialize the API
	ClientAPI::Init();

	ClientAPI::SetCustomUpdate(Update);
	ClientAPI::SetCustomDraw(Draw);

	//-- Add in some Sample Assets
	ClientAPI::AddColour("Colour1", APIHelper::ColourHelper(155,205,225,205));//SDL_Color colour = { 155, 205, 225, 205 };
	ClientAPI::AddFont("OGWEAR", Window::LoadFont("Resources/Fonts/OGWEAR.ttf", 24));//TTF_Font* font = Window::LoadFont("OGWEAR.ttf", 24);
	
	ClientAPI::AddButton("Button1", new Button(APIHelper::RectHelper(200, 200, 200, 100)));//Button* b = new Button(Window::RectHelper(200, 200, 200, 100));
	ClientAPI::GetButton("Button1")->AddLabel("Button Label 25 Button Label 255", ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1"), true);// font, colour, true);
	
	ClientAPI::AddLabel("Label1", new Label("Text Label 1", APIHelper::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1")));// Label* l = new Label("Text Label 1", Window::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), colour);// font, colour);
	
	ClientAPI::AddGuiContainer("Container 1", new GuiContainer());
	ClientAPI::GetGuiContainer("Container 1")->AddButton("C Button 1", new Button(APIHelper::RectHelper(300, 500, 100, 100)));
	ClientAPI::GetGuiContainer("Container 1")->AddLabel("C Label1", new Label("C Text Label 1", APIHelper::RectHelper(200, 600, 200, 100), ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1")));// Label* l = new Label("Text Label 1", Window::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), colour);// font, colour);
	ClientAPI::GetGuiContainer("Container 1")->SetOffset(APIHelper::RectHelper(200, -200, 0, 0));

	ClientAPI::RemoveLabel("Label1");
	ClientAPI::GetGuiContainer("Container 1")->Active = false; 

	//-- Start the APIs main loop
	ClientAPI::BeginMainLoop();
	//-- Quit the API once the APIs Main loop is over
	ClientAPI::Quit();
	return 0;
}

void Update(double time)
{
	cout << "Entering Custom Update" << endl;

	SDL_Delay(1000);
	ClientAPI::ExitMainLoop();
}

void Draw()
{
	cout << "Entering Custom Draw" << endl;
}