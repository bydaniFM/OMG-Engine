/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <Module.hpp>

using namespace std;

namespace OMG_Engine
{

	map< string, Module::Module_Factory >  Module::module_registry;

}