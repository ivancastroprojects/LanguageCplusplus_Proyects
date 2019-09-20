#include "ventanaprincipal.h"
#include <QApplication>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaPrincipal w;

    w.setWindowTitle("Administración de Coches ");        //el titulo de nuestra ventana
    w.show();


    return a.exec();
}
