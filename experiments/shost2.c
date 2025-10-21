#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	struct hostent *host;

	host = gethostbyname(argv[1]);

	printf("%s %s\n", host->h_addr_list[0], host->h_addr_list[1]);	/* some garbage value(in fact with different type represantation it's
									   not garbage). man page says that host->h_addr_list[0] is the
									   representation of struct in_addr fields(that is internet addr 
									   fields). Code that explain what addresses are respond for what
									   are in shost_addrs.c */

	printf("%p\n", (void *)(**host->h_addr_list + 1));	// wtf is going on???

	return 0;
}
