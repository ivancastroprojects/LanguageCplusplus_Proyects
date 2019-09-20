#include <profesor.h>
#include <alumnos.h>
#include "personas.h"
#include <vector>
#include <string>

Profesor::Profesor(){
}

Profesor::~Profesor(){
}


void Profesor::aniadirAlumnos(Alumnos* alumno)
{
    alumnos.push_back(alumno);
}

void Profesor::asignarnota(Alumnos *alumno, float nota1)
{
    alumno->notas.push_back(nota1);
}
void Profesor::asignarnota(Alumnos *alumno, float nota1, float nota2)
{
    alumno->notas.push_back(nota1);
    alumno->notas.push_back(nota2);
}
void Profesor::asignarnota(Alumnos *alumno, float nota1, float nota2, float nota3)
{
    alumno->notas.push_back(nota1);
    alumno->notas.push_back(nota2);
    alumno->notas.push_back(nota3);
}

float Profesor::obtenerNotaMedia(Alumnos* alumno)
{
    return (alumno->notas.at(0)+alumno->notas.at(1)+alumno->notas.at(2)) /3;
}

void Profesor::imprimirListadoAlumnos()
{
    for(unsigned int i=0; i<alumnos.size();i++) {
        cout << "Nombre" + alumnos.at(i)->getNombre() << "Apellidos" + alumnos.at(i)->getApellidos() << "DNI" + alumnos.at(i)->getDNI();
    }
}

void Profesor::imprimirAlumnoMejorNota()
{
    float notamax = 0;
    string nombre;

    for( int i=-1; i<alumnos.size(); i++){
        if(alumnos.at(i)->notas > alumnos.at(i-1)->notas){
            notamax = obtenerNotaMedia(alumnos.at(i));
            nombre = alumnos.at(i)->getNombre();
        }
        cout << "El alumno con la mejor nota es: " + nombre + "y su nota es: " << notamax <<endl;
    }
}




