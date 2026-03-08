#ifndef PETROWIDGET_H
#define PETROWIDGET_H

#include <QWidget>
#include <array>

class PetroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PetroWidget(QWidget *parent = nullptr);
    void OnUpdatePetroWidget(float);
private:
    void loadFrontWidget();
    void paintEvent(QPaintEvent* event);
private:
    std::array<QPixmap,10> m_petro;
    std::array<QPixmap,10> m_petroBg;
    int m_petroValue;
signals:
};

#endif // PETROWIDGET_H
