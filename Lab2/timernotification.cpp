#include "timernotification.h"
#include "ui_timernotification.h"

TimerNotification::TimerNotification(const QString& name,  const QString& note, const QString& sound_file_name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerNotification)
{
    ui->setupUi(this);
    ui->label_name->setText(name);
    ui->label->setText(note);
    sound = new QSound(sound_file_name);
    sound->setLoops(1);
    sound->play();
}

TimerNotification::~TimerNotification()
{
    delete ui;
    delete sound;
}

void TimerNotification::on_buttonBox_accepted()
{
    sound->stop();
}
