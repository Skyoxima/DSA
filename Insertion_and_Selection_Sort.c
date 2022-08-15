#include<stdio.h>
#include<stdlib.h>

void select_sort(int *arr, int n)
{
    int min_index, j, k, temp;

    for(j = 0; j < n - 1; j++)
    {
        min_index = j; //setting the default minimum value at the start of the loop 
        for(k = j + 1; k < n; k++)
        {
            if(arr[k] < arr[min_index])
                min_index = k;
        }
        if(min_index != j)
        {
            temp = arr[j];  // swap if min_index changed
            arr[j] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void insert_sort(int *arr, int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];

        for(j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j]; 
        
        arr[j + 1] = key;
    }
}

void main()
{
    int choice, i, n, *arr;
    system("cls");
    
    printf("\nEnter the number of integers the array should contain: ");
    scanf("%d",&n);
    
    arr = (int *)malloc(n *(sizeof(int)));
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    printf("\nThe entered array of integers are as shown: ");
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    printf("\nEnter the type of sorting to be performed\n1. Selection Sort\n2. Insertion Sort\nChoice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
        exit(0);
        break;

        case(1):
        printf("\nInitializing Selection Sort..."); 
        select_sort(arr, n);
        
        printf("\nArray after performing the selection sort algorithm: ");
        for(i = 0; i < n; i++)
            printf("%d ",arr[i]);
        break;

        case(2):
        printf("\nInitializing Insertion Sort..."); 
        insert_sort(arr, n);
        
        printf("\nArray after performing the insertion sort algorithm: ");
        for(i = 0; i < n; i++)
            printf("%d ",arr[i]);
    }
    
}