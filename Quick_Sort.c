//Quick Sort implementation C program. 
#include<stdio.h>
#include<stdlib.h>

void quicksort(int *, int, int, int);
int partitioner(int *, int, int, int);
void swapper(int *a, int, int);

void main()
{
    int i, n, lb, ub, *arr;
    system("cls");

    printf("\nEnter the number of integers the array should have: ");
    scanf("%d",&n);

    arr = (int *)malloc(n * sizeof(int));
    printf("\nNow enter the %d integers: ",n);
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    printf("\nCurrent (unsorted) array: ");
    for (i = 0; i < n; i++)
        printf("%d ",arr[i]);
    
    lb = 0;
    ub = n - 1;

    quicksort(arr, lb, ub, n);

    printf("\nThe sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);
}

int partitioner(int *a, int lb, int ub, int len)
{
    int start = lb, end = ub, pivot = a[lb];
    //pivot is always the first index, 0th element

    while(start < end)
    {
        while(start < len - 1 && a[start] <= pivot) //first condition to check if out of bounds error is not happening, couldn't directly use "ub" because in recursion it keeps on changing
            start++;
        
        while(a[end] > pivot)
            end--;

        if(start < end)
            swapper(a, start, end);
    }
    if(pivot != a[end]) //to prevent pivot swapping with itself and leave it be
        swapper(a, lb, end); //lb is the index of the pivot element
    
    return end;
}

void quicksort(int *a, int lb, int ub, int len)
{
    int prev_pivot; //named prev_pivot because partitioner returns end which is where the pivot is at the end of partitioning for each sub array
    if(lb < ub)
    {
        prev_pivot = partitioner(a, lb, ub, len);
        quicksort(a, lb, prev_pivot - 1, len);
        quicksort(a, prev_pivot + 1, ub, len);
    }
}

void swapper(int *a, int A, int B)
{
    int temp;

    temp = a[A];
    a[A] = a[B];
    a[B] = temp;
}