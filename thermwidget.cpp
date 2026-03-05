#include "thermwidget.h"
#include <QPainter>
#define THERMWIDGET_WIDTH 56
#define THERMWIDGET_HEIGHT 200


ThermWidget::ThermWidget(QWidget *parent)
    : QWidget{parent}
{
    setGeometry(50,50,THERMWIDGET_WIDTH,THERMWIDGET_HEIGHT);
    m_thermBg.load(":/ImageResources/therm_bg.png");
}

void ThermWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawPixmap(rect(),m_thermBg);
}
