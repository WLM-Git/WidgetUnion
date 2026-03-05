#ifndef WINDOWWIDGET_H
#define WINDOWWIDGET_H

#include <QWidget>
#include "thermwidget.h"
#include "dataworker.h"

class WindowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WindowWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;
    void loadFrontWidgets();
private:
    QPixmap m_background;
    ThermWidget* m_ThermWidget;
    DataWorker* m_DataWorker;
    QThread* workThread;

signals:
};

#endif // WINDOWWIDGET_H
