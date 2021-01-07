#include "FireIdentifySystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireIdentifySystem w;
    w.resize(QSize(1280,720));
    w.show();

    return a.exec();
}
