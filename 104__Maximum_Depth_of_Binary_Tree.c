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

int Max(int a, int b){
	return a>b?a:b;
}

int maxDepth(BiTNode *root, int depth){
	if(root == NULL){
		return depth;	
	}
	return Max(maxDepth(root->left,depth+1), maxDepth(root->right,depth+1));

	/* my previous code returns the 0 depth.	
	int left_depth = depth; 
	int right_depth = depth;
	if(root->left == NULL && root->right == NULL){
		return depth = Max(left_depth,right_depth);
	}
	if(root->left != NULL){
		left_depth ++;
		return maxDepth(root->left,left_depth);
	}
	if(root->right != NULL){
		right_depth ++;
		right_depth = maxDepth(root->right,right_depth);
	}
	*/
}

int main()
{
  int i, max_depth = 0;
  int depth = 0;
  BiTree bt;
  bt=initBiTree(bt);
  #if CHAR
   printf("请先序输入二叉树(如:ab三个空格 a为根节点，b为左子树的二叉树)\n");
  #else 
   printf("请先序输入二叉树(如:1 2 0 0 0  1为根节点，2为左子树的二叉树)\n");
  #endif
  bt=CreateBiTree(bt);
  printf("输入建立的二叉树!!!\n");
  
  max_depth = maxDepth(bt,depth);
  printf("The maximum depth of the tree is: %d \n",max_depth);
 
  PrintTree(bt,5);
}
