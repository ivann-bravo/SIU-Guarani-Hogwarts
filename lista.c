#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

/// Constructor
ListaPtr crearLista(){

    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));

    setPrimero(lista, NULL);

    return lista;
}

/// Destructor
void liberarLista(ListaPtr lista) {

    NodoPtr actual = getPrimero(lista);

    while (actual != NULL){

        NodoPtr aux = actual;
        liberarNodo(actual);
        actual = getSiguiente(aux);
    }

    free(lista);
}

/// Getters y Setters
NodoPtr getPrimero(ListaPtr lista){

    return lista->primero;
}

void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero){

    lista->primero = nuevoPrimero;
}

/// Funciones y Metodos
void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, getPrimero(lista));

    setPrimero(lista, nuevoNodo);
}

void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr actual = getPrimero(lista);

    // Si la lista esta vacia -> Es lo mismo que insertarPrimero
    if (actual == NULL) {
        insertarPrimero(lista, dato);
    } else {

        for (int i = 0; i < obtenerTamanio(lista) - 1; i++){

            actual = getSiguiente(actual);
        }

        setSiguiente(actual, crearNodo(dato, NULL));
    }
}

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){

    int tam = obtenerTamanio(lista);

    if (posicion > tam + 1){
        printf("\nERROR: No se puede insertar en una posicion inexistente\n");
    } else {

        if (posicion < 0){
            printf("\nERROR: No se puede insertar en una posicion negativa\n");
        } else {

            if (posicion == 0){
                insertarPrimero(lista, dato);
            } else {

                if (posicion == tam) {
                    insertarUltimo(lista, dato);
                } else {

                    if (posicion > 0 && posicion < tam) {

                        NodoPtr actual = getPrimero(lista);

                        for (int i = 0; i < posicion - 1; i++){

                            actual = getSiguiente(actual);
                        }

                        setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));
                    }
                }
            }
        }
    }
}

DatoPtr obtenerPrimero(ListaPtr lista){

    NodoPtr actual = getPrimero(lista);
    DatoPtr dato = NULL;

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    } else {
        dato = getDato(actual);
    }

    return dato;
}

DatoPtr obtenerUltimo(ListaPtr lista){

    NodoPtr actual = getPrimero(lista);
    DatoPtr dato = NULL;

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    } else {

        for (int i = 0; i < obtenerTamanio(lista) - 1; i++){

            actual = getSiguiente(actual);
        }

        dato = getDato(actual);
    }

    return dato;
}

DatoPtr obtenerPosicion(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);
    DatoPtr dato = NULL;

    if (posicion > tam + 1){
        printf("\nERROR: La posicion indicada es inexistente - Error ");
    } else {

        if (posicion < 0){
            printf("\nERROR: La posicion indicada es negativa - Error ");
        } else {

            if (posicion == 0){
                dato = obtenerPrimero(lista);
            } else {

                if (posicion == tam) {
                    dato = obtenerUltimo(lista);
                } else {

                    if (posicion > 0 && posicion < tam) {

                        NodoPtr actual = getPrimero(lista);

                        for (int i = 0; i < posicion; i++){

                            actual = getSiguiente(actual);
                        }

                        dato = getDato(actual);
                    }
                }
            }
        }
    }

    return dato;
}

NodoPtr obtenerPrimeroNodo(ListaPtr lista){

    NodoPtr actual = getPrimero(lista);

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    }

    return actual;
}

NodoPtr obtenerUltimoNodo(ListaPtr lista){

    NodoPtr actual = getPrimero(lista);

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    } else {

        for (int i = 0; i < obtenerTamanio(lista) - 1; i++){

            actual = getSiguiente(actual);
        }
    }

    return actual;
}

NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);
    NodoPtr actual = getPrimero(lista);

    if (posicion > tam + 1){
        printf("\nERROR: La posicion indicada es inexistente - Error ");
    } else {

        if (posicion < 0){
            printf("\nERROR: La posicion indicada es negativa - Error ");
        } else {

            if (posicion == 0){
                obtenerPrimeroNodo(lista);
            } else {

                if (posicion == tam) {
                    obtenerUltimoNodo(lista);
                } else {

                    if (posicion > 0 && posicion < tam) {

                        for (int i = 0; i < posicion; i++){

                            actual = getSiguiente(actual);
                        }
                    }
                }
            }
        }
    }

    return actual;
}

void eliminarPrimero(ListaPtr lista){

    NodoPtr nodoABorrar = getPrimero(lista);
    NodoPtr actual = getSiguiente(nodoABorrar);

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    } else {
        setPrimero(lista, actual);
        liberarNodo(nodoABorrar);
    }
}

void eliminarUltimo(ListaPtr lista){

    NodoPtr actual = getPrimero(lista);

    if (actual == NULL) {
        printf("\nERROR: La lista esta vacia.\n");
    } else {

        for (int i = 0; i < obtenerTamanio(lista) - 2; i++){

            actual = getSiguiente(actual); // Obtengo el anteultimo
        }

        liberarNodo(getSiguiente(actual));
        setSiguiente(actual, NULL);
    }
}

void eliminarposicion(ListaPtr lista, int posicion){

    int tam = obtenerTamanio(lista);

    if (posicion > tam + 1){
        printf("\nERROR: La posicion indicada es inexistente - Error ");
    } else {

        if (posicion < 0){
            printf("\nERROR: La posicion indicada es negativa - Error ");
        } else {

            if (posicion == 0){
                eliminarPrimero(lista);
            } else {

                if (posicion == tam) {
                    eliminarUltimo(lista);
                } else {

                    if (posicion > 0 && posicion < tam) {

                        NodoPtr actual = getPrimero(lista);

                        for (int i = 0; i < posicion - 1; i++){

                            actual = getSiguiente(actual); // Obtengo el anterior a eliminar
                        }

                        NodoPtr nodoABorrar = getSiguiente(actual);
                        setSiguiente(actual, getSiguiente(nodoABorrar));
                        liberarNodo(nodoABorrar);
                    }
                }
            }
        }
    }
}

int obtenerTamanio(ListaPtr lista){

    int i = 0;

    NodoPtr actual = getPrimero(lista);

    while (actual != NULL){
        i++;
        actual = getSiguiente(actual);
    }

    return i;
}

void ordenarLista(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr)){

    int permutacion;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;

    if(obtenerTamanio(lista)< 2){
        //ya esta ordenada, no hago nada
    } else {

        do{
            permutacion = 0 ;
            nodo = getPrimero(lista);

            while (getSiguiente(nodo) != ultimo){

                if( comparar(getDato(nodo),getDato(getSiguiente(nodo))) > 0 ){

                    DatoPtr aux = getDato(nodo);
                    setDato(nodo, getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo), aux);
                    permutacion = 1;

                }
                nodo = getSiguiente(nodo);
            }
            ultimo = nodo;
        }while (permutacion!=0);
    }
}

ListaPtr duplicarLista(ListaPtr lista){

    ListaPtr listaDuplicada = crearLista();

    for (int i = 0; i < obtenerTamanio(lista); i++){

        insertarPosicion(listaDuplicada, getDato(obtenerPosicionNodo(lista, i)), i);
    }

    return listaDuplicada;
}

int busquedaSecuencial(ListaPtr lista, DatoPtr buscado, int (*comparar)(DatoPtr, DatoPtr)){

    int i, encontrado = 0;
    int posicion = -1;
    NodoPtr actual = getPrimero(lista);

    while (!encontrado && i < obtenerTamanio(lista)){

        if (comparar(buscado, getDato(actual))){

            encontrado = 1;
            posicion = i;
        }
        actual = getSiguiente(actual);
        i++;
    }

    return posicion;
}

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    NodoPtr actual = lista->primero;

    while (actual != NULL){

        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");
}
