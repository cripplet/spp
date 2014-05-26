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
