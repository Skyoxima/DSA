#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct G_Node 
{
    int data;
    struct G_Node* link;
} Node;

int n_o_nodes;
int visited[MAX];
Node *graph[MAX];

void readGraph()
{

    int i, j, links;
    int edge1, edge2; 

    for(i = 0; i < n_o_nodes; i++)
    {
        graph[i] = (Node*) malloc(sizeof(Node));
        graph[i] -> link = NULL;
        graph[i] -> data = i;
        printf("For Node %d:\n", i);
        printf("Enter Number Of Edges: ");
        scanf("%d", &links);
        
        for(j = 0; j < links; j++)
        {
            printf("Enter edge in the format - [0, 1]: ");
            scanf("%d, %d", &edge1, &edge2);
            Node *temp = (Node*) malloc(sizeof(Node));
            temp -> data = edge2;
            temp -> link = NULL;
            
            Node *t = graph[i];
            while(t -> link != NULL)
                t = t -> link;
            
            t -> link = temp;
        }
    }
}

int outdeg(int v)
{
    Node *p;
    int count = 0;
    p = graph[v];
    while(p -> link != NULL)
    {
        count++;
        p = p -> link;
    }
    return count;
}

int indeg(int v)
{
    Node *p;
    int i, count = 0;
    for(i = 0; i < n_o_nodes; i++)
    {
        p = graph[i] -> link;
        while(p != NULL)
        {
            if(p -> data == v)
                count++;
            p = p -> link;    
        }
    }
    return count;
}

void adj_list()
{
    printf("Adjacency List:\n");
    for(int i = 0; i < n_o_nodes; i++)
    {
        Node *p = graph[i];
        for(p = graph[i]; p -> link != NULL; p = p -> link)
        {
            printf("%d --> ", p -> data);
        }
        printf("%d --> NULL", p -> data);
        printf("\n");
    }
    
}
    
void dfs(int i)
{
    Node *p;
    printf("%d ", i);
    p = graph[i] -> link;
    visited[i] = 1;
    
    while(p != NULL)
    {
        i = p -> data;
        if(visited[i] != 1)
            dfs(i);
        p = p -> link;
    }
}

void main()
{
    int i, choice;
    system("cls");
    
    printf("Enter Number Of Nodes For Graph: ");
    scanf("%d", &n_o_nodes);

    readGraph();
    printf("\n");
    for(i = 0; i < n_o_nodes; i++)
        printf("\nThe out degree of %d is %d", i, outdeg(i));
    printf("\n");
    for(i = 0; i < n_o_nodes; i++)
        printf("\nThe in degree of %d is %d", i, indeg(i));
    
    printf("\n\n");
    adj_list();
    
    for(int i = 0; i < n_o_nodes; i++)
        visited[i] = 0;

    printf("\nEnter the vertex for DFS: ");
    scanf("%d", &choice);
    
    if(choice < 0 || choice >= n_o_nodes)
        printf("Invalid Choice!");
    else
    {
        printf("\nDepth First Search:\n");
        dfs(choice);
    }
}