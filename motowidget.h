#ifndef MOTOWIDGET_H
#define MOTOWIDGET_H

#include <QWidget>

class MotoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MotoWidget(QWidget *parent = nullptr);
    void OnUpdateMotoWidget(float);
private:
    void loadFrontWidget();
    void paintEvent(QPaintEvent* event) override;
private:
    QPixmap m_MotoBg;
    QPixmap m_MotoNeedle;
    float m_rotateValue;

signals:
};

#endif // MOTOWIDGET_H
