
#pragma once

#include <unordered_map>
#include <Variant.hpp>

namespace OMG_Engine {

	/// ATTENTION: First 1000 ids are engine reserved
	enum Message_Id
	{
		// TEST
		MSG_PLAY_AUDIO = 100,
		MSG_PLAY_AUDIO_2 = 102,

		MSG_TRIGGER_EXPLOSION = 200,
		MSG_TRIGGER_TRAP = 201,
	};

	class Message
	{

		int action_id;

		typedef std::unordered_map< int, Variant > Paramer_List;

		Paramer_List parameters;

	public:

		Message(int id) : action_id(id)
		{
		}

		Variant & operator [] (int key)
		{
			return parameters.at(key); //[key];
		}

		const Variant & operator [] (int key) const
		{
			return parameters.at(key);
		}

		bool operator == (const Message & other) const
		{
			return this->action_id == other.action_id;
		}

		bool operator != (const Message & other) const
		{
			return this->action_id != other.action_id;
		}

		operator int() const
		{
			return action_id;
		}

	};

}

/* ----------------------------------------------------

#include "Messages.hpp"

Message m(MSG_TRIGGER_TRAP));


if (MSG_TRIGGER_TRAP == m)
{
}


constexpr int hash(const char * s)
{
	int hash_value = 0;
	
	while (*s)
	{
		hash_value *= *(s++);
	}
	
	return hash_value;
}


*/










