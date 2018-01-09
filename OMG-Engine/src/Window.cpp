/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#include <SDL.h>
#include <Window.hpp>

namespace OMG_Engine
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

	void Window::Close()
	{
		//SDL_QUIT;    ^ ?
		SDL_DestroyWindow(window);	//?
	}

	void Window::Hide()
	{
		//Pause game?
		SDL_HideWindow(window);
	}

	void Window::Show()
	{
		//Unpause game?
		SDL_ShowWindow(window);
	}

	void Window::SetFullscreen(DisplayMode state)
	{
		this->state = state;
		switch (state)
		{
			case FULLSCREEN:
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
				break;
			case BORDERLESS:
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
				break;
			case WINDOWED:
				SDL_SetWindowFullscreen(window, 0);
				break;
		}
	}

	void Window::SetTitle(const char * title)
	{
		SDL_SetWindowTitle(window, title);
	}

	void Window::SwapBuffers()
	{

	}

}