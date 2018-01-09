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
#include <Component.hpp>

using namespace std;

namespace OMG_Engine {

	class Module
	{

		typedef shared_ptr< Module >(*Module_Factory) (Scene * scene);

		static map< string, Module_Factory >  module_registry;

	public:

		static void register_module (const string & id, Module_Factory factory)	//register
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

		virtual shared_ptr< Component > create_component(Entity * entity) = 0;


	};

}