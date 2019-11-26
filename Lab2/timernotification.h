#ifndef TIMERNOTIFICATION_H
#define TIMERNOTIFICATION_H

#include <QDialog>
#include <QtMultimedia/QSound>

namespace Ui {
class TimerNotification;
}

/**
 * Class that provides sound and visual notification when timer
 * or alarm has timed out.
 */
class TimerNotification : public QDialog
{
    Q_OBJECT

public:
    /**
     * Creates notification.
     *
     * @param name timer name.
     * @param note timer note.
     * @param sound_file_name wav file with sound played.
     * @param parent parent object.
     */
    explicit TimerNotification(const QString& name, const QString& note, const QString& sound_file_name, QWidget *parent = nullptr);
    ~TimerNotification();

private slots:
    /**
     * Stops sound when user's accepted.
     */
    void on_buttonBox_accepted();

private:
    QSound* sound;
    Ui::TimerNotification *ui;
};

#endif // TIMERNOTIFICATION_H
