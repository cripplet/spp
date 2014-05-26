#ifndef _CALENDAR_H
#define _CALENDAR_H

#include <memory>

#include "../base/engine.h"

/**
 * Task abstraction layer for the scheduler -- each calendar references an engine and the frequency at which the engine should operate at
 */

class Calendar {
	public:
		// cf. http://bit.ly/1nK6RIb
		Calendar(float frequency, const std::shared_ptr<Engine>& engine);
		~Calendar();

		void run();
		void finish();

	public:
		float timestep;			// time in seconds between each step
		std::shared_ptr<Engine> engine;

		/**
		 * run engine->cycle() until outside signal is received
		 */
		int signal;
};

#endif
