/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
#include<math.h>
struct node
{
	struct node * left;
	int data;
	struct node *right;
};
int arr[100] = { 0 };
int heightOfBst(struct node *root)
{
	if (root == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = heightOfBst(root->left);
		int rDepth = heightOfBst(root->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}

}


void nextLevel(struct node *root, int *arr, int *index, int level, int curlevel)
{
	if (curlevel == level)
	{// if specified level met , copy that value into the array
		arr[(*index)++] = root->data;
		return;
	}

	if (root->right != NULL)	
		nextLevel(root->right, arr, index, level, curlevel + 1);
	if (root->left != NULL)		
		nextLevel(root->left, arr, index, level, curlevel + 1);

}




int* BSTRighttoLeftRows(struct node* root)
{

	if (root == NULL) 
		return NULL;

	int pos = 0,size = 0, level = 0;;
	level= heightOfBst(root);
// for each level, add the node values to array
   for (int i = 0; i < level; i++)
	{
		nextLevel(root, arr, &pos, i, 0);
	}
	return arr;
}
