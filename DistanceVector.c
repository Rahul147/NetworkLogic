/*
8. Write a program for distance vector algorithm to find suitable path for
transmission.
*/
#include "stdio.h"

#define MAX 10

struct dist {
	int dist[MAX];
	int from[MAX];
}rt[10];

int main(void)
{
	int dm[MAX][MAX], i, j ,k, noNodes, count;

	printf("Enter the number of nodes: ");
	scanf("%d", &noNodes);

	for(i = 0; i < noNodes; i++) {
		for(j = 0; j < noNodes; j++) {
			scanf("%d", &dm[i][j]);
			dm[i][i] = 0;
			rt[i].dist[j] = dm[i][j];
			rt[i].from[j] = j;
		}
	}

	do {
		count = 0;

		for(i = 0; i < noNodes; ++i) {
			for(j = 0; j < noNodes; ++j) {
				for(k = 0; k < noNodes; ++k) {
					if(rt[i].dist[j] > (dm[i][k] + rt[k].dist[j])) {
						rt[i].dist[j] = dm[i][k] + rt[k].dist[j];
						rt[i].from[j] = k;
						count++;
					}
				}
			}
		}
	} while(count != 0);

	for (i = 0; i < noNodes; ++i) {
		printf("Routing Info of Router %d\n", i + 1);
		printf("Dest\tNext Hop\tDist\n");

		for(j = 0; j < noNodes; ++j) {
			printf("%d\t%d\t\t%d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
		}
	}

	return 0;
}