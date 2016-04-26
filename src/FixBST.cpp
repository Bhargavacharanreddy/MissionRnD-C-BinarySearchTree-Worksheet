/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node * left;
	int data;
	struct node *right;
};

struct node * prev = NULL;  
int index = 0;
struct node *nodes[2];


void traverse(struct node *root, struct node *arr[])  
{
	if (root->left != NULL) 
		traverse(root->left, arr);
   if (prev != NULL)
		if (index != 1)
		{

			if (root->data < prev->data)
			{
				arr[index++] = prev;
				arr[index] = root;
			}
			else
			{
				prev = root;
			}
		}
      else if (index == 1)
		{
			if (root->data < prev->data){

				arr[index] = root;
				return;
			}

		}

	prev = root;

	if (root->right != NULL)	
		traverse(root->right, arr);
}



void fix_bst(struct node *root)
{

      if (root == NULL)
		return;
     prev = NULL; index = 0;
	 traverse(root, nodes);
	 int x = nodes[1]->data;/*swapping the data values*/
	 nodes[1]->data = nodes[0]->data;
	 nodes[0]->data = x;
}
