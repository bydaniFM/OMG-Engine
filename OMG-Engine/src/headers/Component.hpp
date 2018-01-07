/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

namespace OMG_Engine {

	class Entity;

	class Component
	{
	protected:

		const Entity * parent;

	public:

		Component(Entity * entity) : parent(entity)
		{
		}

		virtual void initialize(Entity * entity) = 0;
		virtual void update(float deltaTime) = 0;
		virtual bool parse(xml_node<> * node) { }

	};

}