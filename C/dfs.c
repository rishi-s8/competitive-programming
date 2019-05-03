/*
 * IC250 Lab 7
 * Number of Connected Components
 * Author: Rishi Sharma (B17138)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define getInt(x) scanf("%d",&x)
#define getChar(x) scanf("%c", &x)
#define MAX 100
#define inf 10000000

typedef struct l
{
    int n, weight;
    struct l *next;
} list;


list* createNode(int n)
{
    list* temp = malloc(sizeof(list));
    temp->n=n;
    temp->next=NULL;
    return temp;
}



void insert(list** head, int n)
{
    list* temp = createNode(n);
    if(*head==NULL)
        *head=temp;
    else if((*head)->n > n)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
        list* cur = *head;
        while(cur->next!=NULL && cur->next->n<n)
            cur=cur->next;
        temp->next=cur->next;
        cur->next=temp;
    }
}


void printList(list *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->n);
        head=head->next;
    }
        printf("\n");
}

int listSize(list *head)
{
    int count=0;
    while(head!=NULL)
    {
        ++count;
        head=head->next;
    }
    return count;
}

list** g;
int n;
int *visited, *parent;

void dfs(int n)
{
    visited[n]=1;
    list* temp = g[n];
    //printf("%d ", n);
    while(temp!=NULL)
    {
        if(!visited[temp->n])
            dfs(temp->n);
        temp=temp->next;
    }
    printf("%c ", n+'A'-1);
}

void addEdgeDirected(int x, int y)
{
    insert(&g[x],y);
}


int findConnectedComponents()
{
    int connectedComponents=0;
    for(int i=1; i<=n; ++i)
    {
        if(!visited[i])
        {
            connectedComponents++;
            dfs(i);
        }
    }
    return connectedComponents;
}

int getMinKeyMST(int* keys, int* inMST)
{
  int min = inf, ind;
  for(int i=1; i<=n; ++i)
    if(!inMST[i] && keys[i]<min)
      min=keys[i], ind=i;
  return ind;
}

int main()
{
    getInt(n);
    g=malloc(sizeof(list *)*(n+1));
    visited=malloc(sizeof(int)*(n+1));
    for(int i=0; i<=n; ++i)
    {
        g[i]=NULL;
        visited[i]=0;
    }
    int m, t;
    char z;
    char x1,x2;
    int x, y;
    getInt(m);
    getInt(t);
    char str[10];
    while(m--)
    {
        getChar(z);
        getChar(x1);
        scanf("%s", str);
        getChar(z);
        getChar(x2);
        x=x1-'A'+1;
        y=x2-'A'+1;
        addEdgeDirected(y,x);
    }
    for(int i=1; i<=n; ++i)
      if(!visited[i]) dfs(i);
    printf("\n");
    free(g);
    return 0;
}
