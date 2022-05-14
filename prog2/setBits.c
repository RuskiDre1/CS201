// andrey toderyan
/* 10/19/21
  
   setbits
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int error_check(int argc, char * argv[]);
int set_and_print(int argc, char * argv[]);

int main(int argc, char * argv[])
{

	if(error_check(argc, argv) == 0)
	{
		printf("Invalid entry");
		exit(0);
	}

	set_and_print(argc, argv);	

	return 1;
}

int set_and_print(int argc, char * argv[])
{
	int largest = 15;
	int i = 1;
	int space = 0;
	//looking for largest, then print, else looking for next largest
	do
	{
		for(i = 1; i < 17; ++i)
		{
			if( argv[i]== NULL  && largest == 0)
			{
				printf("0");
				break;
			}
			//printf("in for loop");
			if( (argv[i] != NULL ) && (atoi(argv[i]) == largest))
			{
			
				//printf("%d \n" , atoi(argv[i]));
				printf("1");
				//largest = atoi(argv[i]);
				//printf("new largest: %d", largest);
				break;
			}
			if(i == 16)
			{
				printf("0");
				break;
			}
			
		}
		
		
		++space;
		if(space == 4)
		{
			printf(" "); 
			space = 0;	
		}
		
		
		--largest;	
		

	}while(largest >= 0  );
	
	printf("\n");
		
	return 0;
	
}
int error_check(int argc, char * argv[])
{
	int i = 0;


	for(i = 0; i < argc; ++i)
	{
		/*
		char * str = argv[i];
		if( isdigit(str) == 0)
			return 0;
		y = atoi(str); // Using atoi()
   		printf("\nThe value of y : %d", y);		
		*/

		if(atoi(argv[i]) < 0 && atoi(argv[i]) > 15)
		{
			return 0;
		}
	}
	return 1;
}
