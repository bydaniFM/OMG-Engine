/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <list>
#include <Task.hpp>

namespace OMG_Engine {

	class Kernel
	{
		typedef std::list< Task * > Task_List;

		Task_List task_list;
		bool      exit;

	public:

		void execute()
		{
			// LLAMAR AL MÉTODO INITIALIZE() DE TODAS LAS TASK

			exit = false;

			for
				(
					auto iterator = task_list.begin();
					iterator != task_list.end() && !exit;
					++iterator
					)
			{
				Task * task = *iterator;

				task->run();

				if (task->is_finished())
				{
					task->finalize();

					task_list.erase(iterator);
				}
			}


			// LLAMAR AL MÉTODO FINALIZE() DE TODAS LAS TASK
		}

		void stop()
		{
			exit = true;
		}

		void add(Task & task)
		{
			// Se añade la tarea a la lista de tareas:

			task_list.push_back(&task);

			// Se reordena la lista por prioridad de ejecución
			// de las tareas:

			task_list.sort(compare);
		}

		static bool compare(const Task * a, const Task * b)
		{
			return *a < *b;
		}

	};

}