#include <stdio.h>
#include <stdlib.h>

void LerMatriz (int **matriz,int lin,int col)
{
	int i,j;
	for ( i=0 ; i<lin ; i++ )
	{
		for ( j=0 ; j<col ; j++ )
		{
			scanf("%d",&matriz[i][j]);  /*lê a matriz*/
		}
	}
}

int ElementoMultiplicacao(int **m1,int **m2,int stop,int lin,int col)
{
	int i;
	int elemento=0;
	for ( i=0 ; i<stop ; i++)
	{
		elemento=elemento+((m1[lin][i])*(m2[i][col]));  /*soma os produtos entre os elementos da linha lin da m1 e os da coluna col da m2*/
	}
	return elemento;
}

int main ()
{
	int lin1,lin2,col1,col2;
	printf("Quantas linhas e colunas tem a primeira matriz?\n");
	scanf("%d %d",&lin1,&col1);
	printf("Quantas linhas e colunas tem a segunda matriz?\n");
	scanf("%d %d",&lin2,&col2);
	if (col1 != lin2)
	{
		printf("NÃO É POSSÍVEL\n");
		return 1;
	}
	else
	{
		int **matriz1 = malloc (lin1*sizeof(int*));
		int **matriz2 = malloc (lin2*sizeof(int*));
		int i;
		for ( i=0 ; i<lin1 ; i++ )
		{
			matriz1[i] = malloc (col1*sizeof(int));
		}
		for ( i=0 ; i<lin2 ; i++ )
		{
			matriz2[i] = malloc (col2*sizeof(int));
		}                                                                          /*Até aqui, alocou a maméria necessária para o funcionamento*/
		printf("Agora, escreva primeiro a primeira matriz e depois a segunda\n");
		LerMatriz (matriz1,lin1,col1);
		printf("\n");
		LerMatriz (matriz2,lin2,col2);
		printf("\n");
		int j;
		for ( i=0 ; i<lin1 ; i++ )
		{
			for ( j=0 ; j<col2 ; j++ )
			{
				printf ("%d ",ElementoMultiplicacao(matriz1,matriz2,lin2,i,j)); /*poderia passar col1 no lugar da lin2 também*/
			}
			printf("\n");
		}
		return 0;
	}
}
