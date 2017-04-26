#include <stdio.h>

#define SIZE (50)
#define TRUE (1)
#define FALSE (0)
#define SUCCESS ('-')

char * InputWord (char array[SIZE]);
void CleanArray (char array[SIZE]);
void LowCase (char *array);
int ValidInput (char *array);
int LetterCounter ( char * point);								
int CheckWord (char * word);
void CompareWord (char * word1 , char * word2);

int main (void)
{
	char word1[SIZE]; 
	char word2[SIZE];

	CleanArray(word1);
	CleanArray(word2);

	int valid;

	char * point1 = InputWord(word1);

	valid = ValidInput(word1);

	while (	valid == FALSE)
	{
		printf("caracter Incorrecto\n");
		CleanArray(word1);
		point1 = InputWord(word1);
		valid = ValidInput(word1);
	}

	LowCase (word1);

	char * point2 = InputWord(word2);
	valid = ValidInput(word2);

		while (	valid == FALSE)
	{
		printf("caracter Incorrecto\n");
		CleanArray(word2);	
		point2 = InputWord(word2);
		valid = ValidInput(word2);
	}

	LowCase (word2);

	CompareWord(word1,word2);

	valid = CheckWord(word2);

	switch (valid)
	{
		case TRUE: printf("Es un Anagrama\n");break;
		case FALSE: printf("No es un Anagrama\n");break;
	}

	return 0;
}

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
					*(word2 + count2) = SUCCESS;
				}
			}
		}
	}
}


int ValidInput (char *array)
{
	int count;
	int value = TRUE;
	char letter;

	if ( *(array + SIZE -1 ) == 0)
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

char * InputWord (char array[SIZE])
{
	char *word = array;

	char letter;
	int count;

	for ( count = 0; count < (SIZE-1) ; ++count)
	{
		letter = getchar();

		switch (letter)
		{
			case '\n': count = SIZE; break;
			default : *(word + count) = letter; break;
		}
	}

	return word;
}

void CleanArray (char array[SIZE])
{
	int count;

	for (count = 0 ; count < SIZE ; ++count)
	{
		*(array + count) = 0;
	}
}

int LetterCounter ( char * point)								
{
	int letter;
	
	for ( letter = 0 ; *(point + letter) != 0 ; ++letter )
	{	
	}
	
	return letter;
}