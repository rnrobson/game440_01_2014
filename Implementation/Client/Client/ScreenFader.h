#include <SDL.h>
#include <math.h>
#include <ClientAPI.h>

class ScreenFader
{
public:
	static void Load();
	static void Update(double _time);
	static void FadeIn();
	static void FadeOut();
	static void Draw();
	static void SetColor(SDL_Color _color);
	static bool IsFadingIn();
	static bool IsFadingOut();
private:
	static SDL_Texture *fader;
	static SDL_Color color;
	static bool isFadingIn, isFadingOut;
	static int alpha;
	~ScreenFader(){ SDL_DestroyTexture(fader); }
};
