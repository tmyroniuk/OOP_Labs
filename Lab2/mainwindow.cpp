#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timerdialog.h"
#include "alarmdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _model = new ImprovisedModel(ui->listWidget);
    startTimer(1000, Qt::PreciseTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _model;
}

void MainWindow::on_add_timer_button_clicked()
{
    TimerClock* data = nullptr;
    TimerDialog dialog(data, this);
    dialog.exec();
    qDebug()<<((data)? "1" : "0");
    if(data) _model->addItem(data);
}

void MainWindow::on_add_alarm_button_clicked()
{
    AlarmClock* data = nullptr;
    AlarmDialog dialog(data, this);
    dialog.exec();
    qDebug()<<((data)? "1" : "0");
    if(data) _model->addItem(data);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow == -1) ui->label->clear();
    else ui->label->setText(_model->getInfo(currentRow));
}

void MainWindow::timerEvent(QTimerEvent*){
    timer_update();
}

void MainWindow::timer_update()
{
    if(ui->listWidget->currentRow() < 0) ui->timer_label->hide();
    else {
        ui->timer_label->setText(_model->getTimerString(ui->listWidget->currentRow()));
        ui->timer_label->show();
    }
}
