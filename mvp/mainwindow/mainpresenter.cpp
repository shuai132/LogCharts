#include "mainpresenter.h"
#include "mainmodel.h"
#include "conf/config.h"

#include <QDebug>

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

    cmdFIFO = new CmdFIFO("nc 192.168.3.196 6666");
    cmdFIFO->setOnRecievedCallback([](byte* data, int len) {
        qDebug()<<"here?";
        qDebug()<<QString::fromUtf8((const char*)data)<<len;
    });
}

MainPresenter::~MainPresenter()
{
    qDebug()<<"~MainPresenter";
    delete cmdFIFO;
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
