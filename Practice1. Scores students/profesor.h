#ifndef PROFESOR_H
#define PROFESOR_H

#include "personas.h"
#include "alumnos.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Profesor : public Personas
{
public:
    Profesor();
    ~Profesor();

    //a) Añadir un nuevo alumno en su lista de alumnos.
    void aniadirAlumnos(Alumnos* alumno);
    //b) Asignar 1, 2 o 3 notas a un alumno (sobrecarga de métodos).
    void asignarnota(Alumnos *alumno, float nota);
    void asignarnota(Alumnos *alumno, float nota1, float nota2);
    void asignarnota(Alumnos *alumno, float nota1, float nota2, float nota3);

    //c)Obtener la nota media de un alumno (nota media de 1, 2 o 3 notas).
    float obtenerNotaMedia(Alumnos* alumno);
    //d) Imprimir por pantalla el listado de alumnos mostrando sus datos y nota media.
    void imprimirListadoAlumnos();
    //e) Imprimir por pantalla el alumno con mejor nota (entre los alumnos con 3 notas).
    void imprimirAlumnoMejorNota();

private:
    vector<Alumnos*> alumnos;
};

#endif // PROFESOR_H
