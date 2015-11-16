#include "iostream"
#include "math.h"
#include "string.h"
#include "stdlib.h"
using namespace std;

int prime(int);
int gcd(long int, long int);
int encrpt(char);
char decrpt(long int);

long int i, e, d, n, p, q, phi, cipher[50];

int main(void) {
	int i, len;
	char text[50];
	cout<<"Enter Text to be Encripted: "<<endl;
	cin>>text;

	len = strlen(text);

	do {
		p = rand()%1000;
	} while(!prime(p));

	do {
		q = rand()%1000;
	} while(!prime(q));

	n = p * q;
	phi = (p - 1) * (q - 1);

	do {
		e = rand()%phi;
	} while(gcd(e, phi)!=1);

	do {
		d = rand()%phi;
	} while(((d * e) % phi)!=1);

	cout<<"The Two Primes are Prime1: "<<p<<"\tPrime2: "<<q<<endl;

	cout<<"N(P*Q) = "<<n<<endl;

	cout<<"PHI(P - 1)*(Q - 1) = "<<phi<<endl;
	cout<<"Public key (N, E): "<<"("<<n<<", "<<e<<")"<<endl;

	cout<<"Private key (Phi, D): "<<"("<<phi<<", "<<d<<")"<<endl;
	 
	for(i = 0; i < len; i++)
		cipher[i] = encrpt(text[i]);

	cout<<"Encripted message is: ";

	for (i = 0; i < len; i++) {
		cout<<cipher[i];
	}

	cout<<endl;

	for(i = 0; i < len; i++) {
		text[i] = decrpt(cipher[i]);
	}
		

	text[i] = '\0';

	cout<<"\nDecrypted Message is: "<<text<<endl;
return 0;
}

int prime(int val) {
		for(i = 2; i < val; i++)
			if((val % i) == 0)
				return 0;

return 1;
}

int gcd(long int a, long int b) {
	if(a==0) return b;
	if(b==0) return a;

return gcd(b, a%b);
}

int encrpt(char ch) {
	long int temp = ch;
	for (i = 1; i < e; i++) {
		temp = (temp *ch) % n; 
		//cout<<temp<<endl;
	}
		

return temp;
}

char decrpt(long int ch) {
	long int temp = ch;
	for(i = 1; i < d; i++) {
		ch = (temp * ch) %n; 
		//cout<<ch<<endl;
	}
		

return ch;
}