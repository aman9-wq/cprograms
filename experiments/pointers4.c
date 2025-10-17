#include <stdio.h>

int main(int argc, char *argv[]) {
	int *a;
	int *str;

	printf("%p %p %p\n", &a, a, *a);
	printf("%p %p %p\n");

	return 0;
}
