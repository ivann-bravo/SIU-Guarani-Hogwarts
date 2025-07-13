#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include "lista.h"

struct Estudiante;
typedef struct Estudiante * EstudiantePtr;

/// Constructor
EstudiantePtr crearEstudiante(char* nombre, ListaPtr materiasAprobadas);

/// Destructor
void liberarEstudiante(EstudiantePtr e);

/// Getters y Setters
char* getNombreEstudiante(EstudiantePtr e);
float getPromedio(EstudiantePtr e);
ListaPtr getMateriasAprobadas(EstudiantePtr e);

void setNombreEstudiante(EstudiantePtr e, char* nuevoNombre);
void setPromedio(EstudiantePtr e, float nuevoPromedio);

float calcularPromedio(ListaPtr materiasAprobadas);

/// Funciones y Metodos


#endif // ESTUDIANTE_H_INCLUDED
