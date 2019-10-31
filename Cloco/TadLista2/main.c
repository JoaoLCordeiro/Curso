#include "lib_lista.h"
#include "lib_lista_complementar.h"
#include <stdio.h>

int main ()
{
	int taml,tamm;
	int elmnt;
	
	printf("Escreva o tamanho da primeira lista\n");
	scanf("%d",&taml);
	printf("Escreva os elementos da lista\n");
	int i;
	t_lista l;
	inicializa_lista(&l);
	for (i=0 ; i<taml ; i++)
	{
		scanf("%d",&elmnt);
		insere_fim_lista(elmnt,&l);
	}
							
	printf("Escreva o tamanho da segunda lista\n");
        scanf("%d",&tamm);
        printf("Escreva os elementos da lista\n");
        t_lista m;
        inicializa_lista(&m);
        for (i=0 ; i<tamm ; i++)
        {
        	scanf("%d",&elmnt);
        	insere_fim_lista(elmnt,&m);
        }							
	
	printf("\n");
	printf("Imprimindo as listas originais\n");
	printf("l -> ");
	imprime_lista(&l);
	printf("m -> ");
	imprime_lista(&m);

	printf("\n");
	t_lista o;
	inicializa_lista(&o);
	copia_lista(&l,&o);
	printf("Imprimindo a copia da primeira lista\n");
        printf("o -> ");
	imprime_lista(&o);

	printf("\n");
	concatena_listas(&m,&o);
	printf("Imprimindo concatenação da segunda lista com a cópia da primeira\n");
	printf("m -> ");
	imprime_lista(&m);
	
	printf("\n");
	ordena_lista(&l);
	ordena_lista(&m);
	printf("Imprimindo listas ordenadas\n");
	printf("l -> ");
	imprime_lista(&l);
	printf("m -> ");
        imprime_lista(&m);

	printf("\n");
        intercala_listas(&l,&m,&o);
        printf("Imprimindo intercalação entre a primeira lista com a atual segunda lista\n");
        printf("o -> ");
        imprime_lista(&o);									

	return 1;
}
