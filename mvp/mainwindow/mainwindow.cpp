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

AutoChart *MainWindow::getChart()
{
    return ui->autoChart;
}

void MainWindow::on_pushButton_clicked()
{
    presenter->execute(ui->inputCmd->toPlainText());
}
