#define MAX 50
#include <stdio.h>
#include "tad_pilha.h"
/* aqui vao as declaracoes iniciais e os codigos das funcoes */
/* inicio das suas modificacoes nesta parte                  */

/*typedef struct tad_pilha */
/*{			   */
/*	char pilha[MAX];   */
/*	int tamanho;       */
/*} tad_pilha ;            */


void inicializa_pilha (tad_pilha *p)
{
		(*p).tamanho=0;
}

int pilha_vazia (tad_pilha *p)
{
		if (! (*p).tamanho)
					return 1;
			return 0;
}

int tamanho_pilha (tad_pilha *p)
{
		return (*p).tamanho;
}

int empilha (float x, tad_pilha *p)
{
		if ((*p).tamanho+1 > MAX)
					return 0;
			(*p).pilha[(*p).tamanho]=x;
				(*p).tamanho=(*p).tamanho+1;
					return 1;
}

int desempilha (float *t, tad_pilha *p)
{
		if (! (*p).tamanho)
					return 0;
			(*p).tamanho=(*p).tamanho-1;
				*t=(*p).pilha[(*p).tamanho];
					return 1;
}

int topo (float *t, tad_pilha *p)
{
		if (! (*p).tamanho)
					return 0;
			*t=(*p).pilha[(*p).tamanho-1];
				return 1;
}


/* fim das suas modificacoes desta parte                     */




































