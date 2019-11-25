#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QDateTime>
#include <chrono>

class Timer : public QObject {
    Q_OBJECT

public:
    enum TimerType{timer_t, alarm_t};

    Timer(QString name, QString note, TimerType type);
    QString getName();
    QString getNote();
    bool isActive();
    TimerType type();
    virtual QString displayedString();
    virtual ~Timer();

signals:
    void timeout(Timer*);

protected slots:
    virtual void onTimeout();

protected:
    void start(const std::chrono::milliseconds& duration);
    void start(const QDateTime& timeout_date);
    QString _name;
    QString _note;
    QTimer* _timer;
    TimerType _type;
};

#endif // TIMER_H
