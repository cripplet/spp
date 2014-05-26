spp
===

Scheduler Plus Plus -- basic C++ scheduler

Usage --

```
#include <memory>		// std::shared_ptr

#include "scheduling.h"
#include "calendar.h"

int main() {
	std::shared_ptr<Engine> e (new Engine());			// an engine to be run in the background during execution
	std::shared_ptr<Calendar> cal_e (new Calendar(60, p));		// schedule the engine to be run at 60Hz
	std::shared_ptr<SchedulingEngine> s (new SchedulingEngine());	// create a schedular
	s->add_calendar(cal_t);

	s->ignite();							// start the schedular
	s->cycle();							// placeholder function for future expansion
	s->shutdown();							// signal to the schedular to call e->shutdown()

	return(0);
}

```

Compiler -- `-std=c++11 -lpthreads`

SPP is designed to be an easy-to-use schedular. Scheduling in SPP revolves around the use of *engines* -- that is, self-contained design abstractions which should be run at a constant frequency.

For example -- we would want to run certain graphics-related functions at the screen refresh rate (e.g. 60 Hz). In order to do this, we simply create an `class GraphicsEngine : public Engine { ... };` class that overrides the `Engine::cycle()` function. We then load the graphics engine into our schedular as per the above syntax and start up the schedular.

-- M
