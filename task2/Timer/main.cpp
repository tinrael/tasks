#include "mainwindow.h"
#include "customtimer.h"

#include <QApplication>
#include <QStyleFactory>
#include <QTime>

int main(int argc, char *argv[])
{
    CustomTimer timer(QTime(5, 5));

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
