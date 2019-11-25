#ifndef IMPROVISEDMODEL_H
#define IMPROVISEDMODEL_H

#include <timerclock.h>
#include <alarmclock.h>

#include <QList>
#include <QListWidget>

class ImprovisedModel: public QObject{
    Q_OBJECT

public:
    ImprovisedModel(QListWidget* widget);
    void addItem(Timer* timer);
    void removeItem(int id);
    void shownItems(Timer::TimerType type);
    QString getTimerString(int id);
    QString getInfo(int id);
    ~ImprovisedModel();
private slots:
    void onTimerTimeout(Timer* timer);
private:
    QListWidget* _widget;
    QList<Timer*>* _list;
};

#endif // IMPROVISEDMODEL_H
