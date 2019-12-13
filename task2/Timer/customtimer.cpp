#include "customtimer.h"
#include <stdexcept>
#include <QDebug>

CustomTimer::CustomTimer(const QTime &time, QObject *parent) : QObject(parent), timer(new QTimer)
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

void CustomTimer::updateTime()
{
    time = time.addSecs(-1);
}
