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
};

#endif // MAINMODEL_H
