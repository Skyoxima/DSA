//C program for implementing a Simple Linked List (SLL)
#include<stdio.h>
#include<stdlib.h>

//creating a structure (user defined data type) for Nodes of the linked list we want to create.
typedef struct LL_Node //using typedef to not have to repeatedly write "struct" whenever declaring LL_Node
{
    int data;
    struct LL_Node *next; //as the "next" pointer will point to another node, it has to be of the type of structure itself.
}Node; //this Node is not a global object of the structure but the name we'll use to refer a linked list node further. This is because of the typedef we've used earlier 


Node* create_SLL(int n)
{
    int i;
    Node *head = (Node *)malloc(sizeof(Node));
    Node* p = head; //we use "p" to traverse through the SLL, it is currently pointing to the start of the SLL

    printf("\nNow enter the first element of the SLL: ");
    scanf("%d",&p -> data);

    for(i = 1; i < n; i++)
    {
        p -> next = (Node *)malloc(sizeof(Node));
        p = p -> next;
        printf("Enter the next data: ");
        scanf("%d",&p -> data);
    }
    p -> next = NULL; //the last node's next should be a NULL so that we can use this condition rather than the inputted node count

    return head;
}

void display_SLL(Node *head)
{
    Node *p = head;

    if(head == NULL)
        printf("\nThe SLL is currently EMPTY!");
    else
    {
        while(p != NULL)
        {
            printf("%d ",p -> data);
            p = p -> next;
        }
    }
}

int node_count(Node *head)
{
    int count = 0;
    Node *p = head;

    if(head != NULL)
    {
        while(p != NULL)
        {
            count++;
            p = p -> next;
        }
    }
    return count;
}

void user_friend_1(Node *head)
{
    printf("Current nodes of the SLL: ");
    display_SLL(head); //for user friendliness
    printf("\nCurrent number of nodes: %d",node_count(head));    
}

Node* insert_beg(Node *, int);
Node* insert_end(Node *, int);
Node* insert_pos(Node *, int, int);
Node* insert_bef(Node *, int, int);

Node* inserts(Node* head)
{
    int choice, val, pos;
    printf("\n\nInsertions Menu:\n1. Insert at the beginning.\n2. Insert at the end.\n3. Insert at specified position (not index!).\n4. Insert before an specific node.\nChoice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        printf("\nEnter the integer you want to insert at the beginning of the SLL: ");
        scanf("%d",&val);
        head = insert_beg(head, val);
        break;

        case 2:
        printf("\nEnter the integer you want to insert at the end of the SLL: ");
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
        printf("\nInvalid Choice!");
    }

    return head;
}

Node* insert_beg(Node *head, int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL) //new node couldn't be formed case
    {        
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;

    if(head == NULL) //no existing node/SLL condition
        new -> next = NULL;
    else    
        new -> next = head;
    
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
    new -> next = NULL;

    if(head == NULL) //no existing node condtion
        return new;

    while(p -> next != NULL)
        p = p -> next;
    p -> next = new;

    return head;
}

