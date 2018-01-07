/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <memory>
#include <map>
#include <string>
#include <Scene.hpp>

using namespace std;

namespace OMG_Engine {

	class Module
	{

		typedef shared_ptr< Module >(*Module_Factory) (Scene * scene);

		static map< string, Module_Factory >  module_registry;

	public:

		static void (const string & id, Module_Factory factory)	//register
		{
			module_registry[id] = factory;
		}

		static shared_ptr< Module > create(const string & id, Scene * scene)
		{
			if (module_registry.count(id))
			{
				return module_registry[id](scene);
			}

			return shared_ptr< Module >();
		}

	public:

		virtual shared_ptr< Compoment > create_component(Entity * entity) = 0;


	};

}