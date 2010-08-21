#include <fstream>
using namespace std;
typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
}BiTreeNode;

class BiTree
{
private:
	ofstream fout;

public:
	int* data;
	int size;
	BiTreeNode * root;
	BiTreeNode *q[MaxSize+1];//use to 
	int Num[MaxSize];//use to indicate whether a char in in_order is treated.
	char pre_order[MaxSize];//="befcgdh";//pre_order
	char in_order[MaxSize];//="febgchd";//in_order
	
	BiTree();
	~BiTree();
	
	void Print(BiTreeNode *bt,int n);
	void Visit(DataType item);
	int Search(char str[],char t);
	int SearchLeft(int Num[],int t);
	int SearchRight(int Num[],int t);
	void PreOrder(BiTreeNode *t,void Visit(DataType item));
	void InOrder(BiTreeNode *t,void Visit(DataType item));
	void PostOrder(BiTreeNode *t,void Visit(DataType item));
	BiTreeNode *InsertLeftNode(BiTreeNode *curr,DataType x);
	void Print();
};

BiTree::BiTree()
{
	root=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	root->leftChild=NULL;
	root->rightChild=NULL;
}

BiTreeNode* BiTree::InsertLeftNode(BiTreeNode *curr,DataType x)
{
	BiTreeNode *s,*t;
	if(curr==NULL) return NULL;
	t=curr->leftChild;
	s=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data=x;
	s->leftChild=t;
	s->rightChild=NULL;
	curr->leftChild=s;
	return curr->leftChild;
}

BiTreeNode *InsertRightNode(BiTreeNode *curr,DataType x)
{
	BiTreeNode *s,*t;
	if(curr==NULL) return NULL;
	t=curr->rightChild;
	s=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data=x;
	s->rightChild=t;
	s->leftChild=NULL;
	curr->rightChild=s;
	return curr->rightChild;
}


void BiTree::Print(BiTreeNode *bt,int n)
{
	int i;
	if(bt==NULL) return;
	Print(bt->rightChild,n+1);
	for(i=0;i<n-1;i++) printf("   ");
	if(n>0)
	{
		printf("---");
		printf("%c\n",bt->data);
	}
	Print(bt->leftChild,n+1);
}

void BiTree::Visit(DataType item)
{
	printf("%c   ",item);
}

void BiTree::PreOrder(BiTreeNode *t,void Visit(DataType item))
{
	if(t!=NULL)
	{
		Visit(t->data);
		PreOrder(t->leftChild,Visit);
		PreOrder(t->rightChild,Visit);
	}
}

void BiTree::InOrder(BiTreeNode *t,void Visit(DataType item))
{
	if(t!=NULL)
	{
		
		InOrder(t->leftChild,Visit);
		Visit(t->data);
		InOrder(t->rightChild,Visit);
	}
}

void BiTree::PostOrder(BiTreeNode *t,void Visit(DataType item))
{
	if(t!=NULL)
	{
		PostOrder(t->leftChild,Visit);
		PostOrder(t->rightChild,Visit);
		Visit(t->data);
	}
}

int BiTree::Search(char str[],char t)
{
	int i=0;
	while(str[i]!=t)
		i++;
	return i;
}

int BiTree::SearchLeft(int Num[],int t)
{
	int i=t;
	while(Num[i]!=1&&i>=0)
		i--;
	if(Num[i]==1)
		return i;
	else return -1;
}

int BiTree::SearchRight(int Num[],int t)
{
	int i=t;
	while(Num[i]!=1&&i<=MaxSize-2)
		i++;
	if(Num[i]==1)
		return i;
	else return -1;
}