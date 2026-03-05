#ifndef THERMWIDGET_H
#define THERMWIDGET_H

#include <QWidget>

class ThermWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ThermWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;
private:
    QPixmap m_thermBg;
signals:
};

#endif // THERMWIDGET_H
