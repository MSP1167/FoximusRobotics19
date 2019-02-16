#include "UDP.h"
#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> /* for fprintf */ 
#include <string.h> /* for memcpy */ 
#include <sys/types.h>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

#include <stdio.h>
using namespace std;
UDP::UDP{
	//constructor here if needed
}

void UDP::Send(string msg) {
	//send that boi to the RIO or other computer
	struct hostent *hp; /* host information */
	struct sockaddr_in servaddr; /* server address */

	//char *my_messsage = "this is a test message"; 

	/* fill in the server's address and data */
	memset((char*)&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);

	/* look up the address of the server given its name */
	hp = gethostbyname(host);
	if (!hp) {
		fprintf(stderr, "could not obtain address of %s\n", host);
		return 0;
	}

	/* put the host's address into the server address structure */
	memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

	/* send a message to the server */
	if (sendto(fd, sendToRIO, strlen(sendToRIO), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("sendto failed");
		return 0;
	}
}

string UDP::Receive() {
	//read the buffer
	struct sockaddr_in src = { .sin_family = AF_INET,.sin_addr.s_addr = INADDR_ANY,.sin_port = htons(68) };

	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

	const int on = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	struct ifreq ifr;
	memset(&ifr, '\0', sizeof(ifr));
	ioctl(fd, SIOCGIFINDEX, &ifr);
	setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));

	bind(fd, (struct sockaddr *)&src, sizeof(src));

	string final = "";
	char buf[512];
	ssize_t res = recvfrom(fd, buf, sizeof(buf), 0, NULL, 0);
	final += res;
	//Returns the recieved value
	return final;
}
