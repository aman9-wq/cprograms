#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	struct hostent *host;
	struct hostent he;

	host = gethostbyname(argv[1]);

	/* he = gethostbyname(argv[1]); leads to error, i dont know why. Perhaps it is because gethostbyname return address to another
	   hostent structure which is fulfilled with data that is related to host */

	printf("%p\n", gethostbyname(argv[1]));		// which is confirms my theory, but maybe there are some arguments against?

	printf("%p %p %p\n", &host->h_addr_list, host->h_addr_list, *host->h_addr_list);
	printf("%p %p %p\n", &host->h_addr_list[0], host->h_addr_list[0], *host->h_addr_list[0]);	/* here *host->h_addr_list ==
													   host->h_addr_list[0] is true
													   it is because *host->h_addr
													  _list is beginning of arr */

	printf("%p %p\n", *host->h_addr_list + 1, *host->h_addr_list + sizeof(char));		/* i don't know why, but it will output the
												   same address */

	return 0;
}
