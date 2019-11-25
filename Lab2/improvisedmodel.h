#ifndef IMPROVISEDMODEL_H
#define IMPROVISEDMODEL_H

#include <timerclock.h>
#include <alarmclock.h>

#include <QList>
#include <QListWidget>
#include <QDebug>

class ImprovisedModel: public QObject{
    Q_OBJECT

public:
    ImprovisedModel(QListWidget* widget);
    void addItem(Timer* item);
    void removeItem(int id);
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
