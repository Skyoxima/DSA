#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct G_Node 
{
    int data;
    struct G_Node* link;
} Node;

typedef struct Q 
{
    Node *front;
    Node *rear;
} Q;

int n_o_nodes;
Node *graph[MAX];
Q* q;

void enqueue(int value)
{
    Node *temp = (Node*) malloc(sizeof(Node));
    temp -> data = value;
    temp -> link = NULL;
    
    if(q -> rear == NULL)
    {
        q -> front = q -> rear = temp;
    }
    else
    {
        q -> rear -> link = temp;
        q -> rear = temp;
        temp -> link = NULL;
    }
}

int dequeue()
{
    Node *temp;
    int a = 0;
    if(q -> front ==NULL)
    {
        printf("Underflow!");
        return -1;
    }
    temp = q -> front;
    q -> front = q -> front -> link;
    if(q -> front == NULL)
        q -> rear = NULL;
    a = temp -> data;
    free(temp);
    return a;
}

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
    
void bfs(int i)
{
    printf("Breadth First Search:\n");
    int visited[n_o_nodes];
    int x, a;
    for(int i = 0; i < n_o_nodes; i++)
        visited[i] = 0;
    Node *p; 

    enqueue(i);
    printf("%d ", i);
    visited[i] = 1;

    while(q -> front != NULL)
    {
        i = dequeue();
        for(p = graph[i]; p != NULL; p = p -> link)
        {
            x = p -> data;
            if(visited[x] == 0)
            {
                enqueue(x);
                visited[x] = 1;
                printf("%d ", x);
            }
        }
    }
    printf("\n");
}

void main()
{
    q = (Q*) malloc(sizeof(Q));
    int i, choice;
    system("cls");
    q -> front = q -> rear = NULL;

    printf("Enter Number Of Nodes For Graph: ");
    scanf("%d", &n_o_nodes);

    readGraph();
    printf("\n");
    for(i = 0; i < n_o_nodes; i++)
        printf("\nThe out degree of %d is %d",i,outdeg(i));
    printf("\n");
    for(i = 0; i < n_o_nodes; i++)
        printf("\nThe in degree of %d is %d",i,indeg(i));
    
    printf("\n\n");
    adj_list();
    
    printf("\nEnter the vertex for BFS: ");
    scanf("%d", &choice);
    
    if(choice < 0 || choice >= n_o_nodes)
        printf("Invalid Choice!");
    else
        bfs(choice);
}