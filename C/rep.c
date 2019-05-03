/*
 * IC250 Lab 6
 * Representation of the graph
 * Author: Rishi Sharma (B17138)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define getInt(x) scanf("%d",&x)
#define getChar(x) scanf("%c", &x)
#define MAX 100

int f;
typedef struct l
{
    int n;
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
        if(f==0)
            printf("%d ", head->n);
        else
            printf("%c ", head->n+'a'-1);
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

int main()
{
    list** g;
    int n;
    f=0;
    getInt(n);
    g=malloc(sizeof(list *)*(n+1));
    for(int i=0; i<=n; ++i)
        g[i]=NULL;
    int m, t;
    char xT[4], yT[4];
    getInt(m);
    getInt(t);
    int mat[MAX][MAX];
    for(int i=0; i<MAX; ++i)
        for(int j=0; j<MAX;++j)
            mat[i][j]=0;
    while(m--)
    {
        scanf("%s%s", xT, yT);
        int x, y;
        if(isalpha(xT[0]))
        {
            f=1;
            x=xT[0]-'a'+1;
            y=yT[0]-'a'+1;
        }
        else
        {
            x=atoi(xT);
            y=atoi(yT);
        }
        if(t)
        {
            insert(g+x, y);
            mat[x][y]=1;
        }
        else
        {
            insert(g+x, y);
            insert(g+y, x);
            mat[x][y]=1;
            mat[y][x]=1;
        }
    }
    for(int i=1;i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    for(int i=1; i<=n; ++i)
    {
        if(f==0)
            printf("%d ", i);
        else
            printf("%c ", i+'a'-1);
        printList(g[i]);
    }
    free(g);
    return 0;
}
