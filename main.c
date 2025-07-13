/*--------------------
| Alumno: Ivan Bravo |
| DNI: 42359488      |
---------------------*/

/*
Aclaraciones:
- Modificando la materia a mostrar en la linea 194, va a cambiar la muestra en pantalla.
Deje seteado el que me parecia mas interesante para mostrar.
- Entiendo que una cola no se podria mostrar, lo que hice fue generar una lista de espera,
ordenarla como dice el enunciado y en base a eso se encola en la materia. Lo que muestro
en pantalla es esa lista de espera que luego se usara para encolar.
*/

#include <stdio.h>
#include "materia.h"
#include "materiaAprobada.h"
#include "estudiante.h"

int main() {

    printf("\n----- SIU Guarani Hogwarts 2024 -----\n\n");

    // Creo materias
    MateriaPtr artesOscuras = crearMateria("Artes Oscuras", 5);
    MateriaPtr vuelo = crearMateria("Vuelo", 4);
    MateriaPtr pociones = crearMateria("Pociones", 3);
    MateriaPtr herbologia = crearMateria("Herbologia", 5);
    MateriaPtr transformaciones = crearMateria("Transformaciones", 3);
    MateriaPtr historiaDeLaMagia = crearMateria("Historia de la Magia", 2);
    MateriaPtr encantamientos = crearMateria("Encantamientos", 2);
    MateriaPtr astronomia = crearMateria("Astronomia", 3);

    // Creo estudiantes con materias aprobadas
    MateriaAprobadaPtr vueloE1 = crearMateriaAprobada(getNombre(vuelo), 10);
    MateriaAprobadaPtr pocionesE1 = crearMateriaAprobada(getNombre(pociones), 6);
    MateriaAprobadaPtr herbologiaE1 = crearMateriaAprobada(getNombre(herbologia), 7);
    MateriaAprobadaPtr encantamientosE1 = crearMateriaAprobada(getNombre(encantamientos), 9);
    MateriaAprobadaPtr astronomiaE1 = crearMateriaAprobada(getNombre(astronomia), 6);
    ListaPtr materiasAprobadasE1 = crearLista();
    insertarPrimero(materiasAprobadasE1, &vueloE1);
    insertarPrimero(materiasAprobadasE1, &pocionesE1);
    insertarPrimero(materiasAprobadasE1, &herbologiaE1);
    insertarPrimero(materiasAprobadasE1, &encantamientosE1);
    insertarPrimero(materiasAprobadasE1, &astronomiaE1);
    EstudiantePtr e1 = crearEstudiante("Harry Potter", materiasAprobadasE1);

    MateriaAprobadaPtr pocionesE2 = crearMateriaAprobada(getNombre(pociones), 10);
    MateriaAprobadaPtr herbologiaE2 = crearMateriaAprobada(getNombre(herbologia), 10);
    MateriaAprobadaPtr historiaDeLaMagiaE2 = crearMateriaAprobada(getNombre(historiaDeLaMagia), 10);
    MateriaAprobadaPtr encantamientosE2 = crearMateriaAprobada(getNombre(encantamientos), 10);
    MateriaAprobadaPtr astronomiaE2 = crearMateriaAprobada(getNombre(astronomia), 10);
    ListaPtr materiasAprobadasE2 = crearLista();
    insertarPrimero(materiasAprobadasE2, &pocionesE2);
    insertarPrimero(materiasAprobadasE2, &herbologiaE2);
    insertarPrimero(materiasAprobadasE2, &historiaDeLaMagiaE2);
    insertarPrimero(materiasAprobadasE2, &encantamientosE2);
    insertarPrimero(materiasAprobadasE2, &astronomiaE2);
    EstudiantePtr e2 = crearEstudiante("Hermione Granger", materiasAprobadasE2);

    MateriaAprobadaPtr artesOscurasE3 = crearMateriaAprobada(getNombre(artesOscuras), 5);
    MateriaAprobadaPtr vueloE3 = crearMateriaAprobada(getNombre(vuelo), 7);
    MateriaAprobadaPtr pocionesE3 = crearMateriaAprobada(getNombre(pociones), 6);
    MateriaAprobadaPtr historiaDeLaMagiaE3 = crearMateriaAprobada(getNombre(historiaDeLaMagia), 6);
    ListaPtr materiasAprobadasE3 = crearLista();
    insertarPrimero(materiasAprobadasE3, &artesOscurasE3);
    insertarPrimero(materiasAprobadasE3, &vueloE3);
    insertarPrimero(materiasAprobadasE3, &pocionesE3);
    insertarPrimero(materiasAprobadasE3, &historiaDeLaMagiaE3);
    EstudiantePtr e3 = crearEstudiante("Ron Weasley", materiasAprobadasE3);

    MateriaAprobadaPtr artesOscurasE4 = crearMateriaAprobada(getNombre(artesOscuras), 10);
    MateriaAprobadaPtr vueloE4 = crearMateriaAprobada(getNombre(vuelo), 10);
    MateriaAprobadaPtr herbologiaE4 = crearMateriaAprobada(getNombre(herbologia), 8);
    MateriaAprobadaPtr astronomiaE4 = crearMateriaAprobada(getNombre(astronomia), 7);
    ListaPtr materiasAprobadasE4 = crearLista();
    insertarPrimero(materiasAprobadasE4, &artesOscurasE4);
    insertarPrimero(materiasAprobadasE4, &vueloE4);
    insertarPrimero(materiasAprobadasE4, &herbologiaE4);
    insertarPrimero(materiasAprobadasE4, &astronomiaE4);
    EstudiantePtr e4 = crearEstudiante("Draco Malfoy", materiasAprobadasE4);

    MateriaAprobadaPtr transformacionesE5 = crearMateriaAprobada(getNombre(transformaciones), 7);
    MateriaAprobadaPtr historiaDeLaMagiaE5 = crearMateriaAprobada(getNombre(historiaDeLaMagia), 8);
    ListaPtr materiasAprobadasE5 = crearLista();
    insertarPrimero(materiasAprobadasE5, &transformacionesE5);
    insertarPrimero(materiasAprobadasE5, &historiaDeLaMagiaE5);
    EstudiantePtr e5 = crearEstudiante("Neville Longbottom", materiasAprobadasE5);

    // Creo estudiantes sin materias aprobadas
    ListaPtr materiasAprobadasE6 = crearLista();
    EstudiantePtr e6 = crearEstudiante("Peter Pettigrew", materiasAprobadasE6);

    ListaPtr materiasAprobadasE7 = crearLista();
    EstudiantePtr e7 = crearEstudiante("Ginny Weasley", materiasAprobadasE7);

    ListaPtr materiasAprobadasE8 = crearLista();
    EstudiantePtr e8 = crearEstudiante("Cedric Diggory", materiasAprobadasE8);

    ListaPtr materiasAprobadasE9 = crearLista();
    EstudiantePtr e9 = crearEstudiante("Cho Chang", materiasAprobadasE9);

    ListaPtr materiasAprobadasE10 = crearLista();
    EstudiantePtr e10 = crearEstudiante("Luna Lovegood", materiasAprobadasE10);

    // Hora de inscribir

    /// Artes Oscuras - 5 cupos
    inscribirEstudiante(artesOscuras, e1);
    inscribirEstudiante(artesOscuras, e2);
    inscribirEstudiante(artesOscuras, e6);
    inscribirEstudiante(artesOscuras, e7);
    inscribirEstudiante(artesOscuras, e8);
    inscribirEstudiante(artesOscuras, e10);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(artesOscuras, e3);
    inscribirEstudiante(artesOscuras, e5);
    inscribirEstudiante(artesOscuras, e9);

    /// Vuelo - 2 cupos
    inscribirEstudiante(vuelo, e2);
    inscribirEstudiante(vuelo, e6);
    inscribirEstudiante(vuelo, e7);
    inscribirEstudiante(vuelo, e8);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(vuelo, e9);
    inscribirEstudiante(vuelo, e10);
    inscribirEstudiante(vuelo, e5);

    /// Pociones - 3 cupos
    inscribirEstudiante(pociones, e6);
    inscribirEstudiante(pociones, e7);
    inscribirEstudiante(pociones, e8);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(pociones, e9);
    inscribirEstudiante(pociones, e4);
    inscribirEstudiante(pociones, e10);
    inscribirEstudiante(pociones, e5);

    /// Herbologia - 6 cupos
    inscribirEstudiante(herbologia, e9);
    inscribirEstudiante(herbologia, e10);
    inscribirEstudiante(herbologia, e6);
    inscribirEstudiante(herbologia, e7);
    inscribirEstudiante(herbologia, e8);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(herbologia, e5);
    inscribirEstudiante(herbologia, e3);

    /// Transformaciones - 3 cupos
    inscribirEstudiante(transformaciones, e10);
    inscribirEstudiante(transformaciones, e8);
    inscribirEstudiante(transformaciones, e7);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(transformaciones, e9);
    inscribirEstudiante(transformaciones, e1);
    inscribirEstudiante(transformaciones, e2);
    inscribirEstudiante(transformaciones, e6);
    inscribirEstudiante(transformaciones, e3);
    inscribirEstudiante(transformaciones, e4);

    /// Historia de la Magia - 2 cupos
    inscribirEstudiante(historiaDeLaMagia, e7);
    inscribirEstudiante(historiaDeLaMagia, e9);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(historiaDeLaMagia, e8);
    inscribirEstudiante(historiaDeLaMagia, e4);
    inscribirEstudiante(historiaDeLaMagia, e6);
    inscribirEstudiante(historiaDeLaMagia, e1);
    inscribirEstudiante(historiaDeLaMagia, e10);

    /// Encantamientos - 2 cupos
    inscribirEstudiante(encantamientos, e7);
    inscribirEstudiante(encantamientos, e8);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(encantamientos, e5);
    inscribirEstudiante(encantamientos, e6);
    inscribirEstudiante(encantamientos, e4);
    inscribirEstudiante(encantamientos, e9);
    inscribirEstudiante(encantamientos, e3);
    inscribirEstudiante(encantamientos, e10);

    /// Astronomia - 3 cupos
    inscribirEstudiante(astronomia, e7);
    inscribirEstudiante(astronomia, e8);
    inscribirEstudiante(astronomia, e9);
    // Estos deberían ir a la cola de espera
    inscribirEstudiante(astronomia, e10);
    inscribirEstudiante(astronomia, e5);
    inscribirEstudiante(astronomia, e6);
    inscribirEstudiante(astronomia, e3);

    // Muestro resultados
    MateriaPtr materiaAMostrar = transformaciones; /// <--- Cambiar aca por cualquier materia para ver los resultados
    // artesOscuras - vuelo - pociones - herbologia - transformaciones - historiaDeLaMagia - encantamientos - astronomia
    printf("-------------------------------\n");
    printf("Inscriptos en %s:\n", getNombre(materiaAMostrar));
    printf("-------------------------------\n");
    mostrarListaGenerica(getInscriptos(materiaAMostrar), mostrarEstudianteDatoPtr);

    printf("------------------------------------\n");
    printf("Lista de espera en %s:\n", getNombre(materiaAMostrar));
    printf("------------------------------------\n");
    mostrarListaGenerica(getEstudiantesEnEspera(materiaAMostrar), mostrarEstudianteDatoPtr);
    printf("---------------------------------------------\n");
    printf("Lista de espera en %s ordenada:\nEsta lista es la que usamos para encolar!\n", getNombre(materiaAMostrar));
    printf("---------------------------------------------\n");
    encolarEstudiantes(materiaAMostrar);
    mostrarListaGenerica(getEstudiantesEnEspera(materiaAMostrar), mostrarEstudianteDatoPtr);

    // Libero memoria
    liberarMateria(artesOscuras);
    liberarMateria(vuelo);
    liberarMateria(pociones);
    liberarMateria(herbologia);
    liberarMateria(transformaciones);
    liberarMateria(historiaDeLaMagia);
    liberarMateria(encantamientos);
    liberarMateria(astronomia);

    liberarEstudiante(e1);
    liberarEstudiante(e2);
    liberarEstudiante(e3);
    liberarEstudiante(e4);
    liberarEstudiante(e5);
    liberarEstudiante(e6);
    liberarEstudiante(e7);
    liberarEstudiante(e8);
    liberarEstudiante(e9);
    liberarEstudiante(e10);

    return 0;
}
