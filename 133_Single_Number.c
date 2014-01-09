/*
 * The tech points are: 1. Correctly init the hash table, and remember that the structure would better only contain the basic data type, because
 * pointer needs to calloc memory space for it.
 * 2. Augment data structure is a very handful strategy for a specific problem.
 * Structure: HASH TABLE, time O(n), space, O(n). no more trade off
 */


#include<stdio.h>
#include<stdlib.h>
#define EMPTY_SLOT -1

typedef struct element{
	int key;
	int exist;
} element;

typedef struct Htable{
	element *H;
	int size;
} Htable;

Htable * CreateHashTable(int size){
	
	Htable *Hash;

	Hash = ( Htable *) calloc(1,sizeof(Htable));
	Hash->H = (element *)calloc(1,sizeof(element)*size);
	Hash->size = size;
	int i;
	for (i = 0; i < size; i++) {
		     Hash->H[i].key = EMPTY_SLOT; 
		     Hash->H[i].exist = 0;
        }
	return Hash;
}

int Hfunction(int key, int size){
	return (key % size);
}

void InsertHash(Htable *HTable,int a[]){
	int value, size;
	size = HTable->size;
	
	int i;
	for(i=0; i < size; i++){
		value = Hfunction(a[i],size);
		if( HTable->H[value].key == EMPTY_SLOT){
			HTable->H[value].key = a[i];
		}else{	
			HTable->H[value].exist += 1;
		}
	}
}

int FindSingleNum(Htable *HTable, int size){
	
	int i,num;
	for(i = 0; i < size; i++){
		if(HTable->H[i].exist == 0 && HTable->H[i].key != EMPTY_SLOT){
			num = HTable->H[i].key;
			break;
		}
			
	}
	return num;
}

int main(void){
	
	int size;
	int a[] = {0,5,2345,436,56,3,3,56,0,2345,436};
	size = sizeof(a)/sizeof(a[0]);
	Htable *H = CreateHashTable(size);
	InsertHash(H,a);

	printf("Single number is: %d \n",FindSingleNum(H,size));
	
	return 0;
}
