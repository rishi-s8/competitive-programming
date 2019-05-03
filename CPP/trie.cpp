#include <iostream>
#include <string.h>
#include <map>
using namespace std;

class trie
{
  struct node
  {
    map<char, node*> child;
    bool isEnd;
  };
  node* head;
public:
  trie()
  {
    head=new node();
    head->isEnd=false;
  }
  void insert(string s)
  {
    int len = s.size();
    node* current = head;
    for(int i=0; i<len; i++)
    {
      if(current->child[s[i]]==NULL)
      {
        current->child[s[i]]=new node();
        current->child[s[i]]->isEnd=false;
      }
      current=current->child[s[i]];
    }
    current->isEnd=true;
  }
  bool search(string s)
  {
    node* current = head;
    int len = s.size();
    for(int i=0; i<len; i++)
    {
      if(current->child[s[i]]!=NULL)
      {
        current=current->child[s[i]];
      }
      else
        return false;
    }
    if(current->isEnd==true)
      return true;
    return false;
  }
};

int main()
{
  trie t;
  t.insert("Rishi");
  t.insert("Hello");
  t.insert("Ris");
  cout << t.search("Rishi") << " " << t.search("Hello") << ' ' << t.search("Ris") << endl;
  return 0;
}
