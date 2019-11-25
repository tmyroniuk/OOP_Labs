#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include "timerclock.h"

#include <QPushButton>
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

    void on_lineEdit_textEdited(const QString &arg1);

private:
    TimerClock*& _res;
    Ui::TimerDialog *ui;
};

#endif // TIMERDIALOG_H
