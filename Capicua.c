#include <stdio.h>



#define TRUE (1)
#define FALSE (0)
#define NEGATIVE ('2')
#define POSITIVE ('1')

int keyboard (char *);
int ValidInput ( int key);
void Reverse ( char * array);
int LetterCounter ( char * point);								

int main (void)
{
	char array[20];
	int valid = keyboard(array);

	//printf("%s\n", array );

	if (valid == TRUE)
	{
		Reverse(array);
	}
	else
	{
		printf("Entrada invalida\n");
	}
}




void Reverse ( char * array)
{
	char count, cap = 0;
	int length;

	//printf("%s\n", array );

	length = LetterCounter(array);

	//printf("%d\n", length );

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
		printf("Es capicua\n");
	}
	else
	{
		printf("No es capicua\n");
	}
}

int LetterCounter ( char * point)								
{
	int letter;
	
	for ( letter = 0 ; *(point + letter) != 'f' ; ++letter )
	{	
	}
	
	return letter;
}

int keyboard (char * array)
{
	int key;
	char sign = POSITIVE;
	int valid_num;
	int count = 0;

	while ( (key = getchar()) != '\n')
	{
		switch (key)
		{
			case '-': sign = (NEGATIVE); break;
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