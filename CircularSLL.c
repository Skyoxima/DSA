#include<stdio.h>
#include<stdlib.h>

typedef struct CSLL_Node
{
    int data;
    struct CSLL_Node *next;
}Node;

int del_ele = 0; 

Node* create_CSLL(int n)
{
    int i;
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
    printf("\nEnter the data for the First node: ");
    scanf("%d",&p -> data);

    for(i = 1; i < n; i++)
    {
        p -> next = (Node *)malloc(sizeof(Node));
        p = p -> next;  
        if(i < n - 1)
            printf("Enter the data for the next node: ");
        else
            printf("Enter the data for the Last node: ");
        scanf("%d",&p -> data);
    }
    p -> next = head;  //makes it a CSLL

    return head;
}

void display_CSLL(Node *head)
{
    int i;
    Node *p = head;

    if(head != NULL)
    {
        printf("\nCurrent nodes of CSLL: ");
        do // so that atleast p is 'incremented' once otherwise p will always be equal to head since it is the starting condition but also the ending condition
        {
            printf("%d ",p -> data);
            p = p -> next;
        }while(p != head);
        
    }
    else
        printf("\nThe CSLL is empty or corrupted...");
}

int node_count(Node *head)
{
    int count = 0;
    Node *p = head;

    if(head != NULL)
    {
        do //same as display_CSLL
        {
            count++;
            p = p -> next;
        }while(p != head);
    }
    return count;
}

void user_friend_1(Node *head)
{
    display_CSLL(head); //for user friendliness
    printf("\nCurrent number of nodes: %d",node_count(head));    
}

Node* insert_beg(Node *, int);
Node* insert_end(Node *, int);
Node* insert_pos(Node *, int, int);
Node* insert_bef(Node *, int, int);

Node* inserts(Node *head)
{
    int choice, val, pos;
    printf("\n~~~ Insertion Menu ~~~\n\n1. Insert at the beginning.\n2. Insert at the end.\n3. Insert at specified position (not index!).\n4. Insert before an specific node.\nChoice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("\nEnter the integer you want to insert at the beginning of the CSLL: ");
        scanf("%d",&val);
        head = insert_beg(head, val);        
        break;

        case 2:
        printf("\nEnter the integer you want to insert at the end of the CSLL: ");
        scanf("%d",&val);
        head = insert_end(head, val);
        break;
        
        case 3:
        user_friend_1(head); //I can afford to do this here because of the lesser number of nodes I use (<< ~100) 
        printf("\n\nEnter the integer you want to insert: ");
        scanf("%d",&val);
        printf("Now enter the \"ith\" position AT which the value is to be inserted: ");
        scanf("%d",&pos);
        head = insert_pos(head, val, pos);        
        break;
        
        case 4:
        user_friend_1(head);
        printf("\n\nEnter the integer you want to insert: ");
        scanf("%d",&val);
        printf("Now enter the value BEFORE which the new integer must be inserted: ");
        scanf("%d",&pos);
        head = insert_bef(head, val, pos);        
        break;

        default:
        printf("\nINVALID CHOICE!");
    }

}

Node* insert_beg(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    Node *p = head;

    if(new == NULL) //new node couldn't be formed case
    {        
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;

    if(head == NULL) //no existing node/SLL condition
        new -> next = new;
    else    //simply prepending and also changing the last node's next pointer 
    {
        while(p -> next != head)
            p = p -> next;
        
        new -> next = head;
        p -> next = new;
    }    
    
    return new;
}

Node* insert_end(Node* head, int val)
{
    Node *p = head;
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {        
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;
    new -> next = new;

    if(head == NULL) //no existing node condtion
        return new;

    while(p -> next != head)
        p = p -> next;
    
    p -> next = new;
    new -> next = head;

    return head;
}

Node* insert_pos(Node* head, int val, int pos)
{
    int count = 1;
    Node *p = head;
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;
    new -> next = new;

    if(head == NULL)
    {   
        printf("\nThe SLL was empty...inserting at 1st position");
        new -> next = NULL;
        return new;
    }
    else if(pos <= 1)
        head = insert_beg(head, val);
    else if(pos > node_count(head)) //new node to be inserted at the last position
        head = insert_end(head, val);
    else
    {   
        while(count < pos - 1)
        {
            count++;
            p = p -> next;
        }
        new -> next = p -> next;
        p -> next = new;
    }

    return head;
}

Node* insert_bef(Node* head, int val, int bef) //using this fucntion you cannot append at the last position, so a case to check for this doesn't arise
{
    Node *p = head;
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;
    new -> next = new;

    if(bef == head -> data)
        head = insert_beg(head, val);
    else //you cannot append to the last but a case to check if the 'bef' data was found is still needed
    {
        while(p -> next != head && bef != p -> next -> data)
            p = p -> next;
        
        if(p -> next == head)
            printf("\n%d was not found in the CSLL, insertion of %d failed...",bef, val);
        else
        {
            new -> next = p -> next;
            p -> next = new;
        }
    }
    
    return head;
}

Node* del_beg(Node *);
Node* del_end(Node *);
Node* del_of_value(Node *, int);
Node* del_pos(Node *, int);

Node* deletes(Node *head)
{
    int val, choice, pos;
    printf("\n~~~ Deletion Menu ~~~\n\n1. Delete the first node.\n2. Delete the last node.\n3. Delete node with specified data.\n4. Delete node at specified position.\nChoice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        head = del_beg(head);
        printf("\n%d was the data of the first node of the CSLL.",del_ele);
        break;

        case 2:
        head = del_end(head);
        printf("\n%d was the data of the first node of the CSLL.",del_ele);
        break;

        case 3:
        break;

        case 4:
        break;

        default:
        printf("INVALID CHOICE! Please try again...");
    }
}

Node* del_beg(Node *head)
{
    Node *p = head;

    if(head == NULL) //0 node case
        printf("\nERROR: UNDERFLOW, CSLL doesn't exist or corrupted!");
    else if(p -> next == head) //1 node case
    {
        del_ele = p -> data;
        free(p);
        head = NULL;
    }
    //error tha
    return head;
}

Node* del_end(Node *head)
{
    Node *p = head;

    if(head == NULL) //0 node case
        printf("\nERROR: UNDERFLOW, CSLL doesn't exist or corrupted!");
    else if(p -> next == head) //1 node case
    {
        del_ele = p -> data;
        free(p);
        head = NULL;
    }

    while(p -> next != head)
        p = p -> next;

    free(p -> next);
    p -> next = head;

    return head;
}

void main()
{
    int i, n, choice, cont = 1;
    Node *start = NULL;
    system("cls");
    printf("\nCircular Singly Linked List (CSLL) Menu Driven C Program");

    do
    {
        printf("\n1. Create CSLL.\n2. Insert a node in CSLL.\n3. Delete a node from CSLL.\n4. Display CSLL.\n5. Count CSLL nodes.\n0. Exit.\nChoice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 0:
            exit(0);
            break;

            case 1:
            printf("\nEnter the number of nodes required in the CSLL: ");
            scanf("%d",&n);
            if(n > 0)
                start = create_CSLL(n);
            break;

            case 2:
            start = inserts(start);
            break;

            case 3:
            start = deletes(start);
            break;

            case 4:
            display_CSLL(start);
            break;

            case 5:
            printf("\nCurrent number of nodes in the CSLL: %d",node_count(start));
            break;

            default:
            printf("\nEntered choice is INVALID...");
        }
        /*printf("\nContinue?: ");
        scanf("%d",&cont);
        getchar();*/ //prevent character buffer messing up the choice inputted for the next iteration
    }while(choice != 6);
}