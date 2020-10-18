#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} node;
node* G[10];

node* addEdge(node *chead, int newv)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->vertex=newv;
    temp->next=chead;
    return temp;
}

int main()
{
    int e, v1, v2;
    scanf("%d", &e);
    for(int i=0;i<10;i++)
        G[i]=NULL;
    for(int i=0;i<e;i++)
    {
        scanf("%d %d", &v1, &v2);
        G[v1]=addEdge(G[v1], v2);
        G[v2]=addEdge(G[v2], v1);
    }
    for(int i=1;i<10;i++)
    {
        printf("G[%d] -> ", i);
        node * traverse= G[i];
        while(traverse!=NULL)
        {
            printf("%d -> ", traverse->vertex);
            traverse=traverse->next;
        }
        printf("NULL\n");
    }
    return 0;
}