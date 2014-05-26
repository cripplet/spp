#ifndef _CALENDAR_H
#define _CALENDAR_H

#include <memory>

#include "../base/engine.h"

class Calendar {
	public:
		Calendar(float frequency, const std::shared_ptr<Engine>& engine);
		~Calendar();

		void run();
		void finish();

	public:
		float timestep;			// time in seconds between each step
		std::shared_ptr<Engine> engine;

		// run engine.cycle() until outside signal is received
		int signal;
};

#endif
