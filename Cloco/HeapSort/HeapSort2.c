#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 32

int esquerda (int i)    
{
    return (i*2+1);
}

int direita (int i)
{
    return ((i+1)*2);
}

void max_heapfy (int *vetor,int i,int tam)
{
    int l = esquerda (i);
    int r = direita  (i);
    int maior;
    if ( (l <= tam)&&(vetor[l] > vetor[i]))
        maior = l;
    else
        maior = i;
    if ( (r <= tam)&&(vetor[r] > vetor[maior]) )
        maior = r;
    if (maior != i)
    {
        int aux;
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        max_heapfy (vetor,maior,tam);
    }
}

void build_max_heapfy (int *vetor,int comp,int tam)
{
    int i = comp/2 + 1;
    while (i != 0)
    {
        i--;
        max_heapfy (vetor,i,tam);
    }
}

void gera_vetor (int *v, int t)
{
	int i;
	srand (time(NULL));
	for (i=0 ; i<t ; i++)
		v[i] = rand() % MAX;
}

void print_vetor (int *vetor, int tam)
{   
    int i = 0;
    while (i<tam)                     
    {
        printf("%d ",vetor[i]);
    	i++;
    }
    printf ("\n");
}

void heapsort (int *vetor,int comp,int tam)
{
    max_heapfy (vetor,comp,tam);
    int i = tam - 1;
    while (i != 0)
    {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor [i] = aux;
        i--;
        max_heapfy (vetor,0,i);
    }
}

int main ()
{
    int *vetor;
    vetor = (int*) malloc (MAX*sizeof (int));
    srand (time(NULL));
    int tam = rand () % MAX;
    while (tam < 8)
    {
        tam = rand () % MAX;
    }
    int comp = MAX;
    gera_vetor (vetor,tam);
    print_vetor (vetor,tam);
    build_max_heapfy (vetor,comp,tam);
    print_vetor (vetor,tam);
    heapsort (vetor,comp,tam);
    print_vetor (vetor,tam);
    return 1;
}
