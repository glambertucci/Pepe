#include <stdio.h>

#define TRUE (1)
#define FALSE (0)


int keyboard (void);
int ValidInput ( int key);



int main (void)
{
	int divisor;
	int num;
	int escape = -1;
	printf("Ingrese un numero\n");
	int fuck = keyboard();
	



	for ( divisor = 2 ; escape < 0 ; ++divisor )
	{
		//printf("En el for, divisor = %d\n", divisor );
		num = fuck % divisor;

		if (num == 0)
		{
			fuck = fuck / divisor;
			printf("%d * ", divisor );
		}
		else if ( divisor >= fuck)
		{
			printf("%d\n", fuck);
			escape = 1;
		}
	}
	putchar('\n');
	return 0;
}



int keyboard (void)
{
	int key;
	int sign = 1;
	int valid_num;
	int validity;
	int floating = FALSE;
	int real = 0;
	int entero=0;
	int respuesta;

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
		respuesta = (-9999.88);
	}
	else
	{
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