#include "serverqt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerQt w;
    w.show();
    return a.exec();
}
