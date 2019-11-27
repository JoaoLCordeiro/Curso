#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
#define MAX 256

void gera_vetor (int *v, int t/*,int d*/)         
{
	int i = 1;
	srand (time(NULL));
    for (i=0 ; i<t ; i++)
        v[i] = rand() % MAX;
}

void print_vetor (int *vetor, int tam)
{   
    int i = 1;
    while (i<tam)                     
    {
        printf("%d ",vetor[i]);
    	i++;
    }
    printf ("\n");
}

void counting_sort (int *vetorA,int *vetorB,int *vetorC,int n,int j)
{
    int i;
    for (i=0 ; i<10 ; i++)
        vetorC[i] = 0;

    for (i=0 ; i<n ; i++)
        vetorC[((vetorA[i]%(j*10))/j)]++;
    
    for (i=1 ; i<10 ; i++)
        vetorC[i] = vetorC[i-1] + vetorC[i];

    for (i=n-1 ; i>=0 ; i--)
    {
        vetorC[((vetorA[i]%(j*10))/j)]--;
        vetorB[vetorC[((vetorA[i]%(j*10))/j)]] = vetorA[i];
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

int acha_digitos (int n)
{
    int i = 0;
    while (n != 0)
    {
        n = n/10;
        i++;
    }
    return i;
}

void copia_vetor (int *vetorA,int *vetorB,int n)
{
    int i;
    for (i=0 ; i<n ; i++)
        vetorA[i] = vetorB[i];
}

void radix_sort (int *vetorA,int *vetorB,int *vetorC,int d,int n)
{
    int i;
    int j = 1;
    for (i=1 ; i<=d ; i++)
    {
        counting_sort (vetorA,vetorB,vetorC,n,j);
        copia_vetor (vetorA,vetorB,n);
        print_vetor (vetorA,n);
        printf("\n");
        j = j*10;
    }
}

int main ()
{
    int *vetorA = (int *) malloc (N*sizeof(int) );
    int *vetorB = (int *) malloc (N*sizeof(int) );
    int *vetorC = (int *) malloc (10*sizeof(int));
    int d = acha_digitos (MAX);
    gera_vetor (vetorA,N);
    print_vetor (vetorA,N);
    printf ("\n");
    radix_sort (vetorA,vetorB,vetorC,d,N);

    if (ta_ordenado(vetorA,N))
        printf ("Ordenado \n");
    else
        printf ("Não ordenado \n");
    return 1;
}
