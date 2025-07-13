#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED

struct MateriaAprobada;
typedef struct MateriaAprobada * MateriaAprobadaPtr;

/// Constructor
MateriaAprobadaPtr crearMateriaAprobada(char* nombre, float nota);

/// Destructor
void liberarMateriaAprobada(MateriaAprobadaPtr m);

/// Getters y Setters
char* getNombreMateriaAprobada(MateriaAprobadaPtr m);
int getNota(MateriaAprobadaPtr m);

void setNombreMateriaAprobada(MateriaAprobadaPtr m, char* nuevoNombre);
void setNota(MateriaAprobadaPtr m, int nuevaNota);

/// Funciones y Metodos



#endif // MATERIAAPROBADA_H_INCLUDED
