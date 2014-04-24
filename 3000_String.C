// very cool, user pointer to manipulate the process
/*
 * Topic about String:
 * 1.Replace the blank
 * 2.Reverse a sting
 * 3.Remove the duplicate (without extra space)
 * 5.Remove the duplicate (with constant extra space)
 */

#include<stdio.h>
#include<stdlib.h>

#define GET_ARRAY_LENGTH(array,len){len = (sizeof(array)/sizeof(array[0]));}
#define MAX 35

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

void reverse(char *str){
	char * end = str;
	char tmp;
	if(str){
		while(*end)
			end++;
		end--;
		while(str < end){
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

void remove_duplicate(char *str, int len){
	if(str == NULL || len < 2)
		return;
	
	int tail = 1;
	int i,j;
	
	for(i = 1; i < len; i++){
		for(j = 0; j < tail; j++)
			if(str[i] == str[j])
				 break;
		if(j == tail){
			str[tail] = str[i];
			++ tail;
		}
	}
			
	// make the tail as the end of the string, to make this string unique.
	/*** THIS IS THE TRICK ***/
	str[tail] = '\0';
}

void remove_duplicate_with_extra_space(char *str, int len){
	if(str == NULL || len < 2)
		return;
	
	// extra 256 * sizeof(bool) bool is 1 byte(not one bit), because CPU cannot 
	// address anything smaller than a byte.
	bool hit[256];
	// Good habit, only one i for linear iteration.
	int i = 0;
	// how concise my code is!.
	while(i < 256)
		hit[i++] = false;

	int tail = 1;
	hit[str[0]] = true;
	for(i = 1; i < len; i++){
		if(hit[str[i]] == false){
			hit[str[i]] = true;
			str[tail] = str[i];
			tail ++;
		}
	}
	
	str[tail] = 0;
}

int main(void){
	
	char string[MAX] = "Hello How are you guys!!!";
	int len = 0;
	while(string[len++] != '\0');
	len--;
	//replaceBlank(string, MAX);
	//reverse(string);
	//remove_duplicate(string, len);
	remove_duplicate_with_extra_space(string, len);
	int i = 0;
	while(string[i] != '\0'){
		printf("%c", string[i++]);
	}

	printf("\n");
	return 0;
}

