#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>

#define PORT 5000

int main(int argc, char *argv[]) {
	struct sockaddr_in servaddr, newaddr;
	int ssocket_fd, newsock_fd, s, size;
	char buffer[100];

	ssocket_fd = socket(PF_INET, SOCK_STREAM, 0);
	if(ssocket_fd < 0) {
		fprintf(stderr, "socket error\n");
		exit(1);
	}

	// socket configuration
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	// binds socket to all available interfaces(not just localhost). It is needed for bind
	servaddr.sin_family = PF_INET;

	s = bind(ssocket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));	// assigning a name to a socket
	if(s != 0) {
		fprintf(stderr, "bind error\n");
		exit(1);
	}

	listen(ssocket_fd, 1);	// marks ssocket_fd as a passive socket, that is ssocket_fd will be used
				// to accept incoming connection from accept()

	size = sizeof(newaddr);
	newsock_fd = accept(ssocket_fd, (struct sockaddr *)&newaddr, &size);	// accept incoming connection
	if(newsock_fd < 0) {
		fprintf(stderr, "accept error\n");
		exit(1);
	}

	recv(newsock_fd, buffer, 1024, 0);	// recving data and writing it to buffer
	printf("IP addr of client: %s\n", buffer);	

	close(ssocket_fd);
}
