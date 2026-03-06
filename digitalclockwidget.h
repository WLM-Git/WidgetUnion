#ifndef DIGITALCLOCKWIDGET_H
#define DIGITALCLOCKWIDGET_H
#include <array>
#include <QWidget>
#include "DigitalTimeInfo.h"

class DigitalClockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DigitalClockWidget(QWidget *parent = nullptr);
private:
    void loadFrontWidget();
    void paintEvent(QPaintEvent* event) override;
private:
    QPixmap m_digitalClockBg;
    std::array<QPixmap,11> m_digitalNumbers;
    QPixmap m_tColon;
    DigitalTimeInfo m_currentTimeInfo;
signals:
public slots:
    void OnUpdateDataForDigitalClockWidget(DigitalTimeInfo);
};

#endif // DIGITALCLOCKWIDGET_H
