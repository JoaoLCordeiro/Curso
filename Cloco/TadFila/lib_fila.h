typedef struct t_nodo {
	int id;
	int t;
	struct t_nodo *prox;
	struct t_nodo *prev;
} t_nodo;

typedef struct tipo_fila {
	t_nodo *ini;
	t_nodo *fim;
	int tamanho;
} tipo_fila;

int inicializa_fila(tipo_fila *F);

int fila_vazia(tipo_fila *F);

int tamanho(tipo_fila *F);

int enfileira(int id, int t, tipo_fila *F);

int desenfileira(int *id, int *t, tipo_fila *F);

int remove_fila(int *id, int *t, tipo_fila *F);

void imprime_fila(tipo_fila *F);
