// binaryTree.cpp : Defines the entry point for the console application.
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
	int left,right,in_Index;
	int is_Visited[MaxSize]={0};//use to indicate whether a char in in_order is treated.
	char strA[MaxSize]="befcgdh";//pre_order
	char strB[MaxSize]="febgchd";//in_order
	char point;int n;
	n=strlen(strA);
	Initiate(&root);
	for(i=0;i<n;i++)
	{
		point=strA[i];
		in_Index=Search(strB,point);
		
		
		left=SearchLeft(is_Visited,in_Index);
		
		right=SearchRight(is_Visited,in_Index);
		
		if(left==-1&&right==-1)//both
		{
			q[in_Index]=InsertLeftNode(root,point);
			is_Visited[in_Index]=1;
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[in_Index]=InsertRightNode(q[left],point);
			is_Visited[in_Index]=1;
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[in_Index]=InsertLeftNode(q[right],point);
			is_Visited[in_Index]=1;
		}
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
