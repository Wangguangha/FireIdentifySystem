#include "FireIdentifySystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireIdentifySystem w;
    //w.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
