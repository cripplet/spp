#include "engine.h"

Engine::Engine() {
	this->status = status_codes::UNINITIALIZED;
	this->signal = 1;
}

void Engine::ignite() { this->status = status_codes::INITIALIZED; }
void Engine::cycle() { this->status = status_codes::RUNNING; }
void Engine::shutdown() { this->status = STOPPED; }

int Engine::get_status() { return(this->status); }
int Engine::get_signal() { return(this->signal); }
