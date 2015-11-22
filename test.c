#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define N strlen(g)

char cs[128], t[128], x[128], g[] = "10001000000100001";
int e, c, a;

void xor() {
	for(c = 1; c < N; c++)
		cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc() {
	for(e = 0; e < N; e++)
		cs[e] = t[e];

	do {
		if(cs[0] == '1')
			xor();

		for(c = 0; c < N - 1; c++)
			cs[c] = cs[c + 1];

		cs[c] = t[e++];
	} while(e <= a + N - 1);
}

int main(void) {
	printf("Enter the input string: ");
	scanf("%s", t);
	strcpy(x, t);

	printf("\nThe generated polynomial is : %s\n", g);

	a = strlen(t);

	for(e = a; e < N + a - 1; e++)
		t[e] = '0';

	printf("The new t[e] : %s\n", t);

	crc();

	printf("The generated CheckSum : %s\n", cs);

	strcat(x, cs);
	strcpy(t, x);

	printf("Final send value is : %s\n", t);

	printf("Add Erroneous Data? 0--comply\t1--reject\n");
	scanf("%d", &e);

	if(e == 0) {
		printf("Enter the position to enter the data\n");
		scanf("%d", &e);

		t[e] = ((t[e] == '1') ? '0' : '1');

		printf("Erroneous Data is : %s\n", t);
	}

	crc();

	for(e = 0; (e < N -1) && (cs[e] != '1'); e++);

	if(e < N - 1)
		printf("Error Detected\n");
	else
		printf("All fine son\n");
return 0;
}