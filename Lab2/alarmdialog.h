#ifndef ALARMDIALOG_H
#define ALARMDIALOG_H

#include "Timers/alarmclock.h"

#include <QPushButton>
#include <QDialog>

namespace Ui {
class AlarmDialog;
}

/**
 * Class which provides dialog to create Alarm.
 */
class AlarmDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * Creates alarm dialog.
     *
     * @param res result of the dialog.
     * @param parent parent object.
     */
    AlarmDialog(AlarmClock*& res, QWidget *parent = nullptr);

    /**
     * Default destructor.
     *
     * Does not delete res ptr.
     */
    ~AlarmDialog();

private slots:
    /**
     * Gives value to res ptr.
     *
     * The value given is pointer to alarm clock
     * object.
     */
    void on_buttonBox_accepted();

    /**
     * Blocks ok button if name is empty.
     *
     * @param arg1 current name.
     */
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::AlarmDialog *ui;
    AlarmClock*& _res;
};

#endif // ALARMDIALOG_H
