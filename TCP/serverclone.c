#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "netdb.h"
#include "sys/fcntl.h"

#define BUF_SIZE 4096
#define SERVER_PORT 2234

char buffer[BUF_SIZE], fname[100];
int s, sa, fd, b, bytes, on = 1;

int main(int argc, char const *argv[]) {
	struct sockaddr_in channel;

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));

	memset(&channel, 0, sizeof(channel));

	channel.sin_family = AF_INET;
	channel.sin_addr.s_addr = htonl(INADDR_ANY);
	channel.sin_port = htons(SERVER_PORT);

	b = bind(s, (struct sockaddr *)&channel, sizeof(channel));

	listen(s, 5);

	while(1) {
		sa = accept(s, 0, 0);

		memset(fname, 0, sizeof(fname));

		read(sa, fname, sizeof(fname));

		fd = open(fname, O_RDONLY);

		while((bytes = read(fd, buffer, BUF_SIZE)) > 0) {
			write(sa, buffer, bytes);
		}
		close(fd);
	}

	close(sa);

return 0;
}