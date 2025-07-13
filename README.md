# SIU Guaraní: Edición Hogwarts 🏰✨

Un simulador de un sistema de inscripción universitaria, desarrollado en C, inspirado en el SIU Guaraní real y traído a la vida con una temática de Harry Potter. Este proyecto es el trabajo práctico final para la materia "Algoritmos y Estructuras de Datos" de la Universidad Nacional de Lanús (UNLa).

El sistema gestiona la inscripción a materias, manejando los casos en que la demanda de estudiantes supera el cupo a través de una lista de espera priorizada.

---

## 📚 Características Principales

* **Gestión de Materias y Estudiantes:** Permite crear dinámicamente materias con cupos limitados y estudiantes con su historial académico.
* **Sistema de Inscripción:** Los estudiantes pueden inscribirse a las materias disponibles. Si una materia está llena, son asignados a una lista de espera.
* **Lista de Espera Priorizada:** La lista de espera no es una simple cola. Se ordena en base a criterios específicos para determinar quién obtiene una vacante si se libera un lugar.
* **Lógica de Priorización Inteligente:**
    1.  Los estudiantes con mayor **cantidad de materias aprobadas** tienen prioridad.
    2.  Si hay un empate en la cantidad de materias, el estudiante con el **promedio académico más alto** tiene la prioridad.
* **Datos Temáticos:** El proyecto utiliza personajes y materias del universo de Harry Potter para ofrecer una demostración divertida y dinámica de la funcionalidad del sistema.

---

## 🛠️ Estructuras de Datos Utilizadas

Este proyecto se basa en estructuras de datos fundamentales en C para gestionar el flujo y las relaciones de la información:

* **Listas Enlazadas (`Lista`):** Se utilizan para gestionar la lista de inscriptos en una materia, así como la lista de materias aprobadas de cada estudiante.
* **Colas (`Cola`):** Se implementan para manejar la lista de espera de las materias una vez que el cupo de inscripción se ha alcanzado, asegurando que los estudiantes sean procesados en el orden de prioridad correcto.

---

## 📂 Estructura del Proyecto

El proyecto está organizado en varios módulos interconectados, cada uno manejando una estructura de datos o un componente lógico específico:

```
.
├── main.c                  # Punto de entrada principal, configuración y demostración
├── estudiante.h            # Cabecera para la estructura y funciones de Estudiante
├── estudiante.c            # Implementación de la lógica de Estudiante
├── materia.h               # Cabecera para la estructura y funciones de Materia
├── materia.c               # Implementación de la lógica de Materia
├── materiaAprobada.h       # Cabecera para MateriaAprobada
├── materiaAprobada.c       # Implementación de MateriaAprobada
├── lista.h                 # Cabecera para la estructura de datos genérica Lista Enlazada
├── lista.c                 # Implementación de la Lista Enlazada
├── cola.h                  # Cabecera para la estructura de datos genérica Cola
├── cola.c                  # Implementación de la Cola
└── nodo.h                  # Cabecera para el Nodo genérico, usado por listas y colas
└── nodo.c                  # Implementación del Nodo
```

---

## 🚀 Cómo Empezar

Este proyecto fue desarrollado utilizando el IDE Code::Blocks.

### Prerrequisitos

* Se requiere un compilador de C (como GCC).
* Asegúrate de que todos los archivos `.c` y `.h` estén en el mismo directorio.

### Compilación y Ejecución

1.  **Clona el repositorio:**
    ```bash
    git clone [https://github.com/ivann-bravo/siu-guarani-hogwarts.git](https://github.com/ivann-bravo/siu-guarani-hogwarts.git)
    cd siu-guarani-hogwarts
    ```

2.  **Compila desde la línea de comandos:**
    Puedes compilar todos los archivos `.c` juntos usando GCC:
    ```bash
    gcc main.c estudiante.c materia.c materiaAprobada.c lista.c cola.c nodo.c -o siu_hogwarts
    ```

3.  **Ejecuta el programa:**
    ```bash
    ./siu_hogwarts
    ```

El programa imprimirá en pantalla los resultados de la inscripción para una materia preseleccionada, mostrando la lista de inscriptos y la lista de espera ordenada por prioridad. Puedes cambiar la materia que se muestra modificando la línea 194 en `main.c`.
  ```bash
    // Muestro resultados
    MateriaPtr materiaAMostrar = transformaciones; /// <--- Cambiar aca por cualquier materia para ver los resultados
    // artesOscuras - vuelo - pociones - herbologia - transformaciones - historiaDeLaMagia - encantamientos - astronomia
  ```
---

**Realizado por Iván Bravo para Algoritmos y Estructuras de Datos - UNLa.**
