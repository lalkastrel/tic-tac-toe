#include "Widget.h"
#include "Menu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.setFixedSize(200, 200);
    w.show();
    return a.exec();
}
