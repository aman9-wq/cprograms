#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	int *x;
	char *arr;
	bool *m;

	int y = 10;

	/* I know that if we'll use different identifiers like %c, %u, %l and so on,
	   then it just representation of value in some type of data that is located
	   by some specific address. So, i won't use different identifiers in this 
	   experiment, expect some special situations */

	printf("%p %p %p\n", &x, x, *x);	// why printf with argument *x prints some value, that is not changing from one
	printf("%p %p %p\n", &arr, arr, *arr);  // execution to another
	// In some reason this leads to error: printf("%p %p %p", &m, m, *m);

	printf("%d %d %d\n", &x, x, *x);	// I assume that this will print addresses in integer either negative or positive
	printf("%d %d %d\n", &arr, arr, *arr);	// Here are the question: Why it prints negative?

	printf("%s %s %s\n", &x, x);		// Here we can see that it prints some strange sequence of symbols
	printf("%s %s %s\n", &arr, arr);	// The main question is: why? Also, if we add *arr or *x as an argument to printf then 
						// it cause to fault

	printf("%c %c %c\n", &x, x, *x);	// same - strange symbols
	printf("%c %c %c\n", &arr, arr, *arr);

	x = 10;

	printf("\n");
	printf("%p %p %p\n", &x, x);		// if i add &x as 3rd argument it will cause to fall
	printf("%s %s %s\n", &x);		// x and *x same
	printf("%c %c %c\n", &x, x);		// *x same

	return 0;
}
