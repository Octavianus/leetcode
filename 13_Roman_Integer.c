/*
 * This solution is based on the feature of the Roman Integer.
 * How to use the switch branch structure to solve the problem.
 */

#include<stdio.h>

// get the length of string, try in the #define last time.
void GET_LENGTH(char *a, int *length){
	*length = 0;
	int i = 0;
	while(a[i] != '\0'){
		i++;
		*length += 1;
	}
}

int RomanToInt(char *a, int length){
	int res = 0;
	int i;
	for(i = length - 1; i >= 0; i--){
		char c = a[i];
		switch (c){
			case 'I':
				res += (res >= 5 ? -1 : 1);
				break;
			case 'V':
				res += 5;
				break;
			case 'X':
				res += 10 * (res >= 50 ? -1 : 1);
				break;
			case 'L':
				res += 50;
				break;
			case 'C':
				res += 100 * (res >= 500 ? -1 : 1);
				break;
			case 'D':
				res += 500;
				break;
			case 'M':
				res += 1000;
				break;
		}
	}
	
	return res;
}

int main(void)
{
	int length = 0;
	char *RomanInt = "MCMLIV";
	int res = 0;
	GET_LENGTH(RomanInt,&length);
	
	res = RomanToInt(RomanInt, length);
	printf("%d \n",res);
	return 0;
}
