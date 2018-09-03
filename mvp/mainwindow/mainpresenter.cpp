#include "mainpresenter.h"
#include "mainmodel.h"
#include "conf/config.h"

#include <QDebug>

MainPresenter::MainPresenter(MainContract::View* view)
    :Presenter(view)
{
    this->model = new MainModel();

    connect(this, &MainPresenter::drewValue, this, [this](double value) {
        this->view->getChart()->addValue(value);
    });
}

MainPresenter::~MainPresenter()
{
    qDebug()<<"~MainPresenter";
    delete cmdFIFO;
}

void MainPresenter::execute(QString shellCmd)
{
    if (cmdFIFO != nullptr) {
        delete cmdFIFO;
    }
    cmdFIFO = new CmdFIFO(shellCmd.toStdString());
    cmdFIFO->setOnRecievedCallback([this](byte* data, int len) {
        QString str = QString::fromUtf8((const char*)data, len - 1);
        qDebug()<<str<<len;
        bool flag = false;
        double value = str.toDouble(&flag);
        qDebug()<<"fffff"<<value<<flag;
        if (flag) {
            this->view->getChart()->addValue(value);
            this->view->getChart()->repaint();
        }
        else {
            qDebug()<<"can not convert "<<str<<" to double!";
        }
    });
}
