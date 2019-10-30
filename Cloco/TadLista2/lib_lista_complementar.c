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
		return 1;
	}
}
