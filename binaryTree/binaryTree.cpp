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




int _tmain(int argc, _TCHAR* argv[])
{
	BiTree *bit=new BiTree();

	
	bit->Print();
	printf("****************************************\n\n");
	printf("PreOrder: \t");
	bit->PreOrder(bit->root->leftChild,bit->Visit);
	printf("\nInOrder:\t");
	bit->InOrder(bit->root->leftChild,bit->Visit);
	printf("\nPostOrder: \t");
	bit->PostOrder(bit->root->leftChild,bit->Visit);
	printf("\n");
	
	return 0;
}
