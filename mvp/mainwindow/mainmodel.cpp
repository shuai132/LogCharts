#include "mainmodel.h"
#include "conf/config.h"
#include <QDebug>

MainModel::MainModel()
{
    const char* initFlagKey = "inited";
    const char* defaultBuateKey = "defaultBuate";

    bool isInited = sp->contains(initFlagKey);
    if (!isInited) {
        sp->setValue(initFlagKey, true);
        sp->setValue(defaultBuateKey, Config::DefaultBuate);
    }
}
