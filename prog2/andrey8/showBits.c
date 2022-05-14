// andrey toderyan
/* 10/19/21
  
   showbits
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int show_common(int argc, char * argv[]);

int main(int argc, char * argv[])
{

	
	int i = 0;
	for(i = 0; i < argc; ++i)
	{
			
		printf("%d , %s \n", argc , argv[i]);
	}
	
	show_common(argc, argv);	

	return 0;
}
int show_common(int argc, char * argv[])
{
	long int first = strtol(argv[1], NULL, 16);
	long int two = strtol(argv[2], NULL, 16);

	int i = 0;
	int x = 0;
	
	long int result = (first & two);

	printf("Bits ");

	while(x < 32)
	{
		if( ((result>> i) & 1 ) == 1)
			printf("%d,", i); 
		++i;
		++x;
	}
	printf("in common. ");

	unsigned int hex = result;	
	
	printf("Hexadecimal: %x, ", hex);

	printf("Signed: %d, ", hex);

	printf("Unsigned: %ld.", result);
	
		
	return 1;
}





