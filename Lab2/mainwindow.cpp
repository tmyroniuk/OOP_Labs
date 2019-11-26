#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Dialog/timerdialog.h"
#include "Dialog/alarmdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _model = new ImprovisedModel(ui->listWidget);
    connect(_model, SIGNAL(timeout(Timer*)), this, SLOT(timerNotify(Timer*)));
    _model->load();

    ui->comboBox->addItem("All");
    ui->comboBox->addItem("Timers");
    ui->comboBox->addItem("Alarms");

    QTimer::singleShot(1000 - QTime::currentTime().msec(), this, SLOT(timer_start()));
}

MainWindow::~MainWindow()
{
    delete ui;
    _model->save();
    delete _model;
}

void MainWindow::on_add_timer_button_clicked()
{
    TimerClock* data = nullptr;
    TimerDialog dialog(data, this);
    dialog.exec();
    if(data) _model->addItem(data);
}

void MainWindow::on_add_alarm_button_clicked()
{
    AlarmClock* data = nullptr;
    AlarmDialog dialog(data, this);
    dialog.exec();
    if(data) _model->addItem(data);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow == -1) ui->label->clear();
    else ui->label->setText(_model->getInfo(currentRow));
    timerEvent(nullptr);
}

void MainWindow::timerEvent(QTimerEvent*){
    if(ui->listWidget->currentRow() == -1) ui->timer_label->clear();
    else ui->timer_label->setText(_model->getTimerString(ui->listWidget->currentRow()));
}

void MainWindow::timer_start()
{
    startTimer(1000, Qt::PreciseTimer);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        _model->shownItems(Timer::other_t);
        break;
    case 1:
        _model->shownItems(Timer::timer_t);
        break;
    case 2:
        _model->shownItems(Timer::alarm_t);
        break;
    }
}

void MainWindow::timerNotify(Timer* timer){
    if(! ui->checkBox->isChecked()){
        QString file;
        if(timer->type()==Timer::timer_t) file = "C:/Projects/OOP_Labs/Lab2/Sounds/Alarm01.wav";
        else file = "C:/Projects/OOP_Labs/Lab2/Sounds/Ring07.wav";
        TimerNotification msg(timer->getName(), timer->getNote(), file, this);
        msg.exec();
    }
    _model->removeItem(timer);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->listWidget->currentRow()>=0) _model->removeItem(ui->listWidget->currentRow());
}
