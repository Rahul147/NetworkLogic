/*
12. Write a program for congestion control using leaky bucket algorithm.
*/

#include "stdio.h"
#include "unistd.h"
#define BKTSIZE 500

void bucket(int, int);

int main(void) {
	int i, noPackets, opRate, packetSize;

	printf("Enter the number of packets:\t");
	scanf("%d", &noPackets);

	printf("Enter the output rate:\t");
	scanf("%d", &opRate);

	for(i = 0; i < noPackets; i++) {
		sleep(1);
		packetSize = rand() % 777;

		printf("Packet[%d] = %d bytes\n", i + 1, packetSize);
		printf("\n\n");
		bucket(packetSize, opRate);
		printf("=========================================================\n");
	}
	return 0;
}

void bucket(int packetSize, int opRate) {

	if(packetSize > BKTSIZE) {
		printf("Bucket Overflow\n");
		return;
	} 
	else {
		while(packetSize > opRate) {
			printf("Number of bytes outputted is: %d\n\n", opRate);
			packetSize -= opRate;
			sleep(2);
		}
		if(packetSize > 0) {
			printf("Number of bytes outputted is: %d\n\n", packetSize);
		}

		printf("Bucket contents emptied\n");
	}
}