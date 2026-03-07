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
}
