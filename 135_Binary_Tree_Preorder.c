#include<stdio.h>

#include<stdlib.h>

#define MAXSIZE 20

typedef struct BiTnode{
	char data;
	struct BiTnode *lchild,*rchild;
}BiTnode,*BiTree;

int i = 0;

BiTree Create(BiTree t,char s[])
{
	char ch;
	ch = s[i++];
	if(ch == ' '){
		t = NULL;
	}else{
		if(!(t = (BiTree)malloc(sizeof(BiTnode))))
		{
			printf("fail to malloc!\n");
			exit(0);
		}
		else{
			t->data = ch;
			t->lchild = Create(t->lchild,s);
			t->rchild = Create(t->rchild,s);
		}
	}
 return t;
}

// Q136 Binary tree post-order traversal

void Post_Order(BiTree T){

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

// Q 137 Binary tree in-order traversal

void In_Order(BiTree T){
	BiTree p, TreeStack[MAXSIZE];
	int element = -1;

	if(T != NULL){
		p = T;
		while(p != NULL || element > -1){
			while(p != NULL){
				TreeStack[++element] = p;
				p = p->lchild;
			}

			if(element > -1){
				p = TreeStack[element --];
				printf("%c ",p->data);
				p = p->rchild;
			}
		}
	}
	printf("\n");
}



// in order display

/*
void display(BiTree t)
{
 BiTree stack[MAXSIZE],p;
 int top = -1;
 
 if(t)
 {
  p = t;
  while(top > -1 || p)
  {
   while(p)
   {   
    stack[++top] = p;
    p = p->lchild;
   }
   if(top > -1)
   {
    p = stack[top--];   
    printf("%c ",p->data);
    p = p->rchild;
   }
  }
  printf("\n");
 }
}
*/

/*
void display(BiTree t)
{
 BiTree stack[MAXSIZE],p;
 int top = -1;
 
 if(t)
 {
  p = t;
  while(top > -1 || p)
  {
   while(p)
   {
    printf("%c ",p->data);  
    stack[++top] = p;
    p = p->lchild;
   }
   if(top > -1)
   {
    p = stack[top--];       
    p = p->rchild;
   }
  }
  printf("\n");
 }
}
*/

// preoder travesal

/*
void display(BiTree t)
{
     BiTree stack[MAXSIZE], p;
     int top = -1;

     if (t)
     {       
         stack[++top] = t;
         while (top > -1)
         {             
             p = stack[top--];
             printf("%c ", p->data);             
             if (p->rchild)
              {                 
                  stack[++top] = p->rchild;
              }     
			  
             if (p->lchild)
              {                
                  stack[++top] = p->lchild;
              }
         }
         printf("\n");
     }
}
*/

// postoder traversal

/*
void display(BiTree t)
{
 BiTree m,stack[MAXSIZE];
 int top = -1;
 int flag;
 
 if(t)
 {
loop:
  flag = 1;
  m = NULL;
  while(t)
  {
   stack[++top] = t;
   t = t->lchild;
  }
  while(flag)
  {
   t = stack[top];
   if(t->rchild == m)
   {
    printf("%c ",t->data);
    top--;
    m = t;
   }
   else
   {
    flag = 0;
    t = t->rchild;
   }
  }
  if(top>-1)
   goto loop;
 }
 printf("\n");
}
*/

/*
void display(BiTree t)
{
    BiTree p = t, stack[MAXSIZE];
    int tag[MAXSIZE];
    int top = -1;
 
 do
     {
         while(p != NULL)
         {
             stack[++top] = p;
             tag[top] = 0;
             p = p->lchild;
         }            
         if(top > -1)
         {
             if(!tag[top]) 
              {
                  p = stack[top];
                  p = p->rchild;
                  tag[top] = 1;
              }
             else
              {           
                   printf("%c ", stack[top--]->data);
              }
         }
     }while((p != NULL)||(top > -1));
 printf("\n");
}    
*/

// pre-order ·display the tree
/*
void display(BiTree t)
{
 if(t)
 {
  printf("%c ",t->data);
  display(t->lchild);
  display(t->rchild);
 }
}
*/

/*
void display(BiTree t)
{
	if(t)
	{
		display(t->lchild);
		printf("%c ", t->data);
		display(t->rchild);
	}
}
*/

/*
void display(BiTree t)
{
 if(t)
 {
  display(t->lchild);
  display(t->rchild);
  printf("%c ",t->data);
 }
}*/

int main(int argc,char *argv[])
{
 BiTree t;
 t = NULL;
 char s[] = "abc  de f  g  h  ";
 t = Create(t,s);
 In_Order(t);
 
 return 0;
}
