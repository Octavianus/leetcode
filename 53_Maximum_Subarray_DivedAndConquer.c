/*
 * This Algorithm is incredible, only in O(n) time but solve a O(n^2) trick.
 * Name: Kadane's algorithm, use the subproblem and structure.
 * 找到子问题和主问题的关系
 */

#include<stdio.h>

#define GET_ARRAY_LENGTH(a,length){ length = (sizeof(a)/sizeof(a[0]));}

int max(int a, int b){
	return (a > b?a : b); 
}

int maxSubArray(int *a, int n){
	if(n <= 0)
		return 0;
	return DivideAndConquer(a, 0, n-1);
}

int DivideAndConquer(int *a, int left, int right){
	if(left == right) return a[left];
	int med, temp = 0;
	int vleft, vright = 0;
	med = (left + right)/2;
	vleft = DivideAndConquer(a,left, med);
	vright = DivideAndConquer(a, med + 1, right);

	int maxright, maxleft;
	maxleft = a[med];
	maxright = a[med + 1];
	
	int i;
	for(i = med; i >= left ; i--){
		temp += a[i];
		if(temp > maxleft)
			maxleft = temp;
	}

	temp = 0;
	for(i = med + 1; i <= right; i++){
		temp += a[i];
		if(temp > maxright)
			maxright = temp;
	}

	return max(max(vleft,vright),maxleft + maxright);
}

int main(void){
	int array[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = 0;
	GET_ARRAY_LENGTH(array,n);

	printf("The largest sum is %d \n",maxSubArray(array, n));

	return 0;
}
