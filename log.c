#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define SIZE (2)

int CheckArgument ( char letter );
int LetterCounter ( char * point);
int ValidString (char * point1, char * point2);

int main (int argc, char *argv[])
{
	char * arguments[SIZE] = {"-u","-p"};				//Defini los usuarios con sus contrasenas y a los argumentos.
	char * user1[] = { "Lucas","12345"};
	char * user2[] = { "Guido","puto"};
	char * user3[] = { "Fran","tonto"};
	char * user4[] = { "Tom","vergalarga"};
	
	int word, try, arg, error, code;
	
	for ( word = 1 ; word < argc ; ++ word )			// Para cada palabra enviada por el usuario, se va a fijar si es un
	{													//argumento o informacion. Como los argumentos tienen que venir antes de 
//		printf("entrando a CheckArgument\n");			// la info y el primer argumento esta en la posicion 1, la informacion va a 
														// estar en los lugares pares. Luego verifica que cada usuario se igrese con
		arg = CheckArgument(argv[word][0]);				// su contrasena.
		
//		printf("Saliendo de CheckArgument, arg = %d\n",arg );

		if ( arg == FALSE)
		{
			if ( ( word % 2 ) == 0 )
			{
				code = ValidString ( argv[word], user1[try] );
				
//				printf("---user1, code = %d\n", code);
				
				if (code == 0)
				{
					code = ValidString ( argv[word], user2[try] );
//					printf("---user2, code = %d\n", code);
				
					if (code == 0)
					{
						code = ValidString ( argv[word], user3[try] );
//						printf("---user3, code = %d\n", code);
				
						if (code == 0)
						{
							code = ValidString ( argv[word], user4[try] );
//							printf("---user4, code = %d\n", code);
				
							if ( code == 0 )
							{
								error = TRUE;
								word = argc;				
							}

						}
					}
				}		
			}
			else
			{
				error = TRUE;
				word = argc;
			}
		}
		else if ( arg == TRUE )
		{
			
			for (try = 0 ; try < SIZE ; ++try )
			{
				code = ValidString(argv[word],arguments[try]);
				
				if (code == 1)
				{
					try = try + SIZE - 1;
				}			
			}
			
			if ( ( try == SIZE ) && ( code == 0 ) )
			{
				error = TRUE;
				word = argc;
			}
			else
			{
				try = try - SIZE;
			}
		}
	}

	if ( (argc-1) != ( 2 * SIZE))
	{
		error = TRUE;
//		printf("puto\n");
	}
		
	if ( error == TRUE )
	{
		printf("Usuario o Constrasena invalida\n");
	}
	else
	{
		if ( ValidString(argv[1],arguments[0]))
		{
			printf("Bienvenido %s\n",argv[2]);
		}
		else if (ValidString(argv[3],arguments[0]))
		{
			printf("Bienvenido %s\n",argv[4]);
		}
	}
	

	return 0;
}




int CheckArgument ( char letter )								// Esta funcion se encarga de fijarse si el primer caracter
{																// de un string indica que es un argumento.
	int value;
	
	switch (letter)
	{
		case '-': value = TRUE; break;
		default : value = FALSE; break;
	}
	
	return value;
}

int ValidString (char * point1, char * point2)					//Esta funcion se fija que dos strings sean iguales
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


int LetterCounter ( char * point)								// Esta funcion cuenta la cantidad de caracteres que tiene un string
{
	int letter;
	
	for ( letter = 0 ; *(point + letter) != 0 ; ++letter )
	{	
	}
	
	return letter;
}