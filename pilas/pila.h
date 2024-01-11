#ifndef __PILA_H
#define __PILA_H

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

typedef tipoCelda *Pila;

int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p, int elemento);

int pilaSuprime(Pila *p);

#endif
