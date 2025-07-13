#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estudiante.h"
#include "materiaAprobada.h"

struct Estudiante{

    char nombre[30];
    float promedio;
    ListaPtr materiasAprobadas;
};

/// Constructor
EstudiantePtr crearEstudiante(char* nombre, ListaPtr materiasAprobadas){

    EstudiantePtr estudiante = (EstudiantePtr) malloc(sizeof(struct Estudiante));

    strcpy(estudiante->nombre, nombre);
    estudiante->materiasAprobadas = materiasAprobadas;

    estudiante->promedio = calcularPromedio(estudiante->materiasAprobadas);

    return estudiante;
}

/// Destructor
void liberarEstudiante(EstudiantePtr e){

    liberarLista(e->materiasAprobadas);
    free(e);
}

/// Getters y Setters
char* getNombreEstudiante(EstudiantePtr e){

    return e->nombre;
}

float getPromedio(EstudiantePtr e){

    return e->promedio;
}

ListaPtr getMateriasAprobadas(EstudiantePtr e){

    return e->materiasAprobadas;
}

void setNombreEstudiante(EstudiantePtr e, char* nuevoNombre){

    strcpy(e->nombre, nuevoNombre);
}

void setPromedio(EstudiantePtr e, float nuevoPromedio){

    e->promedio = nuevoPromedio;
}

/// Funciones y Metodos

float calcularPromedio(ListaPtr materiasAprobadas){

    int totalMaterias = obtenerTamanio(materiasAprobadas);
    int sumaNotas = 0;
    float promedio = 0;

    NodoPtr actual = getPrimero(materiasAprobadas);
    while (actual != NULL) {
        MateriaAprobadaPtr materiaAprobada = *(MateriaAprobadaPtr*) getDato(actual);
        sumaNotas += getNota(materiaAprobada);
        actual = getSiguiente(actual);
    }

    if (sumaNotas > 0){
        promedio = (float) sumaNotas / totalMaterias;
    }

    return promedio;
}
