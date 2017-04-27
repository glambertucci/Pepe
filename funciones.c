

//Convierte Chars enviados por un arreglo a int

int charConvert (char * array, int lenght)
{
	int conta, num;
	int result = 0;

	for ( conta = 0 ; conta < lenght ; ++ conta)
	{
		num = *(array + conta) - '0';
		result= (result * 10) + num;
	}

	return result;
}

// Convierte Chars enviados por un arreglo a doubles

double charConvertReal (char * array, int lenght)
{
	int conta, num;
	double result = 0;

	for ( conta = 0 ; conta < lenght ; ++ conta)
	{
		num = *(array + conta) - '0';
		result= (result * 10) + num;
	}

	return result;
}

// Realiza potencias

int potencia (int num, int potencia)
{
	int result = num;
	int contador;

	for ( contador = 1 ; contador < potencia ; ++contador)
	{
		result = result * num;
	}

	return result;
}

// definiciones necesarias

	#define TRUE (1)
	#define FALSE (0)
	#define SUCCESS ('-')

// Esta funcion compara que cada char de un string sea igual a SUCCESS

int CheckWord (char * word)
{
	int count;
	int value = TRUE;

	for (count = 0 ; *(word + count) != 0 ; ++count)
	{
		if ( *(word + count) != SUCCESS )
		{
			value = FALSE;
		}
	}
	return value;
}

// Esta funcion se fija si una palabra es anagrama de otra. Necesita de la funcion
// LetterCounter para ser lo mas optima posible

void CompareWord (char * word1 , char * word2)
{
	int count1, count2;

	int length1 = LetterCounter(word1);
	int length2 = LetterCounter(word2);

	if (length1 == length2)
	{
		for (count1 = 0 ; count1 < length1 ; ++count1)
		{
			for (count2 = 0 ; count2 < length2 ; ++count2)
			{
				if ( *(word1 + count1) == *(word2 + count2) )
				{
					// Ingrese lo que haga la funcion de ser cada letra igual
				}
			}
		}
	}
}

// Esta funcion cuenta la cantidad de caracteres que tiene un string 

int LetterCounter ( char * point)								
{
	int letter;
	
	for ( letter = 0 ; *(point + letter) != 0 ; ++letter )
	{	
	}
	return letter;
}

// Esta funcion limpia todo un array, pero hay que pasarle el tamano del mismo

void CleanArray (char array[], int size )
{
	int count;

	for (count = 0 ; count < size ; ++count)
	{
		*(array + count) = 0;
	}
}

// Esta funcion se encarga de hacer minuscula a cualquier string que le pase.

