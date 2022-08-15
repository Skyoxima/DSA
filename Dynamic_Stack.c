#include<stdio.h>
#include<stdlib.h>
int max = 0; //defining max as a global variable here to avoid passing it into each function all, for security tho we can totally do that and not define it as a global variable
int TOS = -1; //same is the case with TOS as that of the max

void push(int *a)
{
    int v;

    if(TOS == max - 1) //if the top of stack is already at the upper limit, return failure of OVERFLOW, max - 1 as indexing starts from 0
        printf("\nFailure: Error statement - OVERFLOW!");
    else
    {
        printf("\nEnter the value to be pushed into the Stack: ");
        scanf("%d", &v);
        a[++TOS] = v;
    }
}

int pop(int *a)
{
    int val;

    if(TOS == -1) //if the Stack is already empty
        printf("\nThe Stack is currently empty...");
    else
    {
        val = a[TOS--];
        return val;
    }
    return -1;
}

int peek(int *a)
{
    if(TOS == -1) //if the Stack is already empty
        printf("\nThe Stack is currently empty...");
    else
        return a[TOS];
    return -1;
}

void display(int *a)
{
    int tos = -1;

    if(TOS == -1)
        printf("\nThe Stack is currently empty!");
    else
    {
        printf("\nCurrent Stack contents: ");
        while(tos != TOS)
        {   
            printf("%d ", a[++tos]);
        }
    }    
    printf("\n");
}

void empty(int *a)
{
    while(TOS != -1)
        a[TOS--] = 0;
}

void main()
{
    int i, choice, val;
    int *p, *arr;
    system("cls");

    printf("\nDynamic Stack Implementation in C");
    printf("\nEnter the size of the Stack: "); //the stack should not take in more numbers than what's specified here, it should return OVERFLOW if that's the case
    scanf("%d", &max);
    p = (int *)malloc(max * sizeof(int)); //allocating memory for a max integer array
    if(p == NULL) //checking if memory allocation failed (which it wouldn't here as max has integer size limit of 32767 which is 65534 when x2-ed which is 65 KB)
    {
        printf("\nMemory allocation failure... try reducing the number of integers for the Stack...");
        printf("\nPress any key to continue to exit and retry..."); getchar(); exit(0);
    }
    arr = p;    
    
    do
    {
        printf("\nEnter what do you want to do to the Stack: \n1. Push.\n2. Pop.\n3. Peek.\n4. Display.\n5. Empty.\n6. Increase Stack size.\nChoice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
            exit(0);
            break;

            case 1:
            push(arr);
            break;

            case 2:
            val = pop(arr);
            if(val != -1)
                printf("\nValue that was on the top of the Stack : %d", val);
            break;

            case 3:
            val = peek(arr);
            if(val != -1)
                printf("\nValue that is on the top of the Stack: %d", val);
            break;

            case 4:
            display(arr);
            break;

            case 5:
            empty(arr);
            break;

            case 6:
            printf("\nEnter the new size of the Stack: ");
            scanf("%d", &max);
            arr = (int *)realloc(arr, max * sizeof(int));
            if(arr == NULL)
                printf("\nThe Stack cannot be further expanded...check memory availability");
            
            printf("\nThe Stack size has been increased successfully!");
            break;

            //a decrease stack size function can also be made here but it doesn't really come into the basics of stacks so I am not doing it here
            default:
            printf("\nEntered Invalid Choice!\nPlease try again...");
        }
    }while(choice != 0);
}