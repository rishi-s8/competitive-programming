/*
 * IC250 Lab 7
 * Shortest Path in Unweighted Graph
 * Author: Rishi Sharma (B17138)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define getInt(x) scanf("%d",&x)
#define getChar(x) scanf("%c",&x)
#define getString(x) scanf("%s",x)
#define MAX 100
#define ELEMENTS 12
#define MN 1
#define CH 2
#define DL 3
#define DD 4
#define KL 5
#define GU 6
#define MU 7
#define BH 8
#define GO 9
#define HY 10
#define KK 11
#define CN 12


typedef struct l  // Node Type
{
    int n;
    struct l *next;
} list;

typedef struct  // Queue
{
  list *head, *tail;
} queue;



list* createNode(int n) // Create a new node with given value
{
    list* temp = malloc(sizeof(list));
    temp->n=n;
    temp->next=NULL;
    return temp;
}

int isEmpty(queue q) // Check if the queue is empty or not
{
    if(q.head==NULL && q.tail==NULL) return 1; // Return true
    return 0; // Return false
}

void push(queue *q, int n) // Push Element in the queue
{
    list* temp = createNode(n);
    if(q->head==NULL && q->tail==NULL) q->head=q->tail=temp;
    else
    {
        q->tail->next=temp;
        q->tail=temp;
    }
}

int pop(queue *q) // Pop Element from the queue
{
    list* temp = q->head;
    if(q->head==q->tail)
    {
        q->head=q->tail=NULL;
    }
    else
        q->head=q->head->next;

    int val = temp->n;
    free(temp);
    return val;
}

void insertSorted(list** head, int n) // Insert Element in a sorted list
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
        cur->next=temp;    }
}

void insert(list **head, int n) // Insert Element in unsorted list
{
    list *temp = createNode(n);
    if(*head==NULL)
        *head=temp;
    else
    {
        temp->next=*head;
        *head=temp;
    }
}


void printList(list *head) // Print list
{
    while(head!=NULL)
    {
        printf("%d ", head->n);
        head=head->next;
    }
        printf("\n");
}

int listSize(list *head) // Get the number of elements in the list
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
int* visited;
char cities[ELEMENTS+1][3];

void dfs(int n) // Perform DFS from the source node
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
}

void bfs(int n) // Perform BFS from the source node
{
    visited[n]=1;
    queue Q;
    Q.head=NULL;
    Q.tail=NULL;
    push(&Q, n);
    while(!isEmpty(Q))
    {
        n=pop(&Q);
        //printf("%d ", n);
        list* temp = g[n];
        while(temp!=NULL)
        {
            if(!visited[temp->n])
            {
                visited[temp->n]=1;
                push(&Q,temp->n);
            }
            temp=temp->next;
        }
    }
}

void shortestPathUnweighted(int start, int end) // Find Shortest Path from Start to End
{
    visited[start]=1;
    int parents[ELEMENTS+1];
    memset(parents,0,sizeof(int)*(ELEMENTS+1));
    queue Q;
    Q.head=NULL;
    Q.tail=NULL;
    int n = start;
    push(&Q, n);
    while(!isEmpty(Q))
    {
        n=pop(&Q);
        list* temp = g[n];
        while(temp!=NULL)
        {
            if(!visited[temp->n])
            {
                parents[temp->n]=n;
                visited[temp->n]=1;
                push(&Q,temp->n);
            }

            temp=temp->next;
        }
    }

    list* temp = NULL;
   // insert(&temp,end);
    while(parents[end]!=start)
    {
        insert(&temp,parents[end]);
        end=parents[end];
    }
    while(temp!=NULL)
    {
        printf("%s ", cities[temp->n]);
        temp=temp->next;
    }
    printf("\n");
}

int findConnectedComponents() // Returns number of connected Components
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

void addEdgeUndirected(int x, int y) // Add Undirected edge between x and y
{
    insert(&g[x],y);
    insert(&g[y],x);
}

void addEdgeDirected(int x, int y) // Add directed edge from x to y
{
    insert(&g[x],y);
}

void addEdge(int x, int y)
{
    addEdgeUndirected(x,y);
}

void init()
{
    strcpy(cities[1], "MN");
    strcpy(cities[2], "CH");
    strcpy(cities[3], "DL");
    strcpy(cities[4], "DD");
    strcpy(cities[5], "KL");
    strcpy(cities[6], "GU");
    strcpy(cities[7], "MU");
    strcpy(cities[8], "BH");
    strcpy(cities[9], "GO");
    strcpy(cities[10], "HY");
    strcpy(cities[11], "KK");
    strcpy(cities[12], "CN");
    addEdge(MN,CH);
    addEdge(CH,DL);
    addEdge(DL,DD);
    addEdge(DL,MU);
    addEdge(DL,KL);
    addEdge(KL,GU);
    addEdge(DL,BH);
    addEdge(MU,BH);
    addEdge(MU,GO);
    addEdge(GO,HY);
    addEdge(BH,HY);
    addEdge(GO,KK);
    addEdge(HY,CN);
    addEdge(KK,CN);
    addEdge(KL,CN);
}

int hash(char* s)
{
    if(!strcmp(s,"MN")) return 1;
    if(!strcmp(s,"CH")) return 2;
    if(!strcmp(s,"DL")) return 3;
    if(!strcmp(s,"DD")) return 4;
    if(!strcmp(s,"KL")) return 5;
    if(!strcmp(s,"GU")) return 6;
    if(!strcmp(s,"MU")) return 7;
    if(!strcmp(s,"BH")) return 8;
    if(!strcmp(s,"GO")) return 9;
    if(!strcmp(s,"HY")) return 10;
    if(!strcmp(s,"KK")) return 11;
    if(!strcmp(s,"CN")) return 12;
    return -1;
}

int main()
{
    n = 12;
    g=malloc(sizeof(list *)*(n+1));
    visited=malloc(sizeof(int)*(n+1));
    for(int i=0; i<=n; ++i)
    {
        g[i]=NULL;
        visited[i]=0;
    }
    init();

    char start[3], end[3];
    scanf("%s%s", start, end);
    shortestPathUnweighted(hash(start), hash(end));
    //int ans = shortestPathUnweighted(hash(start), hash(end));
    //printf("%d\n", ans);
    free(g);
    return 0;
}