void LowCase (char *array)
{
	int count;

	for(count = 0 ; *(array + count) != 0 ; ++count)
	{
		if ( ( *(array + count) >= 'A' ) && ( *(array + count) <= 'Z') )
		{
			*(array + count) = *(array +count) + ('b' - 'B');
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

																Validacion				

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Esta funcion valida cualquier string para que solo tenga letras en el y que sea menor que el maximo de
// su arreglo.

int ValidInputLetter (char *array, int size)
{
	int count;
	int value = TRUE;
	char letter;

	if ( *(array + size -1 ) == 0)
	{

		for (count = 0 ; *(array + count) != 0 ; ++count)
		{
			letter = *(array + count);

			if ( ( (letter >= 'a') && (letter <='z') ) || ( (letter >= 'A') && (letter <= 'Z') ) )
			{	
			}
			else
			{
				value = FALSE;
			}
		}
	}
	else
	{
		value = FALSE;
	}

	return value;
}

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Esta funcion se fija que dos strings sean iguales

int ValidString (char * point1, char * point2)					
{
	int counter, value;
	int success = 0;
	int fail = 0;
	
	int length1 = LetterCounter(point1);
	int length2 = LetterCounter(point2);
	
	if ( length1 == length2 )									// Si los strings son de distinto tamano los descarta por que no 
	{															// pueden ser iguales
		for ( counter = 0 ; counter < length1 ; ++counter)
		{
			if ( *(point1 + counter) == *(point2 + counter) )
			{
				++success;										//Esta variable esta solo para debuggear. No afecta al programa.
			}
			else
			{
				++fail;
			}
		}
		switch (fail)
		{
			case 0: value = TRUE; break;
			default: value = FALSE; break;
		}
	}
	else
	{
		value = FALSE;
	}
	
	return value;
}

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Esta funcion valida que un char solo sea un numero

int ValidInputNumber ( int key)
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

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Esta funcion se encarga de fijarse si el char indicado pertenence a una flag '-'

int CheckFlag ( char letter )								
{																
	int value;
	
	switch (letter)
	{
		case '-': value = TRUE; break;
		default : value = FALSE; break;
	}
	
	return value;
}

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Esta funcion te dice si un string de chars es reversible o capicua.

int Reverse ( char * array)
{
	char count, cap = 0;
	int length, value;

	length = LetterCounter(array);

	for (count = 0 ; count <= (length - count) ; ++count)
	{
		//printf("%c --- %c\n", *(array + count), *(array + length - count -1) );
		if ( *(array + count) != *(array + length - count -1) )
		{
			++cap;
		}
	}

	if ( cap == 0)
	{
		value = TRUE;
	}
	else
	{
		value = FALSE;
	}

	return value;
}

// definiciones necesarias
	#define PRIMO (1)
	#define NOPRIMO (2)

// Esta funcion verifica si un numero es primo o no
void primo (int num)
{
	int divisor;
	int num;
	int escape = -1;

	for ( divisor = 2 ; escape < 0 ; ++divisor )
	{
		//printf("En el for, divisor = %d\n", divisor );
		num = num % divisor;

		if (num == 0)
		{
			escape = PRIMO;
		}
		else if (divisor > (num / 2))
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

// Esta funcion calcula el porcentaje de masa corporal

double MasaCorporal (double altura, double peso )
{
	double resultado;

	resultado = (peso) / (altura * altura);

	return resultado;
}

// declaraciones necesarias
	#define TRUEMASK (0x100af120)
	#define byte0 (0x20)
	#define byte1 (0xf1)
	#define byte2 (0x0a)
	#define byte3 (0x10)

// Esta funcion recibe un arreglo de int y la el tamano del arreglo, y corrije a los numeros de a 2 bytes para
// que queden igual que la mascara requerida.

void fix ( int * numbers, int max_num)
{
	char * fixer = (char *) numbers;

	int count, byte, replace;

	for (count = 0 ; count < max_num ; ++count)
	{
		if (numbers[count] != TRUEMASK)
		{
			for ( byte = 0 ; byte < 4 ; ++byte)
			{
				switch (byte)
				{
					case 0: replace = byte0; break;
					case 1: replace = byte1; break;
					case 2: replace = byte2; break;
					case 3: replace = byte3; break;
				}

				if ( *(fixer + 4 * count + byte) != replace)
				{
					*(fixer + 4 * count + byte) = replace;
				}

			}
		}
	}
}

// Esta funcion calcula un porcentaje en relacion al total y al particular.

double porcentaje (double total, double particular)
{
	double result;

	result = ( (particular) / (total) ) * 100;

	return result;
}

//Esta funcion recibe dos strings y los une en uno.

char * MyStringCat ( const char * pointer, char array[SIZE] )
{
	const char * tempsource = pointer;
	char * templetter = array;
	
	int sourcecounter, lettercounter, copycounter;
	
	for ( lettercounter = 0 ; *(templetter + lettercounter) != 0 ; ++lettercounter )	// Este for se encarga de saber cuantos caracteres tiene el string
	{																					// del destino
	}
		
	for ( sourcecounter = 0 ; *(tempsource + sourcecounter) != 0 ; ++sourcecounter )	//Este for se encarga de saber cuantos caracteres tiene el string
	{																					//de la fuente
	}
	
	for ( copycounter = 0 ; copycounter < sourcecounter ; ++copycounter )				//Este for se encarga de guardar los caracteres de la fuente en el
	{																					//arreglo de destino.
		*( templetter + lettercounter + copycounter ) = *( tempsource + copycounter);
	}
	
	return templetter;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

															Input de informacion 				

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Esta funcion te permite escribir en pantalla hasta tocar la letra 'q' o 'Q'. Luego limpia el buffer.

void LetterKeyboard(void)
{
	char c;
	int out=0;

	c = getchar();
	while  (out != 1 )
	{
		switch (c)
		{
			case 'q':out = 1 ;break;
			case 'Q':out = 1 ;break;
		}
		c = getchar();
	}

	while( (c=getchar() ) != '\n')
	{	
	}
}

// Esta funcion te permite ingresar texto, que terminara al tocar 'enter'. Devolvera un puntero a char

char * InputWord (char array[SIZE], int size)
{
	char *word = array;

	char letter;
	int count;

	for ( count = 0; count < (size-1) ; ++count)
	{
		letter = getchar();

		switch (letter)
		{
			case '\n': count = size; break;
			default : *(word + count) = letter; break;
		}
	}

	return word;
}

// Esta funcion permite tomar un string de numeros provenientes de la consola y los pasa a un
// string de char. Al final coloca un terminador

int KeyboardString (char * array)
{
	int key;
	char sign = 1;
	int valid_num;
	int count = 0;

	while ( (key = getchar()) != '\n')
	{
		switch (key)
		{
			case '-': sign = (-1); break;
			default : valid_num = ValidInput(key); break;
		}

		if ((key != '-') )
		{
			*(array + count) = key;
			++count;
		}
	}

	*(array + count) = 'f';
	return valid_num;
}

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Este teclado permite obtener numeros int de los caracteres ingresados en la consola

int KeyboardInt (int * valid)
{
	int key;
	int sign = 1;
	int valid_num;
	int validity;
	int entero=0;
	int respuesta;

	while ( (key = getchar()) != '\n')
	{
		switch (key)
		{
			case '-': sign = (-1); break;
			default : valid_num = ValidInput(key); break;
		}

		if ((key != '-') && ( key!= '.'))
		{
			if (valid_num == TRUE)
			{
				key = key - '0';

				entero = ( 10 * entero) + key;
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
		respuesta = (entero ) * sign;
	}
	return respuesta;
}

// definiciones necesarias
	#define TRUE (1)
	#define FALSE (0)

// Este teclado te permite obtener numeros reales de la consola

double KeyboardFloat (int * valid)
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
