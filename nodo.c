#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct Nodo{

    DatoPtr dato;
    struct Nodo * siguiente;

};

/// Constructor
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    setDato(nodo, dato);
    setSiguiente(nodo, siguiente);

    return nodo;
}

/// Destructor
void liberarNodo(NodoPtr nodo){

    free(nodo);
}

/// Getters y Setters
DatoPtr getDato(NodoPtr nodo){

    return nodo->dato;
}

NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;
}

void setDato(NodoPtr nodo, DatoPtr nuevoDato){

    nodo->dato = nuevoDato;
}

void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){

    nodo->siguiente = nuevoSiguiente;
}

/// Funciones y metodos
void mostrarNodoInt(NodoPtr nodo){

    printf("{ %d }", *(int*)getDato(nodo));
}

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }", (char*)getDato(nodo));

};

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }", *(float*)getDato(nodo));

};
