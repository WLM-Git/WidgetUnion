#include "windowwidget.h"
#include <QPainter>
#include<QScreen>
#include <QThread>

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

    workThread = new QThread(this);
    m_DataWorker = new DataWorker();
    m_DataWorker->moveToThread(workThread);
    connect(workThread,&QThread::started,m_DataWorker,&DataWorker::doWork);
    connect(workThread,&QThread::finished,m_DataWorker,&QObject::deleteLater);

    workThread->start();

    loadFrontWidgets();
}

WindowWidget::~WindowWidget()
{
    if(workThread->isRunning())
    {
        workThread->quit();
        workThread->wait();
    }
}

void WindowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(rect(),m_background);
}

void WindowWidget::loadFrontWidgets()
{
    m_ThermWidget = new ThermWidget(this);
    connect(m_DataWorker,&DataWorker::UpdateDataForThermWidgetSignal,m_ThermWidget,&ThermWidget::OnUpdateDataForThermWidget);

    m_HydroWidget = new HydroWidget(this);
    connect(m_DataWorker,&DataWorker::UpdateDataForThermWidgetSignal,m_HydroWidget,&HydroWidget::OnUpdateDataForHydroWidget);

    m_DigitalClockWidget = new DigitalClockWidget(this);


}
