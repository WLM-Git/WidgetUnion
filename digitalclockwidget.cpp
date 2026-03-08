#include "digitalclockwidget.h"
#include <QPainter>

#define DIGITALCLOCK_WIDTH  434
#define DIGITALCLOCK_HEIGHT 170


DigitalClockWidget::DigitalClockWidget(QWidget *parent)
    : QWidget{parent}
{
    m_currentTimeInfo = {0, 0, 0, 0, 0, 0, 0};
    setGeometry(250,70,DIGITALCLOCK_WIDTH,DIGITALCLOCK_HEIGHT);
    loadFrontWidget();
}

void DigitalClockWidget::loadFrontWidget()
{
    m_digitalClockBg.load(":/ImageResources/digitalClock_bg.png");
    for(int i = 0; i <= 9; i++)
    {
        QString imagePath = QString(":/ImageResources/t_%1.png").arg(i);
        m_digitalNumbers.at(i).load(imagePath);
    }
    m_digitalNumbers.at(10).load(":/ImageResources/t_100.png");
    m_tColon.load(":/ImageResources/t_colon.png");
}

void DigitalClockWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.drawPixmap(rect(),m_digitalClockBg);
    //年
    painter.drawPixmap(QRect(27,23,14,28),m_digitalNumbers.at(2));
    painter.drawPixmap(QRect(47,23,14,28),m_digitalNumbers.at(0));
    painter.drawPixmap(QRect(67,23,14,28),m_digitalNumbers.at((m_currentTimeInfo.years%100)/10));
    painter.drawPixmap(QRect(87,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.years%10));
    //月
    if(m_currentTimeInfo.months<10)
    {
        painter.drawPixmap(QRect(146,23,14,28),m_digitalNumbers.at(10));
    }
    else
    {
        painter.drawPixmap(QRect(146,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.months/10));
    }
    painter.drawPixmap(QRect(166,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.months%10));
    //日
    if(m_currentTimeInfo.days<10)
    {
        painter.drawPixmap(QRect(219,23,14,28),m_digitalNumbers.at(10));
    }
    else
    {
        painter.drawPixmap(QRect(219,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.days/10));
    }
    painter.drawPixmap(QRect(239,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.days%10));
    //温度
    painter.drawPixmap(QRect(357,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.temperature%10));
    painter.drawPixmap(QRect(377,23,14,28),m_digitalNumbers.at(m_currentTimeInfo.temperature/10));
    //时
    if(m_currentTimeInfo.hours<10)
    {
        painter.drawPixmap(QRect(40,80,28,56),m_digitalNumbers.at(10));
    }
    else
    {
        painter.drawPixmap(QRect(40,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.hours/10));
    }
    painter.drawPixmap(QRect(80,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.hours%10));
    //分号
    painter.drawPixmap(QRect(142,92,6,33),m_tColon);
    //分
    if(m_currentTimeInfo.minutes<10)
    {
        painter.drawPixmap(QRect(180,80,28,56),m_digitalNumbers.at(0));
    }
    else
    {
        painter.drawPixmap(QRect(180,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.minutes/10));
    }
    painter.drawPixmap(QRect(220,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.minutes%10));
    //分号
    painter.drawPixmap(QRect(282,92,6,33),m_tColon);
    //秒
    if(m_currentTimeInfo.seconds<10)
    {
        painter.drawPixmap(QRect(320,80,28,56),m_digitalNumbers.at(10));
    }
    else
    {
        painter.drawPixmap(QRect(320,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.seconds/10));
    }
    painter.drawPixmap(QRect(360,80,28,56),m_digitalNumbers.at(m_currentTimeInfo.seconds%10));
}

void DigitalClockWidget::OnUpdateDataForDigitalClockWidget(DigitalTimeInfo digitalTimeInfo)
{
    m_currentTimeInfo = digitalTimeInfo;
    update();
}
