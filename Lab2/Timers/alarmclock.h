#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "timer.h"

/**
 * The timer which triggers in exact time.
 *
 * Can be created with QDateTime object as exact time it will timeout.
 * Has daily feature which restarts timer when timeout.
 */
class AlarmClock : public Timer{
public:
    /**
     * Creates Alarm Clock with given data which will timeout in exact time.
     *
     * @param name the name.
     * @param note the note given.
     * @param timeout_date exact time it will timeout.
     * @param daily if ti triggers every day.
     */
    AlarmClock(QString name, QString note, QDateTime timeout_date, bool daily);

    /**
     * Returns timer as string.
     *
     * Returns string with time it will trigger.
     *
     * @return time it triggers as string.
     */
    QString displayedString() override;

    /**
     * Returns if it is repeated daily.
     *
     * @return daily.
     */
    bool repeated() override;

    qint64 asNum() override;

protected slots:
    /**
     * Triggers timeout signal.
     */
    void onTimeout() override;
protected:
    QDateTime _timeout_date; //*Exact timeout date.
    bool _daily; //*If timer should be repeated.
};

#endif // ALARMCLOCK_H
