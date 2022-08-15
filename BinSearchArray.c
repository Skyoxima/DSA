#include<stdio.h>
#include<stdlib.h>

void sort_array(int *array, int n)
{
    int j, k, temp;

    for(j = 1; j < n; j++)
    {
        for(k = 0; k < n - j; k++)
        {
            if(array[k] > array[k+1])
            {
                temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
    }
}

int bin_search(int *array, int n, int num)
{
    int ll = 0, ul, m; //lower limit, upper limit
    ul = n - 1;
    m = (ll + ul)/2;

    while(ll < ul && array[m] != num)
    {
        if(array[m] < num)
            ll = m + 1;
        else
            ul = m - 1;
        m = (ll + ul)/2;
    }

    return m;
}

void print_order(int n)
{
    switch(n)
    {
        case 1:
        printf("%dst position in the sorted array!",n);
        break;

        case 2:
        printf("%dnd position in the sorted array!",n);
        break;

        case 3:
        printf("%drd position in the sorted array!",n);
        break;
    
        default:
        printf("%dth position in the sorted array!",n);
    }
}

void main()
{
    int n = 0, i, num, choice, ans;
    int *arr;
    system("cls");
    
    printf("\nEnter the number of integers the array should consist: ");
    scanf("%d",&n);

    arr = (int *)malloc(n*(sizeof(int)));
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    do
    {
        printf("\nNumbers in the array are: ");
        for(i = 0; i < n; i++)
            printf("%d ",arr[i]);

        sort_array(arr,n);
    
        printf("\nSorted array of entered numbers: ");
        for(i = 0; i < n; i++)
            printf("%d ",arr[i]);
        
        printf("\n\nEntered the number to be searched in the array: ");
        scanf("%d",&num);

        ans = bin_search(arr, n, num);

        if(arr[ans] == num)
        {
            printf("Entered number %d was found at ",num);
            print_order(ans + 1);
        }
        else
            printf("Entered number %d was not found in the array...",num);
        
        printf("\n\nSearch another number in the same array\n1. Yes\n0. No, exit: ");
        scanf("%d",&choice);
        printf("\n");

    }while(choice != 0);    
}