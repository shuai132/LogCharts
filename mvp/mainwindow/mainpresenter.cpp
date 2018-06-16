#include "mainpresenter.h"
#include "mainmodel.h"
#include "conf/config.h"
#include <QDebug>

#include <thread>
#include <cmath>
MainPresenter::MainPresenter(MainContract::View* view)
    :Presenter(view)
{
    this->model = new MainModel();

    serialPort = new SerialPort(model->getConfigedBaudRate());

    connect(serialPort, SIGNAL(onConStateChanged(bool)), this, SLOT(onConStateChanged(bool)));

    connect(serialPort, SIGNAL(onData(QByteArray)), this, SLOT(onData(QByteArray)));

    connect(this, &MainPresenter::drewValue, this, [this](double value) {
        this->view->getChart()->addValue(value);
    });

    new std::thread([this]{
        int i = 0;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        while (true) {
            auto value = sin(i++ / 10.0);
            emit drewValue(value);
            std::this_thread::sleep_for(std::chrono::milliseconds(16));     // 60fps
        }
    });
}

MainPresenter::~MainPresenter()
{
    qDebug()<<"~MainPresenter";
    delete serialPort;
}

void MainPresenter::onConStateChanged(bool isConnected)
{
    view->setConState(isConnected);
}

void MainPresenter::onData(QByteArray byteArray)
{
    qDebug()<<byteArray;
}
