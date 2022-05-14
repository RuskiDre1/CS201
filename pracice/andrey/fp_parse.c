// andrey toderyan
/* 10/19/21
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>


int error_check(int first, int second, char argv[3]);
int exponent( int frac, int exp, int hex);
int calculate_e(int second, int type);
float fraction(int first, int hex, int type);

int sign(int first , int second, int hex);
float calculator(int type, int E, float M, int S);

int main(int argc, char * argv[])
{

	int first, second, hex;

	sscanf(argv[1] , "%d", &first);		//fraction bits
	sscanf(argv[2] , "%d", &second);	//exp bits
	sscanf(argv[3] , "%x", &hex);		//hex num

	if(error_check(first, second, argv[3]) == 1)
		return 1;


	int type = 0;
	type = exponent(first, second, hex);

	// Calculating E
	int E = 0;
	E = calculate_e(second, type);

	//Fraction
	float M = 0;
	M = fraction(first, hex, type);

	//sign bit
	int S = 0;
	S = sign(first, second, hex);

	//calculator 
	calculator(type, E, M, S);
	
	return 0;
}

float calculator(int type, int E, float M, int S)
{
	//special cases
	if( M < 0)	
	{
		if (M == -2)
			printf("NaN");	
		else if(M == -1 && S == 1)
			printf("+inf");
		else
			printf("-inf");
		return 0;
	}

	printf("%f",( S * M * (pow(2,E)) ));
	return 1;
}
int sign(int first , int second, int hex)
{
	// run to the end and check the sign bit
	int shift = first + second; 
	
	if( ((hex >> shift) & 1) == 1)
		return -1;
	return 1;	

}
float fraction(int first, int hex, int type)
{
	//calculating the fraction
	int i = first;
	int x = -1;
	float sum = 0;

	while(i > 0)
	{
		
		--i;
		if( ( (hex>>i) & 1 ) == 1 )
			sum += ( pow( 2, x));
		--x;
	}

	// special cases	
	if(type == 0)
		return sum;
	if(type == -1 && sum == 0)
		return -1;
	if(type == -1 && sum != 0)
		return -2;

	return 1 + sum;

}
int calculate_e(int second, int type)
{
	// bias calculate
	int bias = ( pow(2, (second - 1)) - 1);

	if(type == 0)
		return (1  - bias); //all zeros denorm

	if(type == -1)
		return 0; // all 1s special

	else
		return ( type - bias);
		
	return -1;
}
int exponent( int frac, int exp, int hex)
{
	//find the exponent

	//check if exp is all 0's or all 1's
	//move over fraction bits and then compare

	int moved = frac;	// starting here (at "decimal point")
	int x = exp;		// how far we will shifting and comparing 
	int i = 1;		// bit shift compare
	int add = 0;

	int array[exp];

	
	while(x > 0)
	{
		if( ((hex>> (moved + add) & 1 ) == 1) )
			array[add] = 1;
		else
			array[add] = 0;	
		++add;	
		--x;
	}

	int sum = 0;
	//checking whether norm or denorm
	for(i = 0; i < exp; ++i)
		sum += array[i];	

	if(sum == 0)
		return 0;

	if(sum == exp)
		return -1;

	//if not denorm get the value
	int addition = 0;
	for(i = 0; i < exp; ++i)
		addition += ( array[i] * ( pow(2, i) ) );

	return addition;
}
int error_check(int first, int second, char hex[])
{
	//first number is fraction bit ( 2 - 10 )
	if( first < 2 || first > 10)
	{
		printf("Invalid number of fraction bits (%id).", first);
		printf("Should be between 2 and 10");
		return 1;
	}

	//second: exponent bits ( 3 - 5)
	if( second < 3 || second > 5)
	{
		printf("Invalid number of exponent bits (%id).", second); printf("Should be between 3 and 5");
		return 1;
	}
	
	//third: hexadecimal representation
	int hex_int;	
	sscanf(hex, "%x", &hex_int);	

	int i = 0;
	int len = strlen(hex);
	while(len != 0)
	{
		
		if(!isxdigit(hex[i]))
		{
			printf("Argument 3 is not a hexadecimal number (%x)", hex_int);
			return 1;
		}
		--len;
		++i;
	}

	// frac bit + exponent bit + sign bit should equal
	// or larger than hex bit 
	int bit_amount = first + second;
	

	int count = 0;
	while(hex_int)
	{
		count++;
		hex_int>>= 1;
	}
	int bit_require = count;

	if(bit_require > bit_amount + 1)
	{
		printf("Number %x exceeds maximum number of bits. ", hex_int);
		printf("Only %d allowed here", bit_amount);
		return 1;
	}

	return 0;
}


