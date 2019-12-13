#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "customtimer.h"
#include <vector>
#include <memory>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<std::shared_ptr<CustomTimer>> timers;

private slots:

    void on_pbAdd_clicked();

    void on_pbDelete_clicked();


signals:
};

#endif // MAINWINDOW_H
