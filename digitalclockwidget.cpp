#include "digitalclockwidget.h"
#include <QPainter>

#define DIGITALCLOCK_WIDTH  434
#define DIGITALCLOCK_HEIGHT 170


DigitalClockWidget::DigitalClockWidget(QWidget *parent)
    : QWidget{parent}
{
    setGeometry(250,70,DIGITALCLOCK_WIDTH,DIGITALCLOCK_HEIGHT);
    loadFrontWidget();
}

void DigitalClockWidget::loadFrontWidget()
{
    m_digitalClockBg.load(":/ImageResources/digitalClock_bg.png");
    for(int i = 0; i <= 9; i++)
    {
        QString imagePath = QString(":/ImageResources/p_%1.png").arg(i);
        m_digitalNumbers.at(i).load(imagePath);
    }
}

void DigitalClockWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.drawPixmap(rect(),m_digitalClockBg);
}
