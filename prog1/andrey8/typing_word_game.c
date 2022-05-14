// 10/05/2021
// Andrey Toderyan
/*


*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

/*	Prototypes	*/
void print(char *  words[], int);
void randomize( int order[], int n);
void swap(int * a, int * b );
void test(int [], char * [], int );

int main()
{

	printf("This is a game that tests typing speed\n\n");

	char * words[] = {"The" ,"dog",  "brown", "over", "lazy",
					"the","quick" , "jumps", "fox"};

	int wordCount = sizeof(words)/sizeof(words[0]);
	int order[] = {0,1,2,3,4,5,6,7,8};

	

	//randomizes the number array 
	randomize(order, wordCount);

	//print(words, wordCount);

	
	
	

	//runs the typing test and displays time
	test(order,words,wordCount);

	return 0;
}
void test(int order[], char * words[], int wordCount)
{
	int counter = 0;
	char entry[6];
	int i = 1;

	//timer struct	
	struct timeval time0, time1, time_diff; 

	printf("Type the following words:\n");	

	//timer start
	gettimeofday (&time0, NULL);	

	while( counter < 9)
	{
		printf("word #%d is %s: ", i, words[order[counter]]);
		if(scanf("%s", entry) != 0);

		for(int i = 0; i < 6; ++i)
		{
			if(entry[i] == ' ')
				entry[i] = '\n';
		}
		//printf("word enter: %s, need %s", entry, words[order[counter]]);
		if(strcmp(entry,words[order[counter]]) == 0)
		{
			++counter;
			++i;
			//memset(entry, 0, 20);
		}
		//++counter;
	}
	gettimeofday(&time1, NULL);

	timersub(&time1, &time0, &time_diff);

	printf("You took %ld seconds and %ld microseconds", 
			time_diff.tv_sec, time_diff.tv_usec);


}
//print just the words array 
void print(char * words[], int wordCount)
{	
	//printf("Type the following words:\n");	
	for(int i = 1; i < 10; ++i)
	{
		if(words[i] == NULL)
			break;
		printf("word #%d is %s:\n",i,words[i-1]);
	}
}
//Fisher-Yates Shuffle 
void randomize(int order[], int n)
{
	srand(time(NULL));
	for (int i = n-1; i > 0;i--)
	{
		int j = rand() % (10);
		swap(&order[i],&order[j]);	
	}
}
void swap ( int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

