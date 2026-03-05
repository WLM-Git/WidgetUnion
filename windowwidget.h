#ifndef WINDOWWIDGET_H
#define WINDOWWIDGET_H

#include <QWidget>
#include "thermwidget.h"

class WindowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WindowWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;
    void loadChileWidget();
private:
    QPixmap m_background;
    ThermWidget* m_ThermWidget;

signals:
};

#endif // WINDOWWIDGET_H
