/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int i;

void inorder1(struct node *root, int *arr)
{
	
	if (!root || !arr) return;
	inorder1(root->left, arr);
	arr[i++] = root->data;
	
	inorder1(root->right, arr);
}
void inorder(struct node *root, int *arr)
{
	i = 0;
	inorder1(root, arr);

}
void preorder1(struct node *root, int *arr)
{
	if (!root || !arr) return;

	arr[i++] = root->data;
	preorder1(root->left, arr);
	preorder1(root->right, arr);
}
void preorder(struct node *root, int *arr)
{
	i = 0;
	//static int j = 0;
	preorder1(root, arr);
}
void postorder1(struct node *root, int *arr)
{
	if (!root || !arr) return;

	postorder1(root->left, arr);
	postorder1(root->right, arr);
	arr[i++] = root->data; 
}
void postorder(struct node *root, int *arr)
{
	//static int z = 0;
	i = 0;
	postorder1(root, arr);

}

