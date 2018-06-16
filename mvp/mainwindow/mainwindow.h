#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maincontract.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public MainContract::View
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void resizeEvent(QResizeEvent *event) override;

private slots:

private:
    Ui::MainWindow *ui;

    // View interface
private:
    void setConState(bool isConnected) override;
    AutoChart *getChart() override;
};

#endif // MAINWINDOW_H
