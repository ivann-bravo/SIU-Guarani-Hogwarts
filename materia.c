#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "materia.h"
#include "materiaAprobada.h"
#include "estudiante.h"
#include "lista.h"

struct Materia{

    char nombre[30];
    int cupo;
    ListaPtr inscriptos;
    ColaPtr colaEspera;
    ListaPtr estudiantesEnEspera;
};

/// Constructor
MateriaPtr crearMateria(char* nombre, int cupo){

    MateriaPtr materia = (MateriaPtr) malloc(sizeof(struct Materia));

    strcpy(materia->nombre, nombre);
    materia->cupo = cupo;
    materia->inscriptos = crearLista();
    materia->colaEspera = crearCola();
    materia->estudiantesEnEspera = crearLista();

    return materia;
}

/// Destructor
void liberarMateria(MateriaPtr m){

    liberarLista(m->inscriptos);
    liberarCola(m->colaEspera);
    liberarLista(m->estudiantesEnEspera);
    free(m);
}

/// Getters y Setters
char* getNombre(MateriaPtr m){

    return m->nombre;
}

int getCupo(MateriaPtr m){

    return m->cupo;
}

ListaPtr getInscriptos(MateriaPtr m){

    return m->inscriptos;
}

ColaPtr getColaEspera(MateriaPtr m){

    return m->colaEspera;
}

ListaPtr getEstudiantesEnEspera(MateriaPtr m){

    return m->estudiantesEnEspera;
}

void setNombre(MateriaPtr m, char* nuevoNombre){

    strcpy(m->nombre, nuevoNombre);
}

void setCupo(MateriaPtr m, int nuevoCupo){

    m->cupo = nuevoCupo;
}

/// Funciones y Metodos
void inscribirEstudiante(MateriaPtr materia, EstudiantePtr estudiante){

    if (obtenerTamanio(materia->inscriptos) < materia->cupo) {
        insertarUltimo(materia->inscriptos, estudiante);
    } else {

        insertarUltimo(materia->estudiantesEnEspera, estudiante);
    }
}

void priorizarCola(MateriaPtr materia){

    ListaPtr listaEsperaDup = duplicarLista(materia->estudiantesEnEspera);
    ordenarLista(listaEsperaDup, compararEstudiantesDatoPtr);
    liberarLista(materia->estudiantesEnEspera); // Libero la lista anterior
    materia->estudiantesEnEspera = listaEsperaDup; // Creo nueva lista
}

void encolarEstudiantes(MateriaPtr materia){

    //priorizarCola(materia);
    ordenarLista(materia->estudiantesEnEspera, compararEstudiantesDatoPtr);

    NodoPtr actual = getPrimero(materia->estudiantesEnEspera);

    while (actual != NULL){

        EstudiantePtr estudiante = *(EstudiantePtr*) getDato(actual);
        insertarUltimoCola(materia->colaEspera, estudiante);
        actual = getSiguiente(actual);
    }
}

int compararEstudiantesDatoPtr(DatoPtr a, DatoPtr b) {

    int resultadoComparacion;

    EstudiantePtr estudianteA = (EstudiantePtr) a;
    EstudiantePtr estudianteB = (EstudiantePtr) b;
    int materiasA = obtenerTamanio(getMateriasAprobadas(estudianteA));
    int materiasB = obtenerTamanio(getMateriasAprobadas(estudianteB));

    if (materiasA != materiasB) {
        resultadoComparacion = materiasB - materiasA; // Mayor número de materias aprobadas primero
    } else {

        // Si tienen misma cantidad de materias aprobadas, comparamos los promedios
        float promedioA = getPromedio(estudianteA);
        float promedioB = getPromedio(estudianteB);

        if (promedioA > promedioB) {
            resultadoComparacion = -1; // Mayor promedio primero
        } else {
            resultadoComparacion = 1;
        }
    }

    return resultadoComparacion;
}

void mostrarEstudianteDatoPtr(DatoPtr dato){

    EstudiantePtr estudiante = (EstudiantePtr) dato;
    printf("\n----- ESTUDIANTE -----\n");
    printf("\nNombre: %s - Promedio: %.2f\n", getNombreEstudiante(estudiante), getPromedio(estudiante));
    NodoPtr actual = getPrimero(getMateriasAprobadas(estudiante));

    if (actual != NULL){
        printf("Materias aprobadas: %d\n", obtenerTamanio(getMateriasAprobadas(estudiante)));
    }
    while (actual != NULL){

        MateriaAprobadaPtr materia = *(MateriaAprobadaPtr*) getDato(actual);
        printf("\t- Materia: %s - Nota: %d\n", getNombreMateriaAprobada(materia), getNota(materia));
        actual = getSiguiente(actual);
    }
}
