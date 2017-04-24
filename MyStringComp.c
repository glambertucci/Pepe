#include <stdio.h>
int myStringComp (const char *s, const char *t);
int check ( const char *a, const char *b );


int main (void)
{
	const char *primero = "holoaaab";
	const char *segundo = "holoaaa";
	
	int result = myStringComp(primero,segundo);
	
	printf("%d\n", result);
	
	return 0;
}



int myStringComp (const char *s, const char *t)
{
	const char *temps = s;
	const char *tempt = t;
	
	int same = 0;
	int count = 0;
	int dif = 0;
	int highlow;
	int a = check(temps,tempt);
	
	while ( a != 0)
	{
		if ( *temps == *tempt )
		{
			++same;
		}
		else if ( *temps != *tempt )
		{
			++dif;
		}
		
		if (dif == 1)
		{
			if ( *temps > *tempt )
			{
				highlow = 1;
			}
			else if (*temps < *tempt )
			{
				highlow = -1;
			}
		}
		
		++temps;
		++tempt;
		++count;
		
		a = check(temps,tempt);		
	}
	
	if ( same == count )
	{
		highlow = 0;
	}
		
	return highlow;
}


int check ( const char *a, const char *b )
{
	int var;
	
	if	( ( *(a) != 0 ) || ( *(b) != 0 ) )
	{
		var = 1;	
	}
	else
	{
		var = 0;
	}
	return var;
}