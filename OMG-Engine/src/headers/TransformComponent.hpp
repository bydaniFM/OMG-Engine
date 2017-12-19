/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <Component.hpp>

namespace OMG_Engine {

	class Transform_Component : public Component
	{

		Transform_Component(Entity * entity) : Component(entity)
		{
		}

		void initialize()
		{
		}

		void update(float deltaTime)
		{
		}

		bool parse(xml_node<> * node)
		{
		}

	};

}