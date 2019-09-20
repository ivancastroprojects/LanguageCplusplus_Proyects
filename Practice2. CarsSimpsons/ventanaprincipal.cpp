#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <string>
#include <iostream>
#include <qpushbutton.h>
#include <QLCDNumber>
#include <QDebug>

#include "coche.h"
#include "taller.h"


using namespace std;

int contador = 0;

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);



  connect(ui->pushGuardar,SIGNAL(clicked()),this, SLOT(guardaCoche()));
  connect(ui->pushGenerar,SIGNAL(clicked()),this, SLOT(generaMatricula()));
  connect(ui->pushSalir,SIGNAL(clicked()),this, SLOT(close()));
  connect(ui->pushTipo,SIGNAL(clicked()),this, SLOT(obtenerTipo()));
  ui->lcdTotal->setSegmentStyle(QLCDNumber::Flat);
  ui->lcdTotal->setStyleSheet("* { background-color: lightgray;color: Black; }");

  Coche *elHomer  = new Coche("El Homer","4","400","Metano","verde",true,false,true,true,true,"8008IES");
  coches.push_back(*elHomer);
  connect(ui->comboLista,SIGNAL(activated(int)),this,SLOT(muestraCoche()));
  ui->comboLista->addItem(coches.at(0).getNombreCoche());
  contador = coches.size();
  ui->lcdTotal->display(contador);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;

}

void VentanaPrincipal::muestraCoche() {
    //obtiene datos de lista
     int seleccion = ui->comboLista->currentIndex();
     if (seleccion==0){
         ui->lineMatricula->setText("");
         ui->lineNombre->setText("");
         ui->linePotencia->setText("");
         ui->lineRuedas->setText("");

         ui->radioReparacion->setChecked(false);
         ui->radioRepuesto->setChecked(false);
         ui->checkBocinas->setChecked(false);
         ui->checkBurbuja->setChecked(false);
         ui->checkPortavasos->setChecked(false);
         ui->comboColor->setCurrentIndex(0);
         ui->comboCombustible->setCurrentIndex(0);

         vRepuesto = false;
         vReparacion = false;
         vBurbuja = false;
         vBocina = false;
         vPortavasos = false;

         vMatricula = "";
         vNombre = "";
         vRuedas = "";
         vPotencia = "";
         vCombustible = "";
         vColor = "";

     } else {
     vNombre = coches.at(seleccion-1).getNombreCoche();
     vRuedas = coches.at(seleccion-1).getRuedas();
     vPotencia = coches.at(seleccion-1).getPotencia();

     int intCombustible = -1;
     vCombustible = coches.at(seleccion-1).getCombustible();

      if (vCombustible.compare("Gasolina") == 0) {
        intCombustible = 0;
      } if (vCombustible.compare("Hidrogeno") == 0) {
        intCombustible = 1;
      } if (vCombustible.compare("Metano") == 0) {
         intCombustible = 2;
      } if (vCombustible.compare("Diésel") == 0) {
         intCombustible = 3;
      } if (vCombustible.compare("Bio-diésel") == 0) {
         intCombustible = 4;
      } if (vCombustible.compare("Eléctrico") == 0) {
         intCombustible = 5;
      } if (vCombustible.compare("Híbrido") == 0) {
         intCombustible = 6;
      }

     int intColor = -1;
     vColor = coches.at(seleccion-1).getColor();

     if (vColor.compare("rojo") == 0) {
       intColor = 0;
     } if (vColor.compare("plateado") == 0) {
         intColor = 1;
     } if (vColor.compare("dorado") == 0) {
         intColor = 2;
     } if (vColor.compare("gris") == 0) {
         intColor = 3;
     } if (vColor.compare("grafito") == 0) {
         intColor = 4;
     } if (vColor.compare("amarillo") == 0) {
         intColor = 5;
     } if (vColor.compare("marron") == 0) {
         intColor = 6;
     } if (vColor.compare("negro") == 0) {
         intColor = 7;
     } if (vColor.compare("azul") == 0) {
         intColor = 8;
     } if (vColor.compare("verde") == 0) {
         intColor = 9;
     }

     vRepuesto = coches.at(seleccion-1).getRepuesto();
     vReparacion = coches.at(seleccion-1).getReparacion();
     vBurbuja = coches.at(seleccion-1).getBurbuja();
     vBocina = coches.at(seleccion-1).getBocina();
     vPortavasos = coches.at(seleccion-1).getPortavasos();
     vMatricula = coches.at(seleccion-1).getMatricula();

     ui->lineMatricula->setText(vMatricula);
     ui->lineNombre->setText(vNombre);
     ui->linePotencia->setText(vPotencia);
     ui->lineRuedas->setText(vRuedas);

     ui->radioReparacion->setChecked(vReparacion);
     ui->radioRepuesto->setChecked(vRepuesto);
     ui->checkBocinas->setChecked(vBocina);
     ui->checkBurbuja->setChecked(vBurbuja);
     ui->checkPortavasos->setChecked(vPortavasos);
     ui->comboColor->setCurrentIndex(intColor);
     ui->comboCombustible->setCurrentIndex(intCombustible);

    }
}

