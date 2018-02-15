/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <Task.hpp>

namespace OMG_Engine
{
	class ReadInput_Task : public Task
	{

	public:
		ReadInput_Task() : Task(0)
		{
		}

		void initialize()
		{
			std::cout << "Init Read Input task" << std::endl;
		}

		void finalize()
		{
			std::cout << "Finish Read Input task" << std::endl;
		}

		void run()
		{
			//std::cout << "Reading Input" << std::endl;
		}

	};
}