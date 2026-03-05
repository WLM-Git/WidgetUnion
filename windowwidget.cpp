#include "windowwidget.h"
#include <QPainter>
#include<QScreen>

#define WINDOWWIDGET_WIDTH 1200
#define WINDOWWIDGET_HEIGHT 580


WindowWidget::WindowWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowFlag(Qt::Window,true);
    m_background.load(":/ImageResources/background.png");

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect rect = screen->availableGeometry();

    int StartX = (rect.width() - WINDOWWIDGET_WIDTH) / 2;
    int StartY = (rect.height() - WINDOWWIDGET_HEIGHT) / 2;

    setGeometry(StartX,StartY,WINDOWWIDGET_WIDTH,WINDOWWIDGET_HEIGHT);

    loadChileWidget();
}

void WindowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),m_background);
}

void WindowWidget::loadChileWidget()
{
    m_ThermWidget = new ThermWidget(this);

}
