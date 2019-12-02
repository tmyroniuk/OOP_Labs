#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "videoengine.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void interface_setup();

    ~MainWindow();

    void setImg();

    void removeImg();

private slots:
    void videoStateChanged(QMediaPlayer::State state);

    void videoStatusChanged(QMediaPlayer::MediaStatus status);

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    VideoEngine* _engine;
    QVideoWidget* _video_widget;
    QPushButton* _play_pause_button;
    QPushButton* _backward_button;
    QPushButton* _forward_button;
    QSlider* _time_bar;
};
#endif // MAINWINDOW_H