Node* insert_pos(Node *head, int val, int pos)
{
    int count = 1; //position numbers, using indexes (0 - n-1) would be hectic to implement
    Node *p = head;
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {        
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val;
    
    if(head == NULL) //no existing node condition
    {
        printf("\nThe SLL was empty...inserting at 1st position");
        new -> next = NULL;
        return new;
    } 
    else if(pos <= 1) //this has to be done otherwise you cannot enter at the 1st position, it would still go at the 2nd, < for 0 and -ve pos check
        head = insert_beg(head, val); //could directly insert first but didn't cause didn't want to write to different returns
    else
    {
        while(count < pos - 1 && p -> next != NULL) //2nd condition to prevent overshooting the n+1th position
        {
            count++;
            p = p -> next;
        }
        new -> next = p -> next; //this also takes care of the NULL if new is entered at the (n+1)th position 
        p -> next = new;
    } 

    return head;
}

Node* insert_bef(Node *head, int val, int bef)
{ 
    Node *p = head;
    Node *new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
    {        
        printf("\nERROR: OVERFLOW, a new node could not be created, please empty the memory!");
        return head;
    }
    new -> data = val; 
    
    if(head == NULL) //no existing node condition
    {
        printf("\nThe SLL was empty...inserting at 1st position");
        new -> next = NULL;
        return new;
    }
    else if(head -> data == bef)
        head = insert_beg(head, val);
    else
    {
        while(p -> next != NULL && p -> next -> data != bef)
            p = p -> next;
        if(p -> next == NULL) //if p is AT the last node, "before" node not found hence cannot be inserted before any node
            printf("\nVALUE_NOT_FOUND ERROR... Please check the SLL and try again!"); //for to insert before the last node p stops at second last node
        else
        {
            new -> next = p -> next;
            p -> next = new;
        }
    }    

    return head;
}

Node* delete_SLL(Node *);
Node* del_beg(Node *);
Node* del_end(Node *);
Node* del_of_value(Node *, int);
Node* del_pos(Node *, int);

void check_if_exists(Node *head)
{
    if(head != NULL)
    {
        printf("\nA SLL already exists, deleting it...");
        delete_SLL(head);
    }
}

Node* deletes(Node *head)
{
    int choice, conf, pos, val;
    
    printf("\nDeletion Menu: \n1. Delete the SLL.\n2. Delete the first node.\n3. Delete the last node.\n4. Delete node with specified data.\n5. Delete node at specified position.\nChoice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        printf("\nAre you sure?\n1. Yes\n0. No: ");
        scanf("%d",&conf);
        if(conf == 1)
            head = delete_SLL(head);
        break;

        case 2:
        head = del_beg(head);
        break;

        case 3:
        head = del_end(head);
        break;

        case 4:
        user_friend_1(head);
        printf("\n\nEnter the value of the node you want to delete: ");
        scanf("%d",&val);
        head = del_of_value(head, val);
        break;

        case 5:
        user_friend_1(head);
        printf("\n\nEnter the position of the node you want to delete: ");
        scanf("%d",&pos);
        head = del_pos(head, pos);
        break;
        
        default:
        printf("\nInvalid Choice!");
    }

    return head;
}

Node* delete_SLL(Node *head)
{
    Node *p = head;
    Node *q;

    if(head == NULL)
        printf("\nSLL does not exists.");
    else
    {
        while(p != NULL)
        {
            q = p;
            p = p -> next;
            free(q);
        }
    }
    head = NULL;

    return head;
}

Node* del_beg(Node *head)
{
    Node *p = head;
    
    if(head == NULL)
        printf("\nSLL is already empty!");
    else
    {
        head = head -> next;
        free(p);
    }

    return head;
}

Node* del_end(Node *head)
{
    Node *p = head;

    if(head == NULL)
        printf("\nSLL is already empty!");
    else if(p -> next == NULL) //single node case
    {
        free(p);
        return NULL;
    }
    else
    {
        while(p -> next -> next != NULL)
            p = p -> next;
        
        free(p -> next);
        p -> next = NULL;
    }

    return head;
}

Node* del_of_value(Node *head, int val)
{
    Node *p = head;
    Node *q = NULL;

    if(head == NULL)
        printf("\nThe SLL is empty...no value to delete!");
    else if(val == head -> data)
        head = del_beg(head);
    else
    {
        while(p -> next != NULL && p -> next -> data != val) //similar logic as that of insert_bef function
            p = p -> next;       
        
        if(p -> next == NULL) //i.e if p itself is at the last node
            printf("\nNode to be deleted NOT FOUND");
        else
        {
            q = p -> next; //the actual node that is to be deleted
            p -> next = q -> next; //takes care of the NULL situation if last node is to be deleted
            free(q);
        }
    }

    return head;
}

Node* del_pos(Node *head, int pos)
{
    int count = 1;                                                                   
    Node *p = head;
    Node *q = NULL;

    if(head == NULL)
        printf("\nThe SLL is currently empty!");
    else
    {
        if(pos <= 1)
            head = del_beg(head);
        else if(pos > node_count(head))
            printf("\nERROR: The SLL doesn't have a node at %dth position...",pos);
        else
        {
            while(count < pos - 1 && p -> next != NULL)
            {
                count++;
                p = p -> next;
            }
            q = p -> next; //the actual node which is to be deleted
            p -> next = q -> next;
            free(q); 
        }
    }
    
    return head;
}

void main()
{
    int i, n, choice, val;
    Node *start = NULL; //a pointer of the type Node to point to a Node object.
    system("cls");
    printf("\nMenu Driven Program for Implementing a Simple Linked List (SLL) in C.");

    do
    {
        printf("\n\n1. Create a Simple/Singly Linked List.\n2. Insert element in a Simple/Singly Linked List.\n3. Delete a Node from the Simple/Singly Linked List.\n4. Display the SLL elements.\n5. Count the number of elements in the SLL. \nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
            exit(0);
            break;

            case 1:
            check_if_exists(start);
            printf("\nEnter the number of nodes you want the SLL to have: ");
            scanf("%d",&n);
            if(n > 0)
                start = create_SLL(n);
            break;

            case 2:
            start = inserts(start);
            break;
            
            case 3:
            start = deletes(start);
            break;

            case 4:
            printf("\nCurrent SLL elements: ");
            display_SLL(start);
            break;

            case 5:
            printf("\nCurrent count of elemets in the SLL: %d",node_count(start));
            break;

            default:
            printf("\nInvalid Choice, please try again!");
        }
    } while(choice != 0);  
}