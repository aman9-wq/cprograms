#include <stdio.h>

int main(int argc, char *argv[]) {
	int *a;
	int *b;
	int *c;

	printf("%p %p %p\n", &a, a, *a);
	printf("%p %p %p\n", &c, c, *c);
	printf("%s %s %s\n", &a, a);		// In some reason printf("%s %s %s\n", &b, b) cause to segmentation fault

	return 0;
}
