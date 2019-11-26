#ifndef IMPROVISEDMODEL_H
#define IMPROVISEDMODEL_H

#include "Timers/timerclock.h"
#include "Timers/alarmclock.h"

#include <QList>
#include <QListWidget>
#include <QTextStream>

/**
 * Class which acts as model between QListWidget and QList of Timers.
 */
class ImprovisedModel: public QObject{
    Q_OBJECT

public:
    /**
     * Creates model for given widget.
     *
     * @param widget the widget.
     */
    ImprovisedModel(QListWidget* widget);

    /**
     * Adds new timer to the list and the widget.
     *
     * @param timer new timer.
     */
    void addItem(Timer* timer);

    /**
     * Removes timer with given id from the list and widget.
     *
     * @param id timer id in list.
     */
    void removeItem(int id);

    /**
     * Removes timer with given id from the list if it is not
     * daily alarm.
     *
     * @param timer the timer removed.
     */
    void removeItem(Timer* timer);

    /**
     * Hides timers of types different from given.
     *
     * If other_t is given, shows all of them.
     *
     * @param type type of visible timers.
     */
    void shownItems(Timer::TimerType type);

    /**
     * Returns timer with id as string.
     *
     * @param id timer id in list.
     * @return timer as string.
     */
    QString getTimerString(int id);

    /**
     * Returns timer name and note as html string.
     *
     * @param id timer id in list.
     * @return timer as string.
     */
    QString getInfo(int id);

    /**
     * Saves timers in list to the save.txt file.
     */
    void save();

    /**
     * Loads timers list from saves.txt file.
     */
    void load();

    ~ImprovisedModel();
signals:
    /**
     * Triggers when one of timers timeout.
     */
    void timeout(Timer*);
private:
    QListWidget* _widget;
    QList<Timer*>* _list;
};

#endif // IMPROVISEDMODEL_H
