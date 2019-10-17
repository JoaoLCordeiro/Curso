#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

int Particiona (int *v,int ini,int fim)
{
	int i=ini;
	int j;
	int pivo=v[ini];
	for ( j=ini+1 ; j<=fim ; j++ )
	{
		if (pivo > v[j] )
		{
			v[i]=v[j];
			v[j]=v[i+1];
			v[i+1]=pivo;
			i++;
		}
	}
	return i;
}

void QuickSort (int *v,int ini,int fim)
{
	if (ini < fim)
	{
		int p=Particiona(v,ini,fim);
		QuickSort(v,ini,p-1);
		QuickSort(v,p+1,fim);
	}
}

void GeraVetor (int *e, int t) 
{
		
		int i;
			srand (time(NULL));
				for (i=0;i<t;i++)
							e[i] = rand() % MAX;

}

void ImprimeVetor (int *v,int tam)
{
	int i;
	for ( i=0 ; i<=tam ; i++ )
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}

int main ()
{
	int n;
	int v[MAX];
	scanf("%d",&n);
	GeraVetor(v,n);
	QuickSort(v,0,n-1);
	ImprimeVetor(v,n-1);
	return 1;
}
