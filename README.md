# Proyecto de Implementación de TADs

Este repositorio contiene la práctica obligatoria para todos los grupos, centrándose en la implementación y/o utilización de Tipos Abstractos de Datos (TADs) discutidos en teoría y detallados en los enunciados prácticos del tema. En resumen, las tareas incluyen:

1. **Implementación del Algoritmo de Ordenación Inserción Directa usando el TAD Lista:**
    - Código para la implementación del algoritmo de ordenación Inserción Directa utilizando el TAD Lista.
    
2. **Extensión del TAD Lista para Inserción Directa:**
    - Ampliación del TAD Lista con funciones adicionales para facilitar la nueva implementación de Inserción Directa.

3. **Estudio Experimental del Algoritmo Implementado:**
    - Realizar un estudio experimental del algoritmo implementado y compararlo con el estudiado en clase.

4. **Implementación del TAD Pila mediante Lista Simplemente Enlazada (sin nodo ficticio):**
    - Código para la implementación del TAD Pila utilizando una lista simplemente enlazada sin nodo ficticio.

5. **Implementación del TAD Cola mediante Lista Simplemente Enlazada (sin nodo ficticio):**
    - Código para la implementación del TAD Cola utilizando una lista simplemente enlazada sin nodo ficticio.

## Estructura del Proyecto

La estructura del proyecto incluye los siguientes archivos y carpetas:

- **`entregaTAD2023.pdf`:**
  - Instrucciones detalladas para la práctica.
  
- **`pruebaInsercion.c`:**
  - Archivo de código en C con una función `main()` y todo lo necesario para probar el algoritmo de ordenación Inserción Directa.
  
- **Carpeta `listas`:**
  - Contiene el archivo de cabecera `lista.h` para el TAD Lista.

- **Carpeta `pilas`:**
  - Contiene el archivo de cabecera `pila.h` con definiciones de tipos y prototipos para el TAD Pila.

- **Carpeta `colas`:**
  - Contiene el archivo de cabecera `cola.h` con definiciones de tipos y prototipos para el TAD Cola.

- **`makefile`:**
  - Permite la compilación de `pruebaInsercion.c` utilizando la implementación del TAD Lista.
