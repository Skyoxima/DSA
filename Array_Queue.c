//C program to implement a standard Array-based queue in C
#include<stdio.h>
#include<stdlib.h>
int size = 0, front, rear; //front and rear are the queue controls

void initiate()
{
    front = rear = -1; //reset the queue controls 
}

int* allocate_Queue()
{
    int *head;
    printf("\nEnter the size of the Integer Queue: ");
    scanf("%d",&size);

    head = (int *)calloc(size, sizeof(int)); //using calloc for experience, additional advantage of calloc is that also initializes all the array members to 0
    if(head != NULL)
        printf("\nConfirmation: A Queue for %d integers has been created!", size);
    else
    {
        printf("\nQueue for %d inetgers could not be formed...perhaps check the RAM size!", size);
        allocate_Queue();            
    }

    return head;
}

void enqueue(int *a)
{
    int num;
    if(front == -1)
        front++;  //we simply can't take front = 0 because that will then not help in figuring out if the queue is empty or not in dequeue or display functions...
    
    printf("\nEnter the number you want to enqueue: ");
    scanf("%d", &num);

    if(rear == size - 1 && front <= rear) //till a full dequeue is not performed, front will always be < or = rear, I didn't want the program to show OVERFLOW message in the False Overflow situation so did this
        printf("Error: OVERFLOW!");
    else if(front > rear && front != 0) //front != 0 means that atleast 1 dequeue has happened from the queue & front > rear means the False Overflow condition has occured
    {
        printf("Queue in a FALSE OVERFLOW state, reinitialising and then enqueuing...\nElement enqueued successfully!");
        initiate();
        front++; //to make front = 0
        a[++rear] = num;
    }
    else
        a[++rear] = num;
}

int dequeue(int *a)
{
    int val = -1;

    if(front == -1)
        printf("\nERROR: UNDERFLOW! The Queue is currently EMPTY!");
    else if(front > rear)
    {
        printf("FALSE OVERFLOW, reinitialising the Queue...\nSuccess...\nQueue is now EMPTY"); //after the last element is dequeued, according to the else part below, front will exceed rear, at that time reset the queue
        initiate();
    }
    else
        val = a[front++];
    
    return val;
}

void display_Queue(int *a)
{
    int i;

    if(front == -1)
        printf("\nThe Queue is currently EMPTY!");
    else if(front > rear)
    {
        printf("FALSE OVERFLOW, reinitialising the Queue...");
        initiate();
    }
    else
    {
        for(i = front; i < rear + 1; i++) //using for loop here to not change the front and rear indices
            printf("%d ", a[i]);
    }
}

void main()
{
    int i, choice, val, *arr; //front and rear in an array based queue are used as index numbers. We could use them to hold actual addresses but then for rear we would repeatedly have to do pointer arithmetics
    system("cls");
    printf("\nMenu Driven Array-based Queue Implementation.");

    arr = allocate_Queue();
    initiate(); //this initiate function sets the front and rear to -1 and -1 for the first time

    do
    {
        printf("\n\n1. Enqueue into the Queue.\n2. Dequeue from the Queue.\n3. Display Queue contents.\nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
            exit(0);
            break;

            case 1:
            enqueue(arr);
            break;

            case 2:
            val = dequeue(arr);
            
            if(val != -1)
                printf("\nElement first in queue was: %d", val);
            break;

            case 3:
            display_Queue(arr);
            break;

            default:
            printf("\nInvalid Choice, please try again...");
        }
    } while (choice != 0);
    
}