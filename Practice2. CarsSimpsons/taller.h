#ifndef TALLER_H
#define TALLER_H

#include <coche.h>
#include <vector>

using namespace std;//sino no funciona vector

class Taller
{
public:
    Taller();

    vector<Coche> getCoches();
    void setCoches(Coche value);

private:

    vector<Coche> coches;
};

#endif // TALLER_H
