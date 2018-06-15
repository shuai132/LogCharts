#ifndef MAINMODEL_H
#define MAINMODEL_H

#include "maincontract.h"
#include "data/sharedpreferences/sharedpreferences.h"

class MainModel : public MainContract::Model
{
public:
    MainModel();

private:
    SharedPreferences* sp = SharedPreferences::getInstance();

    // Model interface
public:
    uint32_t getConfigedBaudRate();
};

#endif // MAINMODEL_H
