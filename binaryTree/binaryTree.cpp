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

int _tmain(int argc, _TCHAR* argv[])
{
	BiTree *bit=new BiTree();

	
	bit->Print(bit->root,0);
	printf("****************************************\n\n");
	printf("PreOrder: \t");
	bit->PreOrder(bit->root->leftChild,BiTree::Visit);
	printf("\nInOrder:\t");
	bit->InOrder(bit->root->leftChild,bit->Visit);
	printf("\nPostOrder: \t");
	bit->PostOrder(bit->root->leftChild,bit->Visit);
	printf("\n");
	
	return 0;
}
