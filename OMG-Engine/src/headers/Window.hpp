/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

struct SDL_Window;

namespace OMG_Engine
{
	class Window
	{
	public:

		enum DisplayMode
		{
			FULLSCREEN,
			WINDOWED,
			BORDERLESS
		};

	private:

		SDL_Window * window;
		DisplayMode state;

	public:

		Window(const char * title, int width, int height);
		~Window();

		void Close();
		void Hide();
		void Show();
		void SetFullscreen(DisplayMode state);
		void SetTitle(const char * title);
		void SwapBuffers();

	};

}