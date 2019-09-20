#include "coche.h"

Coche::Coche(QString nombreCoche, QString numeroRuedas, QString potenciamotor, QString tipoCombustible, QString Color, bool kit, bool repuesto, bool burbuja, bool bocina, bool portaVaso, QString matricula)
{

    this->nombreCoche=nombreCoche;
    this->numeroRuedas=numeroRuedas;
    this->potenciamotor=potenciamotor;
    this->tipoCombustible=tipoCombustible;
    this->Color=Color;
    this->kit=kit;
    this->repuesto=repuesto;
    this->burbuja=burbuja;
    this->bocina=bocina;
    this->portaVaso=portaVaso;
    this->matricula=matricula;
}

void Coche::setNombreCoche(QString value)
{
    nombreCoche = value;
}
QString Coche::getNombreCoche()
{
    return nombreCoche;
}


void Coche::setRuedas(QString value)
{
    numeroRuedas = value;
}
QString Coche::getRuedas()
{
    return numeroRuedas;
}


void Coche::setPotencia(QString value)
{
    potenciamotor = value;
}
QString Coche::getPotencia()
{
    return potenciamotor;
}


void Coche::setCombustible(QString value)
{
    tipoCombustible = value;
}
QString Coche::getCombustible()
{
    return tipoCombustible;
}


void Coche::setColor(QString value)
{
    Color = value;
}
QString Coche::getColor()
{
    return Color;
}


void Coche::setReparacion(bool value)
{
    kit = value;
}
bool Coche::getReparacion()
{
    return kit;
}


void Coche::setBurbuja(bool value)
{
    burbuja = value;
}
bool Coche::getBurbuja()
{
    return burbuja;
}


void Coche::setBocina(bool value)
{
    bocina = value;
}
bool Coche::getBocina()
{
    return bocina;
}


void Coche::setPortavasos(bool value)
{
    portaVaso = value;
}
bool Coche::getPortavasos()
{
    return portaVaso;
}


void Coche::setMatricula(QString value)
{
    matricula = value;
}
QString Coche::getMatricula()
{
    return matricula;
}


void Coche::setRepuesto(bool value) {
    repuesto = value;
}
bool Coche::getRepuesto(){
    return repuesto;
}


QString Coche::genMatricula(){

    QString rMatricula;
    int numMatricula = rand() % 10000;
    rMatricula = QString::number(numMatricula);
    for(int i=0;i<3;i++){
        int charMatricula = rand() % 21;
        rMatricula.append(letras[charMatricula]);
    }

    return rMatricula;
}








