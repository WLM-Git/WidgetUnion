#ifndef WAVEWIDGET_H
#define WAVEWIDGET_H

#include <QWidget>
#include <QPointF>

class WaveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaveWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;
    float m_waveX;
    float m_waveY;
    QVector<QPointF> m_point;

signals:
public slots:
    void OnUpdateDataForWaveWidget(float waveX, float waveY);
};

#endif // WAVEWIDGET_H
