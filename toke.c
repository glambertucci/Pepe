#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define REPLACE (0)
#define CERO (99)


//Hay un problema con el largo del arreglo temporal.

int CheckChar (char letter, char *delimitadores);
int LetterCounter ( char * point);
void CopyString ( char * copy, char * string, int characters);
void DeleteString (int num, char * string);
void MoveString (int numero, char * string);
char * token (char * string , char * delimitadores);


int main (void)
{
	char * delimitadores = " ,.";
	char string[] = "hola,todo bien capo";
	//int var =0;
	char * tok;

	printf("Separando %s en tokens\n", string );

	tok = token(string, delimitadores); 
	while (tok != NULL )
	{
	//	printf("var = %d\n",var );
		printf("%s \n", tok );
	//	++var;
		tok = token(string, delimitadores);
	}
	return 0;
}


char * token (char * string , char * delimitadores)
{
	int space;
	char temporal[16];
	char * point = temporal;

	//printf("---Entra a Token\n");

	if ( (CheckChar(string[0],delimitadores)) == CERO)
	{
		//printf("---Termino el string\n");
			point = NULL;
		//	printf("%s\n", string );
	}
	else
	{
		//printf("---Se fija la cantidad de espacios que hay antes de un caracter\n");
		for (space = 0 ; CheckChar(string[space],delimitadores) == 0 ; ++space )
		{
		}
		
		//printf("--- space%d\n", space );
		//printf("---Copia el string\n");
		CopyString ( point, string, space);
		//printf("---%s\n", point );
		//printf("---Mueve el string principal\n");
		MoveString ((space + 1),string);
		//printf("---Borra lo sobrante del string principal\n");
		DeleteString ((space+1),string);
	}
	//printf("---Devuelve el string recortado\n");
	return point;
}




void MoveString (int numero, char * string)
{
	int letter;
	for(letter = 0 ; *(string + numero + letter) != 0 ; ++letter)
	{
	//	printf("%c -- %c\n",*(string + letter), *(string + letter + numero) );
		*(string + letter) = *(string + numero + letter);
	}
}

void DeleteString (int num, char * string)
{
	int letter;
	int length = LetterCounter(string);

	//printf("%d\n", length);
	//printf("%d\n", num );

	for(letter = 0 ; letter < num ; ++letter)
	{
		//printf("%c---", *(string + num - letter));
		*(string + length -1 - letter) = REPLACE;
		//printf("%c\n", *(string + num - letter) );
	}
	//printf("%s\n", string );
}

void CopyString ( char * copy, char * string, int characters)
{
	int letter;

	for ( letter = 0 ; letter < characters ; ++letter)
	{
		*(copy + letter) = *(string + letter);
	}
}

int CheckChar (char letter, char *delimitadores)
{
	int value = FALSE;
	int contador;
	int length = LetterCounter(delimitadores);

	if (letter != 0)
	{
		for (contador = 0 ; contador < length ; ++contador )
		{
			if( letter == *(delimitadores + contador))
			{
				value = TRUE;
			}
		}
	}
	else
	{
		value = CERO;
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