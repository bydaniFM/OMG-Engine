/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

//#include <glm/mat4x4.hpp>
#include <Module.hpp>

namespace OMG_Engine
{

	class Transform_Module : public Module
	{

		/*class Transform_Task : public Task
		{
		public:
			Transform_Task() : Task(30) { }
			void initialize();
			void update();
			void finalize();
		};*/

		class Transform_Component : public Component
		{
			//Transformation t;
			//glm::mat4x4 transformation;

		public:

			Transform_Component(Entity * entity) : Component(entity)
			{
			}

			void initialize(Entity * entity)
			{
			}

			void update(float deltaTime)
			{
			}

			bool parse(rapidxml::xml_node<char> * node);

			/*void move(v);

			void rotate_x(float angle);*/
		};

	private:

		//Transform_Task; Physics?

		Transform_Module(Scene * scene) : Module(scene)
		{
		}

	public:

		static shared_ptr< Module > create(Scene * scene)
		{
			return shared_ptr< Module >(new Transform_Module(scene));
		}

		shared_ptr< Component > create_component(Entity * entity)
		{
			return shared_ptr< Component >(new Transform_Component(entity));
		}

		/*Task * get_task()
		{
		return &task;
		}*/

	};

}