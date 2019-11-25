#include <stdio.h>
#include <stdlib.h>

void descreve_tabuleiro (int **matrizTab,int contSol)
{
    int i,j;
    int cont = 1;
    printf("\nSolucao: %d\n",contSol+1);
    for (i=0 ; i<8 ; i++)
    {
        for (j=0 ; j<8 ; j++)
        {
            if (matrizTab[i][j] == 2)
            {
                printf ("Rainha %d : %d %d       %d%d%d%d%d%d%d%d\n",cont,i+1,j+1,matrizTab[i][0],matrizTab[i][1],matrizTab[i][2],matrizTab[i][3],matrizTab[i][4],matrizTab[i][5],matrizTab[i][6],matrizTab[i][7]);
                cont=cont+1;
            }
        }
    }
}

int verifica_casa (int **matrizTab,int i,int j)
{
    int k = 1;
    while ((i-k >= 0)&&(j-k >= 0))
    {
        if (matrizTab[i-k][j-k] == 2)
            return 0;
        k++;
    }
    k = 1;                          
    while ((i-k >= 0)&&(j+k <= 7))
    {
        if (matrizTab[i-k][j+k] == 2)        
            return 0;
        k++;
    }
    k = 1;                          
    while ((i+k <= 7)&&(j-k >= 0))
    {
        if (matrizTab[i+k][j-k] == 2)
            return 0;
        k++;
    }
    k = 1;                          
    while ((i+k <= 7)&&(j+k <= 7))
    {
        if (matrizTab[i+k][j+k] == 2)    
            return 0;
        k++;
    }
    k = 1;
    while (i-k >= 0)
    {
        if (matrizTab[i-k][j] == 2)
            return 0;
        k++;
    }
    k = 1;                        
    while (i+k <= 7)
    {
        if (matrizTab[i+k][j] == 2) 
            return 0;
        k++;
    }
    k = 1;                        
    while (j-k >= 0)
    {
        if (matrizTab[i][j-k] == 2)
            return 0;
        k++;
    }
    k = 1;                        
    while (j+k <= 7)
    {
        if (matrizTab[i][j+k] == 2) 
            return 0;
        k++;
    }             
    return 1;                                  
}

int verifica_solucoes (int **matrizTab,int ***vetorSol,int contSol)
{
    int i = 0;
    int j,k;
    int repetido = 0;
    while ((i<contSol)&&(! repetido))
    {
        repetido = 1;
        for (j=0 ; j<8 ; j++)
        {
            for (k=0 ; k<8 ; k++)
            {
                if (matrizTab[j][k] != vetorSol[i][j][k])
                    repetido = 0;
            }
        }
        i++; 
    }
    return !repetido;
}

void rainha_RE (int **matrizTab,int contRainha,int *contSol,int ***vetorSol)
{
    int i,j;
    if (contRainha != 0)
    {
        for (i=0 ; i<8 ; i++)
        {
            for (j=0 ; j<8 ; j++)
            {
                if (matrizTab[i][j] == 0) /*ou seja, não tem uma rainha*/
                {
                    if (verifica_casa(matrizTab,i,j))
                    {
                        matrizTab[i][j] = 2;
                        rainha_RE (matrizTab,contRainha-1,contSol,vetorSol);
                        matrizTab[i][j] = 0;
                    }
                }
            }
        }
    }
    else
    {
        if (verifica_solucoes(matrizTab,vetorSol,*contSol))
        {
            descreve_tabuleiro (matrizTab,*contSol);
            for (i=0 ; i<8 ; i++)
            {
                for (j=0 ; j<8 ; j++)
                {
                    vetorSol[*contSol][i][j] = matrizTab[i][j];
                }
            }
            *contSol = *contSol + 1;
        }
    }
}

int main ()
{
    int i,j,k;
    int **matrizTab;
    int ***vetorSol;
    int contSol = 0;
    vetorSol = (int ***) malloc (92*sizeof(int **));
    for (i=0 ; i<92 ; i++)
    {
        vetorSol[i] = (int **) malloc (8*sizeof(int *));
        for (j=0 ; j<8 ; j++)
        {
            vetorSol[i][j] = (int *) malloc (8*sizeof(int));
            for (k=0 ; k<8 ; k++)
                vetorSol[i][j][k] = 0;
        }
    }
    matrizTab = (int **) malloc (8*sizeof(int *));
    for (i=0 ; i<8 ; i++)       /*poe zeros nas matrizes*/
    {
        matrizTab[i] = (int *) malloc (8*sizeof(int));
        for (j=0 ; j<8 ; j++)
        {
            matrizTab[i][j] = 0;
        }
    }
    rainha_RE (matrizTab,8,&contSol,vetorSol);
    return 1;
}
