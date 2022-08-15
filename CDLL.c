#include<stdio.h>
#include<stdlib.h>

typedef struct LL_Node
{
    int data;
    struct LL_Node *prev, *next;
}Node;

Node* create_CDLL()
{
    int n,i;
    Node *head = (Node*)malloc(sizeof(Node)); //allocating memory for the first node
    Node *p = head; //for traversing
    Node *ptr = head; //for assigning prev of a node
    head -> prev = head; //single node looping on itself
    head -> next = head;

    printf("\nEnter the number of elements you want in the DLL: ");
    scanf("%d",&n);
    if(n == 0)
        printf("\n1 node will be compulsorily created!");

    printf("\nEnter the data for the first node of the CDLL: ");
    scanf("%d",&p -> data);

    for(i = 1; i < n; i++)
    {
        p -> next = (Node*)malloc(sizeof(Node)); //making the next nodes, linking with the current one 
        if(p -> next == NULL)
        {
            printf("\nOverflow!");
            break;
        }
        ptr = p;
        p = p -> next; 
        p -> prev = ptr;
        printf("Enter the next data: ");
        scanf("%d",&p -> data);
        p -> next = head;
    }
    head -> prev = p; //prev of head becomes the last node which is in p after the for loop
    
    return head;
}

void display_CDLL(Node *head)
{
    Node *p = head;
    if(head == NULL)
    {
        printf("\nThe DLL is empty...");
            return;
    }
    
    do
    {
        printf("%d ", p -> data);
        p = p -> next;
    }while(p != head);
}

int count_CDLL(Node *head)
{
    int count = 0;
    Node *p = head;

    if(head == NULL) //list empty / doesn't exist
        return 0;
    
    do
    {
        count++;
        p = p -> next;
    } while (p != head);
    
    return count;
}

void main()
{
    int Option_No, val;
    Node *start = NULL;
    system("cls");  //clear screen

    printf("\nMenu Driven Program for Circular Doubly Linked List (CDLL)");
    do
    {
        printf("\n\n1. Create a CDLL.\n2. Display all the elements of the CDLL.\n3. Count the number of nodes in the CDLL.\nOption_No: ");
        scanf("%d",&Option_No);

        switch(Option_No)
        {
            case(0):
            exit(0);
            break;
            
            case 1:
            start = create_CDLL();
            printf("Created Circular Doubly Linked List: ");
            display_CDLL(start);
            break;

            case 2:
            printf("\nAll the elements of the CDLL: ");
            display_CDLL(start);
            break;

            case 3:
            val = count_CDLL(start);
            printf("\nNumber of elements in the CDLL are: %d", val);
            break;

            default:
            printf("\nInvalid Option!");
        }
    } while(Option_No != 0);
}