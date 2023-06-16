#include "serverqt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /**
    * Desde qui manejamos que ventana mostrar al iniciar la applicación
    */
    QApplication a(argc, argv);
    ServerQt w;
    w.show();
    return a.exec();
}
