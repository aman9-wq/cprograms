#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>		/* inet_ntoa don't work without arpa/inet.h, sys/socket.h, netinet/in.h, so for correct work you should
				   don't forget about this libraries */

int main(int argc, char *argv[]) {
	struct hostent *host;
	struct in_addr **addr_list;

	host = gethostbyname(argv[1]);

	addr_list = (struct in_addr **)host->h_addr_list;	// next i'll try to figure out how type casting works

	printf("%p %p %p %p\n", &addr_list, addr_list, *addr_list, **addr_list);	/* just like basic pointer, but it has 2 pointers.
											   first pointer is addr_list and the second is
											   *addr_list which points to char array(not
                                                                                           confident with that on 100%). shost2.c has exp-
											   planation of this code */

	printf("%s", inet_ntoa(*addr_list[1]));

	for(int i=0; addr_list[i] != NULL; i++) {					
		printf("%s\n", inet_ntoa(*addr_list[i]));
	}

	return 0;
}
