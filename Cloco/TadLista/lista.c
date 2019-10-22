#include <stdlib.h>
#include <stdio.h>

typedef struct t_nodo
{
	int chave;
	struct t_nodo *prox;
} t_nodo;

typedef struct t_lista
{
	t_nodo *ini;
	int tamanho;
}t_lista;			

int cria_lista (t_lista *l)
{
	l->ini = NULL;
	l->tamanho = 0;
	return 1;
}

int lista_vazia (t_lista *l)
{
	if ( (l->tamanho) != 0 )
	{
		return 0;
	}
	return 1;
}

void destroi_lista(t_lista *l)
{
	if (l->ini != NULL)
	{
		t_nodo *p = l->ini;
		while ( p->prox != NULL )
		{ 
			l->ini = p->prox;		/*inicio aponta pro proximo*/
			free(p);			/*libera anterior*/
			p = l->ini;			/*p é p proximo*/
		}
		free(p);
		l->ini = NULL;
		l->tamanho = 0;
	}
}

int insere_inicio_lista(int x, t_lista *l)
{
	t_nodo *new = malloc (sizeof(t_nodo));	/*aloca espaço pro novo elemento*/
	new->chave = x;				
	new->prox = l->ini;			/*new->prox aponta pro antigo inicio*/
	l->ini = new;				/*new é o novo inicio*/
	l->tamanho++;
	return 1;
}

int insere_fim_lista(int x, t_lista *l)
{
	t_nodo *p = l->ini;
	if (p != NULL)
	{
		while ( p->prox != NULL )		/*encontra o ultimo elemento*/
		{
			p = p->prox;
		}
	}
	t_nodo *new = malloc (sizeof(t_nodo));
	if (p != NULL)
	{
		p->prox = new;
	}
	else
	{
		l->ini = new;
	}
	new->chave = x;
	new->prox = NULL;
	l->tamanho++;
	return 1;
}

int insere_ordenado_lista(int x, t_lista *l)
{
	if ((l->ini != NULL)&&(l->ini->chave < x))
	{
		t_nodo *p = l->ini;
		t_nodo *q;
		while ((p != NULL) && (p->chave < x))
		{
			q = p;
			p = p->prox;
		}
		t_nodo *new = malloc (sizeof(t_nodo));
		q->prox = new;
		new->prox = p;
		new->chave = x;
	}
	else
	{
		t_nodo *new = malloc (sizeof(t_nodo));
		new->prox = l->ini;
		new->chave = x;
		l->ini = new;
	}
	l->tamanho++;
	return 1;
}

void imprime_lista (t_lista *l)
{
	if ( l->tamanho != 0 )
	{
		t_nodo *p = l->ini;
		printf (" tam : %d -> ",l->tamanho);
		if ( p != NULL )
		{
			printf ("%d ", p->chave);
			while ( p->prox != NULL )
			{
				p = p->prox;
				printf("%d ", p->chave);
			}
		}
	}
	printf("\n");
}

int remove_primeiro_lista(int *item, t_lista *l)
{
	if (l->ini != NULL)
	{
		*item = l->ini->chave;
		l->ini = l->ini->prox;
		l->tamanho--;
		return 1;
	}
	else
	{
		return 0;
	}
}

int remove_ultimo_lista(int *item, t_lista *l)
{
	if (l->tamanho != 0)
	{
		t_nodo *p = l->ini;
		if (l->tamanho > 1)
		{
			t_nodo *q;
			while (p->prox != NULL)
			{
				q = p;
				p = p->prox;
			}
			*item = p->chave;
			q->prox = NULL;
		}
		else
		{
			*item = p->chave;
			l->ini = NULL;
		}
		l->tamanho--;
		return 1;
	}
	else
	{
		return 0;
	}
}

int remove_item_lista(int chave, int *item, t_lista *l)
{
	if (l->tamanho > 0)
	{
		t_nodo *p = l->ini;
		if (p->chave == chave)
		{
			*item = p->chave;
			l->ini = p->prox;
			l->tamanho--;
		}
		else
		{
			t_nodo *q;
			while (p->prox != NULL)
			{
				q = p;
				p = p->prox;
				if (p->chave == chave)
				{
					*item = p->chave;
					q->prox = p->prox;
					printf("removeu %d\n",*item);
					l->tamanho--;
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int pertence_lista(int chave, t_lista *l)
{
	return 1;
}

int concatena_listas(t_lista *l, t_lista *m)
{
	return 1;
}

int copia_lista(t_lista *l, t_lista *m)
{
	cria_lista (m);
	t_nodo *p = l->ini;
	if (p != NULL)
	{
		t_nodo *new;
		new = malloc (sizeof(t_nodo));
		m->ini = new;
		new->chave = p->chave;
		new->prox = NULL;
		t_nodo *q = new;
		p = p->prox;
		m->tamanho = 1;
		while (p != NULL)
		{
			new = malloc (sizeof(t_nodo));
			q->prox = new;
			new->chave = p->chave;
			q = new;
			p = p->prox;
			m->tamanho++;
		}
		return 1;
	}
	else
	{
		return 0;
	}	
}

