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
	else
	{
		printf("Nao destruida: lista vazia");
	}
}

int insere_inicio_lista(int x, t_lista *l)
{
	t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));	/*aloca espaço pro novo elemento*/
	new->chave = x;				
	new->prox = l->ini;					/*new->prox aponta pro antigo inicio*/
	l->ini = new;						/*new é o novo inicio*/
	l->tamanho++;
	return 1;
}

int insere_fim_lista(int x, t_lista *l)
{
	t_nodo *p = l->ini;
	if (p != NULL)
	{
		while ( p->prox != NULL )			/*encontra o ultimo elemento*/
		{
			p = p->prox;
		}
	}
	t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));		
	if (p != NULL)						/*se tem algum elemento na lista*/
	{
		p->prox = new;
	}
	else							/*caso seja o primeiro elemento da lista*/
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
	if ((l->ini != NULL)&&(l->ini->chave < x))		/*se tiver algum elemento na lista e o nao for pra inserir no comeco*/
	{
		t_nodo *p = l->ini;
		t_nodo *q;
		while ((p != NULL) && (p->chave < x))		/*enquanto nao chega no final da lista e os elementos forem menores que x*/
		{
			q = p;
			p = p->prox;
		}
		t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));
		q->prox = new;
		new->prox = p;
		new->chave = x;
	}
	else
	{
		t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));		/*aqui simplesmente insere no comeco*/
		new->prox = l->ini;
		new->chave = x;
		l->ini = new;
	}
	l->tamanho++;
	return 1;
}

void imprime_lista (t_lista *l)
{
	if ( l->tamanho != 0 )					/*se tiver elemento na lista*/
	{
		t_nodo *p = l->ini;
		printf ("tam: %d -> ",l->tamanho);
		if ( p != NULL )
		{
			printf ("%d ", p->chave);
			while ( p->prox != NULL )		/*ate chegar no final da lista*/
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
	if (l->ini != NULL)					/*se tiver elemento na lista*/
	{
		*item = l->ini->chave;
		t_nodo *p = l->ini;
		l->ini = l->ini->prox;
		free (p);
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
	if (l->tamanho != 0)					/*se tiver elemento na lista*/
	{
		t_nodo *p = l->ini;
		if (l->tamanho > 1)				/*se tiver mais que um na lista*/
		{
			t_nodo *q;
			while (p->prox != NULL)			/*até chegar no fim da lista*/
			{
				q = p;
				p = p->prox;
			}
			*item = p->chave;
			free(p);
			q->prox = NULL;
		}
		else						/*se tiver só 1 elemento*/
		{
			*item = p->chave;
			free(l->ini);
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
	if (l->tamanho > 0)					/*se tiver elemento na lista*/
	{
		t_nodo *p = l->ini;
		if (p->chave == chave)				/*se o primeiro elemento for o desejado*/
		{
			*item = p->chave;
			l->ini = p->prox;
			free(p);
			l->tamanho--;
			return 1;
		}
		else
		{
			t_nodo *q;
			while (p->prox != NULL)			/*até chegar no fim da lista*/
			{
				q = p;
				p = p->prox;
				if (p->chave == chave)		/*se achar o elemento desejado*/
				{
					*item = p->chave;
					q->prox = p->prox;
					free(p);
					l->tamanho--;
					return 1;
				}
			}
		}
		printf ("Nao removido: elemento nao encontrado\n");
		return 0;
	}
	else
	{
		return 0;
	}
}

int pertence_lista(int chave, t_lista *l)
{
	t_nodo *p = l->ini;
	while (p != NULL)					/*até chegar no fim*/
	{
		if (p->chave == chave)				/*se achar o elemento*/
		{
			return 1;
		}
		p = p->prox;
	}
	return 0;
}

int concatena_listas(t_lista *l, t_lista *m)
{
	t_nodo *p = l->ini;
	if (p != NULL)						/*se tiver elementos em l*/
	{
		while (p->prox != NULL)				/*até chegar no fim*/
		{
			p = p->prox;
		}
		p->prox = m->ini;
		m->ini = NULL;
		l->tamanho = l->tamanho + m->tamanho;
		m->tamanho = 0;
	}
	else							/*se nao tiver elemento em l*/
	{
		l->ini = m->ini;				/*o inicio de l recebe inicio de m*/
		l->tamanho = m->tamanho;
	}
	return 1;
}

int copia_lista(t_lista *l, t_lista *m)
{
	cria_lista (m);
	t_nodo *p = l->ini;
	if (p != NULL)						/*se tem elementos na lista*/
	{
		t_nodo *new;
		new = malloc (sizeof(t_nodo));
		m->ini = new;
		new->chave = p->chave;
		new->prox = NULL;
		t_nodo *q = new;
		p = p->prox;
		m->tamanho = 1;					/*até aqui, copiou o primeiro elemento*/
		while (p != NULL)				/*até chegar no fim*/
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

