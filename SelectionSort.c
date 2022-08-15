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

void main()
{
    int choice, i, n, *arr;
    system("cls");
    do
    {
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
        
        select_sort(arr, n);
        printf("\nArray after performing the selection sort algorithm: ");
        for(i = 0; i < n; i++)
            printf("%d ",arr[i]);

        printf("\nWant to sort another set of integers?\n1. Yes\n0. No, exit.: ");
        scanf("%d",&choice);
    }while(choice != 0);
}