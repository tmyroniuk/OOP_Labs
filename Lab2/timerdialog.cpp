#include "timerdialog.h"
#include "ui_timerdialog.h"

TimerDialog::TimerDialog(TimerClock*& res, QWidget *parent) :
    QDialog(parent),
    _res(res),
    ui(new Ui::TimerDialog)
{
    ui->setupUi(this);

    for(int i = 0; i<100; i++){
        ui->hourBox->addItem(QString((i<10)? "0" : "").append(QString::number(i)).append(" hours"));
    }
    for(int i = 0; i<60; i++){
        ui->minBox->addItem(QString((i<10)? "0" : "").append(QString::number(i)).append(" min"));
    }
    for(int i = 0; i<60; i++){
        ui->secBox->addItem(QString((i<10)? "0" : "").append(QString::number(i)).append(" sec"));
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

TimerDialog::~TimerDialog()
{
    delete ui;
}

void TimerDialog::on_buttonBox_accepted()
{
    int temp = (ui->hourBox->currentIndex()) * 3600000;
    temp += (ui->minBox->currentIndex()) * 60000;
    temp += (ui->secBox->currentIndex()) * 1000;
    _res = new TimerClock(ui->lineEdit->text(), ui->textEdit->toPlainText(), std::chrono::milliseconds(temp));
}

void TimerDialog::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1=="") ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    else ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}
