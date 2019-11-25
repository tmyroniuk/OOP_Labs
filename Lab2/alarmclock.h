#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "timer.h"

class AlarmClock : public Timer{
public:
    AlarmClock(QString name, QString note, QDateTime timeout_date, bool daily);
    QString displayedString() override;
protected slots:
    void onTimeout() override;
protected:
    QDateTime _timeout_date;
    bool _daily;
};

#endif // ALARMCLOCK_H
