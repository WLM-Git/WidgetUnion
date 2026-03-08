#include "motowidget.h"
#include <QPainter>
#define MOTOWIDGET_WIDTH 260
#define MOTOWIDGET_HEIGHT 260

MotoWidget::MotoWidget(QWidget *parent)
    : QWidget{parent}
{
    m_rotateValue = -90;
    setGeometry(340,300,MOTOWIDGET_WIDTH,MOTOWIDGET_HEIGHT);
    loadFrontWidget();
}

void MotoWidget::OnUpdateMotoWidget(float rotateValue)
{
    m_rotateValue = -rotateValue * 90.0f;
    update();
}

void MotoWidget::loadFrontWidget()
{
    m_MotoBg.load(":/ImageResources/motor_bg.png");
    m_MotoNeedle.load(":/ImageResources/motor_needle.png");
}

void MotoWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    painter.drawPixmap(rect(),m_MotoBg);

    painter.save();
    painter.translate(width()/2,height()/2);
    painter.rotate(m_rotateValue);
    painter.drawPixmap(-10,-90,m_MotoNeedle);
    painter.restore();
}
