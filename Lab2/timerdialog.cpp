#include "timerdialog.h"
#include "ui_timerdialog.h"

TimerDialog::TimerDialog(TimerClock*& res, QWidget *parent) :
    QDialog(parent),
    _res(res),
    ui(new Ui::TimerDialog)
{
    ui->setupUi(this);
    ui->hourBox->addItem("hh");
    ui->minBox->addItem("mm");
    ui->secBox->addItem("ss");
    QStringList options;
    for(int i = 0; i<60; i++)
        options<<((i<10)? QString("0") : QString("")).append(QString::number(i));
    ui->secBox->addItems(options);
    ui->minBox->addItems(options);
    for(int i = 60; i<100; i++)
        options<<QString::number(i);
    ui->hourBox->addItems(options);
}

TimerDialog::~TimerDialog()
{
    delete ui;
}

void TimerDialog::on_buttonBox_accepted()
{
    if(! ui->hourBox->currentIndex() * ui->minBox->currentIndex() * ui->secBox->currentIndex() == 0){
        int temp = (ui->hourBox->currentIndex()-1) * 3600000;
        temp += (ui->minBox->currentIndex()-1) * 60000;
        temp += (ui->secBox->currentIndex()-1) * 1000;
        _res = new TimerClock(ui->lineEdit->text(), ui->textEdit->toPlainText(), std::chrono::milliseconds(temp));
    }
}
