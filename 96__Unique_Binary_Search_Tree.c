/*
 * Dynamic programming, find the relation between subtrees, init the 
 * table at first, calculate and record in the table or use the 
 * previous work of result directly.
 * Insired by : http://cs.lmu.edu/~ray/notes/binarytrees/
 */

#include<stdio.h>
#include<stdlib.h>

int Unique_BST(int n){
	int *a;
	a = (int *)malloc(n*sizeof(int));

	int i,j;
	// i <= n instead of < n , because 0 is the special case, there 
	// are n + 1 element in the array.
	for(i = 0; i <= n; i++){
		a[i] = 0;
	}

	a[0] = 1; // In this method, the only special case is when n = 0;
	// remember in this question. a(n)=a(0)a(n-1) + a(1)a(n-2)...+
	// a(n-1)a(0). why n-1 becuase there is a root node.
	for(i = 1; i <=n; i++){
		for( j = 1; j <= i; j++){
			a[i] += a[j - 1]*a[i - j];
		}
	}

	return a[n];
}

int main(void){
	int UniqueBST = 0;
	int n;
	n = 3;

	printf("Number of Unique BST = %d \n",Unique_BST(n));
	
	return 0;
}
