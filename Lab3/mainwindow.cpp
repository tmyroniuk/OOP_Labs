#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _engine = new VideoEngine(this);
    interface_setup();
    _engine->setVideoOutput(_video_widget);

    connect(_engine, SIGNAL(statusChanged(QMediaPlayer::MediaStatus)), this, SLOT(videoStatusChanged(QMediaPlayer::MediaStatus)));
    connect(_engine, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(videoStateChanged(QMediaPlayer::State)));
    connect(_play_pause_button, SIGNAL(clicked()),_engine, SLOT(playPause()));
    connect(_forward_button, SIGNAL(clicked()),_engine, SLOT(forward()));
    connect(_backward_button, SIGNAL(clicked()),_engine, SLOT(backward()));
}

void MainWindow::interface_setup()
{
    _backward_button = new QPushButton(this);
    _play_pause_button = new QPushButton(this);
    _forward_button = new QPushButton(this);
    _time_bar = new QSlider(Qt::Horizontal, this);
    _video_widget = new QVideoWidget(this);

    ui->gridLayout->addWidget(_video_widget,0,0,1,4);
    ui->gridLayout->addWidget(_backward_button,1,0);
    ui->gridLayout->addWidget(_play_pause_button,1,1);
    ui->gridLayout->addWidget(_forward_button,1,2);
    ui->gridLayout->addWidget(_time_bar,1,3);

    _backward_button->setMinimumSize(QSize(30, 30));
    _backward_button->setMaximumSize(QSize(30, 30));
    _forward_button->setMinimumSize(QSize(30, 30));
    _forward_button->setMaximumSize(QSize(30, 30));
    _play_pause_button->setMinimumSize(QSize(30, 30));
    _play_pause_button->setMaximumSize(QSize(30, 30));
    _forward_button->setIconSize(QSize(30,30));
    _play_pause_button->setIconSize(QSize(30,30));
    _backward_button->setIconSize(QSize(30,30));
    _play_pause_button->setIcon(QIcon(":/ico/play-icon.png"));

    _time_bar->setMinimum(0);
    _time_bar->setMaximum(100);
    _video_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _video_widget->setAspectRatioMode(Qt::KeepAspectRatio);
    setImg();

    _video_widget->show();
    _time_bar->show();
    _forward_button->show();
    _backward_button->show();
    _play_pause_button->show();
}

MainWindow::~MainWindow()
{
    delete _video_widget;

    delete ui;
}

void MainWindow::videoStateChanged(QMediaPlayer::State state)
{
    if(state==QMediaPlayer::PlayingState) _play_pause_button->setIcon(QIcon(":/ico/pause-icon.png"));
    else _play_pause_button->setIcon(QIcon(":/ico/play-icon.png"));
}

void MainWindow::setImg(){
    _video_widget->resize(QSize(357, 240));
    ui->gridLayout->removeWidget(ui->gridLayout->itemAtPosition(0,0)->widget());
    auto lbl = new QLabel(this);
    lbl->resize(QSize(357, 240));
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setPixmap(QPixmap(":/img/video-icon-free.jpg").scaled(lbl->size(), Qt::KeepAspectRatio));
    ui->gridLayout->addWidget(lbl,0,0,1,4);
}

void MainWindow::removeImg(){
    auto temp = ui->gridLayout->itemAtPosition(0,0)->widget();
    if(temp == _video_widget) return;
    ui->gridLayout->removeWidget(temp);
    delete temp;
    ui->gridLayout->addWidget(_video_widget,0,0,1,4);
    _video_widget->show();
}

void MainWindow::videoStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status==0 || status==1 || status==7 || status==8){
        setImg();
    }
    else {
        removeImg();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "%USERPROFILE%", tr("VIDEO Files (*.mp4 *.avi *.mkv)"));
    _engine->setMedia(QUrl::fromLocalFile(file_name));
}
