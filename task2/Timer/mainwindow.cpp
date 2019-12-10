#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
}


void MainWindow::on_pbStart_clicked()
{
    ui->teTimeSetup->setEnabled(0);
    ui->pbStart->setEnabled(0);
    QString remainingTime = ui->teTimeSetup->text();
    ui->lblRemainingTime->setText(remainingTime);
    time = QTime::fromString(remainingTime, "HH:mm:ss");
    timer->start(1000);
}
