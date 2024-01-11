#ifndef LISTA_H
#define LISTA_H

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda
{
	int elemento;
	struct tipoCelda *sig;
} tipoCelda;
#endif

typedef struct
{
	tipoCelda *raiz, *ultimo;
} Lista;

typedef tipoCelda *tipoPosicion;

// Funciones de la lista
int creaVacia(Lista *l); //
int anula(Lista *l); //
int vacia(Lista *l); //

int inserta(int x, tipoPosicion p, Lista *l); //
int suprime(tipoPosicion p, Lista *l); //
tipoPosicion localiza(int x, Lista *l); // localiza el elemento x en la lista l
int recupera(tipoPosicion p, Lista *l); // devuelve el elemento siguiente a p (nodo + 1)

tipoPosicion primero(Lista *l); //
tipoPosicion siguiente(tipoPosicion p, Lista *l); //
tipoPosicion anterior(tipoPosicion p, Lista *l);	//
tipoPosicion fin(Lista *l); //
tipoPosicion mitad (Lista *l); //

void imprime(Lista *l); //
int destruye(Lista *l); //

int recuperaUltimo(Lista *l); //
int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb); //
int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva); //
#endif
