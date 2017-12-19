/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <map>
#include <Entity.hpp>

using namespace std;

namespace OMG_Engine {

	class Controller
	{
		static map< string, Controller * > controllers;

	public:

		static void register (const string & id, Controller & c)
		{
			controllers[id] = c;
		}

		static Controller * get(const string & id)
		{
			return controllers[id];
		}

	public:

		virtual void initialize(Entity & entity) = 0;
		virtual void finalize(Entity & entity) = 0;
		virtual void update(Entity & entity, float delta_time) = 0;

	};


	class Control_Component : public Component
	{

		Controller & controller;

	public:

		Control_Component(Entity & entity, Controller & c)
			:
			Component(entity),
			controller(c)
		{
		}

		void initialize()
		{
			controller.initialize(entity);
		}

		void finalize()
		{
			controller.finalize(entity);
		}

		void update(float delta_time)
		{
			controller.update(entity, delta_time);
		}

	};

}


/*

PROYECTO ENGINE:

Scene
list< Entity > entities
list< Module > modules;
Kernel kernel

PROYECTO DEMO:

class Box_Controller : public Controller
{

void update (Entity & entity, float deltaTime)
{
if (entity.is_visible ())
{
entity.move (Vector3f(-1, 0, 0));

if (entity.is_colliding ())
{
entity.set_visible (false);
}
}
}
};


main(int number_of_arguments, char ** arguments)
{
Window window("title)Window window("title", 800, 600);

Box_Controller box_controller;

Controller::register ("box_controller", box_controller);

Scene scene(window, "s.xml");

scene.run ();
}
*/