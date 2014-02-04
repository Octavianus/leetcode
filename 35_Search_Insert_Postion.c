/*
 * Problem found: 1. GET_ARRAY_LENGTH can only pass the array to calculate, 
 * if you pass a pointer type, it won't work, the length is always 1;
 * 
 * My code is short, but the not time-efficient, we can apply binary search
 */

#include<stdio.h>
#include<stdlib.h>

#define GET_ARRAY_LENGTH(array,length){length = (sizeof(array)/sizeof(array[0]));}

int BinarySearch(int *a, int des, int length){
	int mid,min,max;
	min = 0;
	max = length - 1;
	if(a[max] == des)
		return max;
	if(a[min] == des)
		return min;
	
	while(min <= max){
		mid = (max + min)/2;
		if(a[mid] == des)
			return mid;
		else if(a[mid] > des)
			max = mid - 1;		
		else
			min = mid + 1;
	}
	
	// This is little bit tricky, no matter is one of the two situation
	// the position is the minimum one.
	if(min > max)
		return min;
}

int InsertPosition(int *a, int x, int length){
	int index = 0;

	//there are two cases that can return the postion directly:
	if(length <= 0)
		return 0;
	if(a[length - 1] < x)
		return length;

	index = BinarySearch(a, x, length);
	return index;
	// normal solution: traversal the array one by one. not perfect.
	/*
	while(a[index] < x && index < length){
		index ++;
		if(a[index] == x){
			return index;
		}
	}

	if(index == 0){
		return 1;
	}else{
		return length + 1;
	}
	*/

	// Binary search
	
}

int main(void){
	int a[] = {1,2,6,7,8};
	int length;
	GET_ARRAY_LENGTH(a,length);
	int number;
	number = 4;
	printf("The insert position is %d \n",InsertPosition(a,number,length));
	return 0;
}
