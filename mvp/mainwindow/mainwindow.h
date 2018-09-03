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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    // View interface
private:
    AutoChart *getChart() override;
};

#endif // MAINWINDOW_H
