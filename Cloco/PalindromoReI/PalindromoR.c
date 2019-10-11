#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int Palindromo(char *vetor,int i,int j)
{
	if (i<j)					/*vai até metade da string*/
	{
		if (vetor[i]!=vetor[j]) 		/*se alguma letra simétrica é diferente, retorna falso*/
		{
			return 0;
		}
		else
		{
			if (Palindromo(vetor,i+1,j-1))	/*se as chamadas internas deram certo, ele retorna verdadeiro, se não, falso*/
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 1;				/*esse else não identifica erro e sim o caso base, quando ele termina de varrer metade da string*/
	}
}


int main ()
{
	char *palavra = malloc(MAX*sizeof(char));
	scanf("%s",palavra);
	int j=strlen(palavra)-1;
	if (Palindromo(palavra,0,j))
	{
		printf("SIM\n");
	}
	else
	{
		printf("NAO\n");
	}
	return 0;
}							
