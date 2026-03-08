#include "petrowidget.h"
#include <QPainter>
#define PETROWIDGET_WIDTH 260
#define PETROWIDGET_HEIGHT 260

#define NUMBERWIDGET_WIDTH 33
#define NUMBERWIDGET_HEIGHT 65


PetroWidget::PetroWidget(QWidget *parent)
    : QWidget{parent}
{
    setGeometry(40,300,PETROWIDGET_WIDTH,PETROWIDGET_HEIGHT);
    m_petroValue = 0;
    loadFrontWidget();
}

void PetroWidget::OnUpdatePetroWidget(float petro)
{
    m_petroValue = (int)qAbs(qAbs(petro * 80) - 80);
    update();
}

void PetroWidget::loadFrontWidget()
{
    for(int i = 0; i < 10;i++)
    {
        QString path = QString(":/ImageResources/p_%1.png").arg(i);
        m_petro.at(i).load(path);
    }
    for(int i = 0;i < 9; i++)
    {
        QString path = QString(":/ImageResources/petro_bg%1.png").arg(i+1);
        m_petroBg.at(i).load(path);
    }
}

void PetroWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawPixmap(rect(),m_petroBg.at(m_petroValue/10));
    if(m_petroValue<10)
    {
        painter.drawPixmap(QRect(94,93,NUMBERWIDGET_WIDTH,NUMBERWIDGET_HEIGHT),m_petro.at(0));
        painter.drawPixmap(QRect(134,93,NUMBERWIDGET_WIDTH,NUMBERWIDGET_HEIGHT),m_petro.at(m_petroValue));
    }
    else
    {
        painter.drawPixmap(QRect(94,93,NUMBERWIDGET_WIDTH,NUMBERWIDGET_HEIGHT),m_petro.at(m_petroValue/10));
        painter.drawPixmap(QRect(134,93,NUMBERWIDGET_WIDTH,NUMBERWIDGET_HEIGHT),m_petro.at(m_petroValue%10));
    }
}
