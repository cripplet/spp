#include <algorithm>

#include "scheduling.h"

SchedulingEngine::SchedulingEngine() : Engine() {}
SchedulingEngine::~SchedulingEngine() {}

void SchedulingEngine::add_calendar(const std::shared_ptr<Calendar>& calendar) {
	if(this->get_status() < status_code::RUNNING) {
		this->calendars.push_back(calendar);
	}
}

void SchedulingEngine::ignite() {
	for(std::vector<std::shared_ptr<Calendar>>::iterator i = this->calendars.begin(); i != this->calendars.end(); ++i) {
		std::shared_ptr<std::thread> t (new std::thread(&Calendar::run, *i));
		this->threads.push_back(t);
	}
	Engine::ignite();
}

void SchedulingEngine::cycle() {
	Engine::cycle();
}

void SchedulingEngine::shutdown() {
	this->signal = 0;
	for(uint32_t i = 0; i < this->calendars.size(); i++) {
		this->calendars.at(i)->finish();
	}
	for(uint32_t i = 0; i < this->calendars.size(); i++) {
		this->threads.at(i)->join();
	}
	Engine::shutdown();
}
