#ifndef DIGITALCLOCKWIDGET_H
#define DIGITALCLOCKWIDGET_H
#include <array>
#include <QWidget>

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
    std::array<QPixmap,10> m_digitalNumbers;
signals:
};

#endif // DIGITALCLOCKWIDGET_H
