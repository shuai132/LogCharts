#include "autochart.h"

AutoChart::AutoChart(QWidget* parent)
    :QChartView(parent)
{
    _series = new QLineSeries();
    _chart = new QChart();
    _chart->addSeries(_series);
    _chart->createDefaultAxes();

    _chart->legend()->hide();
    _chart->axisX()->hide();

    this->setChart(_chart);
    this->setRenderHint(QPainter::Antialiasing);
}
