#include<stdio.h>
#include<stdlib.h>

#define GET_LENGTH(a,length){length = sizeof(a)/sizeof(a[0]);}

int a[] = {2,5,8,44,76,9,5,23,687,65,9,45,23,575,4336};
static int length;

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *a, int start, int end){
	if( a == NULL || start < 0 || end >= length)
		return -1;
	
	int index = (start + end)/2;
	Swap(&a[end], &a[index]);
	int signal = start - 1;
	
	for(index = start; index < end; index++){
		if(a[index] < a[end]){
			signal ++;
			// != or < is the same;
			if(signal < index)
				Swap(&a[signal], &a[index]);
		}
	}
	
	signal ++;
	Swap(&a[signal], &a[end]);

	return signal;
}

void Quick_Sort_Core(int *a, int start, int end){
	if(start < end){
		int med;
		med = partition(a, start, end);
		Quick_Sort_Core(a,start, med - 1);
		Quick_Sort_Core(a, med + 1, end);
	}
}

int Quick_Sort(int *a){
	int status = 0;
	if(length <= 0)
		return status;
	int end, start = 0;
	end = length - 1;

	Quick_Sort_Core(a,start,end);
	
	status = 1;
	return status;
}


int main(void){
	int status = 0;
        GET_LENGTH(a,length);
	status = Quick_Sort(a);

	if(status != 1)
		printf("Fail to sort with some error");
	else{
		int i;
		for(i = 0; i < length; i++)
			printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
