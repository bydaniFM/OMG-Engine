/*
	Author: Daniel Fernandez Marques
	Date: 28/11/2017

	Copyright (c) 2017 OMG-Engine

	Subject to license described in LICENSE file
*/

#include "Scene.hpp"

namespace OMG_Engine{

	int main()
	{
		// initialize

		Scene menu_scene("scenes/main-menu.xml");

		menu_scene.run();

		// cleanup

		return 0;
	}
}