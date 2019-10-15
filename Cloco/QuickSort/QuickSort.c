#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000


void gera_vetor (int *e, int t) 
{
	
	int i;
	srand (time(NULL));
	for (i=0;i<t;i++)
		e[i] = rand() % MAX;

}

int Partition (int *v,int ini,int fim)
{
	int j=ini;
	int i=ini-1;
	int aux;
	for ( j=j ; j<fim ; j++)
	{
		if (v[j]<=v[fim])
		{
			aux=v[i+1];
			v[i+1]=v[j];
			v[j]=aux;
			i++;
		}
	}
	aux=v[i+1];
	v[i+1]=v[fim];
	v[fim]=aux;
	return(i+1);
}

void QuickSort (int *v,int ini,int fim)
{
	if (ini<fim)
	{
		int p=Partition(v,ini,fim);
		QuickSort(v,ini,p-1);
		QuickSort(v,p+1,fim);
	}
}

int main ()
{
	int vetor[MAX];
	int i;
	scanf("%d",&i);
	gera_vetor(vetor,i);
	printf("\n");
	QuickSort(vetor,0,i-1);
	int j=0;
	while (j<i)
        {
        	printf("%d ",vetor[j]);
		j++;
	}
	printf("\n");
	return 0;
}
