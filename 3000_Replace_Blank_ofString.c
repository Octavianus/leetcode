// very cool, user pointer to manipulate the process

#include<stdio.h>
#include<stdlib.h>

#define GET_ARRAY_LENGTH(array,len){len = (sizeof(array)/sizeof(array[0]));}
#define MAX 25

void replaceBlank(char string[], int length){	
	if(length <= 0 || string == NULL)
		return;

	int blankcnt = 0;
	int oriLen = 0;
	int i = 0;
	while(string[i] != '\0'){
		oriLen ++;
		if(string[i] == ' ')
			blankcnt++;
		i++;
	}

	if(oriLen + 2*blankcnt >= length)
		return;

	char *stp1;
	char *stp2;
	// ??? careful
	// is not oriLen - 1 because the string has a stop sigh '\0'
	stp1 = &string[oriLen];
	stp2 = &string[oriLen + 2*blankcnt];
	int tmplen = oriLen;

	while(tmplen > 0 && stp1 != stp2){
		if(*stp1 == ' '){
			*stp2-- = '0';
			*stp2-- = '2';
			*stp2-- = '%';
		}
		else
			*stp2-- = *stp1;
		stp1--;
		tmplen--;
	}
}

int main(void){
	
	char string[MAX] = "Hello World Guys!";
	replaceBlank(string, MAX);
	int i = 0;
	while(string[i] != '\0'){
		printf("%c", string[i++]);
	}

	printf("\n");
	return 0;
}

