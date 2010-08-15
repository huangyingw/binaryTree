#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 20
typedef char DataType;
#include"Bitree.h"
using std::cout;
using std::endl;

int main()
{
	int i;
	BiTreeNode *q[MaxSize+1];
	BiTreeNode *root;
	int left,right,temp;
	int Num[MaxSize]={0};
	char strA[MaxSize]="befcgdh";//pre_order
	char strB[MaxSize]="febgchd";//in_order
	char point;int n;
	n=strlen(strA);
	Initiate(&root);
	for(i=0;i<n;i++)
	{
		point=strA[i];
		temp=Search(strB,point);
		left=SearchLeft(Num,temp);
		right=SearchRight(Num,temp);
		if(left==-1&&right==-1)
		{
			
			q[temp]=InsertLeftNode(root,point);
			Num[temp]=1;
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[temp]=InsertRightNode(q[left],point);
			Num[temp]=1;
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[temp]=InsertLeftNode(q[right],point);
			Num[temp]=1;
		}
	}
	PrintBiTree(root,0);
	printf("****************************************\n\n");
	printf("PreOrder: \t");
	PreOrder(root->leftChild,Visit);
	printf("\nInOrder:\t");
	InOrder(root->leftChild,Visit);
	printf("\nPostOrder: \t");
	PostOrder(root->leftChild,Visit);
	printf("\n*****************************************************************************\n\t\t\t\bCopyright @ 2009 Gary All Right Reserved\n");
	return 0;
}
