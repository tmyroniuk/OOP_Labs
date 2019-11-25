#ifndef TIMERCLOCK_H
#define TIMERCLOCK_H

#include "timer.h"

class TimerClock : public Timer{
public:
    TimerClock(QString name, QString note, std::chrono::milliseconds duration);
};

#endif // TIMERCLOCK_H
