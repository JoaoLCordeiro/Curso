
int inicializa_lista (t_lista *l)
{
	t_nodo *ini = (t_nodo *) malloc (sizeof(t_nodo));
	t_nodo *fim = (t_nodo *) malloc (sizeof(t_nodo));

	if ((ini == NULL) || (fim == NULL))			/*se o malloc não funcionar*/
	{
		free (ini);
		free (fim):
		return 0;
	}

	ini->chave = NULL;					/*inicia o ini e o fim*/
	fim->chave = NULL;

	ini->prox = fim;
	fim->prev = ini;

	ini->prev = NULL;
	fim->prox = NULL;

	l->ini = ini;						/*inicia a lista em si*/
	l->fim = fim;
	l->atual = NULL;
	l->tamanho = 0;
	return 1;
}

int lista_vazia (t_lista *l)
{
	if (l->tamanho != 0)
	{
		return 0;
	}
	return 1;
}

void destroi_lista(t_lista *l)
{
	t_nodo *p = l->ini->prox;
	t_nodo *q;
	while ( p->prox != NULL)		/*destroi elementos intermediarios*/
	{
		q = p;
		p = p->prox;

		q->chave = NULL;
		q->prev = NULL;
		q->prox = NULL;
		free (q);
	}
	l->ini->prox = NULL;			/*destrói ini e fim*/
	free (l->ini);
	p->prev = NULL;
	free (p);
}

int insere_inicio_lista(int item, t_lista *l)
{
	t_nodo *new = (t_nodo *) malloc (sizeof(t_nodo));
	if ( new == NULL )					/*caso o malloc não funcionar*/
	{
		return 0;
	}
	
	l->ini->prox->prev = new;				/*arruma os ponteiros*/
	new->prox = l->ini->prox;
	new->prev = l->ini;
	new->chave = item;
	l->ini->prox = new;
}

int tamanho_lista(int *tam, t_lista *l)
{
	*tam = l->tamanho;
	return 1;
}


