/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#include <Window.hpp>
//#include <Scene.hpp>

namespace OMG_Engine {

	extern "C"
	{

		int SDL_main(int number_of_arguments, char * arguments[])
		{
			// initialize

			//crear ventana
			Window window("Demo game", 1024, 768);

			//Scene menu_scene("scenes/main-menu.xml");

			//menu_scene.run();

			// cleanup

			while (true)
			{
				window.SwapBuffers();
			}

			return 0;
		}
	}
}