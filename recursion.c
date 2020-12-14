#include <stdio.h>

int main(){
	printf("%i", rec1(200);
	printf("%i", rec2(10)); 
}

int rec1(int max){
	return rechelper(0, max);
}

int rec1help(int a, int max){
	if (a > max) return a;
	return rechelper(3*a+2, max);
}

int rec2(int n){
	if (n == 1) return 1;
	return 2*rec2(n-1)-(n-1)%2;
}


