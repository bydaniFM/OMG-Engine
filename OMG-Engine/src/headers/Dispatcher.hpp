
#pragma once

#include <Message.hpp>

namespace OMG_Engine {

	class Dispatcher
	{
	public:

		struct Listener
		{
			virtual     ~Listener() {}
			virtual void handle(const Message &) = 0;
		};

	private:

		typedef std::unordered_multimap< int, Listener * > Listener_Map;

		Listener_Map listeners;

	public:

		void add_listener(int message_id, Listener & listener)
		{
			listeners.insert(std::pair<int, Listener *>(message_id, & listener));
		}

		void remove_listener(Listener & listener)
		{
			/*Listener_Map::iterator item = ...BUSCAR EL VALOR listener EFICIENTEMENTE;

			if (item != listeners.end())
			{
				listeners.erase(item);
			}*/
		}

		void send(const Message & message)
		{
			if (listeners.count(message))
			{
				Listener_Map::iterator it;
				Listener_Map::iterator itlow = listeners.lower_bound(message);
				Listener_Map::iterator itup = listeners.upper_bound(message);

				for (it = itlow; it != itup; ++it)
					it->second->handle(message);

			}
		}

	};


}

