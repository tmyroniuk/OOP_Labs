#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include "../Timers/timerclock.h"

#include <QPushButton>
#include <QDialog>

namespace Ui {
class TimerDialog;
}

/**
 * Class that provides dialog for timer creation.
 */
class TimerDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * Creates dialog to initialise given timer ptr.
     *
     * @param res result.
     * @param parent parent object.
     */
    TimerDialog(TimerClock*& res, QWidget *parent = nullptr);

    ~TimerDialog();

private slots:
    /**
     * Initialises timer when user has accepted.
     */
    void on_buttonBox_accepted();

    /**
     * Blocks ok button if timer name is empty.
     *
     * @param arg1 current name.
     */
    void on_lineEdit_textEdited(const QString &arg1);

private:
    TimerClock*& _res;
    Ui::TimerDialog *ui;
};

#endif // TIMERDIALOG_H
