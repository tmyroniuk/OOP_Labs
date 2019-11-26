#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QDateTime>
#include <chrono>

/**
 * Class that provides interface for different timers.
 *
 * Contains timer, name, note, can save itself.
 */
class Timer : public QObject {
    Q_OBJECT

public:
    enum TimerType{other_t, timer_t, alarm_t};

    /**
     * Creates timer with name, note and given type.
     *
     * @param name name.
     * @param note user note.
     * @param type type from enum.
     */
    Timer(QString name, QString note, TimerType type);

    /**
     * Returns timer name.
     * @return name.
     */
    QString getName();

    /**
     * Returns timer note.
     * @return note.
     */
    QString getNote();

    /**
     * Returns if timer is repeated.
     * (false by default).
     *
     * @return false.
     */
    virtual bool repeated();

    /**
     * Returns timer type.
     *
     * @return timer type.
     */
    TimerType type();

    /**
     * Returns timer as string to be shown.
     *
     * @return timer as string.
     */
    virtual QString displayedString();

    virtual int asNum();

    virtual ~Timer();
signals:
    /**
     * Triggers when timer time is out.
     */
    void timeout(Timer*);

protected slots:
    /**
     * Does actions when timer timeout.
     */
    virtual void onTimeout();

protected:
    /**
     * Starts timer for given amount of time.
     *
     * @param duration timer time.
     */
    void start(const std::chrono::milliseconds& duration);

    /**
     * Starts timer which will end at given time point.
     *
     * @param timeout_date the timeout point.
     */
    void start(const QDateTime& timeout_date);


    QString _name;
    QString _note;

    /**
     * The Qt timer class which is used for time measuring.
     */
    QTimer* _timer;
    TimerType _type;
};

#endif // TIMER_H
