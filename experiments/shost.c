#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	struct hostent *host;		// I'll try to figure this out lately
	struct in_addr **addr_list;	// same
	int i;

	if (argc != 2) {
		printf("Usage: %s dest_addr(not ip)\n", argv[0]);
		exit(1);
	}

	char *addr = argv[1];	// just simplifying if program would get bigger

	if (gethostbyname(addr) != NULL) {	// gethostbyname() will fulfill hostent structure with necessary data.
		host = gethostbyname(addr);
	} else {
		fprintf(stderr, "gethostbyname error\n");
		exit(1);
	}

	addr_list = (struct in_addr **)host->h_addr_list;	// i think that here we do casting because of addr_list variable. What would be
								// if we do not do the casting? I have to check this code.
	for(i=0; addr_list[i] != NULL; i++) {
		printf("%s\n", inet_ntoa(*addr_list[i]));	// we do * because addr_list[i] just address of *addr_list[]
	}

	// for(i=0; host->h_addr_list[i] != NULL; i++) {
	//     	 printf("%s\n", inet_ntoa(host->h_addr_list[i]));	// i don't know why, but here's error. Compiler tells incompatible
	// }								// type for argument 1 of ‘inet_ntoa’. I'll try to write like another
									// program to figure out this.


	return 0;
}
