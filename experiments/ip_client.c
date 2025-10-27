#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 5000

int main(int argc, char *argv[]) {
	struct sockaddr_in adi;
	int ssock_fd, csock_fd;
	char IP[256];

	csock_fd = socket(PF_INET, SOCK_STREAM, 0);	// creating the socket with protocol family(pf)
	if(csock_fd < 0) {
		fprintf(stderr, "socket error\n");
		exit(1);
	}

	adi.sin_port = htons(PORT);	// translating from string to integer
	adi.sin_family = PF_INET;
	adi.sin_addr.s_addr = inet_addr("127.0.0.1");	// translating from internet address(in this case string) to network byte order

	connect(csock_fd, (struct sockaddr *)&adi, sizeof(adi));	// giving address of adi and casting to sockaddr,
									// then passing to connect
	strcpy(IP, inet_ntoa(adi.sin_addr));	// i don't know what is meaning of adi.sin_addr, so i will look up for it later
	send(csock_fd, IP, sizeof(IP), 0);	// sending ip to host(csock_fd is configured using sockaddr_in)

	close(csock_fd);

	return 0;
}
