#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbAdd_clicked()
{
    QString time = ui->teTimeSetup->text();
    timers.emplace_back(new CustomTimer(QTime().fromString(time, "HH:mm:ss")));
    ui->lwTimers->addItem(time);
}

void MainWindow::on_pbDelete_clicked()
{
    int currentRow = ui->lwTimers->currentRow();
    if (currentRow != -1) {
        QListWidgetItem *item =  ui->lwTimers->takeItem(currentRow);
        delete item;
        timers.erase(timers.begin() + currentRow);
    }
}
