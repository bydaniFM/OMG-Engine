/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <map>
#include <string>
#include <memory>
#include <Component.hpp>

using namespace std;

namespace OMG_Engine {

	class Scene;

	class Entity
	{
		map< string, shared_ptr< Component > > components;

		Scene * parent;

	public:

		Entity(Scene * scene) : parent(scene)
		{
		}

		void initialize()
		{
			for (auto & component : components)
			{
				component.second->initialize(this);
			}
		}

		void update(float deltaTime)
		{
			for (auto & component : components)
			{
				component.second->update(deltaTime);
			}
		}

		void add_component(const string & name, shared_ptr< Component > & component)
		{
			components[name] = component;
		}

	};

}