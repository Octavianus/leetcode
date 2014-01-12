/*
 * I believe that this is the dumpest way to the question, I need a array 
 * array and calculate the digit separately.
 * Maybe calculate in bit is a efficient but hard-to-think way
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Reverse(int x){
	
	int count = 0;
	int y,z;
	y = x;
	z = 0;

	while( y != 0){
		y /= 10;
		count ++;
	}
	
	int *a;
	a = (int *)malloc(sizeof(int)*count);

	int i;
	for(i = 0; i < count; i++)
	{
		a[i] = x%10;
		x /= 10;
	}

	for(i = 1; i <= count; i++){
		z += a[count - i]*pow(10, i-1);
	}

	return z;
}

int main(void)
{
	int integer, reverse;
	integer = 123445;
	reverse = Reverse(integer);

	printf("The integer is %d after reverse is %d \n",integer, reverse);
	return 0;
}
