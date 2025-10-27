#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	printf("%d\n", INADDR_ANY);
	printf("%s\n", INADDR_ANY);

	return 0;
}
