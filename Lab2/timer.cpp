#include "timer.h"

Timer::Timer(QObject* parent, QString name, QString note, const QDateTime& timeout_date) :
    _name(name),
    _note(note),
    _timer(new QTimer(parent)),
    _timeout_date(new QDateTime(timeout_date))
{}

void Timer::start(){
    qint64 time_val = QDateTime::currentDateTime().msecsTo(*_timeout_date);
    if(time_val < 0) time_val = 0;
    _timer -> start (time_val);
}
