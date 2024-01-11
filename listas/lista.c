#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

int creaVacia(Lista *l){
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}

int anula(Lista *l){
    tipoPosicion p;
    if (l == NULL || l->raiz == NULL) {
    	return -1;
    }
    p = l->raiz->sig;
    while (p !=NULL) {
    	l->raiz->sig = p->sig;
    	free (p);
    	p = l->raiz->sig;
    }
    l->ultimo = l->raiz;
    return 0;
}

int vacia(Lista *l){
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int inserta(int x, tipoPosicion p, Lista *l){
    tipoCelda *nuevo;

    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return -1;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return -2;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return -3;
    }
    else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        fprintf(stderr,"Fallo: Error en la reserva de memoria.\n");
        return -4;
    }
    else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo;
        return 0;
    }
}

int suprime (tipoPosicion p, Lista *l){
    tipoCelda *ant;

    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return -1;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return -2;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return -3;
    }
    else {
        ant = anterior (p, l);
	    ant->sig = p->sig;
	    if (p==l->ultimo) {
	    	l->ultimo = ant;
	    }
	    free (p);
        return 0;
    }
}

tipoPosicion localiza(int x, Lista *l){
    tipoPosicion p;

    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return NULL;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return NULL;
    }
    else {
        p = l->raiz;
        while (p->sig != NULL && p->sig->elemento != x){
            p = p->sig;
        }
        return p;
    }
}

int recupera(tipoPosicion p, Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return -1;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return -2;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return -3;
    }
    else if (p == fin(l)){
    	return p->elemento;	
	}
    return p->sig->elemento;
}

tipoPosicion primero(Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return NULL;
    }
    else if (l->raiz == NULL){
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return NULL;
    } else{
        return l->raiz;
    }
}

tipoPosicion siguiente(tipoPosicion p, Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return NULL;
    }
    else if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return NULL;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return NULL;
    }
    else
        return p->sig;
}

tipoPosicion anterior(tipoPosicion p, Lista *l){
    tipoCelda *anterior;

    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return NULL;
    }
    if (l->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return NULL;
    }
    if (p == NULL) {
        fprintf(stderr,"Fallo: Posicion no valida .\n");
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}

tipoPosicion fin(Lista *l){
    if (l == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return NULL;
    }
    else if (l->ultimo == NULL){
        fprintf(stderr,"Fallo: Ultimo no existente.\n");
        return NULL;
    }
    else{
        return l->ultimo;
    }
}

void imprime(Lista *l){
    tipoCelda *aImprimir;
    int posicion;

    if (l == NULL || l->raiz == NULL) {
        fprintf(stderr,"Fallo: Lista no existente o nodo ficticio no existe.\n");
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig; 
        printf("\n      Lista:\n");
        while (aImprimir != NULL) {
            printf ("         Posicion %d: %d\n",posicion , aImprimir->elemento);
            aImprimir = aImprimir->sig;
            posicion++;
        }
    }
}

int destruye(Lista *l){
    if (l == NULL || l->raiz == NULL) {
        fprintf(stderr,"Fallo: Lista no existente o nodo ficticio no existe.\n");
        return -1;
    }
    else if (l->raiz->sig != NULL){
        fprintf(stderr,"Fallo: Lista no vacia.\n");
        if(anula(l) == 0){
            fprintf(stdout,"Lista vaciada exitosamente, procediendo a eliminar lista.\n");
            if(destruye(l) == 0){
                return 0;
            }
        }
        else{
            return -2;
        }
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}

int recuperaUltimo(Lista *l){
    if (l == NULL || l->raiz == NULL) {
        fprintf(stderr,"Fallo: Lista no existente o nodo ficticio no existe.\n");
        return -1;
    }
    else if (l->ultimo == NULL){
        fprintf(stderr,"Fallo: Ultimo no existente.\n");
        return -2;
    }
    else{
        return l->ultimo->elemento;
    }
}

int traspasarNodo(tipoPosicion p, Lista* la, tipoPosicion q, Lista* lb) {
    if (la == NULL || lb == NULL) {
		fprintf(stderr,"Fallo: Lista no existente");
    	return -1;  
    }else if (la->raiz == NULL || lb->raiz == NULL) {
		fprintf(stderr,"Fallo: Nodo ficticio no existente");
    	return -2;  
    }else if (p == NULL || q == NULL) {
		fprintf(stderr,"Fallo: Posicion no validadgergerhehet");
    	return -3;  
    }else if(q==fin(lb)){

    	int x = recupera(p, la);

    	if(inserta(x, q, lb) == 0){

    		if(suprime(siguiente(p,la), la) == 0){
    			return 0;
			}
		}
	}else{
		tipoCelda *aux;
		tipoCelda *auxQ;
		auxQ= anterior (q,lb);

		aux = p->sig;
		p->sig = aux->sig;
		aux->sig = q->sig;
		q->sig = aux;

		if(p->sig == NULL){
			la->ultimo = p;
		}
		if(q->sig == NULL){
			lb->ultimo = q;
		}
		return 0;

	}

}

int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva){
    tipoCelda *aux;

    if (lOrigen == NULL || lNueva == NULL) {
        fprintf(stderr,"Fallo: Lista no existente.\n");
        return -1;
    }
    else if (lOrigen->raiz == NULL || lNueva->raiz == NULL) {
        fprintf(stderr,"Fallo: Nodo ficticio no existente.\n");
        return -2;
    }
    else if (p == NULL){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return -3;
    }
    else if(p == fin(lOrigen)){
        fprintf(stderr,"Fallo: Posicion no valida.\n");
        return -4; 
    }
    else {
        aux = p->sig;
        p->sig = NULL;
        lNueva->raiz->sig = aux;
        lNueva->ultimo = lOrigen->ultimo;
        lOrigen->ultimo = p;
        return 0;
    }
}