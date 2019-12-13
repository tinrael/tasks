#include "customtimer.h"
#include <stdexcept>
#include <QDebug>

CustomTimer::CustomTimer(const QTime &time, QObject *parent) : QObject(parent), timer(new QTimer), zeroTime(0, 0)
{
    if (time.isValid()){
        this->time = time;
        QObject::connect(timer, &QTimer::timeout, this, &CustomTimer::updateTime);
    }
    else
        throw std::invalid_argument("The time is invalid!");
}

CustomTimer::~CustomTimer()
{
    delete timer;
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
