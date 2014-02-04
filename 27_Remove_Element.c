#include<stdio.h>
#include<stdlib.h>

#define GET_ARRAY_LENGHT(array, length){length = (sizeof(array)/sizeof(array[0]));}
#define EMPTY -1;

int Remove_Element(int *a, int value, int length){
	int index = 0;
	int new_length = length;

	while(index < length){
	    	if(a[index] == value)
			new_length --;
			a[index] = EMPTY;
	     	index ++;	
	}
	return new_length;
}

int main(void){
	int a[] = {1,2,34,56,1,2,45,5,1,1};
	int length = 0;
	int value = 1;
	GET_ARRAY_LENGHT(a, length);
	printf("The new length is %d \n",Remove_Element(a, value, length));
	return 0;
}
