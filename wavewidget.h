#ifndef WAVEWIDGET_H
#define WAVEWIDGET_H

#include <QWidget>

class WaveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaveWidget(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent* event) override;

signals:
};

#endif // WAVEWIDGET_H
