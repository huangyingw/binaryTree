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
#include "binaryTree.h"
using namespace std;

ofstream fout;

void PrintNum(int Num[])
{
	for(int index=0;index<MaxSize;index++)
	{
		fout<<Num[index];
	}
	fout<<endl;
}



int _tmain(int argc, _TCHAR* argv[])
{
	BiTree *bit=new BiTree();
	/*

	int i;
	
	int left,right,temp;
	int Num[MaxSize]={0};//use to indicate whether a char in in_order is treated.
	char pre_order[MaxSize]="befcgdh";//pre_order
	char in_order[MaxSize]="febgchd";//in_order
	char point;int n;
	n=strlen(pre_order);
	for(i=0;i<n;i++)
	{
		fout<<endl;
		fout<<"i="<<i<<endl;
		point=pre_order[i];
		temp=Search(in_order,point);
		fout << "Search for->"<<point<<"->position in in_order->"<<temp<<endl;
		
		PrintNum(Num);
		
		left=SearchLeft(Num,temp);
		fout << "SearchLeft result->"<<left<<endl;
		
		right=SearchRight(Num,temp);
		fout << "SearchRight result->"<<right<<endl;
		
		if(left==-1&&right==-1)//both
		{
			q[temp]=InsertLeftNode(root,point);
			fout << "InsertLeftNode->"<<point<<endl;
			fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[temp]=InsertRightNode(q[left],point);
			fout << "InsertRightNode->"<<point<<endl;
			fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[temp]=InsertLeftNode(q[right],point);
			fout << "InsertLeftNode->"<<point<<endl;
			fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
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
	printf("\n");
	fout.close();
	*/
	return 0;
}
