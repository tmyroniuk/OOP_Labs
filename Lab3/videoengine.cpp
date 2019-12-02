#include "videoengine.h"

#include <algorithm>

VideoEngine::VideoEngine(QObject *parent) : QObject(parent)
{
    _player = new QMediaPlayer;
    connect(_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SIGNAL(statusChanged(QMediaPlayer::MediaStatus)));
    connect(_player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SIGNAL(stateChanged(QMediaPlayer::State)));
    _player->play();
}

void VideoEngine::setMedia(QUrl url){
    _player->setMedia(url);
}

void VideoEngine::forward()
{
    if(_player->mediaStatus()!=QMediaPlayer::NoMedia && _player->mediaStatus()!=QMediaPlayer::UnknownMediaStatus)
        _player->setPosition(std::min(_player->duration(), _player->position()+15000));
}

void VideoEngine::backward()
{
    if(_player->mediaStatus()!=QMediaPlayer::NoMedia && _player->mediaStatus()!=QMediaPlayer::UnknownMediaStatus)
        _player->setPosition(std::max(qint64(15000), _player->position())-15000);
}

void VideoEngine::playPause()
{
    if(_player->state()==QMediaPlayer::PlayingState) _player->pause();
    else _player->play();
}

void VideoEngine::setVideoOutput(QVideoWidget *vidget)
{
    _player->setVideoOutput(vidget);
}

VideoEngine::~VideoEngine(){
    delete _player;
}
