#include "lib_fila.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_fila (tipo_fila *F)
{
	t_nodo *ini = (t_nodo *) malloc (sizeof(t_nodo));
	t_nodo *fim = (t_nodo *) malloc (sizeof(t_nodo));
                                                        
	if ((ini == NULL) || (fim == NULL))			
	{
		free (ini);
		free (fim);
		return 0;
	}
	                                                        
	ini->prox = fim;
	fim->prev = ini;
                                                        
	ini->prev = NULL;
	fim->prox = NULL;

	ini->t    = -1;
	ini->id   = -1;
	fim->t    = -1;
	fim->id   = -1;
                                                        
	F->ini = ini;						
	F->fim = fim;
	F->tamanho = 0;
	return 1;						
}

int fila_vazia(tipo_fila *F)
{
	if (!(F->tamanho))
		return 1;
	return 0;
}

int tamanho (tipo_fila *F)
{
	if (F == NULL)
		return -1;
	return (F->tamanho);
}

int enfileira (int id, int t, tipo_fila *F)
{
	t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));
	if ( new == NULL )
	{
		return 0;
	}
	new->prox = F->fim;
	new->prev = F->fim->prev;
	new->id = id;
	new->t = t;
	F->fim->prev->prox = new;
	F->fim->prev = new;
	F->tamanho++;
	return 1;
}

int desenfileira (int *id, int *t, tipo_fila *F)
{
	if (!(F->tamanho))
		return 0;
	F->ini->prox 		  = F->ini->prox->prox;		/*o prix do ini recebe o segundo elemento*/
	F->ini->prox->prev->prev  = NULL;  			/*o prev do primeiro elemento recebe nulo*/
	*id 			  = F->ini->prox->prev->id;
	*t 			  = F->ini->prox->prev->t;
	F->ini->prox->prev->prox  = NULL; 			/*o prox do primeiro elemento recebe nulo*/ 
	free (F->ini->prox->prev);	  			/*free no primeiro elemento*/
	F->ini->prox->prev 	  = F->ini;	  		/*o prev do segundo elemento recebe o ini*/
	F->tamanho--;
	return 1;
}

int remove_fila (int *id, int *t, tipo_fila *F)
{
	t_nodo *p;
	p = F->ini->prox;
	while ((p->prox != NULL) && ((p->id != *id) || (p->t != *t)))
	{
		p = p->prox;
	}
	if ((p->id != *id) || (p->t != *t))
		return 0;
	else
	{
		p->prox->prev = p->prev;
		p->prev->prox = p->prox;
		p->prev       = NULL;
		p->prox	      = NULL;
		free(p);
		F->tamanho--;
		return 1;
	}
}

void imprime_fila(tipo_fila *F)
{
	if (F->tamanho)
	{
		t_nodo *p = F->ini->prox;
		while (p->prox != NULL)
		{
			printf(" %d",p->id);
			if (p->t != -1)
				printf("(%d)",p->t);
			if (p->prox->prox != NULL)
				printf(",");
			p = p->prox;
		}
	}
	printf("\n");
}

int main ()
{
	tipo_fila F;
	tipo_fila G;
	int id;
	int t;
	if (inicializa_fila(&F))
		printf("Fila F criada\n");
	if (inicializa_fila(&G))
		printf("Fila G criada\n");
	int i;
	for ( i=0 ; i<5 ; i++)
	{
		if (! enfileira(2*i+1,3*i,&F))
			printf("Deu ruim com F - %d\n",i);
	}
	for ( i=1 ; i<6 ; i++)
	{
		if (! enfileira(2*i,-1,&G))
			printf("Deu ruim com G - %d\n",i);
	}
	printf("F %d ->",tamanho(&F));
	imprime_fila(&F);
	printf("G %d ->",tamanho(&G));
	imprime_fila(&G);
	if (desenfileira(&id,&t,&F))
		printf ("Remove id-> %d t-> %d\n",id,t);
	if (desenfileira(&id,&t,&G))
		printf ("Remove id-> %d t-> %d\n",id,t);
	printf("F %d ->",tamanho(&F));
        imprime_fila(&F);
        printf("G %d ->",tamanho(&G));
        imprime_fila(&G);
	id = 5;
	t  = 6;
	if (remove_fila(&id,&t,&F))
		printf("Remove id-> %d t-> %d\n",id,t);
	id = 6;
	t  = -1;
	if (remove_fila(&id,&t,&G))
		printf("Remove id-> %d t-> %d\n",id,t);
	printf("F %d ->",tamanho(&F));
        imprime_fila(&F);
	printf("G %d ->",tamanho(&G));
	imprime_fila(&G);
	for (i=0 ; i<3 ; i++)
	{
		if (desenfileira(&id,&t,&F))
	        	printf ("Remove id-> %d t-> %d\n",id,t);
	        if (desenfileira(&id,&t,&G))
	        	printf ("Remove id-> %d t-> %d\n",id,t);
	}
	printf("F %d ->",tamanho(&F));
	imprime_fila(&F);
	printf("G %d ->",tamanho(&G));
	imprime_fila(&G);
	return 1;
}
