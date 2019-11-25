#include "timer.h"

Timer::Timer(QString name, QString note, TimerType type) :
    _name(name),
    _note(note),
    _timer(new QTimer(this)),
    _type(type){}

void Timer::start(const std::chrono::milliseconds& duration){
    _timer->start(duration);
}

void Timer::start(const QDateTime& timeout_date){
    auto temp = QDateTime::currentDateTime();
    start(std::chrono::milliseconds (temp.msecsTo(timeout_date)));
}

QString Timer::getName(){
    return _name;
}

QString Timer::getNote(){
    return _note;
}

bool Timer::isActive(){
    return _timer->isActive();
}

Timer::TimerType Timer::type(){
    return _type;
}

QString Timer::displayedString(){
    auto temp = _timer -> remainingTimeAsDuration();
    QString res;

    long long num = std::chrono::floor<std::chrono::hours>(temp).count();
    res.append(QString::number(num).append(':'));
    temp -= std::chrono::hours(num);

    num = std::chrono::floor<std::chrono::minutes>(temp).count();
    res.append(QString::number(num).append(':'));
    temp -= std::chrono::minutes(num);

    res.append(QString::number(std::chrono::floor<std::chrono::seconds>(temp).count()));
    return res;
}

void Timer::onTimeout(){
    emit timeout(this);
}

Timer::~Timer(){
    delete _timer;
}
