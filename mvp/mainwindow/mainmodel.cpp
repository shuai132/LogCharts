#include "mainmodel.h"
#include "conf/config.h"
#include <QDebug>

MainModel::MainModel()
{
    bool isInited = sp->contains(Config::InitedKey);
    if (!isInited) {
        sp->setValue(Config::InitedKey, true);
    }
}
