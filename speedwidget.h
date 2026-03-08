#ifndef SPEEDWIDGET_H
#define SPEEDWIDGET_H

#include <QWidget>

class SpeedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedWidget(QWidget *parent = nullptr);
private:
    void loadFontWidget();
    void paintEvent(QPaintEvent* event) override;
private:
    QPixmap m_speedBg;
    QPixmap m_needle;
    float m_rotateValue;
public slots:
    void OnUpdateDataForSpeedWidget(float speedValue);

signals:
};

#endif // SPEEDWIDGET_H
