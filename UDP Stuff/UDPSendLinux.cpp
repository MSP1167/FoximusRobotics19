#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> /* for fprintf */ 
#include <string.h> /* for memcpy */ 

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