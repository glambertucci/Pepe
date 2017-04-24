#include <stdio.h>
#define SIZEARRAY (9)
char *myStringCat ( char * dest, const char * source);

int main (void)
{
	const char * source = "guido";
	char array [SIZEARRAY];
	
//	printf("--- %s \n", source);
	
	int reg;
	
	for (reg = 0; reg < SIZEARRAY ; ++reg)
	{
		array[reg] = 0;
	}
	array[0] = 'H';
	array[1] = 'o';
	array[2] = 'l';
	array[3] = 'a';
	array[4] = ' ';
	
//	printf("--- %s \n", array);
	

	char * string = myStringCat( array,source);
	
	printf ("%s\n", string);
	
	
	return 0;
}


char * myStringCat ( char * dest, const char * source)
{
	char * tempdest = dest;
	//printf("%p
	const char * tempsource = source;
	
//	printf("---Copio los strings\n");
//	printf("--- %s \n", tempsource);
//	printf("--- %s \n", tempdest);

	
	int stringdest, count;
	
	for ( stringdest = 0 ; *tempdest != 0 ; ++stringdest)
	{
	//	printf("%c\n", *tempdest);
		++tempdest;
		
	}
	tempdest = tempdest - stringdest;
//	printf("-string- %s \n", tempdest);
//	printf("---%d\n", stringdest);
	
	for ( count = 0 ; count < 5 ; ++count)
	{
	//	printf("%c--", tempsource[count]);
	//	printf("%c\n", tempdest[stringdest + count ]);
		*( tempdest + stringdest + count ) = *(tempsource + count);
	}
	
	printf("--- %s \n", tempdest);
	
	printf("---Sale bien de la funcion\n");
	
	return tempdest;
}














