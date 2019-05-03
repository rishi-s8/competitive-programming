#include <bits/stdc++.h>
using namespace std;

struct node
{
  long data;
  node* left;
  node* right;
};

node* createNewNode(long val)
{
  node* temp= new node();
  temp->data=val;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

node* insertElement(node*& root, long val)
{

  if(root==NULL)
  {
    root=createNewNode(val);
  }
  else if(val<root->data)
  {
    root->left=insertElement(root->left, val);
  }
  else
    root->right=insertElement(root->right, val);

  return root;
}

int getMax(node* root, int a, int b)
{
  static int high = 0;
  if(root->data==b)
    return max(high, b);
  else if(a<=root->data && b>root->data)
  {
    high=root->data;
    return getMax(root->right, a, b);
  }
  else if(b<root->data)
  {
    if(high<root->data && high>0)
      high=root->data;
    return getMax(root->left, a, b);
  }
  else if(b>root->data)
  {
    return getMax(root->right, a, b);
  }

  return max(high,b);
}

int main()
{
  int n, temp, high, a, b;
  cin >> n;
  node* head = NULL;
  for(int i=0; i<n; ++i)
  {
    cin >> temp;
    insertElement(head, temp);
  }
  cin >> a >> b;
  high=getMax(head, min(a,b), max(a,b));
  cout << high << endl;
}
