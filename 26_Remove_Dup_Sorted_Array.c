/*
 * The tech points are: 1. array could be passed by function in the form of pointer (int a[] in definition) and (a in call)
 * 2. be familiar to the relationship between array and pointer,
 * 由于p是int *指针，一个int型元素占4个字节，所以p++使p所指向的地址加4，注意不是
 * 加 1。 由于a做右值使用时和&a[0]是一个意思，所以int *pa = &a[0];通常不这么写，
 * 而是写成更简洁的形式int *pa = a;。
 * Problem: the array cannot be trimed because the fix size feature.
 * Structure: Array, time O(n^2), space, O(n). There could be trade off in space ??? 
 */

#include<stdio.h>
#include<stdlib.h>

#define GET_ARRAY_LENGTH(array,len){len = (sizeof(array)/sizeof(array[0]));}

// try *p and p++ to represent the array
//int removeDup(int a[], int n){

int removeDup(int *a, int n){	
	int length = n;
	int jump;

	if(length <= 1)
	{
		return 0;
	}
	
	int current_num = a[0];
	// how many duplicated number of certain number
	int num_dup = 0;

	int i,j,k;
	
	// check the whole array. 
	for(i = 0; i < length; i++){
		for( j = i+1; a[i] == a[j]; j++){
			num_dup ++;
		}
		// the number of index i is being checking, how many duplicates it has.
		jump = 1;
		if(num_dup != 0){
			// ?? remove the duplicated one
			// the only special part is the last element. because the number of elements been jumped is beyond the end of array.
			for(k = j; k < length || jump <= num_dup; k++,jump++){
					if( k < length){
						a[i+jump] = a[k];
						a[k] = NULL;
					}else{
						a[i+jump] = NULL;
					}
				}
		}
	// modify the lenght of the array and the reset the number of duplicate to zero
	length -= num_dup;
	num_dup = 0;
	}

	return length;
}

int main(void){
	
	int status, length;
	int a[] = {0,1,2,2,2,2,2,3,4,5,6,7,7,8,9,9,9,12,12,15};
	GET_ARRAY_LENGTH(a,length);
	status = removeDup(a, length);
	
	printf("The new length is: %d \n", status);

	return 0;
}

