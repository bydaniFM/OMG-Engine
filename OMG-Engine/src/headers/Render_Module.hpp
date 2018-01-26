/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <Module.hpp>

namespace OMG_Engine {

	class Render_Module : public Module
	{

		/*class Render_Task : public Task
		{
			public:
				Render_Task() : Task(30) { }
			void initialize();
			void update();
			void finalize();
		};*/

		class Render_Component : public Component
		{
		public:
			Render_Component(Entity * entity) : Component(entity)
			{
			}
			void initialize(Entity * entity)
			{
			}
			void update(float deltaTime)
			{
			}

			bool parse(rapidxml::xml_node<char> * node);
		};

	private:

		//Render_Task task;

		Render_Module(Scene * scene) : Module(scene)
		{
		}

	public:

		static shared_ptr< Module > create(Scene * scene)
		{
			return shared_ptr< Module >(new Render_Module(scene));
		}

		shared_ptr< Component > create_component(Entity * entity)
		{
			return shared_ptr< Component >(new Render_Component(entity));
		}

		/*Task * get_task()
		{
			return &task;
		}*/
	};

}