#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int VerificaElemento (int **matriz1,int nl,int nc,int l,int c)
{
	int cont=0;
	int i;
	int j;
	for ( i = -1 ; i<2 ; i++ )
	{
		for ( j = -1 ; j<2 ; j++ )
		{
			if (matriz1[(l+i+nl)%nl][(c+j+nc)%nc]==1)	/*essa conta com módulo faz com que os vizinhos sejam contados do outro lado do */
			{						/*tabuleiro. Usamos modulo pois ele não sai da região da matriz já que o resto  */
				cont++;					/* 			é sempre menor que o tamanho da matriz 			*/
			}
		}
	}
	cont=cont-matriz1[l][c];					/*retiramos o valor desse elemento da matriz pois, caso seja 1, o for conta o 	*/
	return cont;							/*		elemento atual também, mas só queremos os vizinhos		*/
}

void CriaNovaGen (int **matriz1,int **matriz2,int l,int c)
{
	int i;
	int j;
	int contvizinhos;
	for ( i = 0 ; i<l ; i++ )
	{
		for ( j = 0 ; j<c ; j++ )
		{			
			contvizinhos=VerificaElemento(matriz1,l,c,i,j);
			if ((contvizinhos < 2)||(contvizinhos > 3))
			{
				matriz2[i][j]=0;
			}
			else if (contvizinhos==2)
			{
				matriz2[i][j]=matriz1[i][j];
			}
			else
			{
				matriz2[i][j]=1;
			}
		}
	}
}

void CopiaMatriz (int **matriz1,int **matriz2,int l,int c)
{
	int i;
	int j;
	for ( i = 0 ; i<l ; i++ )
	{
		for ( j = 0 ; j<c ; j++ )
		{
			matriz1[i][j]=matriz2[i][j];
		}
	}
}

int main (int argc,char **argv)
{
	if ( argc != 4 )
	{
		printf("Número incorreto de parâmetros\n");
		return 1;
	}
	int l = atoi (argv[1]);
	int c = atoi (argv[2]);
	int g = atoi (argv[3]);
	int **genatual = malloc (l*sizeof(int*));
	int **gennova = malloc (l*sizeof(int*));
	int i;
	for ( i=0 ; i<l ; i++ )
	{
		genatual[i] = malloc (c*sizeof(int));
		gennova[i] = malloc (c*sizeof(int));
	}
	int j;
	for ( i=0 ; i<l ; i++ )
	{
		for ( j=0 ; j<c ; j++ )
		{
			genatual[i][j]=0;
			gennova[i][j]=0;
		}
	}
	scanf("%d",&i);
	scanf("%d",&j);
	while ( (( j != -1 )&&( j < c)) || (( i != -1 )&&( i < l )) )
	{
		genatual[i][j] = 1;
		scanf("%d",&i);
		if (( i != -1 )&&( i < l ))
		{
			scanf("%d",&j);
		}
	}
	/*initscr();
	clear();*/
	int h;
	for ( h = 0 ; h<g ; h++ )
	{
		for ( i = 0 ; i<l ; i++ )
		{
			for ( j = 0 ; j<c ; j++ )
			{
				if (genatual[i][j] == 0)
				{
					printf(" ");
				}
				else
				{
					printf("X");
				}
			}
			printf("\n");
		}
		CriaNovaGen (genatual,gennova,l,c);
		CopiaMatriz (genatual,gennova,l,c);
	}
	/*endwin();*/
	return 0;
}
