#include <QApplication>
#include "windowwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowWidget windowWidget;
    windowWidget.show();

    return a.exec();
}
