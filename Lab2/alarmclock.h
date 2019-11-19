#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "timer.h"

class AlarmClock : public Timer
{
public:
    AlarmClock(QObject* parent, QString name, QString note, const QDateTime& timeout_date);
    void start();

};

#endif // ALARMCLOCK_H
