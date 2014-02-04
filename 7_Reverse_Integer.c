/*
 * Optimal way found !
 * I believe that this is the dumpest way to the question, I need a array 
 * array and calculate the digit separately.
 * Maybe calculate in bit is a efficient but hard-to-think way
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

/* dumb way, no need that space and only one time calculation
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
*/

int Reverse2(int n)
{
	int rev = 0;
	bool isneg = false;

	if(n < 0)
	{
		isneg = true;
		n = -n;
	}

	while(n != 0){
		rev = rev*10 + n%10;
		n /= 10;
	}

	return rev * (isneg?-1:1);
}

int main(void)
{
	int integer, reverse;
	integer = -123445;
	reverse = Reverse2(integer);

	printf("The integer is %d after reverse is %d \n",integer, reverse);
	return 0;
}
