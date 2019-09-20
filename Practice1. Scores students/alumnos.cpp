#include <personas.h>
#include <alumnos.h>
#include <vector>
#include <string>

Alumnos::Alumnos(){
}

Alumnos::~Alumnos(){
}

void Alumnos::aniadeNota(float cal) //get
{
    notas.push_back(cal);
}

vector<float> Alumnos::obtenerNota() //set
{
    return this->notas;
}

int Alumnos::NumeroDeNotas()
{
    return this->notas.size();

}
