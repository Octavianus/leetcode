/*
 * There are two tech points in this prob: 1. how to create a binary tree, this 
 * isn't right, 2. how to build a recursive method to tackle a tree, there are 
 * three rules :用数学归纳法来证明只需要证明两点：Base Case正确，递推关系正确。写递
 * 归函数时一定要记得写Base Case，否则即使递推关系正确，整个函数也不正确。
 */

#include<stdio.h>
#include<stdlib.h>
#define CHAR 1 /*字符型1 整型 0 */

#if CHAR
 typedef char TElemType;
 TElemType Nil=' ';/*字符型以空格符为空*/
 #define form "%c" /*输入输出格式为%d*/
#else
 typedef int TElemType;
 TElemType Nil=0; /*整型以0为空*/
 #define form "%d" /*输入输出格式为%d*/
#endif

typedef struct node /*结构类型定义*/
{
  TElemType data;
  struct node *left;
  struct node *right;
}BiTNode,*BiTree;

BiTNode *initBiTree(BiTNode *bt)
{
  bt=NULL;
  return bt;
}

BiTNode *CreateBiTree (BiTNode *bt)
{/*按先序次序输入二叉树中结点的值(可为字符型或整型)*/
  TElemType ch;
  scanf(form,&ch);
  fflush(stdin);
 if(ch==Nil)
   bt=NULL;
 else
  {
    bt=(BiTNode*)malloc(sizeof(BiTNode));/*生成根结点*/
    if(!bt) exit(0);
    bt->data=ch;
    bt->left=CreateBiTree(bt->left);/*构造左子树*/
    bt->right=CreateBiTree(bt->right);/*构造右子树*/
  }
 return bt;
}

void PrintTree(BiTNode *bt,int i)
{/*输出二叉树*/
 if(bt!=NULL)
  {
    PrintTree(bt->right,i+5);/*递归调用右子树*/
    #if CHAR
    if(bt->data!=Nil)
      {
        printf("%*c\n",i,bt->data);/*i不输出，用来调节输出*/
      }
    #else 
    if(bt->data!=Nil)
      {
        printf("%*d\n",i,bt->data);
      }
    #endif
  PrintTree(bt->left,i+5);
  i=i-5;
  }
}

int isSameTree(BiTree A, BiTree B){
	int va,vb;
	va = vb = 0;
	if( A == NULL && B == NULL)
	{
		return 1;
	}else if(A == NULL || B == NULL){
		return 0;
	}else{
		if(A->data == B->data){
			va = isSameTree(A->left,B->left);
			vb = isSameTree(A->right,B->right);
			return (va && vb);
		}else{
			return 0;
		}
	}
}

int main()
{
  BiTree ba,bb;

  // Create first Tree
  ba=initBiTree(ba);
  printf("请先序输入二叉树(如:ab三个空格 a为根节点，b为左子树的二叉树)\n");
  ba=CreateBiTree(ba);
  printf("输入建立的二叉树!!!\n");
  
  /* some problems with the stdin
  fflush(stdin);
  // Create another Tree
  bb = initBiTree(bb);
  printf("请先序输入二叉树(如:ab三个空格 a为根节点，b为左子树的二叉树)\n");
  bb = CreateBiTree(bb);	
  printf("输入建立的二叉树!!!\n");
  */
  
  printf("These two tree are: %d \n",isSameTree(ba,ba)); 
  // Test the result 
  PrintTree(ba,5);
  PrintTree(bb,5);

  return 0;
}
