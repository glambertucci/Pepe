#include <stdio.h>
#include <unistd.h>	

#define TRUE (1)
#define FALSE (0)
#define PRIMO (1)
#define NOPRIMO (2)

void primo (int fuck);


int main (void)
{
	double num1 = 0;
	double num2 = 1;
	double prev;

	printf("%0.f\n", num1);
	printf("%0.f\n", num2);

	while ( 1 )
	{
		sleep(1);
		prev = num1 + num2;
		num1 = num2;
		num2 = prev;
		printf("%0.f\n",prev );
		primo(prev);
	}

	return 0;
}

void primo (int fuck)
{
	int divisor;
	int num;
	int escape = -1;

	for ( divisor = 2 ; escape < 0 ; ++divisor )
	{
		//printf("En el for, divisor = %d\n", divisor );
		num = fuck % divisor;

		if (num == 0)
		{
			escape = PRIMO;
		}
		else if (divisor > (fuck / 2))
		{
			escape = NOPRIMO;
		}
	}

	switch(escape)
	{
		case 2:printf("Es primo\n"); break;
		case 1:printf("No es primo\n"); break;
	}
}