#include<stdio.h>
#define LENGTH_OF_ARRAY(a,n){n = sizeof(a)/sizeof(a[0]);}
#define EMP -1

int MergeTwoArray(int *A, int m, int *B, int n){
	int Pa = m - 1;
	int Pb = n - 1;
	int Pm = n + m - 1;

	if(Pa < 0 || Pb < 0)
	{
		printf("ERROR, Array is empty! \n");
		return -1;
	}

	int i;
	for(i = Pm; i > 0; i --){
		if(A[Pa] >= B[Pb]){
			A[i] = A[Pa];
			Pa--;
		}else{
			A[i] = B[Pb];
			Pb--;
		}
	}

	return 0;
}

int main(void){
	int m, n, pm, pa;

	// Assume the Space of array a is sufficient to merge.
	int A[] = {1,3,5,EMP,EMP,EMP,EMP};
	int B[] = {2,3,8};
	
	LENGTH_OF_ARRAY(A,m);
	LENGTH_OF_ARRAY(B,n);
	
	// How many real element in array a.
	pa = m;
	while(pa >= 0){
		if(A[pa] == EMP)
			m--;
		pa--;
	}

	MergeTwoArray(A, m, B, n);
	printf("The array A is 1,3,5; The array B is 2,3,8.\n");
	printf("The Merged Array is \n");
	pm = 0;
	while(pm <= m + n -1)
	{
		printf("%d ",A[pm]);
		pm++;
	}
	printf("\n");
	
	return 0;
}
