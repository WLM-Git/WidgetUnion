#ifndef DATAWORKER_H
#define DATAWORKER_H
#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include "DigitalTimeInfo.h"

class DataWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataWorker(QObject *parent = nullptr);
private:

private:
    QTimer* m_timer;
    int m_startPointX;
    DigitalTimeInfo m_digitalTimeInfo;

signals:
    void UpdateDataForThermWidgetSignal(float);
    void UpdateDataForDigitalClockWidgetSignal(DigitalTimeInfo);
public slots:
    void doWork();
    void generateData();
};

#endif // DATAWORKER_H
