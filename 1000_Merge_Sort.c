#include<stdio.h>
#include<stdlib.h>

#define GET_LENGTH(a,length){length = sizeof(a)/sizeof(a[0]);}

int a[] = {2,5,8,44,76,9,5,23,687,65,9,45,23,575,4336};
static int length;
int *b;

void Merge(int *a, int low, int med, int end){

	int i = low, j = med + 1;
	int k = 0;
	while(i <= med && j <= end){
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
		
	}

	while(i <= med)
		b[k++] = a[i++];
	while(j <= end)
		b[k++] = a[j++];
	k--;
	while(k >= 0){
		a[low + k] = b[k];
		k--;
	}
}

void Merge_Sort_Core(int *a, int low, int end){
	if(low < end){
		int med = (low + end)/2;
		Merge_Sort_Core(a, low, med);
		Merge_Sort_Core(a, med + 1, end);
		Merge(a, low, med, end);
	}
}

int Merge_Sort(int *a){
	int status = 0;
	if(a == NULL)
		return status;
	
	if(length == 0)
		return status;
	
	status = 1;
	int start = 0, end = length - 1;
	Merge_Sort_Core(a, start, end);
	
	return status;
}

int main(void){
	int status = 0;
        GET_LENGTH(a,length);
	b = malloc(sizeof(a));
	status = Merge_Sort(a);

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
