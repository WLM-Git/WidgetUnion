#include "dataworker.h"

DataWorker::DataWorker(QObject *parent)
    : QObject{parent}
{
    m_startPointX = 0;
}

void DataWorker::generateData()
{
    float thermValue = std::abs(std::cos(m_startPointX / 5.0f));
    emit UpdateDataForThermWidgetSignal(thermValue);
    m_startPointX++;

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QTime currentTime = QTime::currentTime();
    m_digitalTimeInfo.years = currentDateTime.date().year();
    m_digitalTimeInfo.months = currentDateTime.date().month();
    m_digitalTimeInfo.days = currentDateTime.date().day();
    m_digitalTimeInfo.hours = currentTime.hour();
    m_digitalTimeInfo.minutes = currentTime.minute();
    m_digitalTimeInfo.seconds = currentTime.second();
    m_digitalTimeInfo.temperature = 11;
    emit UpdateDataForDigitalClockWidgetSignal(m_digitalTimeInfo);
}

void DataWorker::doWork()
{
    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&DataWorker::generateData);
    m_timer->start(100);
}
