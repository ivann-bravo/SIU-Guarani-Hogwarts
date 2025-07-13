#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#include "lista.h"
#include "cola.h"
#include "estudiante.h"

struct Materia;
typedef struct Materia * MateriaPtr;

/// Constructor
MateriaPtr crearMateria();

/// Destructor
void liberarMateria(MateriaPtr m);

/// Getters y Setters
char* getNombre(MateriaPtr m);
int getCupo(MateriaPtr m);
ListaPtr getInscriptos(MateriaPtr m);
ColaPtr getColaEspera(MateriaPtr m);
ListaPtr getEstudiantesEnEspera(MateriaPtr m);

void setNombre(MateriaPtr m, char* nuevoNombre);
void setCupo(MateriaPtr m, int nuevoCupo);

/// Funciones y Metodos
void inscribirEstudiante(MateriaPtr materia, EstudiantePtr estudiante);
void priorizarCola(MateriaPtr materia);
void encolarEstudiantes(MateriaPtr materia);
int compararEstudiantesDatoPtr(DatoPtr a, DatoPtr b);
void mostrarEstudianteDatoPtr(DatoPtr dato);
ListaPtr duplicarColaALista(ColaPtr cola);

#endif // MATERIA_H_INCLUDED
