#include <stdio.h>

int main(){
	printf("%i\n", rec1(200));    //call rec1 with termination threshold 200
	printf("%i\n", rec2(10));     //call rec2 with number of elements
}

int rec1(int max){
	return rec1help(0, max);      //start recusrion with start value 0
}

//helper function for rec1 to reduce number of inputs of rec1
int rec1help(int a, int max){
	if (a > max) return a;        //check if termination threshold has been passed
	return rec1help(3*a+2, max);  //rec1hep calling itself recursively
}

int rec2(int n){
	if (n == 1) return 1;         //check for base case
	return 2*rec2(n-1)-(n-1)%2;   //calculating return value recursively
}


