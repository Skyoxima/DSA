//C program for Merge Sort implementation on a singular unsorted array
#include<stdio.h>
#include<stdlib.h>

void mergesort(int *a, int lb, int ub);
void merger(int *a, int lb, int mid, int ub);
int count(int, int);

void main()
{
    int i, n, lb, ub;
    int *arr;
    system("cls");

    printf("\nEnter the number of elements the array of integers will have: ");
    scanf("%d",&n);

    arr = (int *)calloc(n, sizeof(int));

    printf("\nNow enter the elements for the array: ");
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    printf("\nCurrent (unsorted) array: ");
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);

    lb = 0;  
    ub = n - 1; 

    mergesort(arr, lb, ub);

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);
}

int count(int lb, int ub)
{
    int count = 0;

    while(lb <= ub)
    {
        lb++;
        count++;
    }
    return count;
}

void mergesort(int *a, int lb, int ub)
{
    int mid = 0;

    if(lb < ub)
    {
        mid = (lb + ub)/2;
        mergesort(a, lb, mid); //recursively calling the function hence time complexity becomes (n)log(n)
        mergesort(a, mid + 1, ub); 
        merger(a, lb, mid, ub); //merge two sub-arrays
    }
}
//highly recommend to refer the recursion tree for these functions in my digital notes.

void merger(int *a, int lb, int mid, int ub) //we don't actually have 2 separate arrays but two parts within the same array decided by these indices 
{
    int *b = (int *)calloc((count(lb, mid) + count((mid + 1), ub)), sizeof(int)); //cannot use ub because it'll cause major space wastage for later elements of the array
    int i = lb, j = mid + 1, k = 0; //mid is what controls the two separate parts

    while(i <= mid && j <= ub) //filling up the auxiliary array in a sorted manner
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;    
    }
    
    while(i <= mid) //emptying first array (if applicable)
    {
        b[k] = a[i];
        k++;
        i++;
    }    

    while(j <= ub) //emptying second array (if applicable)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for(i = lb, j = 0; i <= ub; i++, j++) //copying the auxiliary array contents to the main array at corresponding position
        a[i] = b[j];
    free(b);
}
