#include <stdio.h>

int main(int argc, char *argv[]) {
	int *a;

	printf("%p %p %p", &a, a, *a);

	return 0;
}
