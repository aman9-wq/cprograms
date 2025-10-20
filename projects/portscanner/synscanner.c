#include <stdio.h>

struct pseudo_header {
	unsigned int source_address;
	unsigned int dest_address;
	unsigned char placeholder;
	unsigned char protocol;
	unsigned short tcp_len;

	struct tcphdr tcph;
}

struct in_addr dest_ip;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <ip/dest address>\n", argv[0]);
		exit(1);
	}

	char *cplace = argv[1];

	if(inet_addr(cplace) != -1) {
		dest_ip.s_addr = inet_addr(cplace);	// conventing address from string(likely ip) to internet byte order, returns integer
	} else {
		const char *ip = hostname_to_ip(cplace);	// should return ip if host is give
		if(ip == NULL) {
			fprintf(stderr, "Unable to resolve hostname: %s\n", cplace);
			exit(1);
		} else {
			dest_ip.s_addr = inet_addr(ip);
		}
	}
}

void hostname_to_ip(addr) {
        struct hostent *host;
	struct in_addr **addr_list;
        int i;

        if((host = gethostbyname(addr)) == NULL) {
                fprintf(stderr, "gethostbyname error");
                return NULL;
        }

	addr_list = (in_addr **)host->h_addr_list;	// casting hostent pointer to in_addr double pointer

        for (i=0; host->addr_list[i] != NULL; i++) {	// if addresses end, then it is NULL
                return host->h_addr_list[i];		// return first address, it may be looked even without for loop
        }	

        return NULL;
}
