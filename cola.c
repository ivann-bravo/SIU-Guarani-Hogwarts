#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"

struct Cola{

    NodoPtr primero;
    NodoPtr ultimo;
};

/// Constructor
ColaPtr crearCola(){

    ColaPtr cola = (ColaPtr) malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
}

/// Destructor
void liberarCola(ColaPtr cola) {

    NodoPtr actual = cola->primero;

    while (actual != NULL){

        NodoPtr aux = actual;
        free(actual);
        actual = getSiguiente(aux);
    }

    free(cola);
}

/// Getters y Setters
NodoPtr getPrimeroCola(ColaPtr cola){

    return cola->primero;
}

NodoPtr getUltimoCola(ColaPtr cola){

    return cola->ultimo;
}

void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero){

    cola->primero = nuevoPrimero;
}

void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo){

    cola->ultimo = nuevoUltimo;
}

/// Funciones y Metodos
void insertarUltimoCola(ColaPtr cola, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    // Si ya tenemos un ultimo
    if (cola->ultimo != NULL) {
        setSiguiente(cola->ultimo, nuevoNodo);
    }
    // Seteamos al nuevo ultimo
    cola->ultimo = nuevoNodo;

    // Si la cola esta vacia
    if (cola->primero == NULL) {
        cola->primero = nuevoNodo;
    }
}

void eliminarPrimeroCola(ColaPtr cola){

    NodoPtr nodoABorrar;

    if (cola->primero != NULL){
        nodoABorrar = cola->primero;
        cola->primero = getSiguiente(cola->primero);
    }

    if (cola->primero == NULL){
        cola->ultimo = NULL;
    }

    liberarNodo(nodoABorrar);
}

ColaPtr duplicarCola(ColaPtr cola){

    ColaPtr colaDuplicada = crearCola();
    NodoPtr actual = cola->primero;

    while (actual != NULL){
        insertarUltimo(colaDuplicada, actual);
        actual = getSiguiente(actual);
    }

    return colaDuplicada;
}
