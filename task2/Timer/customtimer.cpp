#include "customtimer.h"
#include <stdexcept>
#include <QDebug>

CustomTimer::CustomTimer(const QTime &time, QObject *parent) : QObject(parent), timer(new QTimer), zeroTime(0, 0)
{
    setTime(time);
    QObject::connect(timer, &QTimer::timeout, this, &CustomTimer::updateTime);
}

CustomTimer::~CustomTimer()
{
    delete timer;
}

void CustomTimer::setTime(const QTime &time)
{
    if (time.isValid()) {
        if (!timer->isActive()) {
            this->time = time;
        } else
            throw std::logic_error("Stop the timer before setting the time!");
    } else
        throw std::invalid_argument("The time is invalid!");
}

QString CustomTimer::getTime()
{
    return time.toString("HH:mm:ss");
}

void CustomTimer::updateTime()
{
    if (time == zeroTime){
        emit timeout();
        stop();
    } else
        time = time.addSecs(-1);
}

void CustomTimer::start()
{
    if (time > zeroTime)
        timer->start(1000);
}

void CustomTimer::stop()
{
    timer->stop();
}

void CustomTimer::reset()
{
    stop();
    time = zeroTime;
}
