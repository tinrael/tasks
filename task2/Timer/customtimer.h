#ifndef CUSTOMTIMER_H
#define CUSTOMTIMER_H

#include <QObject>

class CustomTimer : public QObject
{
    Q_OBJECT
private:

public:
    explicit CustomTimer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CUSTOMTIMER_H
