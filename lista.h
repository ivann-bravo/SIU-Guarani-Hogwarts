#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

/// Constructor
ListaPtr crearLista();

/// Destructor
void liberarLista(ListaPtr lista);

/// Getters y Setters
NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

/// Funciones y Metodos
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista);
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion);

void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista);
void eliminarposicion(ListaPtr lista, int posicion);

int obtenerTamanio(ListaPtr lista);

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);

int busquedaSecuencial(ListaPtr lista, DatoPtr buscado, int (*comparar)(DatoPtr, DatoPtr));

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

#endif // LISTA_H_INCLUDED
