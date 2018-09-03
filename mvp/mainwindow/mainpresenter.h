#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include "maincontract.h"
#include "mainwindow.h"
#include "mainmodel.h"
#include "cmdfifo/cmdfifo.h"

#include <QObject>

class MainPresenter : public QObject, public MainContract::Presenter
{
    Q_OBJECT

public:
    explicit MainPresenter(MainContract::View* view);
    ~MainPresenter();

    void execute(QString shellCmd);

signals:
    void drewValue(double value);

private:
    CmdFIFO* cmdFIFO = nullptr;
};

#endif // MAINPRESENTER_H
