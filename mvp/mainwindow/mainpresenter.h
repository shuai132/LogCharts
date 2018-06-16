#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include "maincontract.h"
#include "serialport/serialport.h"
#include "mainwindow.h"
#include "mainmodel.h"
#include <QObject>

class MainPresenter : public QObject, public MainContract::Presenter
{
    Q_OBJECT

public:
    explicit MainPresenter(MainContract::View* view);
    ~MainPresenter();

signals:
    void drewValue(double value);

private slots:
    void onConStateChanged(bool isConnected);
    void onData(QByteArray byteArray);

private:
    SerialPort* serialPort = nullptr;
};

#endif // MAINPRESENTER_H
