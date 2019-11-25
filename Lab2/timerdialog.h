#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include "timerclock.h"

#include <QDialog>

namespace Ui {
class TimerDialog;
}

class TimerDialog : public QDialog
{
    Q_OBJECT

public:
    TimerDialog(TimerClock*& res, QWidget *parent = nullptr);
    ~TimerDialog();

private slots:
    void on_buttonBox_accepted();

private:
    TimerClock*& _res;
    Ui::TimerDialog *ui;
};

#endif // TIMERDIALOG_H
