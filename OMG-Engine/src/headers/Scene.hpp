/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <iostream>
#include <Kernel.hpp>

namespace OMG_Engine {

	class Scene
	{

		Kernel kernel;

	public:

		Scene(const std::string & scene_description_path)
		{
			//Read_Input_Task 	read_input_task;
			//Update_Physics_Task update_physics_task;
			////...

			//kernel.add(&read_input_task);
			//kernel.add(&update_physics_task);
			////...
		}

		void run()
		{
			kernel.execute();
		}

	};

}