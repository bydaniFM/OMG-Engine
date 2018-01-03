/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <string>
#include <map>
#include <memory>
#include <Kernel.hpp>
#include <Entity.hpp>
#include <Module.hpp>

using namespace std;

namespace rapidxml
{
	template<class Ch = char> class xml_node;
}

namespace OMG_Engine {

	class Scene
	{

		Kernel kernel;
		map< string, shared_ptr< Entity > > entities;
		map< string, shared_ptr< Module > > modules;

	public:

		Scene(const string & scene_file_path)
		{
			load_scene(scene_file_path);

			/*Read_Input_Task 	read_input_task;
			Update_Physics_Task update_physics_task;
			...

				kernel.add(&read_input_task);
			kernel.add(&update_physics_task);
			...*/
		}

		void run()
		{
			kernel.execute();
		}

	private:

		bool load_scene(const string & scene_file_path);

		bool parse_scene(xml_node<>* scene_node);

		bool parse_entities(xml_node<>* entities_node);

		bool parse_config(xml_node<>* config_node);

		bool parse_components(xml_node<>* component_tag, Entity & entity);

		void init_kernel()
		{
			/*for (auto & module : modules)
			{
				Task * task = module->get_task();

				if (task)
				{
					kernel.add_task(task);
				}
			}*/
		}

	};

}