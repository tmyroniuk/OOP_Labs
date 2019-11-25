#ifndef TIMERCLOCK_H
#define TIMERCLOCK_H

#include "timer.h"

/**
 * Class that provides timer which timeouts after given amount of
 * time.
 */
class TimerClock : public Timer{
public:
    /**
     * Creates timer with given name, note and time until timeout.
     *
     * @param name name.
     * @param note user's note.
     * @param duration time until timeout.
     */
    TimerClock(QString name, QString note, std::chrono::milliseconds duration);
};

#endif // TIMERCLOCK_H
