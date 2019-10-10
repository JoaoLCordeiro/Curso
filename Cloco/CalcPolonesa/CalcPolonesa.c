#include <stdio.h>
#include "tad_pilha.h"
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

int main ()
{
	char chatual[MAX];
	tad_pilha pilhacalc[MAX];
	float floataux1;
	float floataux2;
	scanf("%s", chatual);
	while ( !(chatual[0] == 'q') )
	{
		if ( chatual[0] == '-' )						/* Tratamento do dígito -, é um numero negativo ou operador? */
		{
			if ( isdigit(chatual[1]) )				
			{
				floataux1 = atof (chatual);
				empilha (floataux1,pilhacalc);
			}
			else
			{
				if ( !(pilha_vazia(pilhacalc)) )                          
				{
					desempilha (&floataux1,pilhacalc);
					if ( !(pilha_vazia(pilhacalc)) )
					{
						desempilha (&floataux2,pilhacalc);
						floataux1=floataux2-floataux1;
						empilha (floataux1,pilhacalc);
					}
					else
					{
						printf ("Erro: Números faltando para operação\n");
					}
				}
				else
				{
					printf ("Erro: Números faltando para operação\n");
				}
			}
		}
		else if ( ( chatual[0] == '+' ) || ( chatual[0] == '*' ) || ( chatual[0] == '/' ) )   /* Tratamento dos operadores */
		{
			if ( !(pilha_vazia(pilhacalc)) )                          
                        {
                        	desempilha (&floataux1,pilhacalc);
                        	if ( !(pilha_vazia(pilhacalc)) )
                        	{
                        		desempilha (&floataux2,pilhacalc);
                        		if ( chatual[0] == '+' )
					{
						floataux1=floataux2+floataux1;
					}                                     
					if ( chatual[0] == '*' )
                                        {
                                        	floataux1=floataux2*floataux1;
                                        }                                     
					if ( chatual[0] == '/' )
                                        {
						if ( floataux1 != 0 )
						{
                                        		floataux1=floataux2/floataux1;
						}
						else
						{
							printf ("Erro: Divisão por zero\n");
							empilha (floataux2,pilhacalc);
						}
                                        }                                     
                        		empilha (floataux1,pilhacalc);
                        	}
                        	else
                        	{
                        		printf ("Erro: Números faltando para operação\n");
                        	}
                        }
                        else
                        {
                        	printf ("Erro: Números faltando para operação\n");
                        }
		}
		else if ( isdigit( chatual[0]) )            /* Tratamento dos números */
		{
			floataux1 = atof (chatual);
                        empilha (floataux1,pilhacalc);
		}
		else						/* Tratamento de caracteres estranhos */
		{
			printf ("Erro: Caractere não reconhecido\n");
		}
		scanf (" %s", chatual);
	}
	topo (&floataux1,pilhacalc);
	printf ("%f\n", floataux1);
	return 0;
}
