#include <stdio.h>

#define TRUE (1)
#define FALSE (0)

double MasaCorporal (double altura, double peso );
double keyboard (int * valid);
int ValidInput ( int key);




int main (void)
{
	double peso, altura, resultado;
	int valid[1];

	printf("Por favor ingrese su peso\n");
	
	for ( peso = keyboard(valid) ; valid[0] != TRUE ; peso = keyboard(valid) )
	{
		printf("Entrada incorrecta\n");
	}

	printf("Por favor ingrese su altura en metros\n");

	for ( altura = keyboard(valid) ; valid[0] != TRUE ; altura = keyboard(valid) )
	{
		printf("Entrada incorrecta\n");
	}

	resultado = MasaCorporal(altura,peso);

	printf("Su Indice de Masa Corporal es %.2f\n", resultado);


	return 0;
}







double MasaCorporal (double altura, double peso )
{
	double resultado;

	resultado = (peso) / (altura * altura);

	return resultado;
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