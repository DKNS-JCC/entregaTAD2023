#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas/lista.h"
#include "insercion.h"


int main(int argc, char *argv[])
{   
	Lista miLista;
	clock_t tiempoI, tiempoF;
	double tiempoT;
	tipoPosicion p;
	int numElementos = 20,i;
	FILE *f; 

	f = fopen("salida.txt", "w+");
  	fprintf(f,"n;tiempoMedio\n");

	if (argc > 2) {
		printf("\n Uso: ./pruebaInsercion <número de elementos de la lista>\n\n");
		return -1;
	}
	if (argc==2) 
		numElementos=atoi(argv[1]); 

	printf("Creando lista vacía: %d\n", creaVacia(&miLista));

	printf("Se crea una lista de %d elementos\n", numElementos);
	anula(&miLista);	
	p = primero(&miLista);
	for (i = 0; i < numElementos; i++) { 
 		
		inserta(rand()%1000000,p,&miLista);
		p = siguiente(p,&miLista);
	}
	imprime(&miLista);
	tiempoI = clock();
	insercion(&miLista);
	tiempoF = clock();
	printf("\nLista Ordenada \n");
	tiempoT = (double)(tiempoF - tiempoI) / CLOCKS_PER_SEC;
	fprintf(f,"%d;%lf\n",numElementos,tiempoT); //FORMATO CSV
	imprime(&miLista);
	printf("\n");
	anula(&miLista);

	destruye(&miLista);
	fclose(f); 
	return 0;
}

