#include<stdio.h>
int NumberOfDigit(int A,int B){
	int max,temp = 0;
	if(A > B)
		max = A;
	else
		max = B;
	while(max != 0){
		temp++;
		max /= 10;
	}
	return temp;
}
int power(int a,int b){
	int temp = 1;
	while(b != 0){
		temp *= a;
		b--;
	}
	return temp;}
int IntegerMultiplication(int A,int B){
	int r,a1,a0,b1,b0,c1,c2,c,c0,n;
	if(A == 0 || B == 0)
		return 0;
	n = NumberOfDigit(A,B);
	if(n == 1)
		return A * B;
	else{
		r = n/2;
		a1 = A / power(10,r);	
		a0 = A % power(10,r);	
		b1 = B / power(10,r);	
		b0 = B % power(10,r);
		
		c2 = IntegerMultiplication(a1,b1);
		c0 = IntegerMultiplication(a0,b0);
		c1 = (IntegerMultiplication((a0 + a1),(b1 + b0))) - (c2 + c0);
		c = c2 * power(10,(2*r)) + c1 * power(10,r) + c0;
		
		return c;}}
void main(void){
	int A,B;
	printf("\nEnter two integers for multiplication : ");
	scanf("%d%d",&A,&B);
	printf("\nInteger Multiplication of A and B : %d\n",IntegerMultiplication(A,B));

}

