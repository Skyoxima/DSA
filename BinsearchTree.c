#include<stdio.h>
#include<stdlib.h>
int flag = 1;

typedef struct tree_node
{
    int data;
    struct tree_node *left, *right;
}TreeNode;

TreeNode* create_node(int val)
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root -> data = val;
    root -> left = root -> right = NULL;
    return root;
}

TreeNode* insert(TreeNode *root, int val)
{
    if(root == NULL)
    {
        root = create_node(val);
    }
    else if(val < root -> data) //else if better than seperate if else if
    {
        root -> left = insert(root -> left, val);
        if(flag == 1)
            printf("Value %d is appended to the left of %d\n",val,root -> data);
        flag = 0;    
    }  
    else if(val > root -> data)
    {
        root -> right = insert(root -> right, val);
        if(flag == 1)
            printf("Value %d is appended to the right of %d\n",val,root -> data);
        flag = 0;    //this prevents printing all sentences from the parent node to the root node and only uses the parent node
    }    

    return root;
    //all 3 cases will be false for a duplicate value, so it won't append the duplicate at all, although no error will be raised
}

TreeNode* recursive_insertion(TreeNode *root) //could've been done using a while loop too
{
    int value;
    
    printf("\nEnter the value to be entered at a node\n(-1 for no node): ");
    scanf("%d",&value);
    
    if(value == -1)
        return root;

    root = insert(root, value); //since the insert function will ultimately return the root node address, no need for root backup
    flag = 1;
    recursive_insertion(root);

    return root;
}

void minimum_node(TreeNode *root)
{
    TreeNode *leftest = root;
    if(root == NULL)
        printf("\nThe tree is currently empty.\n");
    else
    {
        while(leftest -> left != NULL)
        {
            leftest = leftest -> left;
        }
        
        printf("Smallest value in the entire Binary Search Tree is: %d\n",leftest -> data);
    }
}

void maximum_node(TreeNode *root)
{
    TreeNode *rightest = root;
    if(root == NULL)
        printf("\nThe tree is currently empty.\n");
    else
    {
        while(rightest -> right != NULL)
        {
            rightest = rightest -> right;
        }
        
        printf("Largest value in the entire Binary Search Tree is: %d\n",rightest -> data);
    }
}

int find_node(TreeNode *root, int val)
{
    int left_stat = 0, right_stat = 0;

    if(root == NULL) // if reached leaf(s) or tree empty
        return 0; 
    if(root -> data == val) //if found
        return 1;
    
    left_stat = find_node(root -> left, val);   //searching in left sub-tree 
    if(left_stat == 1)
        return 1;

    right_stat = find_node(root -> right, val); //searching in right sub-tree
    if(right_stat == 1)
        return 1; 
    
    return 0; //not found
}

void preOrder(TreeNode *root)
{
    if(root != NULL) //recursion ends on NULL child addresses
    {
        printf("%d ", root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void inOrder(TreeNode *root)
{
    if(root != NULL) //recursion ends on NULL child addresses
    {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

void postOrder(TreeNode *root)
{
    if(root != NULL) //recursion ends on NULL child addresses
    {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ", root -> data);
    }
}

void traversal(TreeNode *root)
{
    printf("\nPreOrder Traversal: ");
    preOrder(root);
    printf("\nInOrder Traversal: ");
    inOrder(root);
    printf("\nPostOrder Traversal: ");
    postOrder(root);
    printf("\n");
}

void main()
{
    int choice, value;
    TreeNode *Root = NULL;
    //system("cls");

    do
    {
        printf("\n1. Create the Binary Search Tree.\n2. Find Minimum value.\n3. Find Maximum value.\n4. Find Any value\n5. Insert a value.\n6. Show current Binary Search Tree.\n0. Exit.\nChoice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
            exit(0);
            break;

            case 1:
            printf("\nEnter the value for the root node: ");
            scanf("%d",&value);
            Root = create_node(value);
            
            printf("\nAdd more nodes?\n1. Yes\n0. No: ");
            scanf("%d",&choice);
            if(choice == 1)
                Root = recursive_insertion(Root);
            traversal(Root);
            break;

            case 2:
            minimum_node(Root);
            break;

            case 3:
            maximum_node(Root);
            break;

            case 4:
            printf("Enter the value to be searched in the Binary Search Tree: ");
            scanf("%d",&value);
            choice = find_node(Root, value);
            if(choice == 1)
                printf("%d was found in the Binary Search Tree!\n",value);
            else   
                printf("%d was not found in the Binary Search Tree...\n",value);
            break;
            
            case 5:
            printf("\nEnter the value to be entered at a node: ");
            scanf("%d",&value);
            Root = insert(Root, value);
            traversal(Root);
            break;

            case 6:
            traversal(Root);
            break;
            
            case 26:
            break;

            default:
            printf("\nInvalid Choice!");
        }
    }while(choice != 26);
}