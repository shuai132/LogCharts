#ifndef MAINCONTRACT_H
#define MAINCONTRACT_H

#include "../base/mvp.h"
#include "charts/autochart.h"
#include <cstdint>

namespace MainContract {
    class Model : public MVP::Model {
    public:
    };

    class Presenter;
    class View : public MVP::View<Presenter> {
    public:
        virtual AutoChart* getChart() = 0;
    };

    class Presenter : public MVP::Presenter<Model, View>
    {
    public:
        explicit Presenter(View* view)
            :MVP::Presenter<Model, View>(view)
        {}

        virtual void execute(QString shellCmd) = 0;
    };
}

#endif // MAINCONTRACT_H
