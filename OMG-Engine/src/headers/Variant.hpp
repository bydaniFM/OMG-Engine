/*
Author: Daniel Fernandez Marques
Date: 28/11/2017

Copyright (c) 2017 OMG-Engine

Subject to the license described in LICENSE file
*/

#pragma once

#include <string>

namespace OMG_Engine {

	class Variant
	{

		enum Type
		{
			NIL, BOOL, CHAR, INT, FLOAT, POINTER, STRING
		};

		union Data
		{
			bool		  boolean_value;
			wchar_t     	 char_value;
			int		   	   	  int_value;
			float           float_value;
			void        * pointer_value;
			std::string *  string_value;
		};

		Type type;
		Data data;

	public:

		Variant() : type(NIL)
		{
		}

		Variant(bool v) : type(BOOL)
		{
			data.boolean_value = v;
		}

		Variant(wchar_t v) : type(CHAR)
		{
			data.char_value = v;
		}

		Variant(int v) : type(INT)
		{
			data.int_value = v;
		}

		Variant(float v) : type(FLOAT)
		{
			data.float_value = v;
		}

		Variant(const std::string & v) : type(STRING)
		{
			data.string_value = new std::string(v);
		}

		~Variant()
		{
			clear();
		}

		Variant & operator = (const nullptr_t &)
		{
			clear(NIL); return *this;
		}

		Variant & operator = (const float f)
		{
			clear(FLOAT);
			data.float_value = f;
			return *this;
		}

	public:

		void clear(Type t = NIL)
		{
			if (type == STRING) delete data.string_value;

			type = t;
		}

		bool is_nil() const { return type == NIL; }
		bool is_boolean() const { return type == BOOL; }
		bool is_char() const { return type == CHAR; }
		bool is_int() const { return type == INT; }
		bool is_float() const { return type == FLOAT; }
		bool is_string() const { return type == STRING; }

		int as_int() const
		{
			switch (type)
			{
			case INT: 	  return    (data.int_value);
			case FLOAT:   return int(data.float_value);
			case CHAR:    return int(data.char_value);
			case POINTER: return int(data.pointer_value);
			case STRING:  return std::stoi(*data.string_value);
			default: 	  return 0;
			}
		}

		int as_float() const
		{
			switch (type)
			{
			case INT: 	  return float(data.int_value);
			case FLOAT:   return      (data.float_value);
			case CHAR:    return float(data.char_value);
			case POINTER: return float(int(data.pointer_value));
			case STRING:  return std::stof(*data.string_value);
			default: 	  return 0;
			}
		}

		std::string as_string() const
		{
			switch (type)
			{
			case INT: 	  return std::to_string(data.int_value);
			case FLOAT:   return std::to_string(data.float_value);
			case CHAR:    return std::string(1, data.char_value);
			case POINTER: return std::to_string(size_t(data.pointer_value));
			case STRING:  return *data.string_value;
			default: 	  return std::string();
			}
		}

	};

}