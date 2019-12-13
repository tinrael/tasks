#ifndef CUSTOMTIMER_H
#define CUSTOMTIMER_H

#include <QObject>
#include <QTimer>
#include <QTime>

class CustomTimer : public QObject
{
    Q_OBJECT
private:
    QTimer *timer;
    QTime time;
    QTime zeroTime;

public:
    explicit CustomTimer(const QTime& time, QObject *parent = nullptr);
    virtual ~CustomTimer();

signals:
    void timeout();

private slots:
    void updateTime();

public slots:
    void start();
    void stop();
    void reset();
};

#endif // CUSTOMTIMER_H
