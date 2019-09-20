#ifndef PERSONAS_H
#define PERSONAS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Personas {
public:

    Personas();

    // Destructor de la clase
    ~Personas();


    string getNombre();
    void setNombre(string value);

    string getApellidos();
    void setApellidos(string value);

    string getDNI();
    void setDNI(string value);


private:

    string nombre;
    string apellidos;
    string DNI;

};

#endif // PERSONAS_H
