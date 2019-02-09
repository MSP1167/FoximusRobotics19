#define _DEFAULT_SOURCE

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

int udpRecieve()
{
    struct sockaddr_in src = { .sin_family=AF_INET, .sin_addr.s_addr=INADDR_ANY, .sin_port=htons(68) };

    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

    const int on=1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    struct ifreq ifr;
    memset(&ifr, '\0', sizeof(ifr));
    ioctl(fd, SIOCGIFINDEX, &ifr);
    setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));

    bind(fd, (struct sockaddr *)&src, sizeof(src));

    char buf[512];
    ssize_t res = recvfrom(fd, buf, sizeof(buf), 0, NULL, 0);
    //printf("res=%zi\n", res);
	//Returns the recieved value
    return res;
}