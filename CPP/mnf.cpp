#include <bits/stdc++.h>
using namespace std;

struct node
{
  long long data;
  node* left;
  node* right;
};

node* createElement(long long val)
{
  node* temp = new node();
  temp->left=NULL;
  temp->right=NULL;
  temp->data=val;
  return temp;
}

node* insertElement(node*& root, long long val, bool &created)
{
  if(root==NULL)
  {
    root=createElement(val);
  }

  else if(root->data==val)
    created=false;

  else if(val<root->data)
  {
    root->left=insertElement(root->left, val, created);
  }
  else
    root->right=insertElement(root->right, val, created);
  return root;
}


int main()
{
  node* head = NULL;
  int t;
  int n,m;
  long long a;
  cin >> t;
  while(t--)
  {
    head=NULL;
    cin >> n >> m;
    bool created;
    for(int i=0; i<n; ++i)
    {
      cin >> a;
      insertElement(head, a, created);
    }
    for(int j=0; j<m; ++j)
    {
      created=true;
      cin >> a;
      insertElement(head, a, created);
      if(!created)
      {
        cout<< "YES\n";
      }
      else
        cout << "NO\n";
    }
  }
}
