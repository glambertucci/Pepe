#include <stdio.h>

void LetterKeyboard(void);


int main (void)
{
	LetterKeyboard();
	return 0;
}


void LetterKeyboard(void)
{
	char c;
	int out=0;

	c = getchar();
	while  (out != 1 )
	{
		//printf("%c\n", c );
		switch (c)
		{
			case 'q':out = 1 ;break;
			case 'Q':out = 1 ;break;
		}
		//printf("%d\n", out );
		if ( out != 1)
		{
			c = getchar();
		}
	}
}