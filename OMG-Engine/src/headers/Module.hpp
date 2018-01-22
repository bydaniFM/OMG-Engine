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
// <Scene.hpp>
#include <Component.hpp>

using namespace std;

namespace OMG_Engine
{
	class Scene;

	class Render_Module;
	
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

	protected:

		Scene * scene;

		Module(Scene * scene) : scene(scene)
		{
		}

	public:

		virtual shared_ptr< Component > create_component(Entity * entity) = 0;


	};

	// -----------------------------------------------------------------------------------

	/*class Render_Module : public Module
	{
	public:
		static shared_ptr< Module > create(Scene * scene)
		{
			return shared_ptr< Module >(new Render_Module(scene));
		}

	private:

		Render_Module(Scene * scene) : Module(scene)
		{
		}

	public:

		shared_ptr< Component > create_component(Entity * entity)
		{
			return nullptr;
		}

	};*/


	// -----------------------------------------------------------------------------------


	//Module::register_module("render", Render_Module::create);

}