#include "speedwidget.h"
#include <QPainter>
#define SPEEDDWIDGET_WIDTH 260
#define SPEEDDWIDGET_HEIGHT 260

SpeedWidget::SpeedWidget(QWidget *parent)
    : QWidget{parent}
{
    m_rotateValue = 0;
    setGeometry(930,300,SPEEDDWIDGET_WIDTH,SPEEDDWIDGET_HEIGHT);
    loadFontWidget();
}

void SpeedWidget::loadFontWidget()
{
    m_speedBg.load(":/ImageResources/speed_bg.png");
    m_needle.load(":/ImageResources/speed_needle.png");
}

void SpeedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    painter.drawPixmap(rect(),m_speedBg);

    painter.save();
    painter.translate(width()/2,height()/2);
    painter.rotate(-120.0);
    painter.rotate(m_rotateValue);
    painter.drawPixmap(-16,-102,m_needle);
    painter.restore();
}

void SpeedWidget::OnUpdateDataForSpeedWidget(float speedValue)
{
    m_rotateValue = qAbs(speedValue - 1) * 120.0f;
    update();
}
