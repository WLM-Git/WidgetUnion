#ifndef DATAWORKER_H
#define DATAWORKER_H
#include <QObject>
#include <QTimer>

class DataWorker : public QObject
{
    Q_OBJECT
public:
    explicit DataWorker(QObject *parent = nullptr);
private:

private:
    QTimer* m_timer;
    int startPointX;

signals:
    void UpdateDataForThermWidgetSignal(float);
public slots:
    void doWork();
    void generateData();
};

#endif // DATAWORKER_H
