#include "alarmclock.h"
#include <QDebug>

AlarmClock::AlarmClock(QString name, QString note, QDateTime timeout_date, bool daily) :
    Timer(name, note, alarm_t),
    _daily(daily)
{
    _timeout_date = timeout_date;
    _timer->setTimerType(Qt::VeryCoarseTimer);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    start(timeout_date);
}

void AlarmClock::onTimeout(){
    if(_daily){
        _timeout_date = _timeout_date.addDays(1);
        start(_timeout_date);
    }
    Timer::onTimeout();
}

QString AlarmClock::displayedString(){
    return _timeout_date.time().toString("hh:mm:ss");
}

qint64 AlarmClock::asNum(){
    return _timeout_date.time().msecsSinceStartOfDay();
}

bool AlarmClock::repeated(){
    return _daily;
}
