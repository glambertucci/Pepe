#include <stdio.h>

void matrix (int m, int n);

int main (void)
{
	int m = 3;
	int n = 12;

	matrix(m,n);

	return 0;
}



void matrix (int m, int n)
{
	int col, fil;

	for (fil = 0 ; fil < m ; ++fil)
	{
		for ( col = fil ; col < (n + fil) ; ++col)
		{
			printf("|%d", col);
		}
		printf("|\n");
	}
}