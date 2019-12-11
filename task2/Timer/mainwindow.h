#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

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
    QTimer *timer;
    QTime time;
    QTime nullTime;

private slots:
    void updateRemainingTime();
    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void on_pbReset_clicked();
};
#endif // MAINWINDOW_H
