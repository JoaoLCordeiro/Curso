#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void Gera_Vetor (int *e, int t) {
	
	int i;
	srand (time(NULL));
	for (i=0;i<t;i++)
		e[i] = rand() % MAX;

}

void Merge (int vetor[MAX],int comeco,int meio,int fim)
{
	int i=0;
	int j=0;
	int vetor3[MAX];
	while ((i<=(meio-comeco)) && (j<=((meio-comeco) - (fim-comeco+1)%2)) )	/*Até terminar de analisar pelo menos uma metade inteira*/
	{
		if ( vetor[comeco+i]<=vetor[meio+j+1] )
		{
			vetor3[i+j]=vetor[comeco+i];
			i=i+1;
		}
		else
		{
			vetor3[i+j]=vetor[meio+j+1];
			j=j+1;
		}
	}
	if (i<=(meio-comeco))							/*Se sobrar elementos na primeira metade*/
	{
		while ((i+j)<=(fim-comeco))
		{
			vetor3[i+j]=vetor[comeco+i];
			i=i+1;
		}
	}
	else									/*Se sobrar elementos na segunda metade*/
	{
		while ((i+j)<=(fim-comeco))
		{
			vetor3[i+j]=vetor[meio+j+1];
			j=j+1;
		}
	}
	i=0;
	while (i<=(fim-comeco))							/*Copia vetor3 pro vetor original*/
	{
		vetor[comeco+i]=vetor3[i];
		i=i+1;
	}
}


void Merge_Sort (int vetor[MAX], int comeco, int fim)
{
	if ( (fim-comeco+1)>2 )
	{
		int meio=(comeco+fim)/2;
		Merge_Sort (vetor,comeco,meio);
		Merge_Sort (vetor,meio+1,fim);
		Merge (vetor,comeco,meio,fim);
	}
	else
	{
		if (comeco<fim)
		{
			if (vetor[comeco]>vetor[fim])
			{
				int aux=vetor[comeco];
				vetor[comeco]=vetor[fim];
				vetor[fim]=aux;
			}
		}
	}
}

int main ()
{
	int vetor[MAX];
	int i;
	int comeco;
	int fim;
	scanf("%d",&i);
	Gera_Vetor(vetor,i);
	comeco=0;
	fim=i-1;
	Merge_Sort(vetor,comeco,fim);
	i=0;
	printf ("\n");
	while (i<=(fim))
	{
		printf ("%d ",vetor[i]);
		i=i+1;
	}
	printf ("\n");
	return 0;
}
