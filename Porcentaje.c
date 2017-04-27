#include <stdio.h>
#define TRUE (1)
#define FALSE (0)

double porcentaje (double total, double particular);
double keyboard (int * valid);
int ValidInput ( int key);

int main (void)
{
	double total, particular, result;
	int valid[1];

	printf("Ingrese el total\n");

	for ( total = keyboard(valid); valid[0] != TRUE ; total = keyboard(valid) )
	{
		printf("Entrada incorrecta\n");
	}

	printf("Ingrese el particular\n");

	for ( particular = keyboard(valid); valid[0] != TRUE ; particular = keyboard(valid) )
	{
		printf("Entrada incorrecta\n");
	}

	result = porcentaje(total,particular);

	printf("%.2f es el %.2f%% de %.2f\n", particular, result, total );

	return 0;

}



double porcentaje (double total, double particular)
{
	double result;

	result = ( (particular) / (total) ) * 100;

	return result;
}

double keyboard (int * valid)
{
	int key;
	int sign = 1;
	int valid_num;
	int validity;
	int floating = FALSE;
	double real = 0;
	double entero=0;
	double respuesta;

	while ( (key = getchar()) != '\n')
	{
		switch (key)
		{
			case '.': floating = TRUE; break;
			case '-': sign = (-1); break;
			default : valid_num = ValidInput(key); break;
		}

		if ((key != '-') && ( key!= '.'))
		{
			if (valid_num == TRUE)
			{
				key = key - '0';

				entero = ( 10 * entero) + key;

				if (floating == TRUE)
				{
					++real;
				}
			}
			else
			{
				validity = FALSE;
			}
		}
	}

	if (validity == FALSE)
	{
		valid[0] = FALSE;
	}
	else
	{
		valid[0] = TRUE;
		for( real ; real > 0 ; --real)
		{
			entero = entero / 10;
		}
		
		respuesta = (entero ) * sign;
	}
	return respuesta;
}


int ValidInput ( int key)
{
	int valid;

	if ( (key >= '0') && (key <= '9'))
	{
		valid = TRUE;
	}
	else
	{
		valid = FALSE;
	}
	return valid;
}