/*
 * Two tech points:
 * 1.When create the list, we should pass the &l to the create function, and 
 * use the secondary pointer to malloc and change the content of the *head.
 * 2. I just use the data to judge whether there is a cycle under the assumption
 * that each data value will appear only once.
 *
 * The right answer should be two pointer, one is p1->next->next, another is
 * p2->next in each loop, if once p1=p2, it replects that there is a cycle.
 */

#include<stdio.h>
#include<stdbool.h>
#include"stdlib.h"
#define ok 1
#define error 0
#define overflow -2

typedef int status;
typedef int elemtype;
typedef struct lnode{
	elemtype data;
	struct lnode *next;
}lnode,*linklist;

int HaveCycle(lnode *head){
	int havecycle = false;
	lnode *node = NULL;
	lnode *Tnode = NULL;
	node = head;

	while(node->next != NULL){
		Tnode = node->next;
		while(Tnode != NULL && Tnode->data != node->data){
			Tnode = Tnode->next;
		}

		if(Tnode != NULL){
			return havecycle = true;
		}
		node = node->next;
	}

	return havecycle;
}

// **l pointer points to another pointer, must be like this.
status createlist_l(linklist *l, int n){
	linklist q,p;
	int i;
	
	(*l)=(linklist)malloc(sizeof(lnode));
	if(!*l)exit(overflow);
	printf("请输入链表表长\n");
	scanf("%d",&n);
	(*l)->next=NULL;
	q=(*l);
	for(i=1;i<=n;i++){
		   p=(linklist)malloc(sizeof(lnode));
	     	   printf("请依次输入链表\n");
  		   scanf("%d",&p->data);
		   q->next=p;
		   q=p;
	}
	   q->next=NULL;
	     
	   return ok;
}
status listinsert_l(linklist l, int i, elemtype e){
	     linklist p,s;
	     int j;
	     p=l;j=0;
	     printf("请输入你要插入的位置\n");
	     scanf("%d",&i);

	     while(p&&j<i-1){p=p->next;++j;}
	     if(!p||j>i-1)
	     {
		        printf("输入错误\n");
			   return error;
	     }

	     s=(linklist)malloc(sizeof(lnode));
	     printf("请输入你要插入的数\n");
	     scanf("%d",&e);
	     s->data=e;s->next=p->next;
	     p->next=s;
	     p=l;
	     p=p->next;
	     printf("你得到的新链表\n");
	     while (p!=NULL){
		       
		          printf("%d\n",p->data);
			       p=p->next;
	     }
	               
	     return ok;
}

status listdelete_l(linklist l, int i, elemtype e){
	linklist p,q;
	int j;
	p=l;j=0;
	printf("请输入你要删除的位置\n");
	scanf("%d",&i);
	while(p->next&&j<i-1){
		   p=p->next;++j;
	}
	if(!(p->next)||j<i-1){printf("输入错误");return error;}
	q=p->next;p->next=q->next;
	e=q->data;free(q);
	     p=l->next;
	     printf("你得到的新链表\n");
	     while (p!=NULL){
		        e=p->data;
			       printf("%d\n",e);
			              p=p->next;
				         }
	     return ok;
}
status getelem_l(linklist l,int i,elemtype e){
	   linklist p;
	   int j;
	   p=l->next;j=1;
	   printf("请输入你要查找的位置\n");
	   scanf("%d",&i);
	   while(p!=NULL&&j<i){
		            p=p->next;++j;
			      
	   }
	   if(!p||j>i){printf("输入错误\n");return error;}
	   printf("你查到的元素是：\n");
	   printf("%d\n",p->data);
	   return ok;
}

int main(void)
{
	linklist L;
	int m,n,i;
	elemtype e;	
   	createlist_l(&L, n);
	/*
	printf("请输入你的选择，0 结束，1 插入元素，2 删除元素，3 查找元素\n");
   	scanf("%d",&m);
	while(m!=0){
		switch(m){
			case 1:listinsert_l(L, i, e);
			       break;
			case 2:listdelete_l(L, i, e);
			       break;
			case 3:getelem_l(L,i,e);
			       break;
			default:
			       printf("输入的不符要求，请重新输入：\n");
			       break;
		}
		printf("请输入你的选择，0 结束程序 ，1 插入元素，2 删除元素，3 查找元素\n");
		scanf("%d",&m);
	} 
	*/
	printf("The answer is %d \n",HaveCycle(L));
	return 0;
}  
