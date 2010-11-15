#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include <fstream>
#define MaxSize 20
typedef char DataType;
#include"bitree.h"
using namespace std;


void PrintNum(int data[])
{
  for(int index=0;index<MaxSize;index++)
    cout<<data[index];
  cout<<endl;
}

int main()
{
  int i;
  BiTreeNode *q[MaxSize+1];//use to
  BiTreeNode *root;
  int left,right,temp;
  int Num[MaxSize]={0};//use to indicate whether a char in in_order is treated.
  char strA[MaxSize]="befcgdh";//pre_order
  char strB[MaxSize]="febgchd";//in_order
  char point;
  Initiate(&root);
  for(i=0;i<strlen(strA);i++)
  {
    cout<<endl;
    cout<<"i="<<i<<endl;
    point=strA[i];
    temp=Search(strB,point);
    cout << "Search for  "<<point<<"'s position in->"<<strB<<" in_order->"<<temp<<endl;

    PrintNum(Num);

    left=SearchLeft(Num,temp);
    cout << "SearchLeft result->"<<left<<endl;

    right=SearchRight(Num,temp);
    cout << "SearchRight result->"<<right<<endl;

    if(left==-1&&right==-1)//both
    {
      q[temp]=InsertLeftNode(root,point);
      cout << "InsertLeftNode->"<<point<<endl;
      cout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
      Num[temp]=1;
    }
    else if(left!=-1&&q[left]->rightChild==NULL)
    {
      q[temp]=InsertRightNode(q[left],point);
      cout << "InsertRightNode->"<<point<<endl;
      cout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
      Num[temp]=1;
    }
    else if(right!=-1&&q[right]->leftChild==NULL)
    {
      q[temp]=InsertLeftNode(q[right],point);
      cout << "InsertLeftNode->"<<point<<endl;
      cout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
      Num[temp]=1;
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
