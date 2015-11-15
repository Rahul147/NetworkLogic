#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(void) {
	char fname[50], buffer[50];
	int req, res, n;

	req = open("req.fifo", O_WRONLY);
	res = open("res.fifo", O_RDONLY);

	printf("Enter the filename to be requested:");
	scanf("%s", fname);

	write(req, fname, sizeof(fname));

	printf("Recieved Response\n");

	while((n = read(res, buffer, sizeof(buffer))) > 0) {
		write(1, buffer, n);
	}

	close(req);
	close(res);
return 0;
}