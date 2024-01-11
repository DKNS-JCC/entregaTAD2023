#include <stdio.h>
#include <stdlib.h>
#include "insercion.h"
#include "listas/lista.h"

// Ordenacion por insercion directa
int insercion(Lista *l)
{
    Lista lista_aux;
    int x, p, q, ultimo;
    tipoPosicion inicio, p_ref, q_ref, ultimo_ref;

    inicio = siguiente(primero(l), l);

    // CREAR LISTA AUXILIAR
    if (creaVacia(&lista_aux) != 0)
    {
        return -1;
    }
    anula(&lista_aux);

    if (vacia(l) != 0)
    {
        destruye(&lista_aux);
        return -1;
    }
    // DIVIDIR LA LISTA EN DOS
    if (dividirLista(l, inicio, &lista_aux))
    {
        destruye(&lista_aux);
        return -1;
    }

    while (fin(&lista_aux) != primero(&lista_aux))
    {
        q_ref= primero(&lista_aux);
        q = recupera(q_ref, &lista_aux);
        p_ref = primero(l);
        p = recupera(p_ref, &lista_aux);
        ultimo_ref = fin(l);
        ultimo=recuperaUltimo(l);


        if (ultimo < q)
        {                                                  
            traspasarNodo(q_ref, &lista_aux, ultimo_ref, l); // traspasamos el ultimo elemento a la lista 1
        }
        else 
        {
            while (p < q && siguiente(p_ref, l) != NULL) 
            {
                p_ref = siguiente(p_ref, l);
                p = recupera(p_ref, l);
            }
            traspasarNodo(q_ref, &lista_aux, p_ref, l); 
        }

    }
    anula(&lista_aux);
    destruye(&lista_aux);
    return 0;
}