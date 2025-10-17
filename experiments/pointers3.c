#include <stdio.h>

int main(int argc, char *argv[]) {
	int *a;
	char *str;

	printf("%p %p %p\n", &a, a, *a);
	printf("%p %p %p\n", &str, str, *str);

	return 0;
}
