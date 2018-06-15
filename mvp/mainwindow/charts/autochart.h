#ifndef AUTOCHART_H
#define AUTOCHART_H

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QChartView>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

class AutoChart : public QChartView
{
    Q_OBJECT

public:
    explicit AutoChart(QWidget* parent = nullptr);

    void addValue(double value) {
        if(_pos >= _maxLength) {
            _series->removePoints(0, 1);
        }
        _series->append(_pos++, value);

        // fixme:
        rePaint();
    }

    inline void setCachedLength(uint32_t length) {
        _maxLength = length;
    }

    inline int getSize() {
        return _pos;
    }

    inline void clear() {
        _pos = 0;
        _series->clear();
    }

    // fixme:
    inline void rePaint() {
        _chart->removeSeries(_series);
        _chart->addSeries(_series);
    }

private:
    QLineSeries* _series = nullptr;
    QChart* _chart = nullptr;

private:
    int _pos = 0;
    int _maxLength = 100;
};

#endif // AUTOCHART_H
