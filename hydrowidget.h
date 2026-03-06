#ifndef HYDROWIDGET_H
#define HYDROWIDGET_H

#include <QWidget>

class HydroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HydroWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;
private:
    QPixmap m_hydroBg;
    float m_hydroData;
public slots:
    void OnUpdateDataForHydroWidget(float);
signals:
};

#endif // HYDROWIDGET_H
