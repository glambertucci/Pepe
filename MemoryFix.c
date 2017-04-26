#include <stdio.h>

#define TRUEMASK (0x100af120)
#define byte0 (0x20)
#define byte1 (0xf1)
#define byte2 (0x0a)
#define byte3 (0x10)

void fix ( int * numbers, int max_num);

int main (void)
{
	int num [5] = {0x100af120,0x100af121,0x100af020,0x104af120, 0x200af120};
	int max_num = 5;
	int count;

	for ( count = 0 ; count < max_num ; ++count)
	{
		printf("%d | ", num[count]);
	}
	putchar('\n');

	fix(num,max_num);

	for ( count = 0 ; count < max_num ; ++count)
	{
		printf("%d | ", num[count]);
	}
	putchar('\n');


	return 0;
}





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