#include <stdio.h>
#include <string.h>

#define MAXCOUNT 32
#define LEFT  0
#define RIGHT 1

typedef char Elemtype;

typedef struct BtreeNode
{
	Elemtype Data;
  struct BtreeNode *LChild,*RChild;

}BTREENODE,*BTREENODEPTR,*BTREE;

typedef struct Pos
{
	int x,y;
}BTREENODEPOS;

BTREENODEPOS BtnPos[MAXCOUNT];

void InitBtreeNodePos(void)
{
  int i;

  for(i=0;i<16;i++)
  {
      BtnPos[16+i].x=25+i*2;
      BtnPos[16+i].y=16;
  }

  for(i=15;i>=1;i--)
  {
      BtnPos[i].x=(BtnPos[2*i].x+BtnPos[2*i+1].x)/2;
      BtnPos[i].y=BtnPos[2*i].y-2;
  }
}

void DestroyBtree(BTREE Root)
{
  if(Root==NULL)return;
  DestroyBtree(Root->LChild);
  DestroyBtree(Root->RChild);
  Root->LChild=NULL;
  Root->RChild=NULL;
  free(Root);
}

void ShowBtree(BTREE Root,int Index)
{
  int i,j;
  if(Root==NULL)return;
  i=Index*2;
  j=Index*2+1;
  //gotoxy(BtnPos[Index].x,BtnPos[Index].y);
  printf("%c",Root->Data);
  if(i<MAXCOUNT) ShowBtree(Root->LChild,i);
  if(j<MAXCOUNT) ShowBtree(Root->RChild,j);
}

int GetLR(char *PreOrder,char *InOrder,int i,int Data)
{
  int j=0,k=0;
  while(PreOrder[i]!=InOrder[j]) j++;
  while(Data!=InOrder[k]) k++;
  if(j<k) return LEFT; else return RIGHT;
}

void AddBtreeNode(BTREE *Root,char *PreOrder,char *InOrder,int i)
{
  if(*Root==NULL)
  {
      (*Root)=(BTREENODE*)malloc(sizeof(BTREENODE));
      (*Root)->Data=PreOrder[i];
      (*Root)->LChild=NULL;
      (*Root)->RChild=NULL;
  }
  else
  {
      if(GetLR(PreOrder,InOrder,i,(*Root)->Data)==LEFT)
         AddBtreeNode(&(*Root)->LChild,PreOrder,InOrder,i);
      else
         AddBtreeNode(&(*Root)->RChild,PreOrder,InOrder,i);
  }
}

BTREE CreatBtreeByOrder(void)
{
  char PreOrder[32],InOrder[32];
  BTREE Root=NULL;
  int i;
  printf("Input PreOrder:");
  gets(PreOrder);
  printf("Input InOrder :");
  gets(InOrder);
  for(i=0;PreOrder[i]!=0;i++)
  	AddBtreeNode(&Root,PreOrder,InOrder,i);
  return Root;
}

void main()
{
  BTREE Root;
  //clrscr();
  InitBtreeNodePos();
  Root=CreatBtreeByOrder();
  //ShowBtree(Root,1);
  DestroyBtree(Root);
}
