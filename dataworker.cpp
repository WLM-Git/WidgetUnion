#include "dataworker.h"

DataWorker::DataWorker(QObject *parent)
    : QObject{parent}
{
    startPointX = 0;
}

void DataWorker::generateData()
{
    float thermValue = std::abs(std::cos(startPointX / 5.0f));
    emit UpdateDataForThermWidgetSignal(thermValue);
    startPointX++;
}

void DataWorker::doWork()
{
    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&DataWorker::generateData);
    m_timer->start(100);
}
