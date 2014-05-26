spp
===

Scheduler Plus Plus -- basic C++ scheduler

Usage --

```
/* examples/spp.cc */

// std::shared_ptr
#include <memory>

#include "../scheduling/scheduling.h"
#include "../scheduling/calendar.h"

int main() {
    // an engine to be run in the background during execution
    std::shared_ptr<Engine> e (new Engine());

    // schedule the engine to be run at 60Hz
    std::shared_ptr<Calendar> cal_e (new Calendar(60, e));

    // create a schedular
    std::shared_ptr<SchedulingEngine> s (new SchedulingEngine());

    s->add_calendar(cal_e);

    // start the scheduler
    s->ignite();

    // placeholder function for future expansion
    s->cycle();

    // signal to the scheduler to call e->shutdown()
    s->shutdown();

    return(0);
}
```

Compiler flags -- `-std=c++11 -lpthreads`

SPP is designed to be an easy-to-use schedular. Scheduling in SPP revolves around the use of *engines* -- that is, self-contained design abstractions which should be run at a constant frequency.

For example -- we would want to run certain graphics-related functions at the screen refresh rate (e.g. 60 Hz). In order to do this, we simply create an `class GraphicsEngine : public Engine { ... };` class that overrides the `Engine::cycle()` function. We then load the graphics engine into our schedular as per the above syntax and start up the schedular.

Bonus: a Makefile!

```
# example/Makefile

CC=g++

# yadda yadda yadda beware -O3 optimizations and threading
CFLAGS=-Wall -Werror -O3 -std=c++11

LIBS=-lm -lpthread

# remember to add all sources from subdirectories as well here
SOURCES=*cc ../base/*cc ../scheduling/*cc

OBJECTS=$(SOURCES:.cc=.o)

EXECUTABLE=spp.app

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

# remember to run unit tests
test: clean $(EXECUTABLE)
	./$(EXECUTABLE) --test

clean:
	rm -f $(EXECUTABLE) *.o
```
