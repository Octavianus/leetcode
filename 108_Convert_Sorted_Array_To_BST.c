#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define GET_LENGTH(a,length){length = sizeof(a)/sizeof(a[0]);}

typedef struct BiTnode{
	char data;
	struct BiTnode *lchild,*rchild;
}BiTnode,*BiTree;

int i = 0;

BiTree Create(BiTree t,int s[], int end, int start)
{
	int med = (end + start)/2;
	if(end >= start){
		if(!(t = (BiTree)malloc(sizeof(BiTnode)))) 
		{
			printf("fail to malloc!\n");
			exit(0);
		}
		else{
			t->data = s[med];
			t->lchild = Create(t->lchild, s, med - 1, start);
			t->rchild = Create(t->rchild, s, end, med + 1);
		}
	
		return t;
	}
	
	return t;
}

// Q 135 Binary tree pre-order traversal

void Pre_Order(BiTree T){
	BiTree TreeStack[MAXSIZE], p;
	int element = -1;

	if(T != NULL){
		p = T;
		while(element > -1 || p != NULL){
			while(p != NULL){
				printf("%c ",p->data);
				TreeStack[++element] = p;
				p = p->lchild;
			}

			if(element > -1){
				p = TreeStack[element --];
				p = p->rchild;
			}
		}
	}

	printf("\n");
}

void display(BiTree t)
{
	if(t)
	{
	      	printf("%d ",t->data);
	      	display(t->lchild);
	      	display(t->rchild);
	}
	printf("\n");
}

int main(int argc,char *argv[])
{
	BiTree t;
	t = NULL;
	int length = 0;
       	int a[] = {1,3,6,7,9,11,23};
	GET_LENGTH(a,length)
	length = length - 1;
       	t = Create(t,a,length,0);
       	display(t);

       	return 0;
}
