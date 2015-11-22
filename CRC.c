#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define N strlen(g)

char t[128],cs[128],g[]="10001000000100001", z[128];
int e, a, c;

void xor() {
	printf("\n");
	for(c = 1; c < N; c++) 
		{cs[c] = ((cs[c] == g[c]) ? '0' : '1'); 
	printf("%c", cs[c]);}
	printf("\n");
}
void crc() {
	printf("\n");
	for(e = 0; e < N; e++) {
		cs[e] = t[e]; 
		printf("%c", cs[e]);
	}
		
	//printf("%s\n", cs);
	printf("\n");
	do {
		if(cs[0] == '1')
			xor();
		for(c = 0; c < N - 1; c++)
			cs[c] = cs[c + 1];
		cs[c] = t[e++];
		printf("%c\n", cs[c]);
	} while(e <= (a + N - 1));
	printf("\n");
}


int main(void) {


	printf("Enter the Polynomial: ");
	scanf("%s", t);

	strcpy(z, t);

	printf("\nGenerated ploynomial is: %s \n", g);
	
	a = strlen(t);
	printf("%d\t%d\n", a, N);
	for(e = a; e < a + N - 1; e++)
		t[e] = '0';

	printf("Modified t[u] is: \n%s\n", t);

	crc();
	printf("CheckSum is: %s\n", cs);
	/*
	for(e = a; e < a + N -1; e++)
		t[e] = cs[e - a];
	*/
	strcat(z, cs);
	strcpy(t, z);
	printf("Final Code is: %s\n", t);

	printf("Test Error detection? 0 -- HellYea\t1--Could you NOT\n");
	scanf("%d", &e);

	if(e == 0) {
		printf("Enter postion to inseert the error\n");
		scanf("%d", &e);
		t[e] = (t[e] == '0') ? '1' : '0';
		printf("Erroneous Data is: %s\n", t);
	}

	crc();

	for(e = 0; (e < N - 1) && (cs[e] != '1'); e++);

	if(e < N - 1)
		printf("Error Detected\n");
	else
		printf("NO error\n");

return 0;




}

