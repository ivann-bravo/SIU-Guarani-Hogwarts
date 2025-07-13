#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;
typedef struct Cola * ColaPtr;

/// Constructor
ColaPtr crearCola();

/// Destructor
void liberarCola(ColaPtr cola);

/// Getters y Setters
NodoPtr getPrimeroCola(ColaPtr cola);
NodoPtr getUltimoCola(ColaPtr cola);

void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero);
void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo);

/// Funciones y Metodos
void insertarUltimoCola(ColaPtr cola, DatoPtr dato);
void eliminarPrimeroCola(ColaPtr cola);
ColaPtr duplicarCola(ColaPtr cola);

#endif // COLA_H_INCLUDED
