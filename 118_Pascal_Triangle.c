#include<stdio.h>

int Pascal_Triangle(int n){
	int length = n + 1;
	int a3[length],a2[length];
	
	int i;
	for(i = 0; i < length; i++ )
	{
		a2[i] = 0;
		a3[i] = 0;
	}
	a2[0] = a2[1] = 1;

	printf("1 \n");
	printf("%d %d \n",a2[0],a2[1]);
	
	int j, k;	
	for(i = 2; i < n; i++){
		a3[i] = 1;
		a3[0] = 1;
		for(j = 0; j < i - 1; j++){
			a3[j + 1] = a2[j] + a2[j + 1];
		}
		for(k = 0; k < i + 1; k++){
			printf("%d ",a3[k]);
			a2[k] = a3[k];
		}
		printf("\n");
	}

	return 0;
}

int main(void){
	int n;
	n = 10;
	Pascal_Triangle(n);

	return 0;
}

