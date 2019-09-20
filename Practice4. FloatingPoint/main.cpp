#include "coma_flotante.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    coma_flotante w;
    w.show();

    return a.exec();
}
