#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conf/lang.h"
#include "mainpresenter.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"initing...";
    ui->setupUi(this);

    this->resize(800, 500);

    setPresenter(new MainPresenter(this));
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

