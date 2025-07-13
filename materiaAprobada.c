#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "materiaAprobada.h"

struct MateriaAprobada{

    char nombre[30];
    float nota;
};

/// Constructor
MateriaAprobadaPtr crearMateriaAprobada(char* nombre, float nota){

    MateriaAprobadaPtr materiaAprobada = (MateriaAprobadaPtr) malloc(sizeof(struct MateriaAprobada));

    strcpy(materiaAprobada->nombre, nombre);
    materiaAprobada->nota = nota;

    return materiaAprobada;
}

/// Destructor
void liberarMateriaAprobada(MateriaAprobadaPtr m){

    free(m);
}

/// Getters y Setters
char* getNombreMateriaAprobada(MateriaAprobadaPtr m){

    return m->nombre;
}

int getNota(MateriaAprobadaPtr m){

    return m->nota;
}

void setNombreMateriaAprobada(MateriaAprobadaPtr m, char* nuevoNombre){

    strcpy(m->nombre, nuevoNombre);
}

void setNota(MateriaAprobadaPtr m, int nuevaNota){

    m->nota = nuevaNota;
}

/// Funciones y Metodos
