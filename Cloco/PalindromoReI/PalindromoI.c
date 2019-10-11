#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int Palindromo(char *vetor)
{
	int j=strlen(vetor)-1;
	int i;
	for ( i=0 ; i<j ; i++)           /*vai até metade da palavra*/
	{
		if (vetor[i]!=vetor[j])  /*se as letras simétricas são diferentes, retorna falso*/
		{
			return 0;
		}
		j--;
	}
	return 1;  			 /*se passar pelo for inteiro, devolve verdadeiro*/
}


int main ()
{
	char *palavra = malloc(MAX*sizeof(char));
	scanf("%s",palavra);
	if (Palindromo(palavra))
	{
		printf("SIM\n");
	}
	else
	{
		printf("NAO\n");
	}
	return 0;
}							
