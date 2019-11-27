#define MAX 10
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int esquerda (int i)    
{
    return (i*2+1);
}

int direita (int i)
{
    return ((i+1)*2);
}

void Heap (int *vetor, int i,int tam)
{
    int esq = esquerda (i);
    int dir = direita  (i);
    if (i <= tam/2)
    {
        Heap (vetor,esq,tam);
        Heap (vetor,dir,tam);
    }
    int maior = i;
    if ((maior < vetor[esq]) && (tam > esq))
        maior = esq;
    if ((maior < vetor[dir]) && (tam > dir))
        maior = dir;
    int aux = vetor[i];
    vetor[i] = vetor[maior];
    vetor[maior] = aux;
}

void gera_vetor (int *v, int t)         
{
	int i;
	srand (time(NULL));
	for (i=0;i<t;i++)
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

int main ()
{
    int *vetor;
    int tam;
    scanf ("%d",&tam);
    vetor = (int *) malloc (tam*sizeof(int));
    gera_vetor (vetor,tam);
    print_vetor (vetor,tam);
    Heap(vetor,0,tam);
    print_vetor (vetor,tam);
    return 1;
}
