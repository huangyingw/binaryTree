// binaryTree.cpp : Defines the entry pre_Order_Char for the console application.
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
	BiTreeNode *q[MaxSize+1];//use to 
	BiTreeNode *root;
	int left_search_result,right_search_result,in_Order_Index;
	int is_Visited_Array[MaxSize]={0};//use to indicate whether a char in in_order is treated.
	char pre_Order_Str[MaxSize]="befcgdh";//pre_order
	char in_Order_Str[MaxSize]="febgchd";//in_order
	char pre_Order_Char;
	int pre_Order_Str_Length=strlen(pre_Order_Str);
	Initiate(&root);
	for(int nav=0;nav<pre_Order_Str_Length;nav++)
	{
		pre_Order_Char=pre_Order_Str[nav];
		in_Order_Index=Search(in_Order_Str,pre_Order_Char);
		
		left_search_result=SearchLeft(is_Visited_Array,in_Order_Index);
		right_search_result=SearchRight(is_Visited_Array,in_Order_Index);
		
		if(left_search_result==-1&&right_search_result==-1)//both
		{
			q[in_Order_Index]=InsertLeftNode(root,pre_Order_Char);
			PrintBiTree(root,0);
		}
		else if(left_search_result!=-1&&q[left_search_result]->rightChild==NULL)
		{
			q[in_Order_Index]=InsertRightNode(q[left_search_result],pre_Order_Char);
			PrintBiTree(q[left_search_result],0);
		}
		else if(right_search_result!=-1&&q[right_search_result]->leftChild==NULL)
		{
			q[in_Order_Index]=InsertLeftNode(q[right_search_result],pre_Order_Char);
			PrintBiTree(q[right_search_result],0);
		}
		is_Visited_Array[in_Order_Index]=1;
		
		cout<<endl;
	}
	cout<<endl;
	PrintBiTree(root,0);
	printf("PreOrder: \t");
	PreOrder(root->leftChild,Visit);
	printf("\nInOrder:\t");
	InOrder(root->leftChild,Visit);
	printf("\nPostOrder: \t");
	PostOrder(root->leftChild,Visit);
	return 0;
}
