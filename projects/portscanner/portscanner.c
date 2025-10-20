#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct sockaddr_in remote;

	int sfd = socket(AF_INET, SOCK_STREAM, 1);
	if (sfd < 0) {
		perror("socket error");
		return 1;
	}

	memset(&remote, sizeof(struct sockaddr_in), 0);
	remote->sin_family = AF_INET;
	remote->sin_port = htons(atoi(argv[1]));
	remote->sin_addr = inet_aton();
