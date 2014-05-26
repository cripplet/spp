#ifndef _SCHEDULINGENGINE_H
#define _SCHEDULINGENGINE_H

#include <memory>
#include <thread>
#include <vector>

#include "../base/engine.h"
#include "calendar.h"

/**
 * Holds in memory a list of calendars -- upon call to .ignite(), spawns one thread per calendar and runs the engines
 */

class SchedulingEngine : public Engine {
	public:
		SchedulingEngine();
		~SchedulingEngine();

		void ignite() override;
		void cycle() override;
		void shutdown() override;

		void add_calendar(const std::shared_ptr<Calendar>& calendar);

	private:
		std::vector<std::shared_ptr<Calendar>> calendars;
		std::vector<std::shared_ptr<std::thread>> threads;
};

#endif
