typedef struct Node
{
  DataType data;
  struct Node *leftChild;
  struct Node *rightChild;
}BiTreeNode;

void Initiate(BiTreeNode **root)
{
  *root=(BiTreeNode *)malloc(sizeof(BiTreeNode));
  (*root)->leftChild=NULL;
  (*root)->rightChild=NULL;
}

BiTreeNode *InsertLeftNode(BiTreeNode *curr,DataType x)
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

void PrintBiTree(BiTreeNode *bt,int n)
{
  int i;
  if(bt==NULL) return;
  PrintBiTree(bt->rightChild,n+1);
  for(i=0;i<n-1;i++) printf("   ");
  if(n>0)
  {
    printf("---");
    printf("%c\n",bt->data);
  }
  PrintBiTree(bt->leftChild,n+1);
}

void Visit(DataType item)
{
  printf("%c   ",item);
}

void PreOrder(BiTreeNode *t,void varVisit(DataType item))
{
  if(t!=NULL)
  {
    varVisit(t->data);
    PreOrder(t->leftChild,varVisit);
    PreOrder(t->rightChild,varVisit);
  }
}

void InOrder(BiTreeNode *t,void varVisit(DataType item))
{
  if(t!=NULL)
  {

    InOrder(t->leftChild,varVisit);
    varVisit(t->data);
    InOrder(t->rightChild,varVisit);
  }
}

void PostOrder(BiTreeNode *t,void varVisit(DataType item))
{
  if(t!=NULL)
  {
    PostOrder(t->leftChild,varVisit);
    PostOrder(t->rightChild,varVisit);
    varVisit(t->data);
  }
}

int Search(char str[],char t)
{
  int i=0;
  while(str[i]!=t)
    i++;
  return i;
}

int SearchLeft(int data[],int t)
{
  int i=t;
  while(data[i]!=1&&i>=0)
    i--;
  if(data[i]==1)
    return i;
  else return -1;
}

int SearchRight(int data[],int t)
{
  int i=t;
  while(data[i]!=1&&i<=MaxSize-2)
    i++;
  if(data[i]==1)
    return i;
  else return -1;
}
