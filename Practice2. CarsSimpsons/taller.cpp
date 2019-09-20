#include "taller.h"


using namespace std;
Taller::Taller()
{
}

void Taller::setCoches(Coche value)
{
    coches.push_back(value);
}
vector<Coche> Taller::getCoches()
{
    return coches;
}


