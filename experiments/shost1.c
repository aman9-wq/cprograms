#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	struct hostent *host;
	struct in_addr **addr_list;

	host = gethostbyname(argv[1]);

	addr_list = (struct in_addr **)host->h_addr_list;

	printf("%p %p %p %p\n", &addr_list, addr_list, *addr_list, **addr_list);	// just like basic pointer, but it has 2 pointers.
						// first pointer is addr_list and the second is
	
	for(int i=0; addr_list[i] != NULL; i++) {
		printf("%s\n", inet_ntoa(*addr_list[i]));
	}

	return 0;									// *addr_list which points to char array(not
}											// confident with that on 100%).
