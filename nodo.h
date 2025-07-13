#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;

/// Constructor
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

/// Destructor
void liberarNodo(NodoPtr nodo);

/// Getters y Setters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);
void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

/// Funciones y metodos
void mostrarNodoInt(NodoPtr nodo);
void mostrarNodoChar(NodoPtr nodo);
void mostrarNodoFloat(NodoPtr nodo);

#endif // NODO_H_INCLUDED
