/*
 * Try dynamic desgin next time. it's a brutal computation solution.
 */

#include<stdio.h>
#define MAX 100

int counts = 0;

// calculate the permutation of the a certain number
int count(int n, int m)
{
		int ans = 1;
		int i;
		for(i = n; i >= (n-m+1); --i)
			ans *= i;
		while(m)
			ans /= m--;
		return ans;
}

/*
 *  try dynamic solution later.
void count(int m, int k)
{
	int a[MAX+1];
	int i;
	a[0] = 1;
	for(i = 1; i <= MAX; i++)
		a[i] = i*a[i-1];

	if(k == 0)
		counts ++;
	else
		counts += a[m]/a[k];
	
	
	for(i = m; i >= k; i--)
	{
		if(k > 1)
			count(i - 1, k - 1);
		else
		{
			counts++;
		}
	}
}
*/

void climbingStairs(int n)
{
	int i,j;
	for(i = n, j = 0; i >= 0 && j <= n/2; i=i-2, j++){
			counts += count(i+j, j);
	}
}

int main(void){
	int n=5;
	climbingStairs(n);
	printf("There are %d possibilities \n",counts);
	return 0;
}
