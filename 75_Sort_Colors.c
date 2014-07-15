// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

/*
 * My solution is a two pass algorithm using counting sort, with extra space.
 *
 */

#include<stdio.h>

#define GET_ARRAY_LENGTH(a,l){l=(sizeof(a)/sizeof(a[0]));}

// Aggregate the data by the number.
int Sort_Color(int *a, int n){
	int status = 0;
	char color[4] = {0,0,0,0};

	int i;
	for(i = 0; i < n; i++)
	{
		color[a[i]]++;
	}

	int n1, n2, n3, counter;
	n1 = n2 = n3 = counter = 0;
	while(n1 < color[1])
	{
		n1++;
		a[counter++] = 1;
	}

	while(n2 < color[2])
	{
		n2++;
		a[counter++] = 2;
	}


	while(n3 < color[3])
	{
		n3++;
		a[counter++] = 3;
	}

	status = 1;
	return status;
}

int OptSort_Color(int *A, int n){
	int i=-1, j=-1, k=-1;
	
	int p;
	for(p = 0; p < n; p++)
	{
		if(A[p] == 1)
		{
			A[++k]=3;
			A[++j]=2;
			A[++i]=1;
		}
		else if (A[p] == 2)
		{
			A[++k]=3;
			A[++j]=2;

		}
		else if (A[p] == 3)
		{
			A[++k]=3;
		}
	}

	return 1;
} 

int main(void){
	int Object[]={1,2,3,1,2,1,3,2,1,2,3,2};
	int n;
	GET_ARRAY_LENGTH(Object, n);
	if(Sort_Color(Object, n))
	{
		int i;
		for(i = 0; i < n; i++)
			printf("After sorting: %d \n",Object[i]);
	}
	else
		printf("Internal Error!");

	return 0;
}
