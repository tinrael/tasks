#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMediaPlaylist>
#include <QMediaPlayer>

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
    Dialog *notification;
    QTimer *timer;
    QTime time;
    QTime nullTime;
    QTime timeFrame; // if QTime time less than or equal to QTime timeFrame, the countdown timer becomes red
    QMediaPlayer* player;
    QMediaPlaylist *playlist;

    bool isCountdownTimerRed;

    void addSounds();

private slots:
    void updateRemainingTime();
    void openNotification();
    void stopPlayingSound();

    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void on_pbReset_clicked();  

signals:
    void timeIsOver();
};
#endif // MAINWINDOW_H
