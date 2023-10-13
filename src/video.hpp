#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "camera.hpp"

#define W_WIDTH 800
#define W_HEIGHT 600

class Video {
private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;

public:
	Video() {
		// TODO: Take Width and Height as arguments
		SDL_CreateWindowAndRenderer(W_WIDTH, W_HEIGHT, 0, &_window, &_renderer);
	}

	~Video() {
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
	}

	void render_frame() {
		// Clear the screen
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
		SDL_RenderClear(_renderer);

		// Call the render functions for everything that needs to be rendered here

		// Draw everything
		SDL_RenderPresent(_renderer);
	}

	void draw_rectangle(int w, int h, int x, int y, int r, int g, int b, int a) {
		SDL_SetRenderDrawColor(_renderer, r, g, b, a);

		for (int i=-w/2; i<w/2; i++) {
			for (int j=-h/2; j<h/2; j++) {
				SDL_RenderDrawPoint(_renderer, x+i, y+j);
			}
		}
	}
};

#endif