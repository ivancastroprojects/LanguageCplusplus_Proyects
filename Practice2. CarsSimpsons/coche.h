#ifndef COCHE_H
#define COCHE_H

#include<QString>


class Coche
{
    char letras[20]= {'B','C','D','F','G','H','J','K','L','M','N','P','R','S','T','V','W','X','Y','Z'};

public:

    Coche(QString nombreCoche, QString numeroRuedas,QString potenciamotor,QString tipoCombustible,QString Color,bool kit, bool repuesto, bool  burbuja , bool bocina,bool portaVaso,QString matricula);

    void setNombreCoche(QString value);
    QString getNombreCoche() ;

    void setRuedas(QString value);
    QString getRuedas() ;

    void setPotencia(QString value);
    QString getPotencia() ;

    void setCombustible(QString value);
    QString getCombustible();

    void setColor( QString value);
    QString getColor();

    void setReparacion(bool value);
    bool getReparacion() ;

    void setRepuesto(bool value);
    bool getRepuesto();

    void setBurbuja(bool value);
    bool getBurbuja();

    void setBocina(bool value);
    bool getBocina() ;

    void setPortavasos(bool value);
    bool getPortavasos() ;

    void setMatricula(QString value);
    QString getMatricula() ;

    QString genMatricula();

private:
    bool kit;
    bool repuesto;
    bool burbuja;
    bool bocina;
    bool portaVaso;

    QString nombreCoche;
    QString numeroRuedas;
    QString potenciamotor;
    QString tipoCombustible;
    QString Color;
    QString Matricula;

    QString matricula;

};

#endif // COCHE_H
