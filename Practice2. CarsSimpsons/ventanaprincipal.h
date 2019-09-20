#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <vector>
#include <coche.h>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();




private:

    bool vRepuesto;
    bool vReparacion;
    bool vBurbuja;
    bool vBocina;
    bool vPortavasos;

    std::vector<Coche> coches;
    Ui::VentanaPrincipal *ui;
    QString vNombre;
    QString vRuedas;
    QString vPotencia;
    QString vCombustible;
    QString vColor;
    QString vMatricula;


private slots:
    void generaMatricula();
    void obtenerTipo();
    void actualizaLista();
    void muestraCoche();
    void cocheNuevo();
    void guardaCoche();

};

#endif // VENTANAPRINCIPAL_H
