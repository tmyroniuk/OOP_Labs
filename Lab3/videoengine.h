#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <QObject>
#include <QMediaPlayer>
#include <QVideoWidget>

class VideoEngine : public QObject
{
    Q_OBJECT
public:
    explicit VideoEngine(QObject *parent = nullptr);

    ~VideoEngine();

    void setVideoOutput(QVideoWidget* vidget);

    void setMedia(QUrl url);

public slots:
    void playPause();

    void forward();

    void backward();

signals:
    void stateChanged(QMediaPlayer::State);

    void statusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer* _player;
};

#endif // VIDEOENGINE_H
