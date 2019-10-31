#include "lib_lista.h"
#include "lib_lista_complementar.h"

/*struct t_nodo {
    int chave;
    struct t_nodo *prox;
    struct t_nodo *prev;
};
typedef struct t_nodo t_nodo;

struct t_lista {
    t_nodo *ini;
    t_nodo *atual;
    t_nodo *fim;
    int tamanho;
};
typedef struct t_lista t_lista;*/


void imprime_lista(t_lista *l)
{
	t_nodo *p = l->ini->prox;
	while (p->prox != NULL)
	{
		printf("%d ",p->chave);
		p = p->prox;
	}
	printf("\n");
}

int copia_lista(t_lista *l, t_lista *c)
{
	t_nodo *p = l->ini->prox;
	if (!(lista_vazia(c)))
	{
		return 0;
	}
	else
	{
		while (p->prox != NULL)
		{
			t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));
			new->prev = c->fim->prev;
			new->prox = c->fim;
			c->fim->prev->prox = new;
			c->fim->prev = new;
			new->chave = p->chave;
			p = p->prox;
		}
		c->tamanho = l->tamanho;
		return 1;
	}
}

int concatena_listas(t_lista *l, t_lista *c)
{
	l->fim->prev->prox = c->ini->prox;
	c->ini->prox->prev = l->fim->prev;
	c->fim->prev->prox = l->fim;
	l->fim->prev = c->fim->prev;
	c->ini->prox = c->fim;
	c->fim->prev = c->ini;
	l->tamanho = l->tamanho + c->tamanho;
	c->tamanho = 0;
	return 1;
}

int ordena_lista(t_lista *l)
{
	t_nodo *p = l->ini->prox;
	int tam;
	if (!tamanho_lista(&tam,l))
		return 0;
	int i;
	for (i=0 ; i<tam ; i++)						/*bubble sort*/
	{
		while (p->prox->prox != NULL)
		{
			if (p->chave > p->prox->chave)
			{
				p->prev->prox = p->prox;		/*troca*/
				p->prox->prox->prev = p;
				p->prox = p->prox->prox;
				p->prev->prox->prox = p;
				p->prev->prox->prev = p->prev;
				p->prev = p->prev->prox;
			}
			else
				p = p->prox;
		}
		p = l->ini->prox;
	}
	return 1;
}

int intercala_listas(t_lista *l, t_lista *m, t_lista *i)
{
	if (!ordena_lista(l))
		return 0;
	if (!ordena_lista(m))
		return 0;
	
	int j=0;
	int taml,tamm;
	if (!tamanho_lista(&taml,l))
		return 0;
	if (!tamanho_lista(&tamm,m))
		return 0;
	t_nodo *p = l->ini->prox;
	t_nodo *q = m->ini->prox;
	t_nodo *r = i->ini;
	while (j<taml && j<tamm)
	{
		t_nodo *newl = (t_nodo *) malloc (sizeof(t_nodo));
		t_nodo *newm = (t_nodo *) malloc (sizeof(t_nodo));
		
		newl->chave = p->chave;
		newm->chave = q->chave;
		p = p->prox;
		q = q->prox;
		
		r->prox = newl;
		newl->prox = newm;
		newm->prev = newl;
		newl->prev = r;
		i->fim->prev = newm;
		newm->prox = i->fim;
		r = r->prox->prox;
		i->tamanho = i->tamanho + 2;
		j++;
	}

	if (taml < tamm)
	{
		while (j<tamm)
		{
			t_nodo *newm = (t_nodo *) malloc (sizeof(t_nodo));
			newm->chave = q->chave;
			q = q->prox;
			
			r->prox = newm;
			newm->prox = i->fim;
			r->prox->prev = r;
			i->fim->prev = newm;
			r = r->prox;
			i->tamanho++;
			j++;
		}								
	}
	else
	{
		while (j<taml)
                {
                	t_nodo *newl = (t_nodo *) malloc (sizeof(t_nodo));
			newl->chave = p->chave;
			p = p->prox;
			
                	r->prox = newl;
                	newl->prox = i->fim;
                	r->prox->prev = r;
                	i->fim->prev = newl;
                	r = r->prox;
			i->tamanho++;
			j++;
                }								
	}
	return 1;
}
