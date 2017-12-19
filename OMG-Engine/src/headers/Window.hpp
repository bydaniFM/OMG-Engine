
// Copyright...

#pragma once

struct SDL_Window;

namespace engine
{

	class Window
	{

		SDL_Window * window;

	public:

		Window(const char * title, int width, int height);
		~Window();

		void Close();
		void Hide();
		void Show();
		void SetFullscreen(bool state);
		void SetTitle();
		void SwapBuffers();

	};

}