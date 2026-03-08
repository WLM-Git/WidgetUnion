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
    float m_waveX;
    float m_waveY;
    float m_petro;
    float m_moto;
    float m_timeProgressRotateValue;

signals:
    void UpdateDataForThermWidgetSignal(float);
    void UpdateDataForDigitalClockWidgetSignal(DigitalTimeInfo);
    void UpdateDataForWaveWidgetSignal(float,float);
    void UpdateDataForPetroWidgetSignal(float);
    void UpdateDataForMotoWidgetSignal(float);
    void UpdateDataForTimeProgressWidgetSignal(float);

public slots:
    void doWork();
    void generateData();
};

#endif // DATAWORKER_H
