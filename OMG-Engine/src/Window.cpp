
// Copyright...


#include <SDL.h>
#include <Window.hpp>

namespace engine
{

	Window::Window(const char * title, int width, int height)
	{
		window = SDL_CreateWindow
		(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_OPENGL
		);
	}

	Window::~Window()
	{
		SDL_DestroyWindow(window);
	}

}