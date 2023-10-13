#include <SDL2/SDL.h>

#include "game.hpp"
#include "video.hpp"

int main() {
	// TODO: Do separately for subsystems as game starts up
	// https://wiki.libsdl.org/SDL2/SDL_Init
	SDL_Init(SDL_INIT_EVERYTHING);

	Game *game = new Game();
	Video *video = new Video();

	int quit = 0;
	while(quit != 1) {
		// Handle Input
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
			{
				quit = 1;
			}
		}

		game->Update();
		video->render_frame();
	}

	return 0;
}