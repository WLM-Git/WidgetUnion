#ifndef TIMEPROGRESSWIDGET_H
#define TIMEPROGRESSWIDGET_H

#include <QWidget>

class TimeProgressWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeProgressWidget(QWidget *parent = nullptr);
public slots:
    void OnUpdateDataForTimeProgessWidget(float rotateValue);
private:
    void loadFrontWidget();
    void paintEvent(QPaintEvent* event);
private:
    QPixmap m_timeProgressBg;
    QPixmap m_timeProfressFg;
    int m_rotateValue;
signals:
};

#endif // TIMEPROGRESSWIDGET_H
