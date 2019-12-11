#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), nullTime(0, 0, 0), timeFrame(0, 0, 15), isCountdownTimerRed(false)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::updateRemainingTime);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
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

        ui->lblRemainingTime->setStyleSheet("");
        isCountdownTimerRed = false;

        ui->teTimeSetup->setEnabled(1);
        ui->pbStart->setEnabled(1);
        ui->pbStop->setEnabled(0);
    }
}

/* TODO: Each time after stopping the countdown, the new timeout interval is 1000,
 * but the first timeout interval must be timer->remainingTime(), getting after the stop button clicked.
 */
void MainWindow::on_pbStart_clicked()
{
    ui->pbStart->setText("Start");
    ui->pbStart->setEnabled(0);
    ui->pbStop->setEnabled(1);

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

}
