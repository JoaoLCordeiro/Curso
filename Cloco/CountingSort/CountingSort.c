#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

void gera_vetor (int *v, int t)         
{
	int i;
	srand (time(NULL));
	for (i=0 ; i<t ; i++)
		v[i] = rand() % N;
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

int maior_elemento (int *vetor,int n)
{
    int i;
    int maior = vetor[0];
    for (i=1 ; i<n ; i++)
        if (vetor[i] > maior)
            maior = vetor[i];
    return maior;
}

void counting_sort (int *vetorA,int *vetorB,int *vetorC,int k,int n)
{
    int i;
    for (i=0 ; i<k ; i++)
        vetorC[i] = 0;

    for (i=0 ; i<n ; i++)
        vetorC[vetorA[i]]++;

    print_vetor (vetorC,k);
    
    for (i=1 ; i<k ; i++)
        vetorC[i] = vetorC[i-1] + vetorC[i];

    print_vetor (vetorC,k);

    for (i=0 ; i<n ; i++)
    {
        vetorC[vetorA[i]]--;
        vetorB[vetorC[vetorA[i]]] = vetorA[i];
    }
}

int ta_ordenado (int *vetor,int n)
{
    int i;
    for (i=1 ; i<n ; i++)
        if (vetor [i] < vetor[i-1])
            return 0;
    return 1;
}

int main ()
{
    int *vetorA = (int *) malloc (N*sizeof(int));
    int *vetorB = (int *) malloc (N*sizeof(int));
    gera_vetor (vetorA,N);
    int k = maior_elemento (vetorA,N) + 1;
    int *vetorC = (int *) malloc (k*sizeof(int));
    print_vetor (vetorA,N);
    counting_sort (vetorA,vetorB,vetorC,k,N);
    print_vetor (vetorB,N);
    if (ta_ordenado(vetorB,N))
        printf ("Ordenado \n");
    else
        printf ("Não ordenado \n");
    return 1;
}
