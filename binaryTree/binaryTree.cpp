// binaryTree.cpp : Defines the entry pre_Order_Index for the console application.
//

#include "stdafx.h"


#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include <fstream>
#define MaxSize 20
typedef char DataType;
#include"Bitree.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int i;
	BiTreeNode *q[MaxSize+1];//use to 
	BiTreeNode *root;
	int left,right,in_Order_Index;
	int is_Visited_Array[MaxSize]={0};//use to indicate whether a char in in_order is treated.
	char pre_Order_Str[MaxSize]="befcgdh";//pre_order
	char in_Order_Str[MaxSize]="febgchd";//in_order
	char pre_Order_Index;int n;
	n=strlen(pre_Order_Str);
	Initiate(&root);
	for(i=0;i<n;i++)
	{
		pre_Order_Index=pre_Order_Str[i];
		in_Order_Index=Search(in_Order_Str,pre_Order_Index);
		
		
		left=SearchLeft(is_Visited_Array,in_Order_Index);
		
		right=SearchRight(is_Visited_Array,in_Order_Index);
		
		if(left==-1&&right==-1)//both
		{
			q[in_Order_Index]=InsertLeftNode(root,pre_Order_Index);
			
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[in_Order_Index]=InsertRightNode(q[left],pre_Order_Index);
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[in_Order_Index]=InsertLeftNode(q[right],pre_Order_Index);
		}
		is_Visited_Array[in_Order_Index]=1;
	}
	PrintBiTree(root,0);
	printf("PreOrder: \t");
	PreOrder(root->leftChild,Visit);
	printf("\nInOrder:\t");
	InOrder(root->leftChild,Visit);
	printf("\nPostOrder: \t");
	PostOrder(root->leftChild,Visit);
	printf("\n");
	return 0;
}