void VentanaPrincipal::cocheNuevo(){
    ui->lineMatricula->setText("");
    ui->lineNombre->setText("");
    ui->linePotencia->setText("");
    ui->lineRuedas->setText("");

    ui->radioReparacion->setChecked(false);
    ui->radioRepuesto->setChecked(false);
    ui->checkBocinas->setChecked(false);
    ui->checkBurbuja->setChecked(false);
    ui->checkPortavasos->setChecked(false);

    ui->comboColor->setCurrentIndex(0);
    ui->comboCombustible->setCurrentIndex(0);

    vRepuesto = false;
    vReparacion = false;
    vBurbuja = false;
    vBocina = false;
    vPortavasos = false;

    vMatricula = "";
    vNombre = "";
    vRuedas = "";
    vPotencia = "";
    vCombustible = "";
    vColor = "";

}

void VentanaPrincipal::guardaCoche(){
 if(ui->comboLista->currentIndex()==0){
     vNombre = ui->lineNombre->text();
     vRuedas = ui->lineRuedas->text();
     vPotencia = ui->linePotencia->text();
     vMatricula = ui->lineMatricula->text();

     vCombustible = ui->comboCombustible->currentText();
     vColor = ui->comboColor->currentText();
     vRepuesto = ui->radioRepuesto->isChecked();
     vReparacion = ui->radioReparacion->isChecked();
     vBurbuja = ui->checkBurbuja->isChecked();
     vBocina = ui->checkBocinas->isChecked();
     vPortavasos = ui->checkPortavasos->isChecked();


     Coche *nuevo = new Coche(vNombre,vRuedas,vPotencia,vCombustible,vColor,vReparacion,vRepuesto,vBurbuja,vBocina,vPortavasos,vMatricula);
     coches.push_back(*nuevo);
     actualizaLista();
     ui->comboLista->setCurrentIndex(coches.size());
     contador = coches.size();
     ui->lcdTotal->display(contador);
 } else {
     coches.at(ui->comboLista->currentIndex()-1).setNombreCoche(ui->lineNombre->text());
     coches.at(ui->comboLista->currentIndex()-1).setRuedas(ui->lineRuedas->text());
     coches.at(ui->comboLista->currentIndex()-1).setPotencia(ui->linePotencia->text());
     coches.at(ui->comboLista->currentIndex()-1).setCombustible(ui->comboCombustible->currentText());
     coches.at(ui->comboLista->currentIndex()-1).setColor(ui->comboColor->currentText());
     coches.at(ui->comboLista->currentIndex()-1).setRepuesto(ui->radioRepuesto->isChecked());
     coches.at(ui->comboLista->currentIndex()-1).setReparacion(ui->radioReparacion->isChecked());
     coches.at(ui->comboLista->currentIndex()-1).setBurbuja(ui->checkBurbuja->isChecked());
     coches.at(ui->comboLista->currentIndex()-1).setBocina(ui->checkBocinas->isChecked());
     coches.at(ui->comboLista->currentIndex()-1).setPortavasos(ui->checkPortavasos->isChecked());
     coches.at(ui->comboLista->currentIndex()-1).setMatricula(ui->lineMatricula->text());

     contador=coches.size();
     ui->lcdTotal->display(contador);
 }
}

void VentanaPrincipal::generaMatricula(){
    if (ui->comboLista->currentIndex()!=0){
        ui->lineMatricula->setText(coches.at(ui->comboLista->currentIndex()-1).genMatricula());
    } else {
      ui->lineMatricula->setText(coches.at(0).genMatricula());
    }
}

void VentanaPrincipal::obtenerTipo(){

    QString tipo;
    if(ui->comboLista->currentIndex()!=0){
        if (vRuedas.compare("2")==0){
            tipo = "Moto";
        } else {
            tipo = "Coche";
            if (vColor.compare("verde")==0 && vBurbuja==true && vPortavasos==true){
                tipo = "Powel motors EL HOMER";
            }
        }
        QMessageBox::information(this,"Tipo de vehiculo", tipo);
    } else {
        QMessageBox::information(this,"Tipo de vehiculo", "Aun no se especificaron datos");
    }
}

void VentanaPrincipal::actualizaLista(){
    ui->comboLista->clear();
    ui->comboLista->addItem("Nuevo...");
    connect(ui->comboLista,SIGNAL(clicked()),this,SLOT(cocheNuevo()));
    for (vector<Coche>::iterator it = coches.begin(); it != coches.end(); ++it) {

        ui->comboLista->addItem(it->getNombreCoche());
        //connect(ui->comboLista,SIGNAL(clicked()),this, SLOT(muestaCoche()));
        contador = coches.size();
        ui->lcdTotal->display(contador);
    }
}


