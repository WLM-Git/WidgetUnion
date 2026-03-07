#include "wavewidget.h"
#include <QPainter>
#define WAVEWIDGET_WIDTH 434
#define WAVEWIDGET_HEIGHT 170


WaveWidget::WaveWidget(QWidget *parent)
    : QWidget{parent}
{
    setGeometry(720,70,WAVEWIDGET_WIDTH,WAVEWIDGET_HEIGHT);
}

void WaveWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(),Qt::black);
    painter.translate(-m_offsetX,0);
    QPen pen(Qt::green);
    pen.setWidth(2);
    painter.setPen(pen);

    for(int i = 0;i<m_point.count();i++)
    {
        QPointF point = m_point.at(i);
        QPointF endPoint = QPointF(m_point.at(i).x(),170);
        painter.drawLine(point,endPoint);
    }

}

void WaveWidget::OnUpdateDataForWaveWidget(float waveX, float waveY)
{
    m_waveX = waveX;
    m_waveY = waveY;
    qDebug()<<m_waveX<<"  "<<m_waveY<<Qt::endl;
    m_point.append(QPointF(m_waveX,m_waveY));

    if(m_waveX > WAVEWIDGET_WIDTH)
    {
        m_offsetX = m_waveX - WAVEWIDGET_WIDTH;
    }

    while(!m_point.empty()&&m_point.first().x()<(m_offsetX-10))
    {
        m_point.removeFirst();
    }
    update();
}
