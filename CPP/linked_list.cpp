#include <iostream>
using namespace std;

class list
{
  struct node
  {
    int data;
    node* next;
  };
  node* head;
  node* current;
  node* temp;
  int sz;
public:
  list()
  {
    head=NULL;
    current=NULL;
    temp=NULL;
    sz=0;
  }
  void NewNode(int k)
  {
    node* n=new node;
    n->next=NULL;
    n->data=k;
    if(head!=NULL)
    {
      current=head;
      while(current->next!=NULL)
      {
        current=current->next;
      }
      current->next=n;
    }
    else
      head=n;
  }
  void DelNode(int d)
  {
    node* del=NULL;
    int s=0;
    current=head;
    temp=head;
    while(s<d)
    {
      temp=current;
      current=current->next;
      s++;
    }
    if(current!=NULL)
    {
      del=current;
      current=current->next;
      temp->next=current;
      delete del;
      cout << "DELETED\n";
    }
    else
    {
      cout<<"404: NOT FOUND\n";
      delete del;
    }
  }
  void Print(int p)
  {
    current=head;
    for(int i=0; i<p;i++)
    {
      current=current->next;
      if(current==NULL)
      {
        cout << "Doesn't Exist!\n";
        return;
      }
    }
    cout << current->data;
  }

};

int main()
{
  list l1;
  for(int i=0, j=20; i<10; i++,j--)
    l1.NewNode(j);
  cout << "LIST:" << endl;
  for(int i=0;i<10;i++)
  {
      l1.Print(i);
      cout << " ";
  }
  return 0;

}
