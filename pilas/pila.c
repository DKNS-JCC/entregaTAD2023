#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"

int pilaCreaVacia(Pila *p)
{
    Pila pila;
    pila = (Pila)malloc(sizeof(tipoCelda));
    if (pila == NULL)
    {
        return -1;
    }
    pila->sig = NULL;
    *p = pila;
    return 0;
}

// -1 = error, 1 = vacia, 0 = no vacia
int pilaVacia(Pila *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else if ((*p)->sig == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// añade un elemento a la pila
int pilaInserta(Pila *p, int elemento)
{
    Pila pila_nueva;
    pila_nueva = (Pila)malloc(sizeof(tipoCelda));
    if (pila_nueva == NULL)
    {
        return -1;
    }
    pila_nueva->elemento = elemento;
    pila_nueva->sig = *p; // el siguiente de la nueva pila es la pila anterior
    *p = pila_nueva;      // la nueva pila es el inicio de la pila anterior
    return 0;
}

//-1 = error, -2 = vacia, 0 = primer elemento eliminado
int pilaSuprime(Pila *p)
{
    Pila pila_aux;
    if (p == NULL)
    {
        return -1;
    }
    else if ((*p)->sig == NULL)
    {
        return -2;
    }
    else
    {
        pila_aux = *p;  // pila_aux es el primer elemento de la pila
        *p = (*p)->sig; // p pasa a ser el segundo elemento de la pila
        free(pila_aux); // se libera el primer elemento de la pila
        return 0;
    }
}
