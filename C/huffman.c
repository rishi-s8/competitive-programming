#include <stdio.h>

typedef struct n
{
  struct n *left;
  char ch;
  int frequency;
  struct n *right;
} node;

/*typedef struct
{
  char ch;
  int frequency;
} table;*/

node* head;

node* newNode(char c, int freq)
{
  node* currentNode=(node*) malloc(sizeof(node));
  currentNode->left=NULL;
  currentNode->right=NULL;
  currentNode->frequency=freq;
  currentNode->ch=c;
  return currentNode;
}

int main()
{
  head=newNode('\0', 0);
  int ar[128];
  ar['a']=5;
  ar['b']=9;
  ar['c']=12;
  ar['d']=13;
  ar['e']=16;
  ar['f']=45;

}
