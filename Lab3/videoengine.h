#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <QObject>

class VideoEngine : public QObject
{
    Q_OBJECT
public:
    explicit VideoEngine(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VIDEOENGINE_H
