/*	a4.c
	andrey toderyan
	10/19/21

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

struct menu
{
	int num_array[7];
	char * stringarray[7];
	
};

//Prototypes
int print_options( struct menu);
int calculator( int argc, char * argv [], struct menu, int (*func_ptr[])(int, char* []));

int Exit(int argc , char * argv [] );
int Addition(int argc , char * argv [] );
int Subtraction(int argc , char * argv [] );
int Modulo(int argc , char * argv [] );
int  Multiplication(int argc , char * argv [] );
int Division(int argc , char * argv [] );
int Reverse_input(int argc , char * argv [] );
int input_check(int argc , char * argv []);

int (*func_ptr[7])(int argc,char * argv);

int main(int argc, char * argv[])
{

	if(input_check(argc, argv))
		return 1;

	struct menu options = { {0,1,2,3,4,5,6} , {"Exit","Addition","Subtraction","Multiplication",
					"Division","Modulo","Reverse Input"} };
	
	//create table
	int (*func_ptr[7])(int, char * []) = {Exit,Addition,Subtraction, Multiplication,
                                                        Division,Modulo,Reverse_input};

	//calculator
	calculator( argc, argv, options, func_ptr);
	
	return EXIT_SUCCESS;

}
int input_check(int argc , char * argv [])
{
	if(argc < 3 || argc > 16)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
int Addition(int argc , char * argv [])
{
	int sum = 0;
	int temp = 0;
	
	for(int i = 1; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) == 1)
		{
			printf("temp :%i \n" , temp);
			sum += temp;
		}
	}
	
	for(int i = 1; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) == 1)
		{
			if(argc != i+1)
			{
				printf("%i + " , temp);
			
			}
			else
				printf("%i = ", temp);
		}
	}

	printf("%d", sum);

	return EXIT_SUCCESS;
}
int calculator( int argc, char * argv [], struct menu options, int (*func_ptr[])(int, char * []))
{
	int choice = 0;
	do
	{
		choice = print_options(options);

		if(choice > 6 || choice < 0)
		{
			printf("Invalid selection. Try again.");
		}
		else
			func_ptr[choice](argc, argv);
		
		printf("\n");

	}while(choice != 0);

	return EXIT_SUCCESS;
}
int Subtraction(int argc , char * argv [] )
{
	int temp = 0;
	sscanf(argv[1] , "%i", &temp);
	int sum = temp;
	
	for(int i = 2; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) == 1)
			sum -= temp;
	}

	for(int i = 1; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) != 1)
			return 0;
		if(argc != i+1)
		{
			printf("%i - " , temp);
			
		}
		else
			printf("%i = ", temp);
	}

	printf("%d", sum);

	return EXIT_SUCCESS;
}
int Modulo(int argc , char * argv [] )
{
	int one  = 0;
	int two = 0;
	
	sscanf(argv[1] , "%i", &one);
	sscanf(argv[2] , "%i", &two);
	int ans = one%two;

	printf("%i mod %i = %d" , one, two, ans);

	return EXIT_SUCCESS;
}
int Multiplication(int argc , char * argv [] )
{
	int temp = 0;
	sscanf(argv[1] , "%i", &temp);
	int sum = temp;

	for(int i = 2; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) == 1)
			sum = sum * temp;
	}

	for(int i = 1; i < argc; ++i)
	{
		if(sscanf(argv[i] , "%i", &temp) != 1)
			return 0;

		if(argc != i+1)
			printf("%d * " , temp);
		else
			printf("%d = ", temp);
	
	}

	printf("%d", sum);

	return EXIT_SUCCESS;
}
int Division(int argc , char * argv [] )
{		
	signed int one = 0;
	signed int two = 0;
	float calc1 = 0;
	float calc2 = 0;

	if(sscanf(argv[1] , "%i", &one) != 1)
		return 0;
	if(sscanf(argv[2] , "%i", &two) != 1)
		return 0;

	signed int ans = one / two;
	printf("This is the before approach: %d \n", ans);
	
	printf("%i / %i = " , one, two);
	
	if(two == 0)
		printf("-nan");
	else
	{
		if(sscanf(argv[1] , "%g", &calc1) != 1)
			return 0;
		if(sscanf(argv[2] , "%g", &calc2) != 1)		
			return 0;
		float ans = calc1 / calc2;
		printf("%f", ans);
	}

	return EXIT_SUCCESS;
}
int Reverse_input(int argc , char * argv [] )
{

	char str[50];
	char temp;

	for(int i = argc - 1; i > 0; --i)
	{
		strcpy(str, argv[i]);

		for(int j = strlen(str); j > -1; --j)
		{
			if(str[j])
			{
				temp = str[j];
				printf("%c", temp);
			}
		}
		if(i != 1)
			printf(" ");
	}
	
	return EXIT_SUCCESS;
}
int Exit(int argc , char * argv [] )
{
	return EXIT_SUCCESS;
}
int print_options( struct menu options)
{
	for(int i = 0; i < 7; ++i)
		printf("\n%d. %s", options.num_array[i], options.stringarray[i]);
	
	printf("\n\nMenu item: ");
	int num = 0;

	if(scanf("%d",&num));

	return num;
}
