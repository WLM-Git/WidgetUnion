#include "hydrowidget.h"
#include <QPainter>
#define HYDROWIDGET_WIDTH   60
#define HYDROWIDGET_HEIGHT  204

HydroWidget::HydroWidget(QWidget *parent)
    : QWidget{parent}
{
    setGeometry(150,50,HYDROWIDGET_WIDTH,HYDROWIDGET_HEIGHT);
    m_hydroBg.load(":/ImageResources/hydro_bg.png");
}

void HydroWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPixmap(rect(),m_hydroBg);

    painter.save();
    painter.setBrush(QColor(242,93,95));
    painter.setPen(QPen(QColor(242,93,95),1));

    painter.translate(21.5,153);
    int rectWidget = 9;
    int rectHeight = m_hydroData * 136;
    painter.drawRect(0,0,rectWidget,-rectHeight);
    painter.restore();
}

void HydroWidget::OnUpdateDataForHydroWidget(float hydroData)
{
    m_hydroData = hydroData;
    update();
}
