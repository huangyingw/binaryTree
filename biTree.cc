#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node * left;
  Node * right;
};

// Find the index of an element in a sequence within a certain length.
template <typename T>
int IndexOf(T* sequence, int length, T element) {
  for(int i = 0; i < length; ++i) {
    if(element == sequence[i]) {
      return i;
    }
  }
  return -1;
}

// Reconstruct a binary tree through its pre- and mid-order traversal.
template <typename T>
Node<T>* TreeReconstruction(T* preOrder, T* midOrder, int length) {
  if(length == 0) {
    return NULL;
  }
  Node<T>* root = new Node<T>();
  root->data = preOrder[0];
  int index = IndexOf(midOrder, length, preOrder[0]); // Find index of root in mid-order sequence.
  assert(index != -1);
  root->left = TreeReconstruction(preOrder + 1, midOrder, index); // Reconstruct root's left child.
  root->right = TreeReconstruction(preOrder + 1 + index, midOrder +1 + index, length - 1 - index); //Reconstruct root's right child.
  return root;
}

  template <typename T>
void PrintBiTree(Node<T> *bt,int n)
{
  int i;
  if(bt==NULL) return;
  PrintBiTree(bt->right,n+1);
  for(i=0;i<n-1;i++) printf("   ");
  if(n>0)
  {
    printf("---");
    printf("%d\n",bt->data);
  }
  PrintBiTree(bt->left,n+1);
}

int main(int argc, char ** argv) {
  int pre[8] = {1,2,4,5,7,8,3,6};
  int mid[8] = {4,2,7,5,8,1,3,6};
  Node<int>* tree = TreeReconstruction(pre, mid, 8);
  PrintBiTree(tree,1);
  return 0;
}
