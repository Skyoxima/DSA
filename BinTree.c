#include<stdio.h>
#include<stdlib.h>
int flag = 1;

typedef struct tree_node
{
    int data;
    struct tree_node *left, *right;
}TreeNode;

TreeNode* create_tree()
{
    int val = 0;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    
    if (flag == 1) //for formatting purposes
    {
        printf("\nEnter the value for the root node: ");
        flag = 0;
    }
    scanf("%d",&val);
    if(val == -1)
    {
        return NULL; //exit condition from infinite recursion
    }
    root -> data = val;
    
    printf("\nNow enter the left child of %d",root -> data);
    printf("\n(Enter -1 to not create a child) : ");
    root -> left = create_tree();
    
    printf("\nNow enter the right child of %d",root -> data);
    printf("\n(Enter -1 to not create a child) : ");
    root -> right = create_tree();
     
    return root;
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

int node_count(TreeNode *root)
{
    if(root == NULL)
        return 0;   //the recursion exit statement, as well as the tree existence check statement
    else if(root -> left == NULL && root -> right == NULL) // to prevent recursive call with null arguments passed
        return 1;   //ends recursion by counting the root that actually has a value and just returning that count

    return(1 + node_count(root -> left) + node_count(root -> right));
}

int leaf_count(TreeNode *root)
{
    if(root == NULL)
        return 0;
    else if(root -> left == NULL && root -> right == NULL)
        return 1;

    return(leaf_count(root -> left) + leaf_count(root -> right));
}

int deg_1_count(TreeNode *root)
{
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) //or part is written to prevent null arguments recursive call
        return 0;
    else if((root -> left == NULL && root -> right != NULL)||(root -> left != NULL && root -> right == NULL)) //condtions for one child
        return(1 + deg_1_count(root -> left) + deg_1_count(root -> right));
    else
        return((deg_1_count(root -> left)) + (deg_1_count(root -> right)));
}

int deg_2_count(TreeNode *root)
{
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) //or part is written to prevent null arguments recursive call
        return 0;
    else if(root -> left != NULL && root -> right != NULL) //condition for 2 children
        return(1 + deg_2_count(root -> left) + deg_2_count(root -> right));
    else
        return((deg_2_count(root -> left)) + (deg_2_count(root -> right)));     
}

TreeNode* copy_tree(TreeNode *root)
{
    if(root == NULL)
        return NULL;

    TreeNode *new_root = (TreeNode *)malloc(sizeof(TreeNode));
    new_root -> data = root -> data;
    
    new_root -> left = copy_tree(root -> left);
    new_root -> right = copy_tree(root -> right);

    return new_root;
}

void mirror_tree(TreeNode *mirror_root)
{    
    if(mirror_root == NULL)
        return;
    
    TreeNode *temp = NULL;
    
    mirror_tree(mirror_root -> left);
    mirror_tree(mirror_root -> right);

    temp = mirror_root -> left;
    mirror_root -> left = mirror_root -> right;
    mirror_root -> right = temp; 
}

int height_of_tree(TreeNode *root)
{
    int lh = 0, rh = 0;
    
    if(root == NULL)
        return -1; //to adjust height (depth) of tree starting from 0

    lh = 1 + height_of_tree(root -> left);
    rh = 1 + height_of_tree(root -> right);
    
    if(lh > rh)
        return (lh);
    return (rh);
}

void main()
{
    int choice, leafs, nodes, degree, height;
    TreeNode *Root = NULL;  //to prevent infinite empty tree printing in traversals 
    TreeNode *NewRoot = NULL;
    system("cls");

    do
    {
		printf("\n\n1. Create a Binary Tree.\n2. PreOrder Traversal.\n3. InOrder Traversal.\n4. PostOrder Traversal.\n5. Count total number of nodes in the binary tree.");
		printf("\n6. Count leaf nodes in the binary tree.\n7. Count Degree 1 nodes.\n8. Count Degree 2 nodes.\n9. Copy Binary Tree.\n10. Create Mirror Tree.\n11. Find height of the binary Tree.");
		printf("\nChoice : ");
		scanf("%d",&choice);

		switch(choice)
		{
	    	case 0:
	    	exit(0);
	    	break;

	    	case 1:
	    	Root = create_tree();
	    	flag = 1;
            break;

            case 2:
	    	printf("Following is the binary tree in printed in PreOrder: ");
            preOrder(Root);
            break;

	    	case 3:
	    	printf("Following is the binary tree in printed in InOrder: ");
            inOrder(Root);
            break;

	    	case 4:
	    	printf("Following is the binary tree in printed in PostOrder: ");
            postOrder(Root);
            break;

	    	case 5:
	    	nodes = node_count(Root);
            printf("Number of nodes in the binary tree : %d",nodes);
            break;

	    	case 6:
            leafs = leaf_count(Root);
            printf("Number of leaf nodes in the binary tree : %d",leafs);
            break;

            case 7:
	    	degree = deg_1_count(Root);
            printf("Number of 1st Degree Nodes (nodes with 1 child) : %d",degree);
            break;

	    	case 8:
	    	degree = deg_2_count(Root);
            printf("Number of 2nd Degree Nodes (nodes with 2 children) : %d",degree);
            break;

	    	case 9:
            NewRoot = copy_tree(Root);
            printf("The Original binary tree has been copied...");
            printf("\nFollowing is the original binary tree in Pre-Order: ");
            preOrder(Root);
            printf("\nFollowing is the copied binary tree in Pre-Order: ");
            preOrder(NewRoot);
            break;

	    	case 10:
	    	NewRoot = copy_tree(Root);
            printf("The Original binary tree has been copied");
            mirror_tree(NewRoot);
            printf("...mirror copy has been created");
            printf("\nFollowing is the original binary tree in Pre-Order: ");
            preOrder(Root);
            printf("\nFollowing is the mirrored binary tree in Pre-Order: ");
            preOrder(NewRoot);
            break;

	    	case 11:
	    	height = height_of_tree(Root);
            printf("Height of Binary Tree is : %d",height);
            break;

	    	case 24:
	    	break;

	    	default:
	    	printf("\nInvalid Choice!");
	    	break;
		}
    }while(choice != 24);
}