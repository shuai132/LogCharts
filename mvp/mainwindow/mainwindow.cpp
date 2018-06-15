#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conf/lang.h"
#include "mainpresenter.h"
#include <cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"initing...";
    ui->setupUi(this);

    setPresenter(new MainPresenter(this));

    const int pointNum = 100;
    ui->autoChart->setCachedLength(pointNum);
    for (int i=0; i<pointNum; i++) {
        ui->autoChart->addValue(sin((float)i / pointNum * 2 * M_PI * 2));
    }
}

MainWindow::~MainWindow()
{
    delete presenter;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug()<<event;
}

void MainWindow::setConState(bool isConnected)
{
    ui->lbConState->setText(isConnected ? Lang::connected : Lang::notconnected);
}

