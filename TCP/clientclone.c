#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/fcntl.h"
#include "netdb.h"

#define SERVER_PORT 2234
#define BUF_SIZE 4096

char fname[128], buff[BUF_SIZE];
int byte, c, s;

int main(int argc, char const *argv[]) {
	
	struct sockaddr_in channel;
	struct hostent * h;

	gets(fname);

	h = gethostbyname("localhost");

	memset(&channel, 0, sizeof(channel));
	channel.sin_family = AF_INET;
	memcpy(&channel.sin_addr.s_addr, h->h_addr, h->h_length);

	channel.sin_port = htons(SERVER_PORT);

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	c = connect(s, (struct sockaddr*)&channel, sizeof(channel));

	write(s, fname, sizeof(fname));

	while((byte = read(s, buff, BUF_SIZE)) > 0) {
		write(1, buff, byte);
	}

return 0;
}