#include <stdio.h>
#include "lib_lista.h"
#define MAX 7
int tinsprlist (t_lista *l) {
	
	int i;
	for (i = 0; i < MAX; i++) 
		if (! insere_inicio_lista(2*i+1,l)) return 0;
	return 1;
}
int tinsfimlist (t_lista *c) {

	int i;
	for (i = 0; i < MAX; i++) 
		if (! insere_fim_lista (2*i,c)) return 0;
	return 1;
}
int tinsordlist (t_lista *l) {

	if (! insere_ordenado_lista(15,l)) return 0;
	if (! insere_ordenado_lista(3,l)) return 0;
	if (! insere_ordenado_lista(7,l)) return 0;
	if (! insere_ordenado_lista(5,l)) return 0;
	if (! insere_ordenado_lista(1,l)) return 0;
	if (! insere_ordenado_lista(0,l)) return 0;
	return 1;
}
int tclista (t_lista *l,t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Cria listas\n");

	printf ("Criando lista l\n");
	if (! inicializa_lista(l)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}
	
	printf ("Criando lista c\n");
	if (! inicializa_lista(c)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}

	printf ("Criando lista o\n");
	if (! inicializa_lista(o)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}

	printf ("Criando lista p\n");
	if (! inicializa_lista(p)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}
	
	return 1;

}
int trmchvlist (t_lista *o, t_lista *p) {

	int lixo;
	if ( remove_item_lista (0,&lixo,o)) printf ("O 0 foi removido da lista o\n"); 	
	if ( remove_item_lista (2,&lixo,o)) printf ("O 2 foi removido da lista o\n"); 
	if ( remove_item_lista (3,&lixo,o)) printf ("O 3 foi removido da lista o\n"); 
	if ( remove_item_lista (4,&lixo,o)) printf ("O 4 foi removido da lista o\n"); 
	if ( remove_item_lista (5,&lixo,o)) printf ("O 5 foi removido da lista o\n"); 
	if ( remove_item_lista (0,&lixo,p)) printf ("O 0 foi removido da lista p\n"); 
	if ( remove_item_lista (1,&lixo,p)) printf ("O 1 foi removido da lista p\n"); 
	if ( remove_item_lista (5,&lixo,p)) printf ("O 5 foi removido da lista p\n"); 
	if ( remove_item_lista (7,&lixo,p)) printf ("O 7 foi removido da lista p\n"); 
	if ( remove_item_lista (9,&lixo,p)) printf ("O 9 foi removido da lista p\n"); 
	if ( remove_item_lista (9,&lixo,p)) printf ("O 9 foi removido da lista p\n"); 
	if ( remove_item_lista (10,&lixo,p)) printf ("O 10 foi removido da lista p\n"); 
	if ( remove_item_lista (12,&lixo,p)) printf ("O 12 foi removido da lista p\n"); 
	return 1;
}
int tremlista (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Remoção\n");

	int lixo;
	
	printf ("Remove início da lista\n");
	while (! lista_vazia(l)) {
		if (! remove_inicio_lista (&lixo,l))  return 0;
		insere_inicio_lista (lixo,o); 	
	}
	printf ("Tamanho lista l: %d\n", l->tamanho);
	imprime_lista (o);
	
	printf ("Remove fim da lista\n");
	while (! lista_vazia(c)) {
		if (! remove_inicio_lista (&lixo,c)) return 0;
		insere_inicio_lista (lixo,p); 	
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);
	imprime_lista (p);

	printf ("Remove item\n");	
	if (! trmchvlist (o,p)) return 0;

	printf ("Tamanho lista o: %d\n", o->tamanho);
	imprime_lista (o);

	printf ("Tamanho lista p: %d\n", p->tamanho);
	imprime_lista (p);
	
	return 1;
}
void trmatlist (t_lista *l) {

	int lixo;
	
	printf ("Teste: Remove atual da lista\n");

	if (remove_item_atual(&lixo,l)) printf ("O atual %d for removido\n", lixo);
	if (remove_item_atual(&lixo,l)) printf ("O atual %d for removido\n", lixo);

	if (consulta_item_atual(&lixo,l)) printf ("O atual elemento: %d", lixo);
	printf ("\n");
}
int tatlista (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	t_nodo *aux;

	printf ("Teste: atual\n");
	if (inicializa_atual_inicio(l)) {
		printf ("Atual no inicio da lista f %d\n", l->atual->chave);
		return 0;
	}
	if (inicializa_atual_fim(c)) {
		printf ("Atual no fim da lista c %d\n", c->atual->chave);
		return 0;
	}

	if (inicializa_atual_inicio(o)) printf ("Atual no inicio da lista o: %d\n", o->atual->chave);
	if (inicializa_atual_fim(p)) printf ("Atual no fim da lista p: %d\n", p->atual->chave);

	printf ("Testa incrementa atual - lista o\n");	
	aux = o->ini->prox;
	while (aux != o->fim) {
		if (incrementa_atual (o))
			printf ("%d ",o->atual->chave);
		aux = aux->prox;
	}
	printf ("\n");
	
	printf ("Testa decrementa atual - lista p\n");
	aux = p->fim->prev;
	while (aux != p->ini) {
		if (decrementa_atual (p))
			printf ("%d ",p->atual->chave);
		aux = aux->prev;
	}
	printf ("\n");

	trmatlist (p);
	trmatlist (o);

	return 1;
}
int tinslista (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Insere nas listas\n");

	printf ("Insere no início da lista\n");
	if (! tinsprlist (l)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista l: %d\n", l->tamanho);
	imprime_lista (l);

	printf ("Insere no fim da lista\n");
	if (! tinsfimlist(c)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);
	imprime_lista (c);

	printf ("Insere ordenado na lista\n");
	if (! tinsordlist(c)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);
	imprime_lista (c);

	return 1;
}
int tperlista (t_lista *o, t_lista *p) {

	printf ("Teste: pertencimento\n");
	if (pertence_lista(6,p)) printf ("O 6 pertence a lista p\n");	
	if (pertence_lista(4,p)) printf ("O 4 pertence a lista p\n");
	if (pertence_lista(0,p)) printf ("O 0 pertence a lista p\n");
	if (pertence_lista(1,p)) {
		return 0;
		printf ("O 1 pertence a lista\n");
	}
	if (pertence_lista(7,o)) printf ("O 7 pertence a lista o\n");
	if (pertence_lista(9,o)) printf ("O 9 pertence a lista o\n");
	if (pertence_lista(4,o)) {
		return 0;
		printf ("O 4 pertence a lista\n");
	}
	return 1;
}
void tdstlist (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	int tam;

	printf ("Destruindo a lista l\n");
	destroi_lista (l);
	tamanho_lista (&tam,l);	
	printf ("Tamanho lista l: %d -> ", tam);
	imprime_lista (l);

	printf ("\n");
	printf ("Destruindo a lista c\n");
	destroi_lista (c);
	tamanho_lista (&tam,c);	
	printf ("Tamanho lista c: %d -> ", tam);
	imprime_lista (c);

	printf ("\n");
	printf ("Destruindo a lista o\n");
	destroi_lista (o);
	tamanho_lista (&tam,o);	
	printf ("Tamanho lista o: %d -> ", tam);
	imprime_lista (o);

	printf ("\n");
	printf ("Destruindo a lista p\n");
	destroi_lista (p);
	tamanho_lista (&tam,p);	
	printf ("Tamanho lista p: %d -> ", tam);
	imprime_lista (p);

	printf ("\n");
}
int main () {

	t_lista l,c,o,p;

	if (! tclista (&l,&c,&o,&p)) return 1;
		printf ("\n");
	if (! tinslista(&l,&c,&o,&p)) return 1;
		printf ("\n");
	if (! tremlista(&l,&c,&o,&p)) return 1;
		printf ("\n");
	if (! tatlista(&l,&c,&o,&p)) return 1;
		printf ("\n");
	if (! tperlista(&o,&p)) return 1;
		printf ("\n");
	tdstlist (&l,&c,&o,&p);	
	return 0;

}
