#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

using namespace std;

#define FONT_PATH   "assets/fonts/Calibri.ttf"
#define IMAGE_PATH  "assets/images/image.png"

int main()
{
	// Initialize SDL with video
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Failed to initialize the SDL2 library\n";
		std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	// Init SDL2_ttf
	if (TTF_Init() != 0) {
		std::cerr << "Couldn't init SDL_ttf: " << TTF_GetError() << "\n";
		return -1;
	}

	// Load a font
	TTF_Font *font = TTF_OpenFont(FONT_PATH, 48);

	if (!font) {
		std::cerr << "Couldn't load font: %s" << FONT_PATH << "\n";
		return -1;
	}

	// Create window
	SDL_Window *window = SDL_CreateWindow("SDL2 Window",
					      SDL_WINDOWPOS_CENTERED,
					      SDL_WINDOWPOS_CENTERED,
					      680, 480,
					      0);

	if (!window) {
		std::cerr << "Failed to create window\n";
		std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	if (!window_surface) {
		std::cerr << "Failed to get the surface from the window\n";
		std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	/*  Load image with SDL2_image instead of native SDL_LoadBMP */
	SDL_Surface *image = IMG_Load(IMAGE_PATH);

	if (!image) {
		std::cerr << "Failed to load image\n";
		std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
		return -1;
	}

	SDL_Color color = { 128, 128, 128 };
	SDL_Surface *ttf_surface = TTF_RenderText_Blended(font, "Hello, world!", color);

	bool keep_window_open = true;

	while (keep_window_open) {
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0) {
			switch (e.type) {
			case SDL_QUIT:
				/* Cleanup before we quit. */
				SDL_FreeSurface(ttf_surface);
				TTF_CloseFont(font);
				TTF_Quit();
				keep_window_open = false;
				break;
			}

			SDL_BlitSurface(image, NULL, window_surface, NULL);
			SDL_BlitSurface(ttf_surface, NULL, window_surface, NULL);
			SDL_UpdateWindowSurface(window);
		}
	}

}
