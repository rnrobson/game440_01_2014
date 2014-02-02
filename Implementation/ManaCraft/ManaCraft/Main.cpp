// Individual TODO: Project Properties -> Configuration Properties -> VC++ Directories -> 
// -> Set the project dependencies to point to your own SDL file within the project repository directory.  (They're all there).

#include <SDL.h>
#include <SDL_net.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char* argcs[]) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL failed to initiaize." << std::endl;
	}
	if (SDLNet_Init() != 0) {
		std::cout << "SDLNet failed to initiaize." << std::endl;
	}

	SDLNet_Quit();
	SDL_Quit();
	std::cin.get();
	return 0;
}