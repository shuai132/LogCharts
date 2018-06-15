#ifndef MAINCONTRACT_H
#define MAINCONTRACT_H

#include "../base/mvp.h"
#include <QString>

namespace MainContract {
    class Model : public MVP::Model {
    public:
    };

    class Presenter;
    class View : public MVP::View<Presenter> {
    public:
        virtual void setConState(bool isConnected) = 0;
    };

    class Presenter : public MVP::Presenter<Model, View>
    {
    public:
        explicit Presenter(View* view)
            :MVP::Presenter<Model, View>(view)
        {}
    };
}

#endif // MAINCONTRACT_H
