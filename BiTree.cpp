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

int main()
{
	ofstream fout; 
	fout.open("output.txt");

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
		fout << "left->"<<left<<endl;
		
		right=SearchRight(Num,temp);
		fout << "right->"<<right<<endl;
		
		if(left==-1&&right==-1)
		{
			
			q[temp]=InsertLeftNode(root,point);
			fout << "q[temp]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[temp]=InsertRightNode(q[left],point);
			fout << "q[temp]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[temp]=InsertLeftNode(q[right],point);
			fout << "q[temp]->"<<q[temp]->data<<endl;
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
	fout.close();
	return 0;
}
