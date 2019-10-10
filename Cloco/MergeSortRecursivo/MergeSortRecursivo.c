#include <stdio.h>
#define MAX 50

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
	if ( comeco < fim )
	{
		int meio=(comeco+fim)/2;
		Merge_Sort (vetor,comeco,meio);
		Merge_Sort (vetor,meio+1,fim);
		Merge (vetor,comeco,meio,fim);
	}
}

int main ()
{
	int vetor[MAX];
	int i=0;
	int comeco;
	int fim;
	scanf("%d",&vetor[0]);
	while ( ( vetor[i] != 0 ) && (i<MAX) )
	{
		i=i+1;
		if (i==MAX-1)
		{
			vetor[i]=0;
		}
		else
		{
			scanf("%d",&vetor[i]);
		}
	}
	comeco=0;
	fim=i-1;
	Merge_Sort(vetor,comeco,fim);
	i=0;
	printf ("\n");
	while (i<=(fim)) /*(vetor[i] != 0)*/
	{
		printf ("%d ",vetor[i]);
		i=i+1;
	}
	printf ("\n");
	return 0;
}
