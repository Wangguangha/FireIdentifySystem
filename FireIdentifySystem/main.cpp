#include "FireIdentifySystem.h"
#include <QApplication>

#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireIdentifySystem w;
    w.resize(QSize(1280,720));
    w.show();

    return a.exec();
}
