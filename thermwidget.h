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
    float m_thermData;
signals:

public slots:
    void OnUpdateDataForThermWidget(float);
};

#endif // THERMWIDGET_H
