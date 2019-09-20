#include <iostream>
#include <personas.h>
#include <profesor.h>
#include <alumnos.h>
#include <string>

using namespace std;

void ImprimirDatosPersona(Personas *a)
{
    cout << "Nombre          : " << a->getNombre()       << endl;
    cout << "Apellidos       : " << a->getApellidos()    << endl;
    cout << "DNI             : " << a->getDNI()          << endl;
}
void Calificando(){
       Personas *profesor1 = new Profesor();
       profesor1->setNombre("Maite");
       profesor1->setApellidos("Garcia Ordas");
       profesor1->setDNI("72272348W");


       Personas *alumno1 = new Alumnos();
       alumno1->setNombre("Iván");
       alumno1->setApellidos("Castro Martínez");
       alumno1->setDNI("71476474H");

       Personas *alumno2 = new Alumnos();
       alumno1->setNombre("Aitana");
       alumno1->setApellidos("Perez Martínez");
       alumno1->setDNI("71484953T");

       Personas *alumno3 = new Alumnos();
       alumno1->setNombre("Ramon");
       alumno1->setApellidos("Villegas Conde");
       alumno1->setDNI("71423184L");

       Personas *alumno4 = new Alumnos();
       alumno1->setNombre("Pablo");
       alumno1->setApellidos("García Santos");
       alumno1->setDNI("71401890P");

       Personas *alumno5 = new Alumnos();
       alumno1->setNombre("Sara");
       alumno1->setApellidos("De Asis Sanchez");
       alumno1->setDNI("72632902A");


       ((Profesor*)profesor1)->aniadirAlumnos(((Alumnos*)alumno1));
       ((Profesor*)profesor1)->aniadirAlumnos(((Alumnos*)alumno2));
       ((Profesor*)profesor1)->aniadirAlumnos(((Alumnos*)alumno3));
       ((Profesor*)profesor1)->aniadirAlumnos(((Alumnos*)alumno4));
       ((Profesor*)profesor1)->aniadirAlumnos(((Alumnos*)alumno5));

       ((Profesor*)profesor1)->asignarnota(((Alumnos*)alumno1), 3.0, 9.4, 7.1);
       ((Profesor*)profesor1)->asignarnota(((Alumnos*)alumno2), 4.2, 8.6);
       ((Profesor*)profesor1)->asignarnota(((Alumnos*)alumno3), 7.3);
       ((Profesor*)profesor1)->asignarnota(((Alumnos*)alumno4), 7.6, 8.3);
       ((Profesor*)profesor1)->asignarnota(((Alumnos*)alumno5), 9, 4.5, 3);


       ((Profesor*)profesor1)->imprimirListadoAlumnos();
       ((Profesor*)profesor1)->imprimirAlumnoMejorNota();

}

int main()
{
    Calificando();
    return 0;
}

