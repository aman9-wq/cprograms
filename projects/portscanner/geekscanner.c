#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 4) {
		fprintf("Usage: %s site range_start range_end");
		exit(1);
	}

	char tip[16] = { 0 };	// just fulfill this char array with 0s 
	strcpy(tip, argv[1]);	// copying argv[1] to this array
	char first_port[6] = { 0 };
	strcpy(first_port, argv[2]);
	char end_port[6] = { 0 };
	strcpy(end_port, argv[3]);
	
	geek_scanner(tip, first_port, end_port);

	return 0;
}

void geek_scanner(ip, range_start, range_end) {
	struct addrinfo hints;			// What is the primary purpose of this structure? I think that this structure helps us later
	memset(&hints, sizeof(hints), 0);	// with info of host and correct data for gethostbyname()
	hints->ai_family = AF_INET;		// just fulfill with protocol that we will use
	hints->ai_socktype = SOCK_STREAM;	// same as above
	
	getaddrinfo(ip, &hints, &serv_addr);
}
