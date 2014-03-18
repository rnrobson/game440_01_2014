#include "ClientAPI.h"
//#include "Window.h"

//-- Function Prototypes
void Update(double time);
void Draw();

int testmain(int argc, char* args[])
{
	//-- Initialize the API
	ClientAPI::Init();

	ClientAPI::SubscribeCustomUpdate(Update);
	ClientAPI::SubscribeCustomDraw(Draw);

	//-- Add in some Sample Assets
	ClientAPI::AddColour("Colour1", APIHelper::ColourHelper(155,205,225,205));//SDL_Color colour = { 155, 205, 225, 205 };
	ClientAPI::AddFont("OGWEAR", Window::LoadFont("Resources/Fonts/OGWEAR.ttf", 24));//TTF_Font* font = Window::LoadFont("OGWEAR.ttf", 24);
	
	ClientAPI::AddGuiContainer("Test Container", new GuiContainer());
	ClientAPI::GetGuiContainer("TestContainer")->AddGuiElement("ImageButton", new Button(APIHelper::LoadPNGTexture("Resources/Images/evilTestingIcon.png"), APIHelper::RectHelper(100, 100, 200, 267)));
	ClientAPI::GetGuiContainer("TestContainer")->AddGuiElement("Button1", new Button(APIHelper::RectHelper(200, 200, 200, 100)));//Button* b = new Button(Window::RectHelper(200, 200, 200, 100));
	ClientAPI::GetGuiContainer("TestContainer")->GetButton("Button1")->AddLabel("Button Label 25 Button Label 255", ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1"), true);// font, colour, true);
	
	ClientAPI::GetGuiContainer("TestContainer")->AddGuiElement("Label1", new Label("Text Label 1", APIHelper::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1")));// Label* l = new Label("Text Label 1", Window::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), colour);// font, colour);
	
	ClientAPI::GetGuiContainer("TestContainer")->AddGuiContainer("Container 1", new GuiContainer());
	ClientAPI::GetGuiContainer("TestContainer")->GetGuiContainer("Container 1")->AddGuiElement("C Button 1", new Button(APIHelper::RectHelper(300, 500, 100, 100)));
	ClientAPI::GetGuiContainer("TestContainer")->GetGuiContainer("Container 1")->AddGuiElement("C Label1", new Label("C Text Label 1", APIHelper::RectHelper(200, 600, 200, 100), ClientAPI::GetFont("OGWEAR"), ClientAPI::GetColor("Colour1")));// Label* l = new Label("Text Label 1", Window::RectHelper(600, 200, 200, 100), ClientAPI::GetFont("OGWEAR"), colour);// font, colour);
	ClientAPI::GetGuiContainer("TestContainer")->GetGuiContainer("Container 1")->SetPosition(APIHelper::RectHelper(200, -200, 0, 0));

	ClientAPI::GetGuiContainer("TestContainer")->RemoveGuiElement("Label1");
	ClientAPI::GetGuiContainer("TestContainer")->GetGuiContainer("Container 1")->Active = false;

	//-- Start the APIs main loop
	ClientAPI::BeginMainLoop();
	//-- Quit the API once the APIs Main loop is over
	ClientAPI::Quit();
	return 0;
}

void Update(double time)
{
	std::cout << "Entering Custom Update" << std::endl;

	SDL_Delay(1000);
	ClientAPI::ExitMainLoop();
}

void Draw()
{
	std::cout << "Entering Custom Draw" << std::endl;
}