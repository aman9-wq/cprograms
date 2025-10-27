#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	struct sockaddr_in sa;

	sa.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("%d\n", sa.sin_addr);
	printf("%s\n", (char *)&sa.sin_addr);

	printf("%p %p\n", &sa.sin_addr, sa.sin_addr);

	return 0;
}
