#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#define sprite1i1 " /+\\ "	/*posso otimizar esses sprites*/
#define sprite1i2 "/o-O\\"
#define sprite1i3 "\\+++/"
#define sprite1i5 "/O-o\\"
#define sprite2i1 " /W\\ "
#define sprite2i2 " \\0/ "
#define sprite2i3 "\\_H_/"
#define sprite2i5 " \\-/ "
#define sprite2i6 "/_H_\\"
#define sprite3i1 "d000b"
#define sprite3i2 "|8-8|"
#define sprite3i3 "/|||\\"
#define sprite3i5 "|8o8|"

typedef struct t_alien{
	int vida;
	int posi_l;
	int posi_c;
	int tipo;
} *t_alien;

void InicializaSpritesAliens(char **vetors)	/*essa funcao inicaliza as sprites dos aliens em um vetor com esses sprites*/
{
	strcpy(vetors[0],sprite1i1);
	strcpy(vetors[1],sprite1i2);
	strcpy(vetors[2],sprite1i3);
	strcpy(vetors[3],sprite1i1);
	strcpy(vetors[4],sprite1i5);
	strcpy(vetors[5],sprite1i3);
	strcpy(vetors[6],sprite2i1);
	strcpy(vetors[7],sprite2i2);
	strcpy(vetors[8],sprite2i3);
	strcpy(vetors[9],sprite2i1);
	strcpy(vetors[10],sprite2i5);
	strcpy(vetors[11],sprite2i6);
	strcpy(vetors[12],sprite3i1);
	strcpy(vetors[13],sprite3i2);
	strcpy(vetors[14],sprite3i3);
	strcpy(vetors[15],sprite3i1);
	strcpy(vetors[16],sprite3i5);
	strcpy(vetors[17],sprite3i3);
}

void InicializaMatrizAliens(int **matriz)
{
	int i;
	int j;
	for ( i=0 ; i<5 ; i++ )
	{
		for ( j=0 ; j<11 ; j++ )
		{
			matriz[i][j] = 1;
		}	
	}
}

void ImprimeAliensPOSATUAL(int **matriz,int linha,int coluna,char **vetorS,WINDOW *jogo)
{
	int i;
	int j;
	int tipo;
	for ( i=0 ; i<5 ; i++)
	{
		for ( j=0 ; j<11 ; j++ )
		{
			tipo = (i+1)/2;
			mvwprintw(jogo,linha+4*i,coluna+7*j,vetorS[tipo*6]);
			mvwprintw(jogo,linha+4*i+1,coluna+7*j,vetorS[tipo*6+1]);
			mvwprintw(jogo,linha+4*i+2,coluna+7*j,vetorS[tipo*6+2]);
			wrefresh(jogo);
			usleep(50000);
		}
	}
	/*wrefresh(jogo);*/
}

int main ()
{
	char **vetorsprites;
	vetorsprites = (char **) malloc (18*sizeof(char*));		/*aloca espaço pra um vetor de sprites de aliens e poe os sprites nele*/
	int i;
	for ( i=0 ; i<18 ; i++)
	{
		vetorsprites[i] = (char *) malloc (sizeof(char));
	}
	InicializaSpritesAliens (vetorsprites);

	int **matrizalien;
	matrizalien = (int **) malloc (5*sizeof(int*));			/*aloca espaco para uma matriz com os aliens e poe que todos eatão vivos*/
	for ( i=0 ; i<5 ; i++ )
	{
		matrizalien[i] = (int *) malloc (11*sizeof(int));
	}
	InicializaMatrizAliens (matrizalien);
	
	/*strcpy(alien->sprite3,sprite1i3);*/

	initscr();
	int janela_x,janela_y;
	getmaxyx(stdscr,janela_x,janela_y);
	WINDOW *jogo = newwin(janela_x,janela_y-(janela_y/6),0,0);
	refresh();
	WINDOW *score = newwin(janela_x,(janela_y/6),0,janela_y-(janela_y/6));

	box(score,0,0);
	box(jogo,0,0);
	wrefresh(jogo);
	wrefresh(score);
	
	int linhaAliens,colunaAliens;
	linhaAliens = 1;
	colunaAliens = 1;
	ImprimeAliensPOSATUAL(matrizalien,linhaAliens,colunaAliens,vetorsprites,jogo);
	wrefresh(jogo);
	int c = getch();
	endwin();
	return 0;
}
