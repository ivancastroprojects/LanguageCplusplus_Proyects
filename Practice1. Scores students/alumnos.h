#ifndef ALUMNOS_H
#define ALUMNOS_H

#include "personas.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Alumnos : public Personas
{
public:
    Alumnos();
    ~Alumnos();

    //a) Añadir una nueva nota en su lista de notas.
    void aniadeNota(float cal);
    //b) Obtener cada una de sus notas, de su lista de notas.
    vector<float> obtenerNota();
    //c) Devolver el número de notas que tiene en su lista (tamaño de la lista).
    int NumeroDeNotas();

    vector<float> notas;

};

#endif // ALUMNOS_H
