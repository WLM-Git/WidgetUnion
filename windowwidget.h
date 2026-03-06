#ifndef WINDOWWIDGET_H
#define WINDOWWIDGET_H

#include <QWidget>
#include "thermwidget.h"
#include "hydrowidget.h"
#include "dataworker.h"
#include "digitalclockwidget.h"

class WindowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WindowWidget(QWidget *parent = nullptr);
    ~WindowWidget();
private:
    void paintEvent(QPaintEvent* event) override;
    void loadFrontWidgets();
private:
    QPixmap m_background;
    ThermWidget* m_ThermWidget;
    HydroWidget* m_HydroWidget;
    DataWorker* m_DataWorker;
    QThread* workThread;
    DigitalClockWidget* m_DigitalClockWidget;

signals:
};

#endif // WINDOWWIDGET_H
