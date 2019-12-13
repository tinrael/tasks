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

public:
    explicit CustomTimer(const QTime& time, QObject *parent = nullptr);
    virtual ~CustomTimer();
signals:

private slots:
    void updateTime();

public slots:   
};

#endif // CUSTOMTIMER_H
