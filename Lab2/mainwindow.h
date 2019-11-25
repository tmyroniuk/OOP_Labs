#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "improvisedmodel.h"

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void timerEvent (QTimerEvent*);

private slots:
    void on_add_timer_button_clicked();

    void on_add_alarm_button_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void timer_update();

private:
    ImprovisedModel *_model;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
