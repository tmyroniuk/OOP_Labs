#include "timerclock.h"

TimerClock::TimerClock(QString name, QString note, std::chrono::milliseconds duration) :
    Timer(name, note, timer_t)
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    start(duration);
}
