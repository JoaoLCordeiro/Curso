#include <stdio.h>

int TermoPascal(int n)
{
	if ( n<5 )
	{
		return 1;
	}
	else
	{
		int i=1;
                while ( (1+i)*i/2 <= n )
                {
                	if ( ( (1+i)*i/2 == n ) || ( (1+i)*i/2 + 1 == n ) )
                	{
                		return 1;
                	}
                	i=i+1;
                }
                i=i-1;
		return ( TermoPascal (n-i) + TermoPascal (n-i-1) );
		printf ("%d/n", i);
	}

}

int main ()
{
	int t;
	printf ("Qual termo do triângulo de Pascal que você deseja?\n");
	scanf ("%d", &t);
	printf ("%d\n", TermoPascal (t));
	return 0;
}
