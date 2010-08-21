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
	static ofstream fout;

public:
	int* data;
	int size;
	BiTreeNode * root;
	BiTreeNode *q[MaxSize+1];//use to 
	int Num[MaxSize];//use to indicate whether a char in in_order is treated.
	char *pre_order;//="befcgdh";//pre_order
	char *in_order;//="febgchd";//in_order
	
	BiTree();
	~BiTree();
	
	void Print(BiTreeNode *bt,int n);
	static void Visit(DataType item);
	int Search(char str[],char t);
	int SearchLeft(int t);
	int SearchRight(int t);
	void PreOrder(BiTreeNode *t,void Visit(DataType item));
	void InOrder(BiTreeNode *t,void Visit(DataType item));
	void PostOrder(BiTreeNode *t,void Visit(DataType item));
	BiTreeNode *InsertLeftNode(BiTreeNode *curr,DataType x);
	BiTreeNode* InsertRightNode(BiTreeNode *curr,DataType x);
	void PrintNum();
};

void BiTree::PrintNum()
{
	for(int index=0;index<MaxSize;index++)
	{
		BiTree::fout<<Num[index];
	}
	BiTree::fout<<endl;
}


BiTree::BiTree()
{
	root=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	pre_order="befcgdh";
	in_order="febgchd";
	root->leftChild=NULL;
	root->rightChild=NULL;
	
	int left,right,temp;
	
	
	char point;int n;
	n=strlen(pre_order);
	for(int i=0;i<n;i++)
	{
		BiTree::fout<<endl;
		BiTree::fout<<"i="<<i<<endl;
		point=pre_order[i];
		temp=Search(in_order,point);
		BiTree::fout << "Search for->"<<point<<"->position in in_order->"<<temp<<endl;
		
		PrintNum();
		
		left=SearchLeft(temp);
		BiTree::fout << "SearchLeft result->"<<left<<endl;
		
		right=SearchRight(temp);
		BiTree::fout << "SearchRight result->"<<right<<endl;
		
		if(left==-1&&right==-1)//both
		{
			q[temp]=InsertLeftNode(root,point);
			BiTree::fout << "InsertLeftNode->"<<point<<endl;
			BiTree::fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(left!=-1&&q[left]->rightChild==NULL)
		{
			q[temp]=InsertRightNode(q[left],point);
			BiTree::fout << "InsertRightNode->"<<point<<endl;
			BiTree::fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
		else if(right!=-1&&q[right]->leftChild==NULL)
		{
			q[temp]=InsertLeftNode(q[right],point);
			BiTree::fout << "InsertLeftNode->"<<point<<endl;
			BiTree::fout << "q["<<temp<<"]->"<<q[temp]->data<<endl;
			Num[temp]=1;
		}
	}
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

BiTreeNode* BiTree::InsertRightNode(BiTreeNode *curr,DataType x)
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
	for(i=0;i<n-1;i++) BiTree::fout<<"   ";
	if(n>0)
	{
		BiTree::fout<<"---";
		BiTree::fout<<bt->data<<endl;
	}
	Print(bt->leftChild,n+1);
}

void BiTree::Visit(DataType item)
{
	BiTree::fout<<item<<"   ";
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

int BiTree::SearchLeft(int t)
{
	int i=t;
	while(Num[i]!=1&&i>=0)
		i--;
	if(Num[i]==1)
		return i;
	else return -1;
}

int BiTree::SearchRight(int t)
{
	int i=t;
	while(Num[i]!=1&&i<=MaxSize-2)
		i++;
	if(Num[i]==1)
		return i;
	else return -1;
}