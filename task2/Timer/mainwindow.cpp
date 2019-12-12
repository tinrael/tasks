#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), nullTime(0, 0, 0), timeFrame(0, 0, 15), player(new QMediaPlayer)
    , playlist(new QMediaPlaylist), isCountdownTimerRed(false)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    notification = new Dialog(this);

    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::updateRemainingTime);
    QObject::connect(this, &MainWindow::timeIsOver, this, &MainWindow::openNotification);
    QObject::connect(notification, &Dialog::finished, this, &MainWindow::stopPlayingSound);

    addSounds();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete notification;
    delete timer;
    delete player;
    delete playlist;
}

// TODO: relative path, not absolute.
void MainWindow::addSounds()
{
    playlist->addMedia(QUrl("C:/Users/TimurKrasnopir/Desktop/tasks/task2/Timer/sounds/calm.mp3"));
    playlist->addMedia(QUrl("C:/Users/TimurKrasnopir/Desktop/tasks/task2/Timer/sounds/cuckoo.mp3"));
    playlist->addMedia(QUrl("C:/Users/TimurKrasnopir/Desktop/tasks/task2/Timer/sounds/hurry.mp3"));
    playlist->addMedia(QUrl("C:/Users/TimurKrasnopir/Desktop/tasks/task2/Timer/sounds/signal.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    player->setPlaylist(playlist);
    player->setVolume(75);

    ui->cbSounds->addItem("Calm");
    ui->cbSounds->addItem("Cuckoo");
    ui->cbSounds->addItem("Hurry");
    ui->cbSounds->addItem("Signal");
}

void MainWindow::updateRemainingTime()
{
    time = time.addSecs(-1);
    ui->lblRemainingTime->setText(time.toString("HH:mm:ss"));

    if (time <= timeFrame && !isCountdownTimerRed) {
        ui->lblRemainingTime->setStyleSheet("QLabel {color: red;}");
        isCountdownTimerRed = true;
    }

    if (time == nullTime) {
        timer->stop();

        playlist->setCurrentIndex(ui->cbSounds->currentIndex());
        player->play();

        emit timeIsOver();

        ui->lblRemainingTime->setStyleSheet("");
        isCountdownTimerRed = false;

        ui->teTimeSetup->setEnabled(1);
        ui->pbStart->setEnabled(1);
        ui->pbStop->setEnabled(0);
        ui->cbSounds->setEnabled(1);
    }
}

void MainWindow::openNotification()
{
    notification->open();
}

void MainWindow::stopPlayingSound()
{
    player->stop();
}

/* TODO: Each time after stopping the countdown, the new timeout interval is 1000,
 * but the first timeout interval must be timer->remainingTime(), getting after the stop button clicked.
 */
void MainWindow::on_pbStart_clicked()
{
    ui->pbStart->setText("Start");
    ui->pbStart->setEnabled(0);
    ui->pbStop->setEnabled(1);
    ui->cbSounds->setEnabled(0);

   /* Only if the time editor is enabled, the new countdown needs to set up.
    * If the editor is disabled, the stop button has pressed before,
    * so the countdown should continue the work.
    */
    if (ui->teTimeSetup->isEnabled()) {
        ui->teTimeSetup->setEnabled(0);

        QString remainingTime = ui->teTimeSetup->text();
        ui->lblRemainingTime->setText(remainingTime);
        time = QTime::fromString(remainingTime, "HH:mm:ss");
        if (time <= timeFrame){
            ui->lblRemainingTime->setStyleSheet("QLabel {color: red;}");
            isCountdownTimerRed = true;
        }
    }

    timer->start(1000);
}

void MainWindow::on_pbStop_clicked()
{
    timer->stop();

    ui->pbStart->setText("Continue");
    ui->pbStart->setEnabled(1);
    ui->pbStop->setEnabled(0);
}

void MainWindow::on_pbReset_clicked()
{
    timer->stop();
    time = nullTime;

    ui->lblRemainingTime->setText(nullTime.toString());
    ui->lblRemainingTime->setStyleSheet("");
    isCountdownTimerRed = false;

    ui->pbStart->setText("Start");
    ui->teTimeSetup->setEnabled(1);
    ui->pbStart->setEnabled(1);
    ui->pbStop->setEnabled(0);
    ui->cbSounds->setEnabled(1);
}
