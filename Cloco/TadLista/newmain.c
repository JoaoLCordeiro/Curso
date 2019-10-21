#include "lista.h"
#include <stdio.h>

int main ()
{
	printf("Insere ordenado");
	t_lista l;
	cria_lista(&l);
	insere_ordenado_lista(8,&l);
	insere_ordenado_lista(10,&l);
	insere_ordenado_lista(9,&l);
	insere_ordenado_lista(6,&l);
	insere_ordenado_lista(7,&l);
	insere_ordenado_lista(11,&l);
	imprime_lista(&l);
	return 0;
}
