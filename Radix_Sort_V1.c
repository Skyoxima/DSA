//C program for radix sort using static 2D array, 10 inputs compulsory
#include<stdio.h>
#include<stdlib.h>
int TOS[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //last one is the "master TOS"

int digi_max(int *a)
{
    int i, temp, count, max_count = 0;
    for(i = 0; i < 10; i++)
    {
        temp = a[i];
        
        while(temp != 0)
        {
            count++;
            temp = temp / 10;
        }
        if(max_count < count)
            max_count = count;
        
        count = 0;
    }
    
    return max_count;
}

void printer(int a[15][15])
{
    int i, j;
    for(i = 0; i < 10; i++) //2D array printer
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void empty_bucket(int buck_mat[15][15], int in_arr[15])
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(buck_mat[i][j] != 0)
                {
                    in_arr[++TOS[10]] = buck_mat[i][j]; //master TOS used here
                    buck_mat[i][j] = 0;
                }
        }
    }
}

void bucket_sort(int buck_mat[15][15], int in_arr[15], int b_in_arr[15])
{
    int i, j;

    for(i = 0; i < 10; i++) //for all input array elements
    {
        for(j = 0; j < 10; j++) // for all bucket numbers
        {
            if(b_in_arr[i] % 10 == j)
            {
                TOS[j]++;
                buck_mat[j][TOS[j]] = in_arr[i];
            }
        }
    } 
}

void TOS_reset()
{
    int i;

    for(i = 0; i < 11; i++) //reset from 0 to 10 cause 10th is the master TOS
        TOS[i] = -1;
}

void LSD_change(int *a, int expo)
{
    int i;
    
    for(i = 0; i < 10; i++)
        a[i] = a[i]/expo;
}

//integer arrays in C do not have a terminating character, you will always have to use the upper limit for for loop condition checking
void main()
{
    int i, j, k, max, n, e, in_arr[15], b_in_arr[15], bucket_mat[15][15];
    system("cls");
    printf("\nRadix Sort (Bucket Sort) Trial program!");

    printf("\nEnter the elements you want to sort (Limit of 10 numbers!): ");
    for(i = 0; i < 10; i++)
        scanf("%d",&in_arr[i]);
    
    for(i = 0; i < 10; i++) //creating a positional copy, which essentially controls the flow of the placevalues of digits
            b_in_arr[i] = in_arr[i]; //b_in_arr - "backup in-array"
    
    max = digi_max(in_arr); //find out the digits of the max number, used for controlling how many times buckets will be made

    for(i = 0; i < 10; i++) //setting all cells of the n x n 2D matrix as 0
    {
        for(j = 0; j < 10; j++)
        {
            bucket_mat[i][j] = 0;
        }
    }
    printf("\n");
    
    for(k = 0, e = 10; k < max; k++, e *= 10) //e is exponent control, used for controlling division done on b_in_arr for place change (LSD to MSD)
    {
        bucket_sort(bucket_mat, in_arr, b_in_arr);
        printf("\n\nCurrent buckets status: \n"); //testing purpose
        printer(bucket_mat);

        empty_bucket(bucket_mat, in_arr);

        printf("\nInput array after emptying current bucket: "); //testing purpose
        for(j = 0; j < 10; j++)
            printf("%d ",in_arr[j]);    

        for(i = 0; i < 10; i++) //creating a positional copy
            b_in_arr[i] = in_arr[i];
        
        LSD_change(b_in_arr, e);

        printf("\nChanges made to the auxiliary array: "); //testing purpose
        for(j = 0; j < 10; j++)
            printf("%d ",b_in_arr[j]);
        
        TOS_reset();
    }

    printf("\nThe sorted array is: ");
    for(j = 0; j < 10; j++)
            printf("%d ",in_arr[j]);
}
