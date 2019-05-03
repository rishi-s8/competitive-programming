#include <bits/stdc++.h>
using namespace std;

class BinarySearchTree
{
  struct node
  {
    int val;
    node* left;
    node* right;
  };
  node* head;
  int created, deleted;


  public:
  BinarySearchTree()
  {
    head=NULL;
    created = deleted = 0;
  }
  node* insertElement(int data);
  node* insertElement(node*& root, int data);
  node* createNewNode(int data);
  bool searchElement(int data);
  bool searchElement(node* root, int data);
  int getMin();
  int getMin(node* root);
  int getMax();
  int getMax(node* root);
  int deleteElement(int data);
  int deleteElement(node*& root, int data);
  void dft();
  void dft(node* root);
  void eraseAll();
  void eraseAll(node*& root);
  int getDeleted()
  {
    return deleted;
  }
  int getCreated()
  {
    return created;
  }

  int inOrderSuccessor(int data);
};

int BinarySearchTree::inOrderSuccessor(int data)
{
  node* parent=NULL;
  node* current = head;
  while(current->val!=data)
  {
    if(current==NULL)
      return -1;
    if(data < current->val)
      current=current->left;
    else
      current=current->right;
  }
  cout << "\nFOUND: " << current->val << endl;
  if(current->right!=NULL)
  {
    cout << "Right is NULL\n";
    return getMin(current->right);
  }
  else
  {
    node* temp = head;
    while(temp!=current)
    {
      if(data<temp->val)
      {
        parent=temp;
        temp=temp->left;
      }
      else
      {
        temp=temp->right;
      }
    }
    if(parent==NULL)
    {
        cout << "No Successor!\n";
        return -1;
    }
    return parent->val;
  }
}

BinarySearchTree::node* BinarySearchTree::insertElement(int data)
{
  return insertElement(head, data);
}

BinarySearchTree::node* BinarySearchTree::insertElement(node*& root, int data)
{
  if(root==NULL)
  {
    root = createNewNode(data);
    ++created;
  }
  else if(data <= root->val)
  {
    root->left=insertElement(root->left, data);
  }
  else
    root->right=insertElement(root->right, data);
  return root;
}

BinarySearchTree::node* BinarySearchTree::createNewNode(int data)
{
  node* temp = new node();
  temp->left=NULL;
  temp->right=NULL;
  temp->val=data;
  cout << "Created Node with value:" << data << endl;
  return temp;
}

bool BinarySearchTree::searchElement(int data)
{
  return searchElement(head, data);
}

bool BinarySearchTree::searchElement(node* root, int data)
{
  if(root==NULL)
    return false;
  else if(root->val==data)
    return true;
  else if(data < root->val)
    return searchElement(root->left, data);
  else
    return searchElement(root->right, data);
}

int BinarySearchTree::getMin()
{
  return getMin(head);
}

int BinarySearchTree::getMin(node* root)
{
  if(root==NULL)
    return -1;
  else if(root->left==NULL)
    return root->val;
  else
    return getMin(root->left);
}

int BinarySearchTree::getMax()
{
  return getMax(head);
}

int BinarySearchTree::getMax(node* root)
{
  if(root==NULL)
    return -1;
  else if(root->right==NULL)
    return root->val;
  else
    return getMin(root->right);
}

int BinarySearchTree::deleteElement(int data)
{
  return deleteElement(head, data);
}

int BinarySearchTree::deleteElement(node*& root, int data)
{
  if(root==NULL)
    return -1;
  else if(data < root->val)
    deleteElement(root->left, data);
  else if(data > root->val)
    deleteElement(root->right, data);
  else
  {
    cout << "Deleting: " << root->val << endl;
    if(root->left == NULL && root->right == NULL)
    {
      cout << data << " is leaf node\n";
      node* temp=root;
      root=NULL;
      delete temp;
    }
    else if(root->left==NULL)
    {
      cout << data << " has no left child\n";
      node* temp=root;
      root=root->right;
      delete temp;
    }
    else if(root->right==NULL)
    {
      cout << data << " has no right child\n";
      node* temp=root;
      root=root->left;
      delete temp;
    }
    else
    {
      cout << data << " has both left and right child\n";
      int min=getMin(root->right);
      cout << "Minimum: " << min << endl;
      root->val=min;
      deleteElement(root->right, min);
    }
    ++deleted;
  }
  return data;
}

void BinarySearchTree::dft()
{
  dft(head);
  cout << endl;
}

void BinarySearchTree::dft(node* root)
{
  //InOrder
  if(root==NULL)
    return;
  dft(root->left);
  cout << root-> val << " ";
  dft(root->right);
}

void BinarySearchTree::eraseAll()
{
  eraseAll(head);
  cout << "Binary Tree Empty..." << endl;
}

void BinarySearchTree::eraseAll(node*& root)
{
  if(root==NULL)
    return;
  eraseAll(root->left);
  eraseAll(root->right);
  if(root->left==NULL && root->right==NULL)
  {
    cout << "Erasing: " << root->val << endl;
    node* temp = root;
    root=NULL;
    delete temp;
    ++deleted;
  }
}


int main()
{
  BinarySearchTree bst;
  bst.insertElement(15);
  bst.insertElement(10);
  bst.insertElement(20);
  bst.insertElement(8);
  bst.insertElement(6);
    bst.insertElement(12);
      bst.insertElement(11);
  bst.insertElement(17);
    bst.insertElement(25);
      bst.insertElement(27);
        bst.insertElement(16);
  bst.dft();
  cout << "Created: " << bst.getCreated() << endl;

  cout << "Successors: \n";
  cout << 10 << " " << bst.inOrderSuccessor(10) << endl;
  cout << 20 << " " << bst.inOrderSuccessor(20) << endl;
  cout << 12 << " " << bst.inOrderSuccessor(12) << endl;
  cout << 11 << " " << bst.inOrderSuccessor(11) << endl;
  cout << 10 << " " << bst.inOrderSuccessor(10) << endl;
  cout << 27 << " " << bst.inOrderSuccessor(27) << endl;

  bst.eraseAll();
  cout << "Deleted: " << bst.getDeleted() << endl;
}
