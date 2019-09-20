#include <personas.h>


Personas::Personas()
{
}

Personas::~Personas()
{
}

string Personas::getNombre()
{
    return nombre;
}

void Personas::setNombre(string value)
{
    this->nombre = value;
}

string Personas::getApellidos()
{
    return apellidos;
}

void Personas::setApellidos(string value)
{
    this->apellidos = value;
}

string Personas::getDNI()
{
    return DNI;
}

void Personas::setDNI(string value)
{
    this->DNI = value;
}

