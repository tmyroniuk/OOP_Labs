#include "alarmdialog.h"
#include "ui_alarmdialog.h"

AlarmDialog::AlarmDialog(AlarmClock*& res, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDialog),
    _res(res)
{
    ui->setupUi(this);

    for(int i = 0; i<24; i++){
        ui->hourBox->addItem(QString((i<10)? "0" : "").append(QString::number(i)).append(" hours"));
    }
    for(int i = 0; i<60; i++){
        ui->minBox->addItem(QString((i<10)? "0" : "").append(QString::number(i)).append(" min"));
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

AlarmDialog::~AlarmDialog()
{
    delete ui;
}

void AlarmDialog::on_buttonBox_accepted()
{
    QDateTime temp;
    temp.setDate(QDate::currentDate());
    temp.setTime(QTime(ui->hourBox->currentIndex(), ui->minBox->currentIndex(), 0));
    if (temp<=QDateTime::currentDateTime()) temp = temp.addDays(1);
    _res = new AlarmClock(ui->lineEdit->text(), ui->textEdit->toPlainText(), temp, ui->checkBox->isChecked());
}

void AlarmDialog::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1=="") ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    else ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}
