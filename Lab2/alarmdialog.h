#ifndef ALARMDIALOG_H
#define ALARMDIALOG_H

#include "alarmclock.h"

#include <QPushButton>
#include <QDialog>

namespace Ui {
class AlarmDialog;
}

class AlarmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmDialog(AlarmClock*& res, QWidget *parent = nullptr);
    ~AlarmDialog();

private slots:
    void on_buttonBox_accepted();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::AlarmDialog *ui;
    AlarmClock*& _res;
};

#endif // ALARMDIALOG_H
