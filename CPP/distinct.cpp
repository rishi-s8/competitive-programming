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

node* insertElement(node*& root, long val, bool& isDuplicate)
{

  if(root==NULL)
  {
    root=createNewNode(val);
  }
  else if(val==root->data)
    isDuplicate=true;
  else if(val<root->data)
  {
    root->left=insertElement(root->left, val, isDuplicate);
  }
  else
    root->right=insertElement(root->right, val, isDuplicate);

  return root;
}


/*void eraseAll(node*& root)
{
  if(root==NULL)
    return;
  eraseAll(root->left);
  eraseAll(root->right);
  if(root->left==NULL && root->right==NULL)
  {
    node* temp = root;
    root=NULL;
    delete temp;
  }
}*/

int main()
{
  node* head;
  int t;
  cin>>t;
  while(t--)
  {
    head=NULL;
    long n,x, temp, duplicates=0;
    cin >> n >>x;
    for(int i=0; i<n; ++i)
    {
      cin >> temp;
      bool isDuplicate = false;
      insertElement(head, temp, isDuplicate);
      if(isDuplicate)
        ++duplicates;
    }
    if(n-duplicates < x)
      cout << "Bad\n";
    else if(n-duplicates==x)
      cout << "Good\n";
    else
      cout << "Average\n";
  //  eraseAll(head);
  }
}
