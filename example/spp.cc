// std::shared_ptr
#include <memory>

// sleep()
#include <unistd.h>

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

    // start the scheduler -- calls e->ignite() and starts e->cycle()
    s->ignite();

    // placeholder for future expansion
    // should wait for SIG_INT (or similar) to exit
    // cf. http://bit.ly/1nqOnyd
    s->cycle();

    // in the meantime, using this
    sleep(1);

    // signal to the scheduler to call e->shutdown()
    s->shutdown();

    return(0);
}
