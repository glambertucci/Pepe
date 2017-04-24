#include <stdio.h>
#define SIZE (20)
char * MyStringCat ( const char * pointer, char array[SIZE] );

int main (void)
{
	const char * source = "hola";
	char letter[SIZE] = "Puto ";

	char * string = MyStringCat(source, letter);
	
	printf(" %s \n", string);

	return 0;
}

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