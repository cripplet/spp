#include "engine.h"

Engine::Engine() {
	this->status = status_code::UNINITIALIZED;
	this->signal = 1;
}
Engine::~Engine() {}

void Engine::ignite() { this->status = status_code::INITIALIZED; }
void Engine::cycle() { this->status = status_code::RUNNING; }
void Engine::shutdown() { this->status = STOPPED; }

int Engine::get_status() { return(this->status); }
int Engine::get_signal() { return(this->signal); }
