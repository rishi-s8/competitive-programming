#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
};

node* createNewNode(int val)
{
  node* temp= new node();
  temp->data=val;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

node* insertElement(node*& root, int val, int &height)
{

  if(root==NULL)
  {
    root=createNewNode(val);
  }
  else if(val<=root->data)
  {
    root->left=insertElement(root->left, val, height);
  }
  else
    root->right=insertElement(root->right, val, height);
  //cout << "Incrementing height:  " << height << endl;
  height++;
  return root;
}



int main()
{
  int n;
  node* head=NULL;
  int max_height=0, temp, cur_height;
  cin >> n;
  for(int i=0; i<n; ++i)
  {
    cur_height=0;
    cin >> temp;
    insertElement(head, temp, cur_height);
    if(cur_height>max_height)
      max_height=cur_height;
  }
  cout << max_height << endl;

}
