#ifndef TIMER_H
#define TIMER_H

#include <Qtimer>
#include <QDateTime>

class Timer
{
public:
    Timer(QObject* parent, QString name, QString note, const QDateTime& timeout_date);
    virtual void start();
    virtual QString timeoutIn() = 0;
    virtual ~Timer();
private:
    QString _name;
    QString _note;
    QTimer* _timer;
    QDateTime* _timeout_date;
};

#endif // TIMER_H
