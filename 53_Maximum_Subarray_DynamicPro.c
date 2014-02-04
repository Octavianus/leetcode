/*
 * This Algorithm is incredible, only in O(n) time but solve a O(n^2) trick.
 * Name: Kadane's algorithm, use the subproblem and structure.
 * 找到子问题和主问题的关系
 */

#include<stdio.h>

#define GET_ARRAY_LENGTH(a,length){ length = (sizeof(a)/sizeof(a[0]));}

int maxSubArray(int *a, int n){
	// these two should be inversed;
	int current_value = a[0], previous_max_point = a[0];
	
	int i;
	for(i = 1; i < n; i ++){
		
		if(previous_max_point < 0)
			previous_max_point = a[i];
		else
			previous_max_point += a[i];

		if(previous_max_point >= current_value)
			current_value = previous_max_point;
	}

	return current_value;
}

int main(void){
	int array[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = 0;
	GET_ARRAY_LENGTH(array,n);

	printf("The largest sum is %d \n",maxSubArray(array, n));

	return 0;
}
