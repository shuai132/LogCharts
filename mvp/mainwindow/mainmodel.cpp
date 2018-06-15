#include "mainmodel.h"
#include "conf/config.h"
#include <QDebug>

MainModel::MainModel()
{
    bool isInited = sp->contains(Config::InitedKey);
    if (!isInited) {
        sp->setValue(Config::InitedKey, true);
        sp->setValue(Config::BaudRateKey, Config::DefaultBuate);
    }
}

uint32_t MainModel::getConfigedBaudRate()
{
    return sp->getValue(Config::BaudRateKey).toUInt();
}
