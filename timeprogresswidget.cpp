#include "timeprogresswidget.h"
#include <QPainter>
#define TIMERPROGRESSWIDGET_WIDTH 260
#define TIMERPROGRESSWIDGET_HEIGHT 260

TimeProgressWidget::TimeProgressWidget(QWidget *parent)
    : QWidget{parent}
{
    m_rotateValue = 0;
    setGeometry(640,300,TIMERPROGRESSWIDGET_WIDTH,TIMERPROGRESSWIDGET_HEIGHT);
    loadFrontWidget();
}

void TimeProgressWidget::OnUpdateDataForTimeProgessWidget(float rotateValue)
{
    m_rotateValue = (int) qAbs((rotateValue - 1)*180.0);     //[0,2]
    update();
}

void TimeProgressWidget::loadFrontWidget()
{
    m_timeProgressBg.load(":/ImageResources/timeprogress_bg.png");
    m_timeProfressFg.load(":/ImageResources/timeprogress_fg.png");
}

void TimeProgressWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);

    painter.drawPixmap(rect(),m_timeProgressBg);
    QRectF drawRect(24.5,24.5,211,211);

    painter.save();
    painter.setPen(QPen(QColor(2,208,169),2));
    painter.setBrush(QColor(2,208,169));
    painter.translate(width()/2,height()/2);
    painter.rotate(-90);                                  //使得扇形从正上方开始画
    painter.translate(-width()/2,-height()/2);
    painter.drawPie(drawRect,0,-m_rotateValue*16);
    painter.restore();

    painter.drawPixmap(drawRect.toRect(),m_timeProfressFg);

    QFont font;
    font.setFamily("Apple Symbols - Bold");
    font.setWeight(QFont::Thin);
    font.setPixelSize(30);
    painter.setFont(font);
    painter.drawText(QRect(100,95,60,40),Qt::AlignCenter,QString("%1").arg(m_rotateValue));
}
